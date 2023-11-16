from utdate.src.conv.json2hdl import json2hdl
from utdate.src.technology_reader import Technology_file
from os import path

class DRC(json2hdl):

    def __init__(self, json_file, technology_parameters, scan_dir, filename) -> None:
        json2hdl.__init__(self, json_file, technology_parameters)
        self.DIR = scan_dir
        self.filename = filename
        self.log = list()
        self.PI_clock = ""
        self.Success = True
        # self.yosys_dir = yosys_dir
        #  ver_dir = self.DIR + filename + "_synth_premap.v"
        ver_dir = path.join(self.DIR, filename + "_synth_premap.v")
        with open(ver_dir, "r") as f:
            self.ver_file = f.read()

    # Description : checks if a net is connected directly to primary input
    def check_if_connected_to_PI(self, net):
        for port in self.ports_list:
            if (len(self.top_module["ports"][port]["bits"]) == 1 and
                    net == self.top_module["ports"][port]["bits"][0] and
                    (self.top_module["ports"][port]["direction"] == "input")):
                return True
        return False

    ##########################################################################
    # Description : checks if a net is connected to the output of an inverter
    def check_if_connected_INV(self, net):
        # print(self.top_module["cells"])

        for cell in self.top_module["cells"].values():
            if ((cell["type"] in self.technology_parameter.list_of_inv)):
                index = self.technology_parameter.list_of_inv.index(cell["type"])
                input_port = str(self.technology_parameter.list_of_inv_input[index])
                output_port = str(self.technology_parameter.list_of_inv_output[index])
                # print(input_port, output_port)
                if (cell["connections"][output_port][0] == net):
                    return cell["connections"][input_port][0]
        return None

    # Description : checks if a net is connected to the output of an buffer
    def check_if_connected_BUF(self, net):
        # print(self.top_module["cells"])
        for cell in self.top_module["cells"].values():
            if ((cell["type"] in self.technology_parameter.list_of_buf)):
                index = self.technology_parameter.list_of_buf.index(cell["type"])
                input_port = str(self.technology_parameter.list_of_buf_input[index])
                output_port = str(self.technology_parameter.list_of_buf_output[index])
                # print(input_port, output_port)
                if (cell["connections"][output_port][0] == net):
                    return cell["connections"][input_port][0]
        return None


    def check_for_series_of_BUF(self, net):
        port = net
        while port is not None:
            result = port
            port = self.check_if_connected_BUF(port)
        return result
    

    ##########################################################################
    def find_key(self, val, dic):
        for key, value in dic.items():
            if val == value:
                return key

     ##########################################################################
    # Description : Searchs through all storage elements in design and
    # return : A list of clks that are connected directly to primary input
    # and a list of ffs violating clock rule
    def find_clk_violative_dffs(self):
        list_of_input_clk = list()
        list_of_violative_dff = list()


        ### check if connected to PI
        #### check for series of BUF
        ### find key
        for cell in self.top_module["cells"].values():
            if cell["type"] in self.technology_parameter.list_of_dff:
                index = self.technology_parameter.list_of_dff.index(cell["type"])
                if self.check_if_connected_to_PI(cell["connections"][self.technology_parameter.list_of_clk[index]][0]):
                    if cell["connections"][self.technology_parameter.list_of_clk[index]][0] not in list_of_input_clk:
                        list_of_input_clk.append(cell["connections"][self.technology_parameter.list_of_clk[index]][0])
                else:
                    clk_port = self.check_for_series_of_BUF(cell["connections"][self.technology_parameter.list_of_clk[index]][0])
                    if self.check_if_connected_to_PI(clk_port):
                        if clk_port not in list_of_input_clk:
                            list_of_input_clk.append(clk_port)
                    else:
                        key_cell = self.find_key(cell, self.top_module["cells"])
                        if key_cell not in list_of_violative_dff:
                            list_of_violative_dff.append(key_cell)

        return list_of_input_clk, list_of_violative_dff

    ##########################################################################
    def resolve_clock_violation(self, list_of_violative_dff, NBART):
        # print(list_of_violative_dff)
        # print(self.list_of_input_clk)

        if (len(self.list_of_input_clk) == 0):
           # print("\033[1;33m" + "Cannot check design for derived clock\nCannot check design for gated clock\n")
            self.log.append("Type = Error  " + "--- ERROR: No clock found to resolve\n")
            self.Success = False
            return
        for port in self.ports_list:
            if (len(self.top_module["ports"][port]["bits"]) == 1 and
                    self.list_of_input_clk[0] == self.top_module["ports"][port]["bits"][0] and
                    (self.top_module["ports"][port]["direction"] == "input")):
                PI_clock = port
                self.PI_clock = PI_clock

        #print(PI_clock)

        list_of_added_MUXs = list()
        list_of_added_Wires = list()

        for violative_dff in list_of_violative_dff:
           # print("\033[1;33m" + "FF cell " + violative_dff + " has a derived/gated clock signal that is"
            #                                                     " not controllable from primary inputs\n"+"\033[0;0m")
            self.log.append("Type = Warning  " + "---- Rule violation in FF cell " + violative_dff + " :\n--- Derived/gated clock signal\n")
            self.log.append("Type = Report  " + "-- Issue resolved in cell " + violative_dff + "\n\n")
            index = self.ver_file.find(violative_dff)
            if index > -1:
                end_of_module = self.ver_file[index:].find(';')
                #current_module = self.ver_file[index:end_of_module]
                port_name = '.' + self.technology_parameter.list_of_clk[
                    self.technology_parameter.list_of_dff.index(self.top_module["cells"][violative_dff]["type"])] + '('
                start_of_replacement_index = index + self.ver_file[index:].find(port_name) - 1

                end_of_replacement_index = start_of_replacement_index + self.ver_file[start_of_replacement_index:].find(
                    ')')
                clock_port_start = start_of_replacement_index + self.ver_file[start_of_replacement_index:].find('(')
                module_clock_port = self.ver_file[clock_port_start + 1:end_of_replacement_index]
                # print(module_clock_port)
                list_of_added_Wires.append('_MUX' + str(len(list_of_added_Wires)) + '_')
                self.ver_file = self.ver_file[:start_of_replacement_index] + port_name + list_of_added_Wires[
                    -1] + self.ver_file[
                          end_of_replacement_index:]
                # list_of_added_MUXs.append("\tMUXT M" + str(
                #     len(list_of_added_Wires)) + "(" + module_clock_port + ", " + self.PI_clock + ", " + NBART + ", " +
                #                           list_of_added_Wires[-1] + ");\n")
                list_of_added_MUXs.append("assign " + list_of_added_Wires[-1] + " = (" + NBART + ") ? " + self.PI_clock +
                                          " : " +  module_clock_port + " ;\n")
                # print(list_of_added_MUXs[-1])
        added_wires = ""

        for i in range(len(list_of_added_Wires)):
            added_wires = added_wires + "\twire " + list_of_added_Wires[i] + ";\n"
        index = self.ver_file.find("wire")
        self.ver_file = self.ver_file[:index] + added_wires + self.ver_file[index:]
        index = self.ver_file.find("endmodule")
        # print(index)
        added_assignments = ""

        for i in range(len(list_of_added_MUXs)):
            added_assignments = added_assignments + list_of_added_MUXs[i]

        self.ver_file = self.ver_file[:index] + added_assignments + self.ver_file[index:]
        # mux_module = "\nmodule MUXT(input a,b,s, output c);\n\tassign c = (s) ? b : a;\nendmodule\n"
        # self.ver_file = self.ver_file + mux_module


    ###############################################################################
    ####### Description: detects and repairs ffs with gated or derived clocks #####
    ###############################################################################
    
    def check_clock_rule(self, NBART):
        # Detection
        #print("\nchecking for derived/gated clock signal...\n")
        self.log.append("Type = Report  " + "\n  Derived/Gated clock rule check...\n\n")

        self.list_of_input_clk, list_of_violative_dff = self.find_clk_violative_dffs()

        if len(list_of_violative_dff) == 0:
            if (len(self.list_of_input_clk) == 0):
               # print("\033[1;32m" + "No clock port found ! tool is not able to perform scan synthesis\n"+ "\033[0;0m")
                self.log.append("Type = Error  " + "--- ERROR: No clock port found !\n-Cannot perform scan synthesis\n")
                self.Success = False
                return

            for port in self.ports_list:
                if (len(self.top_module["ports"][port]["bits"]) == 1 and
                        self.list_of_input_clk[0] == self.top_module["ports"][port]["bits"][0] and
                        (self.top_module["ports"][port]["direction"] == "input")):
                    self.PI_clock = port

           # print("\033[1;32m" + "No clock violation detected\n" + "\033[0;0m")
            self.log.append("Type = Success  " + "  No clock violation detected\n")
        else:
            self.resolve_clock_violation(list_of_violative_dff, NBART) # IN MOHEME HAAAA ((((IMPORTAT SOS SOS SOS ))))

        #print("\033[0;0m" + "-------------------------------------------------"
         #                   "-------------------------------------------------\n")
     #   self.log.append("Type = Report  " + "\n --------------------------------- \n")

    ################################################################
    ###############################################################
    ###############################################################

    def is_active_high(self, cell, set_rst):
        for c in self.technology_parameter.cells:
            if self.top_module["cells"][cell]["type"] == str(c.args[0]):
                FF = c.get_groups('ff')
                if (set_rst == "rst"):
                    if str(FF[0]["clear"]).find('!') > -1  or str(FF[0]["clear"]).find('\'') > -1:
                        return False
                    else:
                        return True
                else:
                    if str(FF[0]["preset"]).find('!') > -1 or str(FF[0]["preset"]).find('\'') > -1:
                        return False
                    else:
                        return True

    def find_set_rst_violative_dffs(self):
        list_of_rst_violative_dff = list()
        list_of_set_violative_dff = list()

        for cell in self.top_module["cells"].values():
            # if super().DFF_cell(cell["type"]):
            if cell["type"] in self.technology_parameter.list_of_dff:
                key_cell = self.find_key(cell, self.top_module["cells"])
                index = self.technology_parameter.list_of_dff.index(cell["type"])
                if self.technology_parameter.list_of_set[index] != "None":
                    if self.check_if_connected_to_PI(cell["connections"][self.technology_parameter.list_of_set[index]][0]) == False:
                        if cell["connections"][self.technology_parameter.list_of_set[index]][0] != "1" and \
                                cell["connections"][self.technology_parameter.list_of_set[index]][0] != "0":
                            set_port = self.check_for_series_of_BUF(cell["connections"][self.technology_parameter.list_of_set[index]][0])
                            if self.check_if_connected_to_PI(set_port) == False:
                                set_port = self.check_if_connected_INV(cell["connections"][self.technology_parameter.list_of_set[index]][0])
                                if set_port is None:
                                    list_of_set_violative_dff.append(key_cell)
                                elif self.check_if_connected_to_PI(set_port) == False:
                                    list_of_set_violative_dff.append(key_cell)

                if self.technology_parameter.list_of_rst[index] != "None":
                    if self.check_if_connected_to_PI(cell["connections"][self.technology_parameter.list_of_rst[index]][0]) == False:
                        if cell["connections"][self.technology_parameter.list_of_rst[index]][0] != "1" and \
                                cell["connections"][self.technology_parameter.list_of_rst[index]][0] != "0":
                            rst_port = self.check_for_series_of_BUF(cell["connections"][self.technology_parameter.list_of_rst[index]][0])

                            if self.check_if_connected_to_PI(rst_port) == False:

                                rst_port = self.check_if_connected_INV(cell["connections"][self.technology_parameter.list_of_rst[index]][0])
                                if rst_port is None:

                                    list_of_rst_violative_dff.append(key_cell)
                                elif self.check_if_connected_to_PI(rst_port) == False:
                                    list_of_rst_violative_dff.append(key_cell)


        return list_of_rst_violative_dff, list_of_set_violative_dff

    def resolve_set_rst_violation(self, list_of_rst_violative_dff, list_of_set_violative_dff, NBART):
        list_of_added_ANDs = list()
        #list_of_added_ORs = list();
        list_of_added_Wires = list()
        ###### rst signal #######
        for rst_violative_dff in list_of_rst_violative_dff:
            # print("\033[1;33m"+"FF cell" + rst_violative_dff + "has an asynchrounous reset signal that is"
            #                                       " not controllable from primary inputs\n " + "\033[0;0m")
            self.log.append("Type = Warning  " + "--- Rule violation in FF cell" + rst_violative_dff + " :\n Derived async reset signal\n")
            self.log.append("Type = Report  " + "-- Issue resolved in cell " + rst_violative_dff + "\n\n")
            
            index = self.ver_file.find(rst_violative_dff)
            if index > -1:
                port_name = '.' + self.technology_parameter.list_of_rst[
                    self.technology_parameter.list_of_dff.index(self.top_module["cells"][rst_violative_dff]["type"])] + '('

                start_of_replacement_index = index + self.ver_file[index:].find(port_name) - 1
                end_of_replacement_index = start_of_replacement_index + self.ver_file[start_of_replacement_index:].find(
                    ')')
                rst_port_start = start_of_replacement_index + self.ver_file[start_of_replacement_index:].find('(')
                module_rst_port = self.ver_file[rst_port_start + 1:end_of_replacement_index]

                list_of_added_Wires.append('_DRS' + str(len(list_of_added_Wires)) + '_')
                self.ver_file = self.ver_file[:start_of_replacement_index] + port_name + list_of_added_Wires[
                    -1] + self.ver_file[
                          end_of_replacement_index:]
                if self.is_active_high(rst_violative_dff, "rst"):
                    #list_of_added_ANDs.append("\tandT _AND" + str(len(list_of_added_Wires))+"_ ("+ list_of_added_Wires[-1] +", "+NBART+", " + module_rst_port +");\n")
                    list_of_added_ANDs.append("assign " + list_of_added_Wires[-1] + " = ~" +  NBART + " & " +
                    module_rst_port + " ;\n")
                    #assign c = ~T & R;

                else:
                    # list_of_added_ANDs.append("\torT _OR" + str(len(list_of_added_Wires)) + "_ (" + list_of_added_Wires[
                    #     -1] + ", " + NBART + ", " + module_rst_port + ");\n")
                    list_of_added_ANDs.append("assign " + list_of_added_Wires[-1] + " = " + NBART + " | " +
                                              module_rst_port + " ;\n")

        for set_violative_dff in list_of_set_violative_dff:
           # print("\033[1;33m"+"FF cell"+ set_violative_dff + "has an asynchrounous set signal that is"
           #                                      " not controllable from primary inputs\n " + "\033[0;0m")
            self.log.append("Type = Warning  " + " -- Rule violation in FF cell"+ set_violative_dff + " :\nDerived async set signal\n")
            self.log.append("Type = Report  " + "-- Issue resolved in cell " + set_violative_dff + "\n\n")
            index = self.ver_file.find(set_violative_dff)
            if index > -1:
                port_name = '.' + self.technology_parameter.list_of_set[
                    self.technology_parameter.list_of_dff.index(self.top_module["cells"][set_violative_dff]["type"])] + '('

                start_of_replacement_index = index + self.ver_file[index:].find(port_name) - 1
                end_of_replacement_index = start_of_replacement_index + self.ver_file[start_of_replacement_index:].find(
                    ')')
                set_port_start = start_of_replacement_index + self.ver_file[start_of_replacement_index:].find('(')
                module_set_port = self.ver_file[set_port_start + 1:end_of_replacement_index]

                list_of_added_Wires.append('_DRS' + str(len(list_of_added_Wires)) + '_')
                self.ver_file = self.ver_file[:start_of_replacement_index] + port_name + list_of_added_Wires[
                    -1] + self.ver_file[
                          end_of_replacement_index:]
                if self.is_active_high(set_violative_dff, "set"):
                    list_of_added_ANDs.append("assign " + list_of_added_Wires[-1] + " = ~" + NBART + " & " +
                                              module_set_port + " ;\n")
                    # list_of_added_ANDs.append("\tandT _AND" + str(len(list_of_added_Wires))+"_ ("+
                    #                           list_of_added_Wires[-1] +", "+NBART+", " + module_set_port +");\n")

                else:
                    list_of_added_ANDs.append("assign " + list_of_added_Wires[-1] + " = " + NBART + " | " +
                                              module_set_port + " ;\n")
                    # list_of_added_ANDs.append("\torT _OR" + str(len(list_of_added_Wires)) + "_ (" + list_of_added_Wires[
                    #     -1] + ", " + NBART + ", " + module_set_port + ");\n")




        #print(list_of_added_Wires, list_of_added_ANDs)
        added_wires = ""

        for i in range(len(list_of_added_Wires)):
            added_wires = added_wires + "\twire " + list_of_added_Wires[i] + ";\n"
        index = self.ver_file.find("wire")
        self.ver_file = self.ver_file[:index] + added_wires + self.ver_file[index:]

        index = self.ver_file.find("endmodule")
        # print(index)
        added_assignments = ""

        for i in range(len(list_of_added_ANDs)):
            added_assignments = added_assignments + list_of_added_ANDs[i]

        self.ver_file = self.ver_file[:index] + added_assignments + self.ver_file[index:]
        # mux_module = "\nmodule orT(output c, input T,R);\n\tassign c = T | R;\nendmodule\n"
        # self.ver_file = self.ver_file + mux_module
        # mux_module = "\nmodule andT(output c, input T,R);\n\tassign c = ~T & R;\nendmodule"
        # self.ver_file = self.ver_file + mux_module

    def check_set_rst_rule(self, NBART):
       # print("\nChecking for derived async set/rst signal...\n")
        self.log.append("Type = Report  " + "\n  Derived async set/rst rule check...\n\n")
        
        list_of_rst_violative_dff, list_of_set_violative_dff = self.find_set_rst_violative_dffs()
        if len(list_of_rst_violative_dff) == 0 and len(list_of_set_violative_dff) == 0:
          # print("\033[1;32m" + "No set/rst violation detected\n" + "\033[0;0m")
            self.log.append("Type = Success  " + "  No set/rst violation detected\n")
        else:
            self.resolve_set_rst_violation(list_of_rst_violative_dff, list_of_set_violative_dff, NBART)
            

            # pass
     #   print("-------------------------------------------------"
      #          "-------------------------------------------------\n")
     #   self.log.append("Type = Report  " + "\n --------------------------------- \n")
    #######################################################
    ####### Description: adds NBART and Grst to design #####
    #######################################################
    def add_scan_inputs(self, NBART, Grst):
        index = self.ver_file.find(self.module_name) + len(self.module_name)
        index += self.ver_file[index:].find("(")
        self.ver_file = self.ver_file[:index + 1] + NBART + ", " + Grst + ", " + self.ver_file[ index + 1:]
        added_wires = "input " + NBART + ";\n"
        added_wires = added_wires + "\tinput " + Grst + ";\n"
        index = self.ver_file.find("wire")
        self.ver_file = self.ver_file[:index] + added_wires + self.ver_file[index:]

    
    def Design_Rule_Check (self, NBART, Grst):



        self.log.append("Type = Report  " + "\n ---- MODULE : " + self.module_name + " ----\n --- DESIGN RULE CHECK ---\n")

        self.add_scan_inputs(NBART, Grst)

        self.check_clock_rule(NBART)

        if(self.PI_clock == ""):
            return self.log

        self.check_set_rst_rule(NBART)

        f = open( path.join(self.DIR, "test_ready.v"), "w")
        f.write(self.ver_file)
        f.close()

        return self.log

        