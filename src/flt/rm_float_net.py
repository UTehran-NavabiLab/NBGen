import json


def unique_list(input_list):
  
    # initialize a null list
    unique_list = []
      
    # traverse for all elements
    for x in input_list:
        # check if exists in unique_list or not
        if x not in unique_list:
            unique_list.append(x)
    
    return unique_list

# extract_name ; take the name and prune extra control tokens
#     @input   ; name
def find_clk_rst_netNumber(cells):
    clk_num = list()
    rst_num = list()
    
    for cell in cells.values():
        if cell["type"].find("DFF") > -1:
            clk_num.append(cell["connections"]["C"][0])
            rst_num.append(cell["connections"]["R"][0])
    
    clk_num = unique_list(clk_num)
    rst_num = unique_list(rst_num)
    old_clk_num = clk_num.copy()
    
    do_while = True
    while ((len(old_clk_num) != len(clk_num)) or do_while):
        do_while = False
        old_clk_num = clk_num.copy()

        for cell in cells.values():
            for connection_name, connection_value in cell["connections"].items():
                if (connection_name.find("Y") > -1):
                    if (connection_value[0] in clk_num):
                        if (cell["type"] == "BUF"):
                            clk_num.append(cell["connections"]["A"][0])
                        else:
                            clk_num.append(cell["connections"]["A"][0])
                            clk_num.append(cell["connections"]["B"][0])
                if (connection_name.find("O") > -1):
                    if (connection_value[0] in clk_num):
                        clk_num.append(cell["connections"]["I"][0])
                
                # rest finder
                if (connection_name.find("Y") > -1):
                    if (connection_value[0] in rst_num):
                        if (cell["type"] == "BUF"):
                            rst_num.append(cell["connections"]["A"][0])
                        else:
                            rst_num.append(cell["connections"]["A"][0])
                            rst_num.append(cell["connections"]["B"][0])
                if (connection_name.find("O") > -1):
                    if (connection_value[0] in rst_num):
                        rst_num.append(cell["connections"]["I"][0])
        
        clk_num = unique_list(clk_num)
        rst_num = unique_list(rst_num)
    
    return clk_num, rst_num


def find_clk_rst_name(ports, clk_num, rst_num):
    clk = ""
    rst = ""
    for port_name, port_value in ports.items():
        if port_value["bits"][0] in clk_num:
            clk = port_name    
        if port_value["bits"][0] in rst_num:
            rst = port_name    

    return clk, rst

def rm_float_net(json_file, verilog_file, bench_output):
    with open(json_file, "r") as j:
        js = json.load(j)

        module_name = list(js["modules"])[0]
        top_module = js["modules"][module_name]
        cells = top_module["cells"]
        ports = top_module["ports"]
        clk_list, rst_list = find_clk_rst_netNumber(cells)
        clk, rst = find_clk_rst_name(ports, clk_list, rst_list)


    with open(verilog_file, "r") as v:
        vlog = v.read()
    
    page2line = vlog.splitlines()
    rst_nets = list()
    for indx, line in enumerate(page2line):
        if (line.strip().find(clk) > -1):
            page2line[indx] = "# clock has been removed"
        if (line.strip().find(rst) > -1):
            if (line.strip().find("=") > -1):
                rst_name_name = line[:line.strip().find("=")].strip()
                rst_nets.append(rst_name_name)
                page2line[indx] = "# net connected to rst has been removed"
            else:
                page2line[indx] = "# rst has been removed"
            # page2line[indx] = line.replace('DFFRSE', 'DFF')
    
    for indx, line in enumerate(page2line):
        for rst_net in rst_nets:
            if (line.strip().find(rst_net) > -1):
                page2line[indx] = "# net connected to rst has been removed"

    return "\n".join(page2line)
