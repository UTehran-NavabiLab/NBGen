import os
import sys
import json
import subprocess
import shutil
from utilitie_funcs import *
from utilitie_funcs import split_page
from make_script import yosys_script_mk
from make_script import abc_script_mk
from replace_lut import replace_bench


def preparation():
   # create directory (synthesis, lib, log, bench)
   working_directory = os.getcwd()
   synthesis_dir = mkdir("synthesis", working_directory)
   lib_dir = mkdir("lib", working_directory, False)
   log_dir = mkdir("log", working_directory)
   bench_dir = mkdir("bench", working_directory)

   # read config file
   with open(os.path.join(lib_dir, "config.json"), "r") as json_file:
      config = json.load(json_file)

   # copy abc.rc to bench_dir
   abc_rc_src = os.path.join(lib_dir, "abc.rc")
   abc_rc_dst = os.path.join(bench_dir, "abc.rc")
   try:
      shutil.copyfile(abc_rc_src, abc_rc_dst)

   # If source and destination are same
   except shutil.SameFileError:
      print("Source and destination represents the same file.")
   
   # If destination is a directory.
   except IsADirectoryError:
      print("Destination is a directory.")
   
   # If there is any permission issue
   except PermissionError:
      print("Permission denied.")
   
   # For other errors
   except:
      print("Error occurred while copying file.")

   return {"directories": [working_directory, synthesis_dir, lib_dir, log_dir, bench_dir], 
            "config": config}

# @def: synthesize using yosys
#  @args: 
#     config: dictionary of configuration obtained from json
#     vhdl: determine the design to be vhdl
#     use_existing_script: if set to false bypasses script making process
#        user must provide valid yosys script at valid location (under lib_dir)
def netlist(input_file_name, module_name, config, working_directory, synthesis_dir, lib_dir, log_dir, vhdl=False, use_existing_script=False):
   yosys_script_dir = os.path.join(lib_dir, "yosys_script.ys")

   if not (use_existing_script):
      with open(yosys_script_dir,'w',encoding = 'utf-8') as f:
         f.write(yosys_script_mk(input_file=input_file_name, module_name=module_name, 
                                 config=config, working_directory=working_directory, 
                                 lib_dir=lib_dir, synthesis_dir=synthesis_dir, vhdl=vhdl))

   # change dir to synthesis
   os.chdir(synthesis_dir)
   # run yosys script with input file name, throw exception if failed
   yosys_log = subprocess.run([config["yosys_bin"], yosys_script_dir], stdout=subprocess.PIPE, text=True, check=True)
   # yosys_log = subprocess.run([config["yosys_bin"], yosys_script_dir], stdout=subprocess.PIPE, text=True, input=f'script {yosys_script_dir}', check=True)
   yosys_log_dir = os.path.join(log_dir, "yosys.log")
   with open(yosys_log_dir,'w', encoding = 'utf-8') as f:
      f.write(yosys_log.stdout)
   # change dir back to workdirectory
   os.chdir(working_directory)

def bench(config, working_directory, synthesis_dir, lib_dir, log_dir, bench_dir):
   # writing abc script
   abc_script_dir = os.path.join(lib_dir, "abc_script.scr")

   with open(abc_script_dir,'w',encoding = 'utf-8') as f:
      f.write(abc_script_mk(config=config, lib_dir=lib_dir, 
                              bench_dir=bench_dir, synthesis_dir=synthesis_dir))
   
   with open(os.path.join(synthesis_dir, config["yosys_script_premap_v_outputName"]), 'r', encoding = 'utf-8') as f:
      yosys_v_output = f.read()
      
   # remove .C port from asynch DFF_PP
   with open(os.path.join(bench_dir, config["abc_v_inputName"]), 'w', encoding = 'utf-8') as f:
      f.write(remove_DFFport(yosys_v_output))
   

   # change dir to synthesis
   os.chdir(bench_dir)
   # run abc script with input file name, through exception if failed
   abc_log = subprocess.run([config["abc_bin"]], stdout=subprocess.PIPE, text=True, input=f'source -x {abc_script_dir}', check=True)
   yosys_log_dir = os.path.join(log_dir, "abc.log")
   with open(yosys_log_dir,'w', encoding = 'utf-8') as f:
      f.write(abc_log.stdout)
   # change dir back to workdirectory
   os.chdir(working_directory)

   with open(os.path.join(bench_dir, "abc_bench.bench"), 'r', encoding = 'utf-8') as f:
      abc_pre_replace = f.read()
   
   abc_post_replace = restore_name(abc_pre_replace)
   abc_post_replace = lut2gate(abc_post_replace)

   with open(os.path.join(bench_dir, "abc_bench.bench"), 'w', encoding = 'utf-8') as f:
      f.write(abc_post_replace)
