from os import path, getcwd, chdir, listdir, mkdir
from subprocess import run, PIPE
from json import load, dump
from subprocess import CalledProcessError
from shutil import copyfile, SameFileError, copy
from utdate.src.utility_functions import *
from utdate.src.utility_functions import split_page
from utdate.src.conv.json2hdl import json2hdl
from utdate.src.conv.json2vhdl import json2vhdl
from utdate.src.conv.json2verilog import json2verilog
from utdate.src.conv.json2sc_testbench import json2sc_testbench
from utdate.src.conv.json2sc_testbench_pwr import json2sc_testbench_pwr
from utdate.src.conv.json2sc_testbench_atpg import json2sc_testbench_atpg
from utdate.src.conv.json2sc_testbench_flt_uvm import json2sc_testbench_flt_uvm
from utdate.src.conv.json2systemc import json2systemc
from utdate.src.conv.json2systemc_pwr import json2systemc_pwr
from utdate.src.conv.json2systemc_flt import json2systemc_flt
from utdate.src.flt.fault_collapsing import fault_collapsing
from utdate.src.technology_reader import Technology_file
from utdate.src.test.bist import bist_insertion
import utdate.lib as lib
import utdate.bin as bin

class utdate_beckend:
   def __init__(self) -> None:
      # create directory (synthesis, lib, log, bench)
      self.working_dir = getcwd()
      self.synthesis_dir = mkdir("synthesis", self.working_dir, False)
      self.log_dir = mkdir("log", self.working_dir)
      self.test_dir = mkdir("test", self.working_dir)
      self.fltSim_dir = mkdir("fault_simulation", self.test_dir)
      self.lib_dir = lib.__path__[0]
      self.bin_dir = bin.__path__[0]
      self.config_dir = ""

      # check wether the "tech" directory exist in working directory
      if (path.isdir(path.join(self.working_dir, "tech"))):
         self.config_dir = path.join(self.working_dir, "tech")
      else:
         self.config_dir = self.lib_dir

      self.config_json = dict()
      # read config file
      with open(path.join(self.config_dir, "config.json"), "r") as json_file:
         self.config_json = load(json_file)
      ## TODO: no need for tech file anymore
      #     remove this 
      #     change tech(dir) name to config
      with open(path.join(self.config_dir, "tech.json"), "r") as tech_json:
         tech = load(tech_json)

      # copy abc.rc to self.test_dir
      abc_rc_src = path.join(self.lib_dir, "abc.rc")
      abc_rc_dst = path.join(self.test_dir, "abc.rc")
      try:
         copyfile(abc_rc_src, abc_rc_dst)
      # If source and destination are same
      except SameFileError:
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

      # copy all files from lib/fault_simulation files to test_dir
      source_folder = path.join(self.lib_dir, "fault_simulation")
      destination_folder = self.fltSim_dir
      
      # fetch all files
      for file_name in listdir(source_folder):
         # construct full file path
         source = path.join(source_folder, file_name)
         destination = path.join(destination_folder, file_name)
         # copy only files
         if path.isfile(source):
            copy(source, destination)
         else:
            print("file/directory does not exist: ", source)
      

      self.technology_parameter = Technology_file(path.join(self.lib_dir, self.config_json["liberty_file"]))

      # a map to output directories
      # working_directory | synthesis_dir | lib_dir | log_dir | test_dir | fltSim_dir| config_dir
      # ------------------|---------------|---------|---------|----------|-----------|------------
      #        0          |       1       |    2    |    3    |     4    |    5      |      6
      # return {"directories": [working_directory, synthesis_dir, lib_dir, log_dir, test_dir, fltSim_dir, config_dir], 
      #          "config": config, "tech": tech}

   # @def: synthesize using yosys
   #  @args: 
   #     config: dictionary of configuration obtained from json
   #     vhdl: determine the design to be vhdl
   #     use_existing_script: if set to false bypasses script making process
   #        user must provide valid yosys script at valid location (under lib_dir)
   def netlist(self, input_file_name, module_name, vhdl=False, use_existing_script=False):
      yosys_script_dir = path.join(self.config_dir, "yosys_script.ys")

      if not (use_existing_script):
         with open(yosys_script_dir,'w',encoding = 'utf-8') as f:
            f.write(self.yosys_script_mk(input_file=input_file_name, module_name=module_name, vhdl=vhdl))
      
      ###################### yosys ######################
      # get parent directory

      try:
         # run yosys script with input file name, throw exception if failed
         yosys_log = run([path.join(self.bin_dir, "yosys"), yosys_script_dir], stdout=PIPE, text=True, check=True)
         # an alternative would be to use input arg
         # yosys_log = run([config["yosys_bin"], yosys_script_dir], stdout=PIPE, text=True, input=f'script {yosys_script_dir}', check=True)
      except CalledProcessError:
         yosys_log = "CalledProcessError: \n" 
         yosys_log += "    yosys returned non-zero exit status 1"
         yosys_log_dir = path.join(self.log_dir, "yosys.log")
         with open(yosys_log_dir,'w', encoding = 'utf-8') as f:
            f.write(yosys_log)
      
      else:
         ###################### convert to vhdl, verilog, systemC ######################
         if (self.config_json["yosys_script_postmap_json_outputName"] != ""):
            json_input = path.join(self.synthesis_dir, self.config_json["yosys_script_postmap_json_outputName"])
         else:
            json_input = path.join(self.synthesis_dir, self.config_json["yosys_script_premap_json_outputName"])

         self.hdl_base = json2hdl(json_input, self.config_json, self.technology_parameter)


         yosys_log_dir = path.join(self.log_dir, "yosys.log")
         with open(yosys_log_dir,'w', encoding = 'utf-8') as f:
            f.write(yosys_log.stdout)

         # gate_signal_file = path.join(self.synthesis_dir, self.config_json["gate_signal_json_file"])
         
         # j2vhd = json2vhdl(json_input, self.config_json, self.technology_parameter)
         # with open(path.join(self.synthesis_dir, self.config_json["vhdl_netlist_fileName"]), "w") as f:
         #    f.write(j2vhd.generate_vhdl())
         
         # j2v = json2verilog(json_input, self.config_json, self.technology_parameter)
         # with open(path.join(self.synthesis_dir, self.config_json["verilog_netlist_fileName"]), "w") as f:
         #    f.write(j2v.generate_verilog())
         
         # j2sc = json2systemc(json_input, self.config_json, self.technology_parameter, gate_signal_file)
         # with open(path.join(self.synthesis_dir, self.config_json["systemC_netlist_fileName"]), "w") as f:
         #    f.write(j2sc.generate_systemc())
         # j2sc_pwr = json2systemc_pwr(json_input, self.config_json, self.technology_parameter, gate_signal_file)
         # with open(path.join(self.synthesis_dir, "power_netlist.h"), "w") as f:
         #    f.write(j2sc_pwr.generate_systemc())
         # j2sc_tb_pwr = json2sc_testbench_pwr(json_input, self.config_json, self.technology_parameter, "testbench", "cut")
         # with open(path.join(self.synthesis_dir, "power_testbench.h"), "w") as f:
         #    f.write(j2sc_tb_pwr.generate_systemc())
         
         # j2sc_tb_atpg = json2sc_testbench_atpg(json_input, self.config_json, self.technology_parameter, "testbench", "cut")
         # with open(path.join(self.synthesis_dir, "atpg_testbench.h"), "w") as f:
         #    f.write(j2sc_tb_atpg.generate_systemc())
         
         # j2sc_tb_flt_uvm = json2sc_testbench_flt_uvm(json_input, self.config_json, self.technology_parameter, "testbench", "dut")
         # with open(path.join(self.synthesis_dir, "testbench_flt.h"), "w") as f:
         #    f.write(j2sc_tb_flt_uvm.generate_systemc())
   
   # @def: convert synthesized output to vhdl format
   def to_vhdl(self):
      if (self.config_json["yosys_script_postmap_json_outputName"] != ""):
         json_input = path.join(self.synthesis_dir, self.config_json["yosys_script_postmap_json_outputName"])
      else:
         json_input = path.join(self.synthesis_dir, self.config_json["yosys_script_premap_json_outputName"])

      j2vhd = json2vhdl(json_input, self.config_json, self.technology_parameter)
      with open(path.join(self.synthesis_dir, self.config_json["vhdl_netlist_fileName"]), "w") as f:
         f.write(j2vhd.generate_vhdl())
      
   # @def: convert synthesized output to verilog format
   def to_verilog(self):
      if (self.config_json["yosys_script_postmap_json_outputName"] != ""):
         json_input = path.join(self.synthesis_dir, self.config_json["yosys_script_postmap_json_outputName"])
      else:
         json_input = path.join(self.synthesis_dir, self.config_json["yosys_script_premap_json_outputName"])

      j2v = json2verilog(json_input, self.config_json, self.technology_parameter)
      with open(path.join(self.synthesis_dir, self.config_json["verilog_netlist_fileName"]), "w") as f:
         f.write(j2v.generate_verilog())

      self.insert_bist("RTS")
         
   # @def: convert synthesized output to systemc format
   def to_systemc(self):
      if (self.config_json["yosys_script_postmap_json_outputName"] != ""):
         json_input = path.join(self.synthesis_dir, self.config_json["yosys_script_postmap_json_outputName"])
      else:
         json_input = path.join(self.synthesis_dir, self.config_json["yosys_script_premap_json_outputName"])

      gate_signal_file = path.join(self.synthesis_dir, self.config_json["gate_signal_json_file"])

      j2sc = json2systemc(json_input, self.config_json, self.technology_parameter, gate_signal_file)
      with open(path.join(self.synthesis_dir, self.config_json["systemC_netlist_fileName"]), "w") as f:
         f.write(j2sc.generate_systemc())
      j2sc_pwr = json2systemc_pwr(json_input, self.config_json, self.technology_parameter, gate_signal_file)
      with open(path.join(self.synthesis_dir, "power_netlist.h"), "w") as f:
         f.write(j2sc_pwr.generate_systemc())
      j2sc_tb_pwr = json2sc_testbench_pwr(json_input, self.config_json, self.technology_parameter, "testbench", "cut")
      with open(path.join(self.synthesis_dir, "power_testbench.h"), "w") as f:
         f.write(j2sc_tb_pwr.generate_systemc())
      j2sc_tb_atpg = json2sc_testbench_atpg(json_input, self.config_json, self.technology_parameter, "testbench", "cut")
      with open(path.join(self.synthesis_dir, "atpg_testbench.h"), "w") as f:
         f.write(j2sc_tb_atpg.generate_systemc()) 
      j2sc_tb_flt_uvm = json2sc_testbench_flt_uvm(json_input, self.config_json, self.technology_parameter, "testbench", "dut")
      with open(path.join(self.synthesis_dir, "testbench_flt.h"), "w") as f:
         f.write(j2sc_tb_flt_uvm.generate_systemc())

   def insert_bist(self, bist_type : str):
      bist = bist_insertion(bist_config)
      
      Primary_input_size, Primary_output_size = self.hdl_base.size_Of_Ports()
      bist_config = dict()
      bist_config.update({"type": bist_type})
      bist_config.update({"shiftSize": Primary_input_size})
      
      if (bist_type == "RTS"):
         bist.rts()
         
   def abc_script_mk(self):
      abc_script = f'read {path.join(self.config_dir, self.config_json["mycells_abc_lib_fileName"])} \n'
      abc_script += f'read -m {path.join(self.test_dir, self.config_json["abc_v_inputName"])} \n'
      abc_script += f'write_bench {path.join(self.test_dir, self.config_json["abc_bench_output"])} \n'

      return abc_script
      
   # def func with input file name as argument
   def yosys_script_mk(self, input_file, module_name, vhdl=False):
      # read yosys script template
      with open(path.join(self.lib_dir, self.config_json['yosys_script_fileName']), "r") as yosys_template_script:
         yosys_script = yosys_template_script.read()

      list_of_files = ""
      for file_name in input_file:
         list_of_files += f'{path.join(self.working_dir, file_name)} '
      
      if (vhdl):
         yosys_script = f'ghdl {list_of_files} -e {module_name} \n' + yosys_script
      else:
         # create yosys_script from template
         yosys_script = f'read_verilog {list_of_files} \n' + yosys_script


      yosys_script_1st, yosys_script_2nd = split_page(yosys_script, ["# placeholder for dfflibmap"])
      # split_page won't start from new line so we add it add new line 
      yosys_script_1st += '\n'
      yosys_script_1st += f'dfflibmap -liberty {path.join(self.config_dir, self.config_json["mycells_yosys_lib_fileName"])} \n'
      yosys_script = yosys_script_1st + yosys_script_2nd

      yosys_script_1st, yosys_script_2nd = split_page(yosys_script, ["# placeholder for abc"])
      # split_page won't start from new line so we add it add new line 
      yosys_script_1st += '\n'
      yosys_script_1st += f'abc -liberty {path.join(self.config_dir, self.config_json["mycells_yosys_lib_fileName"])} \n'
      yosys_script = yosys_script_1st + yosys_script_2nd
      
      if ((self.technology_parameter.high_cell != []) and (self.technology_parameter.low_cell != [])):
         yosys_script_1st, yosys_script_2nd = split_page(yosys_script, ["# placeholder for constant mapping"])
         # split_page won't start from new line so we add it add new line 
         yosys_script_1st += '\n'
         yosys_script_1st += f'hilomap -hicell {self.technology_parameter.high_cell[0][0]} {self.technology_parameter.high_cell[0][1]} \n'
         yosys_script_1st += f'hilomap -locell {self.technology_parameter.low_cell[0][0]} {self.technology_parameter.low_cell[0][1]} \n'
         yosys_script = yosys_script_1st + yosys_script_2nd
      
      yosys_script_1st, yosys_script_2nd = split_page(yosys_script, ["# placeholder for i/o pads mapping"])
      # split_page won't start from new line so we add it add new line 
      yosys_script_1st += '\n'
      # some library might have different types of BUF for input/output, check for correnspoding variables
      yosys_script_1st += f'iopadmap -inpad {self.technology_parameter.list_of_buf[0][0]} {self.technology_parameter.list_of_buf[0][1]}:{self.technology_parameter.list_of_buf[0][2]} -bits \n'
      yosys_script_1st += f'iopadmap -outpad {self.technology_parameter.list_of_buf[0][0]} {self.technology_parameter.list_of_buf[0][2]}:{self.technology_parameter.list_of_buf[0][1]} -bits \n'
      # yosys_script_1st += f'iopadmap -inpad {tech["bufcell"] if (tech["inbufcell"] == "") else tech["inbufcell"]} {tech["bufpin_out"] if (tech["inbufpin_out"] == "") else tech["inbufpin_out"]}:{tech["bufpin_in"] if (tech["inbufpin_in"] == "") else tech["inbufpin_in"]} -bits \n'
      # yosys_script_1st += f'iopadmap -outpad {tech["bufcell"] if (tech["outbufcell"] == "") else tech["outbufcell"]} {tech["bufpin_in"] if (tech["outbufpin_in"] == "") else tech["outbufpin_in"]}:{tech["bufpin_out"] if (tech["outbufpin_out"] == "") else tech["outbufpin_out"]} -bits \n'
      yosys_script = yosys_script_1st + yosys_script_2nd

      yosys_script_1st, yosys_script_2nd = split_page(yosys_script, ["# placeholder for abc after splitnets"])
      # split_page won't start from new line so we add it add new line 
      yosys_script_1st += '\n'
      yosys_script_1st += f'abc -liberty {path.join(self.config_dir, self.config_json["mycells_yosys_lib_fileName"])} \n'
      yosys_script = yosys_script_1st + yosys_script_2nd

      yosys_script_1st, yosys_script_2nd = split_page(yosys_script, ["# placeholder for premap_synthesis file"])
      # split_page won't start from new line so we add it add new line 
      yosys_script_1st += '\n'
      yosys_script_1st += f'write_verilog -noattr {path.join(self.synthesis_dir, self.config_json["yosys_script_premap_v_outputName"])} \n'
      yosys_script_1st += f'write_blif {path.join(self.synthesis_dir, self.config_json["yosys_script_premap_blif_outputName"])} \n'
      yosys_script_1st += f'write_json {path.join(self.synthesis_dir, self.config_json["yosys_script_premap_json_outputName"])} \n'
      yosys_script = yosys_script_1st + yosys_script_2nd

      if ((self.config_json["Logic_map_fileName"] != "") or (self.config_json["DFF_map_fileName"] != "")):
         yosys_script_1st, yosys_script_2nd = split_page(yosys_script, ["# placeholder techmap"])
         # split_page won't start from new line so we add it add new line 
         yosys_script_1st += '\n'
         if (self.config_json["DFF_map_fileName"] != ""):
            yosys_script_1st += f'techmap -map {path.join(self.config_dir, self.config_json["DFF_map_fileName"])} \n'
            yosys_script_1st += f'abc -liberty {path.join(self.config_dir, self.config_json["mycells_yosys_lib_fileName"])} \n'
            yosys_script_1st += "opt; clean -purge\n"
         
         if (self.config_json["Logic_map_fileName"] != ""):
            yosys_script_1st += f'techmap -map {path.join(self.config_dir, self.config_json["Logic_map_fileName"])} \n'
         yosys_script = yosys_script_1st + yosys_script_2nd

         yosys_script_1st, yosys_script_2nd = split_page(yosys_script, ["# placeholder for postmap_synthesis file"])
         # split_page won't start from new line so we add it add new line 
         yosys_script_1st += '\n'
         yosys_script_1st += f'write_verilog -noattr {path.join(self.synthesis_dir, self.config_json["yosys_script_postmap_v_outputName"])} \n'
         # write json output for future use
         yosys_script_1st += f'write_json {path.join(self.synthesis_dir, self.config_json["yosys_script_postmap_json_outputName"])} \n'
         yosys_script = yosys_script_1st + yosys_script_2nd

      return yosys_script


   # @def: generate bench file using abc
   #  @args: 
   #     config: dictionary of configuration obtained from json
   #     reference to directories
   def bench(self):
      # writing abc script
      abc_script_dir = path.join(self.config_dir, "abc_script.scr")

      with open(abc_script_dir,'w',encoding = 'utf-8') as f:
         f.write(self.abc_script_mk())
      
      with open(path.join(self.synthesis_dir, self.config_json["yosys_script_premap_v_outputName"]), 'r', encoding = 'utf-8') as f:
         yosys_v_output = f.read()
         
      # remove .C port from asynch DFF_PP
      with open(path.join(self.test_dir, self.config_json["abc_v_inputName"]), 'w', encoding = 'utf-8') as f:
         f.write(remove_DFFport(yosys_v_output, self.technology_parameter))
      

      # change dir to synthesis
      chdir(self.test_dir)
      ###################### yosys ######################
      # run abc script with input file name, through exception if failed
      abc_log = run([path.join(self.bin_dir, "yosys-abc")], stdout=PIPE, text=True, input=f'source -x {abc_script_dir}', check=True)
      yosys_log_dir = path.join(self.log_dir, "abc.log")
      with open(yosys_log_dir,'w', encoding = 'utf-8') as f:
         f.write(abc_log.stdout)
      # change dir back to workdirectory
      chdir(self.working_dir)

      with open(path.join(self.test_dir, self.config_json["abc_bench_output"]), 'r', encoding = 'utf-8') as f:
         abc_pre_replace = f.read()
      
      abc_post_replace = restore_name(abc_pre_replace)
      abc_post_replace = lut2gate(abc_post_replace)

      with open(path.join(self.test_dir, self.config_json["abc_bench_output"]), 'w', encoding = 'utf-8') as f:
         f.write(abc_post_replace)


   # @def: generate fault list and corresponding test vector
   #  @args: 
   #     testbench_name: name of simulated testbench, used to address hierarchy 
   #     instance_name: name of design under test, used to address hierarchy 
   #     config: dictionary of configuration obtained from json
   #     use_existing_script: if set to false bypasses script making process
   #     reference to directories
   def fault_simulation(self, testbench, instance):
      if (self.config_json["yosys_script_postmap_json_outputName"] != ""):
         json_input = path.join(self.synthesis_dir, self.config_json["yosys_script_postmap_json_outputName"])
      else:
         json_input = path.join(self.synthesis_dir, self.config_json["yosys_script_premap_json_outputName"])
      
      # change dir to fault simulation directory
      chdir(self.fltSim_dir)

      # copy fault_list and test_list file into fault_simulation directory

      fault_list_source = path.join(self.test_dir, "fault_list.flt")
      fault_list_destination = path.join(self.fltSim_dir, "fault_list.flt")

      if path.isfile(fault_list_source):
         copy(fault_list_source, fault_list_destination)
      else:
         print("file/directory does not exist: ", fault_list_source)


      # remove extra information from atalanta output file and retain lists of vectors
      test_list_file = ""
      test_for_comb = ""
      test_for_seq = ""
      with open(path.join(self.test_dir, "test_list.txt"), "r") as f:
         test_list_file = f.read()
         # find the specifier
         page_one, page_two = split_page(test_list_file, "* Test patterns and fault free responses:")
         # turn string into list of lines
         page2line = page_two.splitlines()
         for line in page2line:
            if(line):
                  # split line into list considering "white space"
                  split_space = line.split(' ')
                  # for combinational test list just retain input test patterns
                  test_for_comb += split_space[-2] + "\n"
                  # for sequential test list concatenate input test patterns and expected outputs (fault free responses)
                  test_for_seq += split_space[-2] + split_space[-1] + "\n"
         
         # remove last line break "\n"
         test_for_comb = test_for_comb[:-1]
         test_for_seq = test_for_seq[:-1]


      with open(path.join(self.fltSim_dir, "test_list_comb.txt"), "w") as f:
         f.write(test_for_comb)
      with open(path.join(self.fltSim_dir, "test_list_seq.txt"), "w") as f:
         f.write(test_for_seq)

      j2sc_testbench = json2sc_testbench(json_input, self.config_json, self.technology_parameter, testbench, instance)
      with open(path.join(self.fltSim_dir, self.config_json["systemC_testbench_fileName"]), "w") as f:
         f.write(j2sc_testbench.generate_systemc())

      j2sc_faultable_netlist = json2systemc_flt(json_input, self.config_json, self.technology_parameter)
      with open(path.join(self.fltSim_dir, self.config_json["systemC_faultable_netlist_fileName"]), "w") as f:
         f.write(j2sc_faultable_netlist.generate_systemc())
      # call make file and save stdout
      # ** use stdout to debug later
      fault_log = run(["make"], stdout=PIPE, text=True, check=True)


   # @def: generate fault list and corresponding test vector
   #  @args: 
   #     testbench_name: name of simulated testbench, used to address hierarchy 
   #     instance_name: name of design under test, used to address hierarchy 
   #     config: dictionary of configuration obtained from json
   #     use_existing_script: if set to false bypasses script making process
   #     reference to directories
   def faultCollapsing(self, testbench_name,  instance_name):
      if (self.config_json["yosys_script_postmap_json_outputName"] != ""):
         json_input = path.join(self.synthesis_dir, self.config_json["yosys_script_postmap_json_outputName"])
      else:
         json_input = path.join(self.synthesis_dir, self.config_json["yosys_script_premap_json_outputName"])
         
      ###################### fault collapsing ######################
      fault_list = fault_collapsing(json_input, self.config_json, self.technology_parameter, testbench_name,  instance_name)
      with open(path.join(self.test_dir, self.config_json["fault_list_fileName"]), 'w', encoding = 'utf-8') as f:
         f.write(fault_list.generate_fault_list())



   # @def: generate fault list and corresponding test vector
   #  @args: 
   #     testbench_name: name of simulated testbench, used to address hierarchy 
   #     instance_name: name of design under test, used to address hierarchy 
   #     config: dictionary of configuration obtained from json
   #     use_existing_script: if set to false bypasses script making process
   #     reference to directories
   def test_set_gen(self):
      json_premap_input = path.join(self.synthesis_dir, self.config_json["yosys_script_premap_json_outputName"])
      bench_input = path.join(self.test_dir, self.config_json["abc_bench_output"])

      ###################### atalanta ######################
      with open(path.join(self.test_dir, self.config_json["abc_bench_rm_floated_net_output"]), 'w', encoding = 'utf-8') as b:
         b.write(rm_float_net(json_premap_input, bench_input, self.technology_parameter))
      
      # change dir to test_dirctory
      chdir(self.test_dir)

      atalanta_script = f'{self.config_json["abc_bench_rm_floated_net_output"]}'

      # run atalanta script with input file name, through exception if failed
      atalanta_log = run([self.config_json["atalanta_bin"], "-t", "test_list.txt", atalanta_script], stdout=PIPE, text=True, check=True)
      atalanta_log_dir = path.join(self.log_dir, "atalanta.log")
      with open(atalanta_log_dir,'w', encoding = 'utf-8') as f:
         f.write(atalanta_log.stdout)

      # change back to working dir
      chdir(self.working_dir)



