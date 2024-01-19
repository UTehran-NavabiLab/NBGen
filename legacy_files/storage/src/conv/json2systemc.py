from utdate.src.conv.json2hdl import json2hdl
from json import dumps

# see if it's multi-bit port
# TODO: check if module name is also used for any other property
#   if so change module name, since it raise an error in systemc
#   add option to be yosys compatible

WHITE_SPACE = "    "

class json2systemc(json2hdl):
    def __init__(self, json_file, config_json, technology_parameters, gate_signal_file="") -> None:
        json2hdl.__init__(self, json_file, config_json, technology_parameters)

        self.systemc = ""
        self.gate_signal_dict = dict()
        self.gate_signal_file = gate_signal_file


    def dump_gate_signal_dict(self):
        if (self.gate_signal_file != ""):
            with open(self.gate_signal_file, "w") as f:
                f.write(dumps(self.gate_signal_dict))


    
    # @def: 
    #   number_of_DFF; helper function to find number of DFFs in design
    def number_of_DFF(self):
        cells_dic = self.top_module["cells"]
        numb_DFF = 0

        for cell in cells_dic.values():
            if ((cell["type"].find("DFF") > -1) or (cell["type"].find("dff") > -1)):
                numb_DFF = numb_DFF + 1

        return numb_DFF
   
    # @def: find actual net name using net integer value
    #   input: net integer value
    #   output: net name
    def find_net(self, net_number):
        # is net_number string
        # some net are set to constant string 1/0 
        if not (isinstance(net_number, str)):
            for key, values in self.net_dict.items():
                if len(values) == 1:
                    if (values[0] == net_number):
                        return key
                else:
                    for value in values:
                        if (value == net_number):
                            return key + "[" + str(values.index(value)) + "]"
        else:
            return "sc_logic_" + net_number + "_signal"
 
    # @def: add standard library library  
    def includes(self):
        include_lib = '#include <systemc.h>' + "\n"
        include_lib += f'#include "{self.config_js["systemC_library"]}"'

        return include_lib

    # @def: define sc_core namespace
    def namespace_decl(self):
        namespace_decl = "using namespace sc_core;"
        return namespace_decl

    # @def: define sc_logic_signals to be use for port binding
    #   @output: a list of three string
    #       sc_logic_signal_declr: that goes to signal_declartion()
    #       sc_logic_method_declr: that goes to constructor_declaration()
    #       sc_logic_function_declr: that goes to module_declaration()
    def sc_logic_signals(self):
        sc_logic_signal_declr = ""
        sc_logic_method_declr = ""
        sc_logic_function_declr = ""

        # singals that provide SC_LOGIC_(0/1) for port binding process
        sc_logic_signal_declr += WHITE_SPACE 
        sc_logic_signal_declr += "sc_signal<sc_logic> sc_logic_1_signal;\n"
        sc_logic_signal_declr += WHITE_SPACE 
        sc_logic_signal_declr += "sc_signal<sc_logic> sc_logic_0_signal;\n"

        sc_logic_method_declr += WHITE_SPACE + f'SC_METHOD(sc_logic_signal_assignment);\n'
        
        sc_logic_function_declr += WHITE_SPACE + "void sc_logic_signal_assignment(void){ \n"
        sc_logic_function_declr += WHITE_SPACE + WHITE_SPACE + "sc_logic_1_signal.write(SC_LOGIC_1);\n"
        sc_logic_function_declr += WHITE_SPACE + WHITE_SPACE + "sc_logic_0_signal.write(SC_LOGIC_0);\n"
        sc_logic_function_declr += WHITE_SPACE + "}\n"
        
        return sc_logic_signal_declr, sc_logic_method_declr, sc_logic_function_declr

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
                signal_declartion += f'sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> {net} = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("{net}");' + "\n"

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
        # cell_port_direction = cell["port_directions"]

        instance_pointer = ""
        cell_instantiation = ""

        instatnce_name = cell_type + "_" + str(index)
        # start string
        instance_pointer = WHITE_SPACE + cell_type + "* " + instatnce_name + ";\n"
 
        cell_instantiation = WHITE_SPACE + instatnce_name + " = new " + cell_type + '("' + instatnce_name + '");\n'
        
        # add new key to gate_signal dictionary
        self.gate_signal_dict.update({instatnce_name:[]})

        # port mapping 
        # loop through each connection, get corresponding net-name
        for con_name, con_value in cell_connections.items():
            # is port multi-bit
            if (len(con_value) == 1):
                cell_instantiation += WHITE_SPACE + WHITE_SPACE
                cell_instantiation += instatnce_name + "->" + con_name + "(" + self.find_net(con_value[0]) + ");\n"
                
                # first element *can be* be output (change association to by-name), so the order is not that important
                # if( cell_port_direction[con_name] == "output" ):
                #     self.gate_signal_dict[instatnce_name].insert(0, {con_name: self.find_net(con_value[0])})
                # else:
                self.gate_signal_dict[instatnce_name].append({con_name: self.find_net(con_value[0])})
                    
            else: # if net is multi-bit, slice the port loop through each bit
                i = 0
                for connection in con_value:
                    cell_instantiation += WHITE_SPACE + WHITE_SPACE
                    cell_instantiation += instatnce_name + "->" + con_name + "[" + str(i) + "]" + "(" + self.find_net(connection) + ");\n"
                    i += 1

                    # if( cell_port_direction[con_name] == "output" ):
                    #     self.gate_signal_dict[instatnce_name].insert(0, {con_name: self.find_net(connection)})
                    # else:
                    self.gate_signal_dict[instatnce_name].append({con_name: self.find_net(connection)})
                        
                    
        return instance_pointer, cell_instantiation


    # @def: instance all the required modules, define pointers outside constructor and port binding inside
    def cells_declaration(self):
        instance_pointer = ""
        cell_instantiation = ""
        i = 0
        
        
        for cell_name, cell_prop in self.top_module["cells"].items():
            i = self.gate_indexing(cell_prop["type"])
            instance_pointer_temp, cell_instantiation_temp = self.get_each_cell(cell_prop, i)
            instance_pointer += instance_pointer_temp
            cell_instantiation += cell_instantiation_temp + "\n"

        return instance_pointer, cell_instantiation

    # @def: declare module signature 
    def constructor_declaration(self, cell_in_constructor_declaration):
        constructor_declaration = ""
        constructor_declaration += f'SC_CTOR( {self.module_name} ) ' + '{\n'
        
        # add cell instantiation and binding
        constructor_declaration += cell_in_constructor_declaration + "\n"
        
        # add sc_module for sc_logic_signals
        constructor_declaration += self.sc_logic_signals()[1] + "\n"

        constructor_declaration += WHITE_SPACE + "}\n"

        return constructor_declaration

    # @def: declare module signature 
    def module_declaration(self):
        # cell instantiation must get called only one time
        cell_pointer_instantiation, cell_in_constructor_declaration = self.cells_declaration()

        entity_declaration = ""
        entity_declaration += f'SC_MODULE( {self.module_name} ) ' + '{\n'
        
        entity_declaration += "\n"
        entity_declaration += self.port_declaration()
        entity_declaration += "\n"
        entity_declaration += self.signal_declartion()
        entity_declaration += "\n"
        entity_declaration += cell_pointer_instantiation
        entity_declaration += "\n"
        entity_declaration += self.constructor_declaration(cell_in_constructor_declaration)
        entity_declaration += "\n"
        entity_declaration += self.sc_logic_signals()[2]

        entity_declaration += "};"
        return entity_declaration

    # @def: concatinate pieces and output final systemc module
    def generate_systemc(self):

        self.systemc += self.includes() + "\n"
        self.systemc += "\n"
        self.systemc += self.namespace_decl() + "\n"
        self.systemc += "\n"
        self.systemc += self.module_declaration() + "\n"
        
        self.dump_gate_signal_dict()

        return self.systemc
