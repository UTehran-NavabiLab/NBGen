from os import path, getcwd, chdir, mkdir
from utdate.src.conv.json2vhdl import json2vhdl
from utdate.src.utility_functions import split_page
import utdate.lib as lib

# see if it's multi-bit port
# TODO: check if module name is also used for any other property
#   if so change module name, since it raise an error in systemc

WHITE_SPACE = "    "

class json2vhdl_virtualTesterScan(json2vhdl):
    def __init__(self, json_file, config_json, technology_parameter) -> None:
        json2vhdl.__init__(self, json_file, config_json, technology_parameter)
        self.list_of_Q_ports = list()
        self.cells_instance_pointer, self.cells_instantiation = self.cells_declaration()
        # get directory of library inside package repository
        self.scan_chain_lib = path.join((path.join(lib.__path__[0], "test")), "scan_chain")
        self.working_dir = getcwd()

        self.working_dir = getcwd()
        self.scan_chain = ""

        # check wether the "test" directory exist in working directory
        # if not create a new one
        if (path.isdir(path.join(self.working_dir, "test"))):
            self.scan_chain = path.join(self.working_dir, "test")
        else:
            test_dir = mkdir("test", self.working_dir)
            self.scan_chain = mkdir("bist", test_dir)
        
        RTS_template_dir = path.join(self.scan_chain_lib, "VirtualTester_Scan_template.vhd")

        # Copy unmodified files
        
        # RTS_controller ----------------
        # Read from the template
        with open(path.join(RTS_template_dir, "VirtualTester_Scan_template.vhd"), "r") as rd:
            vTester_template = rd.read()

            # set constants
            # self.constants(vTester_template, configurations={
            #     "numDFF": self.
            # })



            with open(path.join(self.scan_chain, "RTS_Controller.vhd"), "w") as wr:
                wr.write(vTester_template)

    # @def: add standard library library  
    def constants(self, template, configurations):
        # replace numDFF
        if (configurations["numDFF"] != None):
            p1, p2 = split_page(template, ["numDFF", ":", "INTEGER", ":="])
            p2, p3 = split_page(p2, [";"])
            template = p1 + " " + str(configurations["numDFF"]) + ";" + p3
        if (configurations["sizePI"] != None):
            # replace sizePI
            p1, p2 = split_page(template, ["sizePI", ":", "INTEGER", ":="])
            p2, p3 = split_page(p2, [";"])
            template = p1 + " " + str(configurations["sizePI"]) + ";" + p3
        if (configurations["sizePO"] != None):
            # replace sizePO
            p1, p2 = split_page(template, ["sizePO", ":", "INTEGER", ":="])
            p2, p3 = split_page(p2, [";"])
            template = p1 + " " + str(configurations["sizePO"]) + ";" + p3
        if (configurations["chainLength"] != None):
            # replace chainLength
            p1, p2 = split_page(template, ["chainLength", ":", "INTEGER", ":="])
            p2, p3 = split_page(p2, [";"])
            template = p1 + " " + str(configurations["chainLength"]) + ";" + p3
        if (configurations["clkPeriod"] != None):
            # replace clkPeriod
            p1, p2 = split_page(template, ["clkPeriod", ":", "time", ":="])
            p2, p3 = split_page(p2, ["ns"])
            template = p1 + " " + str(configurations["clkPeriod"]) + ";" + p3

    # @def: define SC_METHOD for scan signal So 
    #   @output: a list of three string
    #       sc_logic_signal_declr: that goes to signal_declartion()
    #       sc_logic_method_declr: that goes to constructor_declaration()
    #       sc_logic_function_declr: that goes to module_declaration()
    def so_assignment_method(self):
        so_assignment_method_declr = ""
        so_assignment_function_declr = ""

        if(self.is_sequential):
            so_assignment_method_declr += WHITE_SPACE + f'SC_METHOD(So_assignment);\n'
            so_assignment_method_declr += WHITE_SPACE + WHITE_SPACE + f'sensitive << {self.list_of_Q_ports[-1]};\n' # get last element of dff Q ports
            
            so_assignment_function_declr += WHITE_SPACE + "void So_assignment(void){\n"
            so_assignment_function_declr += WHITE_SPACE + WHITE_SPACE + f'So_sig.write({self.list_of_Q_ports[-1]}.read());\n' # get last element of dff Q ports
            so_assignment_function_declr += WHITE_SPACE + "}\n"
        
        return so_assignment_method_declr, so_assignment_function_declr

    # @def: declare ports
    def port_declaration(self):

        port_declaration = ""

        for port_name, port_prop in self.top_module["ports"].items():
            port_declaration += WHITE_SPACE 

            if port_prop["direction"] == "input":
                if len(port_prop["bits"]) == 1:
                    port_declaration += f'sc_in<sc_logic> {port_name};\n'
                else:
                    port_declaration += f'sc_in<sc_logic> {port_name}[{str(len(port_prop["bits"]))}];\n'
                
            elif port_prop["direction"] == "output":
                if len(port_prop["bits"]) == 1:
                    port_declaration += f'sc_out<sc_logic> {port_name};\n'
                else:
                    port_declaration += f'sc_out<sc_logic> {port_name}[{str(len(port_prop["bits"]))}];\n'
                
        if(self.is_sequential):
            port_declaration += WHITE_SPACE + f'sc_in<sc_logic> global_reset;\n'
            port_declaration += WHITE_SPACE + f'sc_in<sc_logic> NbarT;\n'
            port_declaration += WHITE_SPACE + f'sc_in<sc_logic> Si;\n'
            port_declaration += WHITE_SPACE + f'sc_out<sc_logic> So;\n'

        return port_declaration

    # @def: find actual net name using net integer value
    #   input: net integer value
    #   output: net name
    def signal_declartion(self):

        signal_declartion = ""

        signal_declartion += self.sc_logic_signals()[0] + "\n"

        for net in self.net_dict:
            if not (net in self.ports_list):
                signal_declartion += WHITE_SPACE 
                signal_declartion += "sc_signal<sc_logic> " + net + ";\n"

        if(self.is_sequential):
            signal_declartion += WHITE_SPACE + f'sc_signal<sc_logic> global_reset_sig;\n'
            signal_declartion += WHITE_SPACE + f'sc_signal<sc_logic> NbarT_sig;\n'
            signal_declartion += WHITE_SPACE + f'sc_signal<sc_logic> Si_sig;\n'
            signal_declartion += WHITE_SPACE + f'sc_signal<sc_logic> So_sig;\n'

        return signal_declartion
  
    # @def: retrieve cell parameters for each cell and pass it to cells_declaration()
    #   input: 
    #       cell: dictionaly of cell {hide_name, type, parameters, attributes, connections}
    #       index: an index to name and address cells with (get appended at the end of cell name)
    #   output: two separate string to append at different location
    #       instance_pointer: create a pointer to gate type
    #       cell_instantiation: instantiation of cells inside constructor
    def get_each_cell(self, cell, index, dff_count):
        # retrieve cell type, parameters and connection as a dictionary
        cell_type = cell["type"]
        cell_parameter = cell["parameters"]
        cell_connections = cell["connections"]

        instance_pointer = ""
        cell_instantiation = ""

        instatnce_name = cell_type + "_" + str(index)
        # create pointer for each faulty cell (add "_flt") at the end
        instance_pointer = WHITE_SPACE + cell_type + "_flt" + "* " + instatnce_name + ";\n"
 
        cell_instantiation = WHITE_SPACE + instatnce_name + " = new " + cell_type + "_flt" + '("' + instatnce_name + '", accessRegistry);\n'
        
        # port mapping 
        # loop through each connection, get corresponding net-name
        ################# change
        for con_name, con_value in cell_connections.items():
            if(((cell_type.find("DFF") > -1) or (cell_type.find("dff") > -1)) and (self.is_sequential)):
                if(con_name == "NbarT"):
                    cell_instantiation += WHITE_SPACE + WHITE_SPACE
                    cell_instantiation += instatnce_name + "->" + con_name + "(" + "NbarT_sig" + ");\n"
                elif(con_name == "global_reset"):
                    cell_instantiation += WHITE_SPACE + WHITE_SPACE
                    cell_instantiation += instatnce_name + "->" + con_name + "(" + "global_reset_sig" + ");\n"
                elif(con_name == "Si"):
                    # if it is the first dff bind Si
                    if(dff_count == 0):
                        cell_instantiation += WHITE_SPACE + WHITE_SPACE
                        cell_instantiation += instatnce_name + "->" + con_name + "(" + "Si_sig" + ");\n"
                    else: # if it's not first dff, connect Si to previous dff Q port
                        cell_instantiation += WHITE_SPACE + WHITE_SPACE
                        cell_instantiation += instatnce_name + "->" + con_name + "(" + self.list_of_Q_ports[dff_count - 1] + ");\n"
                else: # treat rest of the ports as normal
                    # is port multi-bit
                    if(con_name == "Q"): # save Q port for next dff to bind
                        self.list_of_Q_ports.append(self.find_net(con_value[0]))
                    if (len(con_value) == 1):
                        cell_instantiation += WHITE_SPACE + WHITE_SPACE
                        cell_instantiation += instatnce_name + "->" + con_name + "(" + self.find_net(con_value[0]) + ");\n"
                    else: # if net is multi-bit, slice the port loop through each bit
                        portIndex = 0
                        for connection in con_value:
                            cell_instantiation += WHITE_SPACE + WHITE_SPACE
                            cell_instantiation += instatnce_name + "->" + con_name + "[" + str(portIndex) + "]" + "(" + self.find_net(connection) + ");\n"
                            portIndex += 1

            else: # it is not a dff
                # is port multi-bit
                if (len(con_value) == 1):
                    cell_instantiation += WHITE_SPACE + WHITE_SPACE
                    cell_instantiation += instatnce_name + "->" + con_name + "(" + self.find_net(con_value[0]) + ");\n"
                else: # if net is multi-bit, slice the port loop through each bit
                    portIndex = 0
                    for connection in con_value:
                        cell_instantiation += WHITE_SPACE + WHITE_SPACE
                        cell_instantiation += instatnce_name + "->" + con_name + "[" + str(portIndex) + "]" + "(" + self.find_net(connection) + ");\n"
                        portIndex += 1

        return instance_pointer, cell_instantiation


    # @def: instance all the required modules, define pointers outside constructor and port binding inside
    def cells_declaration(self):
        instance_pointer = ""
        cell_instantiation = ""

        cell_index = 0
        dff_count = 0
        # set flags to identify first and last dff
        for cell_name, cell_prop in self.top_module["cells"].items():
            cell_index = self.gate_indexing(cell_prop["type"])
            instance_pointer_temp, cell_instantiation_temp = self.get_each_cell(cell_prop, cell_index, dff_count)
            instance_pointer += instance_pointer_temp
            cell_instantiation += cell_instantiation_temp + "\n"

            # if cell is of type dff
            if(((cell_prop["type"].find("DFF") > -1) or (cell_prop["type"].find("dff") > -1)) and (self.is_sequential)):
                dff_count = dff_count + 1
            
            # cell_index += 1
        
        pin_input_list = ["So_sig", "global_reset", "NbarT", "Si"]
        pin_output_list = ["So", "global_reset_sig", "NbarT_sig", "Si_sig"]

        if(self.is_sequential):
            for j in range(4):
                if(j == 0):
                    instance_pointer += WHITE_SPACE + f'pout_flt* pout_{cell_index + j};\n'
                    cell_instantiation += WHITE_SPACE + f'pout_{cell_index + j} = new pout_flt("pout_{cell_index + j}", accessRegistry);\n'
                    cell_instantiation += WHITE_SPACE + WHITE_SPACE + f'pout_{cell_index + j}->I({pin_input_list[j]});\n'
                    cell_instantiation += WHITE_SPACE + WHITE_SPACE + f'pout_{cell_index + j}->O({pin_output_list[j]});\n'
                else:
                    instance_pointer += WHITE_SPACE + f'pin_flt* pin_{cell_index + j};\n'
                    cell_instantiation += WHITE_SPACE + f'pin_{cell_index + j} = new pin_flt("pin_{cell_index + j}", accessRegistry);\n'
                    cell_instantiation += WHITE_SPACE + WHITE_SPACE + f'pin_{cell_index + j}->I({pin_input_list[j]});\n'
                    cell_instantiation += WHITE_SPACE + WHITE_SPACE + f'pin_{cell_index + j}->O({pin_output_list[j]});\n'

        return instance_pointer, cell_instantiation

    # @def: declare module signature 
    def constructor_declaration(self):
        constructor_declaration = ""
        constructor_declaration += f'SC_HAS_PROCESS({self.module_name});\n'
        constructor_declaration += WHITE_SPACE + f'{self.module_name}(sc_module_name _name, faultRegistry* accessRegistry)' + '{\n'
        
        # add cell instantiation and binding
        constructor_declaration += self.cells_instantiation + "\n"
        
        # add sc_method for sc_logic_signals
        constructor_declaration += self.sc_logic_signals()[1] + "\n"
        constructor_declaration += self.so_assignment_method()[0] + "\n"

        # # add sc_module for port concatenation
        # constructor_declaration += self.cells_declaration()[2]

        constructor_declaration += WHITE_SPACE + "}\n"

        return constructor_declaration

    # @def: declare module signature 
    def module_declaration(self):
        entity_declaration = ""
        entity_declaration += f'SC_MODULE( {self.module_name} ) ' + '{\n'
        
        entity_declaration += "\n"
        entity_declaration += self.port_declaration()
        entity_declaration += "\n"
        entity_declaration += self.signal_declartion()
        entity_declaration += "\n"
        entity_declaration += self.cells_instance_pointer
        entity_declaration += "\n"
        entity_declaration += self.constructor_declaration()
        entity_declaration += "\n"
        entity_declaration += self.sc_logic_signals()[2]
        entity_declaration += "\n"
        entity_declaration += self.so_assignment_method()[1]

        entity_declaration += "};"
        return entity_declaration