from utdate.src.conv.json2hdl import json2hdl
from utdate.src.technology_reader import Technology_file
from os import path

class ScanSynth(json2hdl, Technology_file):
    def __init__(self, json_file, technology_parameters, scan_dir, filename, PI_clock) -> None:
        json2hdl.__init__(self, json_file, technology_parameters)
        self.DIR = scan_dir
        self.filename = filename
        self.log = list()
        self.Success = True
        #ver_dir = self.DIR + filename + "_test_ready_synth_premap.v"
        ver_dir = path.join(self.DIR, filename + "_synth_premap.v")
        # print(ver_dir)
        # print(json_file)
        with open(ver_dir, "r") as f:
            self.ver_file = f.read()
        
        self.list_of_replacable_FFs = list()
        self.find_replacable_FFs()
        self.PI_clock = PI_clock
        self.scan_info = list()
        self.scan_info.append("Type = Report  " + "\n ---- MODULE : " + self.module_name + " ----\n --- Scan SYNTHESIS ---\n No. of Storage Eelements : " 
                    + str(len(self.list_of_replacable_FFs)) + "\n\n")

    def find_replacable_FFs(self):
        for cell in self.top_module["cells"].values():
            if cell["type"] in self.technology_parameter.list_of_dff:
                cell_name = self.find_key(cell, self.top_module["cells"])
                if len(cell["connections"]) <= 5:
                    self.list_of_replacable_FFs.append(cell_name)

    def find_key(self, val, dic):
        for key, value in dic.items():
            if val == value:
                return key

    def port_name(self, text, port):
     
        keyword = '.' + port + '('
        start_of_port_index = text.find(keyword) - 1
        start_of_replacement_index = start_of_port_index + text[start_of_port_index:].find('(')
        end_of_replacement_index = start_of_port_index + text[start_of_port_index:].find(')')
        return text[start_of_replacement_index + 1:end_of_replacement_index]
    
    def is_active_high(self, cell, set_rst):
        for c in self.technology_parameter.cells:
            if self.top_module["cells"][cell]["type"] == str(c.args[0]):
                FF = c.get_groups('ff')
                if (set_rst == "rst"):
                    if str(FF[0]["clear"]).find('!') > -1  or str(FF[0]["clear"]).find('\'') > -1 :
                        return False
                    else:
                        return True
                else:
                    
                    if str(FF[0]["preset"].find('!')) > -1 or str(FF[0]["preset"].find('\'')) > -1 :
                        return False
                    else:
                        return True
    
    def replace_text(self, module_desc, cell_type, cell_name, si_port, NbarT, Grst):
        index = self.technology_parameter.list_of_dff.index(cell_type)
        preset_port = self.technology_parameter.list_of_set[index]
        clear_port = self.technology_parameter.list_of_rst[index]


        clock_name = self.port_name(module_desc, self.technology_parameter.list_of_clk[index])
        Q_name = self.port_name(module_desc, self.technology_parameter.list_of_dff_Q[index])
        D_name = self.port_name(module_desc, self.technology_parameter.list_of_dff_D[index])
        preset_name = ''
        clear_name = ''
        if preset_port != "None":
            preset_name = self.port_name(module_desc, preset_port)

        if clear_port != "None":
            clear_name = self.port_name(module_desc, clear_port)
            
        
        # print(D_name, Q_name, clock_name, clear_name, preset_name)
    

        scan_text = ""
        scan_text = scan_text + "\tscandff " + cell_name + "("
        scan_text = scan_text + ".Q(" + Q_name + "), "
        scan_text = scan_text + ".D(" + D_name + "), "
        scan_text = scan_text + ".C(" + clock_name + "), "
        if clear_port != "None" and clear_port != "1\'h1" and clear_port != "1\'h0":
            if (self.is_active_high(cell_name,"rst")):
                scan_text = scan_text + ".CLR(" + clear_name + "), "
            else:
                scan_text = scan_text + ".CLR(( ~" + clear_name + ")), "
        else:
            scan_text = scan_text + ".CLR(1'h0), "

        if preset_port != "None" and preset_name != "1\'h1" and preset_name != "1\'h0":
            if (self.is_active_high(cell_name,"set")):
                scan_text = scan_text + ".PRE(" + preset_name + "), "
            else:
                scan_text = scan_text + ".PRE((~ " + preset_name + ")), "
        else:
            scan_text = scan_text + ".PRE(1'h0), "

        scan_text = scan_text + ".NbarT(" + NbarT + "), "

        scan_text = scan_text + ".Si(" + si_port + "), "

        scan_text = scan_text + ".global_reset(" + Grst + "));\n"

        return scan_text, Q_name
    
    def add_Si_So(self, Si, So):
        siso_list = Si + So
        text = ""
        index = self.ver_file.find(self.module_name) + len(self.module_name)
        for s in siso_list:
            text = text + s + ", "

        self.ver_file = self.ver_file[:index + 1] + text + self.ver_file[index + 1:]

        added_inout = ""

        for s in Si:
            added_inout = added_inout + "\tinput " + s + ";\n"
        for s in So:
            added_inout = added_inout + "\toutput " + s + ";\n"

        index = self.ver_file.find("wire")
        self.ver_file = self.ver_file[:index] + added_inout + self.ver_file[index:]

    def add_dummy_scan_cell(self, chain_size, So, current_So, NbarT, Grst):
        size = int(len(self.list_of_replacable_FFs)/len(chain_size))
        list_of_added_wires = list()
        wire_text = ""
        scan_text = ""

        #print(size)
        if max(chain_size) > size:
            size = max(chain_size)
        #print(size)


        for i in range(len(chain_size)):
            si_port = current_So[i]
            for j in range(size - chain_size[i]):
                list_of_added_wires.append("_DMY"+str(len(list_of_added_wires))+"_")
                scan_text = scan_text + "\tscandff _dummy" + str(len(list_of_added_wires)-1) + "_("
                scan_text = scan_text + ".Q(" + list_of_added_wires[-1] + "), "
                scan_text = scan_text + ".D(1'h0), "
                scan_text = scan_text + ".C(" + self.PI_clock + "), "
                scan_text = scan_text + ".CLR(1'h0), "
                scan_text = scan_text + ".PRE(1'h0), "
                scan_text = scan_text + ".NbarT(" + NbarT + "), "
                scan_text = scan_text + ".Si(" + si_port + "), "
                scan_text = scan_text + ".global_reset(" + Grst + "));\n\n"
                si_port = list_of_added_wires[-1]

            current_So[i] = si_port


        for i in range(len(list_of_added_wires)):
            wire_text = wire_text + "\twire " + list_of_added_wires[i] + ";\n"

        for i in range(len(So)):
            scan_text = scan_text + "\t assign " + So[i] + " = " + current_So[i] + ";\n";

        return scan_text, wire_text


    def full_scan(self, NBART, Grst, Si, So, chain_size = None):

        unique_so = list(dict.fromkeys(So))
        unique_si = list(dict.fromkeys(Si))

        #print(Si, unique_si)
       # print(So, unique_so)

        if(chain_size is None):
            self.add_Si_So(unique_si, unique_so)
            self.signle_full_replacement_stitching(NBART, Si[0], Grst, So[0])
        else:
            if sum(chain_size) == len(self.list_of_replacable_FFs):
                if len(unique_so) == len(chain_size):
                    self.add_Si_So(unique_si, unique_so)
                    self.multiple_full_replacement_stitching(NBART, Si, Grst, So, chain_size)
                else:
                    # print("\033[1;31m" + "ERROR: Cannot use one So port for more than one chain\n"
                    #                         "------ Scan insertion ended unsuccessfully\n" + "\033[0;0m")
                    self.log.append("Type = Error  " + "--- ERROR: Cannot use Same So port for more than one scan chain\n\n")
                    self.Success = False
                    return
            else:
                # print("\033[1;31m" + "ERROR: mismatch in number of FFs in chains "
                #                         "and number of replacable FFs\n"
                #                         "------ Scan insertion ended unsuccessfully\n" + "\033[0;0m")
                self.log.append("Type = Error  " + "--- ERROR:  Mismatch in no. of FFs in chains and no. of replacable FFs\n\n")
                self.Success = False
                return

        self.add_scan_module()

        ver_dir = path.join(self.DIR,  "scan_ready.v")

        f = open(ver_dir, "w")
        f.write(self.ver_file)
        f.close()
        return 


    def signle_full_replacement_stitching(self, NBART, Si, Grst, So):
        Si_port = Si
        for cell in self.top_module["cells"].values():
            if cell["type"] in self.technology_parameter.list_of_dff:
                cell_name = self.find_key(cell, self.top_module["cells"])
                start_index = self.ver_file.find(cell["type"] + " " + cell_name)
                end_index = start_index + self.ver_file[start_index:].find(';')
                module_desc = self.ver_file[start_index:end_index]
                
                if(cell_name in self.list_of_replacable_FFs):

                   # print("\033[1;32m" + "cell " + cell_name + " is replacable\n" + "\033[0;0m")

                    scan_desc, Si_port = self.replace_text(module_desc, cell["type"], cell_name, Si_port, NBART, Grst)

                    self.ver_file = self.ver_file[:start_index] + scan_desc + self.ver_file[end_index + 1:]
                else:
                    print("\033[1;33m"+"cannot replace cell" + cell_name + "with scan cell\n"+"\033[0;0m")
                    self.log.append("Type = Warning  " + "Cannot replace cell " + cell_name + "\n with scan cell\n")


        index = self.ver_file.find(self.module_name)

        index = index + self.ver_file[index:].find("endmodule")
        # print(index)
        added_assignments = "\t assign " + So + " = " + Si_port + ";\n"

        self.ver_file = self.ver_file[:index] + added_assignments + self.ver_file[index:]

        # print(self.ver_file)

    def multiple_full_replacement_stitching(self, NBART, Si, Grst, So, chain_size):
        i = 0
        chain_num = 0
        list_of_so_signals = list()
        Si_port = Si[chain_num]

        for cell in self.top_module["cells"].values():
            if cell["type"] in self.technology_parameter.list_of_dff:
                if i == chain_size[chain_num]:
                    chain_num += 1
                    list_of_so_signals.append(Si_port)
                    Si_port = Si[chain_num]
                    i=0
                cell_name = self.find_key(cell, self.top_module["cells"])
                start_index = self.ver_file.find(cell["type"] + " " + cell_name)
                end_index = start_index + self.ver_file[start_index:].find(';')
                module_desc = self.ver_file[start_index:end_index]


                if cell_name in self.list_of_replacable_FFs:

                    #print( chain_size[chain_num])

                    #print("\033[1;32m" + "cell " + cell_name + " is replacable" + "\033[0;0m")

                    scan_desc, Si_port = self.replace_text(module_desc, cell["type"], cell_name, Si_port, NBART, Grst)

                    self.ver_file = self.ver_file[:start_index] + scan_desc + self.ver_file[end_index + 1:]
                    i += 1

                else:
                    print("\033[1;33m"+"cannot replace cell" + cell_name + " with scan cell"+"\033[0;0m")
                    self.log.append("Type = Warning  " + "Cannot replace cell " + cell_name + "\n with scan cell\n")

        if i == chain_size[chain_num]:
            list_of_so_signals.append(Si_port)

        ## call a function to insert dummy scans and it's required dummies
        scan_text, wire_text = self.add_dummy_scan_cell(chain_size,So,list_of_so_signals,NBART, Grst)

        index = self.ver_file.find(self.module_name)

        wire_index = index + self.ver_file[index:].find("wire")

        self.ver_file = self.ver_file[:wire_index] + wire_text + self.ver_file[wire_index:]

        end_index = index + self.ver_file[index:].find("endmodule")

        self.ver_file = self.ver_file[:end_index] + scan_text + self.ver_file[end_index:]
        # print(index)

        #print(self.ver_file)
        ## the next line must turn into a loop
        #added_assignments = "\t assign " + So + "= " + Si_port + ";\n";

        #self.ver_file = self.ver_file[:index] + added_assignments + self.ver_file[index:]
    
    def add_scan_module(self):

        scandff = ""

        scandff = scandff + "\nmodule scandff (Q, D, C, CLR, PRE, NbarT, Si, global_reset);\n\n"

        scandff = scandff + "\tinput D, C, CLR, PRE, NbarT, Si, global_reset;\n\toutput reg Q;\n\n"

        scandff = scandff + "\twire rst = CLR || global_reset;\n\n"

        scandff = scandff + "\talways @ (posedge C, posedge PRE, posedge rst)begin\n"

        scandff = scandff + "\t\tif (rst)\n"

        scandff = scandff + "\t\t\tQ <= 1'b0;\n"

        scandff = scandff + "\t\telse if (PRE)\n"

        scandff = scandff + "\t\t\tQ <= 1'b1;\n"

        scandff = scandff + "\t\telse if (NbarT)\n"

        scandff = scandff + "\t\t\t Q <= Si;\n"

        scandff = scandff + "\t\telse\n"

        scandff = scandff + "\t\t\tQ <= D;\n\n"

        scandff = scandff + "\tend\n\n"

        scandff = scandff + "endmodule\n"

        self.ver_file = self.ver_file + scandff