# # @def: generate fault list and corresponding test vector
# #  @args: 
# #     testbench_name: name of simulated testbench, used to address hierarchy 
# #     instance_name: name of design under test, used to address hierarchy 
# #     config: dictionary of configuration obtained from json
# #     use_existing_script: if set to false bypasses script making process
# #     reference to directories
# def fault(testbench_name,  instance_name, config, tech, working_directory, synthesis_dir, lib_dir, log_dir, test_dir):
#    if (config["yosys_script_postmap_json_outputName"] != ""):
#       json_input = path.join(synthesis_dir, config["yosys_script_postmap_json_outputName"])
#    else:
#       json_input = path.join(synthesis_dir, config["yosys_script_premap_json_outputName"])
      
#    json_premap_input = path.join(synthesis_dir, config["yosys_script_premap_json_outputName"])
#    bench_input = path.join(test_dir, config["abc_bench_output"])

#    ###################### fault collapsing ######################
#    fault_list = fault_collapsing(json_input, testbench_name,  instance_name)
#    with open(path.join(test_dir, config["fault_list_fileName"]), 'w', encoding = 'utf-8') as f:
#       f.write(fault_list.generate_fault_list())

#    ###################### atalanta ######################
#    with open(path.join(test_dir, config["abc_bench_rm_floated_net_output"]), 'w', encoding = 'utf-8') as b:
#       b.write(rm_float_net(json_premap_input, bench_input, tech))
   
#    # change dir to test_dirctory
#    chdir(test_dir)

#    atalanta_script = f'{config["abc_bench_rm_floated_net_output"]}'

#    # run atalanta script with input file name, through exception if failed
#    atalanta_log = run([config["atalanta_bin"], "-t", "test_list.txt", atalanta_script], stdout=PIPE, text=True, check=True)
#    atalanta_log_dir = path.join(log_dir, "atalanta.log")
#    with open(atalanta_log_dir,'w', encoding = 'utf-8') as f:
#       f.write(atalanta_log.stdout)

#    # change back to working dir
#    chdir(working_directory)
   