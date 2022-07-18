from . json2systemc import json2systemc

# see if it's multi-bit port
# TODO: check if module name is also used for any other property
#   if so change module name, since it raise an error in systemc

WHITE_SPACE = "    "

class json2systemc_flt(json2systemc):
    def __init__(self, json_file) -> None:
        json2systemc.__init__(self, json_file)
        self.last_dff_Q_port = ""

    # @def: add standard library library  
    def includes(self):
        include_lib = '#include <systemc.h>' + "\n"
        include_lib += '#include "component_flt_lib.h"'
        return include_lib

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
            so_assignment_method_declr += WHITE_SPACE + WHITE_SPACE + f'sensitive << {self.last_dff_Q_port};\n'
            
            so_assignment_function_declr += WHITE_SPACE + "void So_assignment(void){\n"
            so_assignment_function_declr += WHITE_SPACE + WHITE_SPACE + f'So_sig.write({self.last_dff_Q_port}.read());\n'
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
    def get_each_cell(self, cell, index):
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
        dff_number = 0
        previous_Q = ""
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
                    if(dff_number == 0):
                        cell_instantiation += WHITE_SPACE + WHITE_SPACE
                        cell_instantiation += instatnce_name + "->" + con_name + "(" + "Si_sig" + ");\n"
                    else: # if it's not first dff, connect Si to previous dff Q port
                        cell_instantiation += WHITE_SPACE + WHITE_SPACE
                        cell_instantiation += instatnce_name + "->" + con_name + "(" + previous_Q + ");\n"
                else: # treat rest of the ports as normal
                    # is port multi-bit
                    if(con_name == "Q"): # save Q port for next dff to bind
                        previous_Q = self.find_net(con_value[0])
                        if(dff_number == (self.number_of_DFF() - 1)):
                            self.last_dff_Q_port = self.find_net(con_value[0])
                    if (len(con_value) == 1):
                        cell_instantiation += WHITE_SPACE + WHITE_SPACE
                        cell_instantiation += instatnce_name + "->" + con_name + "(" + self.find_net(con_value[0]) + ");\n"
                    else: # if net is multi-bit, slice the port loop through each bit
                        portIndex = 0
                        for connection in con_value:
                            cell_instantiation += WHITE_SPACE + WHITE_SPACE
                            cell_instantiation += instatnce_name + "->" + con_name + "[" + str(portIndex) + "]" + "(" + self.find_net(connection) + ");\n"
                dff_number = dff_number + 1
                i += 1

            else: # it is not a dff
                # is port multi-bit
                if (len(con_value) == 1):
                    cell_instantiation += WHITE_SPACE + WHITE_SPACE
                    cell_instantiation += instatnce_name + "->" + con_name + "(" + self.find_net(con_value[0]) + ");\n"
                else: # if net is multi-bit, slice the port loop through each bit
                    i = 0
                    for connection in con_value:
                        cell_instantiation += WHITE_SPACE + WHITE_SPACE
                        cell_instantiation += instatnce_name + "->" + con_name + "[" + str(i) + "]" + "(" + self.find_net(connection) + ");\n"
                        i += 1

        return instance_pointer, cell_instantiation


    # @def: instance all the required modules, define pointers outside constructor and port binding inside
    def cells_declaration(self):
        instance_pointer = ""
        cell_instantiation = ""
        sc_method_declaration = ""
        concatenation_functions = ""
        i = 0
        
        for cell_name, cell_prop in self.top_module["cells"].items():
            instance_pointer += self.get_each_cell(cell_prop, i)[0]
            cell_instantiation += self.get_each_cell(cell_prop, i)[1] + "\n"
            i += 1
        
        if(self.is_sequential):
            for j in range(4):
                if(j == 0):
                    instance_pointer += WHITE_SPACE + f'pout_flt* pout_{i + j};'
                    cell_instantiation += WHITE_SPACE + f'pout_{i + j} = new pout_flt("pout_{i + j}", accessRegistry);\n'
                    cell_instantiation += WHITE_SPACE + WHITE_SPACE + f'pout_{i + j}->in1(So_sig);\n'
                    cell_instantiation += WHITE_SPACE + WHITE_SPACE + f'pout_{i + j}->out1(So);\n'
                else:
                    instance_pointer += WHITE_SPACE + f'pin_flt* pin_{i + j};'
                    cell_instantiation += WHITE_SPACE + f'pin_{i + j} = new pin_flt("pin_{i + j}", accessRegistry);\n'
                    cell_instantiation += WHITE_SPACE + WHITE_SPACE + f'pin_{i + j}->in1(Si);\n'
                    cell_instantiation += WHITE_SPACE + WHITE_SPACE + f'pin_{i + j}->out1(Si_sig);\n'

        return instance_pointer, cell_instantiation

    # @def: declare module signature 
    def constructor_declaration(self):
        constructor_declaration = ""
        constructor_declaration += f'SC_HAS_PROCESS({self.module_name});\n'
        constructor_declaration += WHITE_SPACE + f'{self.module_name}(sc_module_name _name, faultRegistry* accessRegistry)' + '{\n'
        
        # add cell instantiation and binding
        constructor_declaration += self.cells_declaration()[1] + "\n"
        
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
        entity_declaration += self.cells_declaration()[0]
        entity_declaration += "\n"
        entity_declaration += self.constructor_declaration()
        entity_declaration += "\n"
        entity_declaration += self.sc_logic_signals()[2]
        entity_declaration += "\n"
        entity_declaration += self.so_assignment_method()[1]

        entity_declaration += "};"
        return entity_declaration
