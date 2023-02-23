import os
from utdate.src.utility_functions import split_page


def abc_script_mk(config, config_dir, test_dir):
    abc_script = f'read {os.path.join(config_dir, config["mycells_abc_lib_fileName"])} \n'
    abc_script += f'read -m {os.path.join(test_dir, config["abc_v_inputName"])} \n'
    abc_script += f'write_bench {os.path.join(test_dir, config["abc_bench_output"])} \n'

    return abc_script
    
# def func with input file name as argument
def yosys_script_mk(input_file, module_name, config, tech, working_directory, lib_dir, synthesis_dir, config_dir, vhdl=False):
    # read yosys script template
    with open(os.path.join(lib_dir, config['yosys_script_fileName']), "r") as yosys_template_script:
        yosys_script = yosys_template_script.read()

    list_of_files = ""
    for file_name in input_file:
        list_of_files += f'{os.path.join(working_directory, file_name)} '
    
    if (vhdl):
        yosys_script = f'ghdl {list_of_files} -e {module_name} \n' + yosys_script
    else:
        # create yosys_script from template
        yosys_script = f'read_verilog {list_of_files} \n' + yosys_script


    yosys_script_1st, yosys_script_2nd = split_page(yosys_script, ["# placeholder for dfflibmap"])
    # split_page won't start from new line so we add it add new line 
    yosys_script_1st += '\n'
    yosys_script_1st += f'dfflibmap -liberty {os.path.join(config_dir, config["mycells_yosys_lib_fileName"])} \n'
    yosys_script = yosys_script_1st + yosys_script_2nd

    yosys_script_1st, yosys_script_2nd = split_page(yosys_script, ["# placeholder for abc"])
    # split_page won't start from new line so we add it add new line 
    yosys_script_1st += '\n'
    yosys_script_1st += f'abc -liberty {os.path.join(config_dir, config["mycells_yosys_lib_fileName"])} \n'
    yosys_script = yosys_script_1st + yosys_script_2nd
    
    
    yosys_script_1st, yosys_script_2nd = split_page(yosys_script, ["# placeholder for constant mapping"])
    # split_page won't start from new line so we add it add new line 
    yosys_script_1st += '\n'
    yosys_script_1st += f'hilomap -hicell {tech["tiehi"]} {tech["tiehipin_out"]} \n'
    yosys_script_1st += f'hilomap -locell {tech["tielo"]} {tech["tielopin_out"]} \n'
    yosys_script = yosys_script_1st + yosys_script_2nd
    
    yosys_script_1st, yosys_script_2nd = split_page(yosys_script, ["# placeholder for i/o pads mapping"])
    # split_page won't start from new line so we add it add new line 
    yosys_script_1st += '\n'
    # some library might have different types of BUF for input/output, check for correnspoding variables
    yosys_script_1st += f'iopadmap -inpad {tech["bufcell"] if (tech["inbufcell"] == "") else tech["inbufcell"]} {tech["bufpin_out"] if (tech["inbufpin_out"] == "") else tech["inbufpin_out"]}:{tech["bufpin_in"] if (tech["inbufpin_in"] == "") else tech["inbufpin_in"]} -bits \n'
    yosys_script_1st += f'iopadmap -outpad {tech["bufcell"] if (tech["outbufcell"] == "") else tech["outbufcell"]} {tech["bufpin_in"] if (tech["outbufpin_in"] == "") else tech["outbufpin_in"]}:{tech["bufpin_out"] if (tech["outbufpin_out"] == "") else tech["outbufpin_out"]} -bits \n'
    yosys_script = yosys_script_1st + yosys_script_2nd

    yosys_script_1st, yosys_script_2nd = split_page(yosys_script, ["# placeholder for abc after splitnets"])
    # split_page won't start from new line so we add it add new line 
    yosys_script_1st += '\n'
    yosys_script_1st += f'abc -liberty {os.path.join(config_dir, config["mycells_yosys_lib_fileName"])} \n'
    yosys_script = yosys_script_1st + yosys_script_2nd

    yosys_script_1st, yosys_script_2nd = split_page(yosys_script, ["# placeholder for premap_synthesis file"])
    # split_page won't start from new line so we add it add new line 
    yosys_script_1st += '\n'
    yosys_script_1st += f'write_verilog -noattr {os.path.join(synthesis_dir, config["yosys_script_premap_v_outputName"])} \n'
    yosys_script_1st += f'write_blif {os.path.join(synthesis_dir, config["yosys_script_premap_blif_outputName"])} \n'
    yosys_script_1st += f'write_json {os.path.join(synthesis_dir, config["yosys_script_premap_json_outputName"])} \n'
    yosys_script = yosys_script_1st + yosys_script_2nd

    if ((config["Logic_map_fileName"] != "") or (config["DFF_map_fileName"] != "")):
        yosys_script_1st, yosys_script_2nd = split_page(yosys_script, ["# placeholder techmap"])
        # split_page won't start from new line so we add it add new line 
        yosys_script_1st += '\n'
        if (config["DFF_map_fileName"] != ""):
            yosys_script_1st += f'techmap -map {os.path.join(config_dir, config["DFF_map_fileName"])} \n'
            yosys_script_1st += f'abc -liberty {os.path.join(config_dir, config["mycells_yosys_lib_fileName"])} \n'
            yosys_script_1st += "opt; clean -purge\n"
        
        if (config["Logic_map_fileName"] != ""):
            yosys_script_1st += f'techmap -map {os.path.join(config_dir, config["Logic_map_fileName"])} \n'
        yosys_script = yosys_script_1st + yosys_script_2nd

        yosys_script_1st, yosys_script_2nd = split_page(yosys_script, ["# placeholder for postmap_synthesis file"])
        # split_page won't start from new line so we add it add new line 
        yosys_script_1st += '\n'
        yosys_script_1st += f'write_verilog -noattr {os.path.join(synthesis_dir, config["yosys_script_postmap_v_outputName"])} \n'
        # write json output for future use
        yosys_script_1st += f'write_json {os.path.join(synthesis_dir, config["yosys_script_postmap_json_outputName"])} \n'
        yosys_script = yosys_script_1st + yosys_script_2nd

    return yosys_script

