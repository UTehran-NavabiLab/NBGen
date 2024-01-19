from utdate.src.conv.json2hdl import json2hdl
from json import dumps, load
import re
from os import path
# see if it's multi-bit port
# TODO: check if module name is also used for any other property
#   if so change module name, since it raise an error in systemc
#   add option to be yosys compatible

WHITE_SPACE = "    "

class json2systemc():
    def __init__(self, json_file, technology_parameters, config_json, synthesis_dir, gate_signal_file="") -> None:
        # json2hdl.__init__(self, json_file, technology_parameters)
        with open(json_file, "r") as f:
            self.js = load(f)

        self.synthesis_dir = synthesis_dir
        self.technology_parameter = technology_parameters
        self.config_js = config_json
        self.gate_signal_dict = dict()
        self.gate_signal_file = gate_signal_file
        self.generate_systemc()
        # self.is_sequential = self.is_sequential_check()

            
    # # @def: 
    # #   is_sequential_check ; check whether the circuit is combinational/sequential
    # def is_sequential_check(self):
    #     is_seq = False

    #     # check whether the design is sequential/combinational (check for existance of dff)
    #     for cell in self.top_module["cells"].values():
    #         for dff_name, dff_ports in self.technology_parameter.dict_of_dff.items():
    #             if (cell["type"].find(dff_name) > -1):
    #                 is_seq = True

    #     return is_seq

    def dump_gate_signal_dict(self):
        if (self.gate_signal_file != ""):
            with open(self.gate_signal_file, "w") as f:
                f.write(dumps(self.gate_signal_dict))

    # @def: add standard library library  
    def includes(self):
        include_lib = '#include <systemc.h>' + "\n"
        include_lib += f'#include "{self.config_js["systemC_library"]}"'

        return include_lib


    # @def: concatinate pieces and output final systemc module
    def generate_systemc(self):
        for module_name, module_prop in self.js["modules"].items():
            module_name_stript = re.sub("['.~:\[\]!@#$%^&*\\\+=-]", "_", module_name)
            if ("blackbox" in module_prop["attributes"].keys()): # skip if it is blackbox
                if (module_prop["attributes"]["blackbox"].find("1") > -1):
                    continue

            systemc = ""
            systemc += self.includes() + "\n"
            systemc += "\n"
            sc_module     = sc_module_gen(module_name_stript, module_prop, self.technology_parameter)
            systemc += sc_module.generate_systemc() + "\n"
            
            # TODO: is it necessary to something different for top module
            if ("top" in module_prop["attributes"].keys()): 
                if (module_prop["attributes"]["top"].find("1") > -1):
                    with open(path.join(self.synthesis_dir, f'{module_name_stript}.h'), "w") as f:
                        f.write(systemc)
                else:
                    with open(path.join(self.synthesis_dir, f'{module_name_stript}.h'), "w") as f:
                        f.write(systemc)
            else:
                with open(path.join(self.synthesis_dir, f'{module_name_stript}.h'), "w") as f:
                    f.write(systemc)
            
            self.gate_signal_dict.update(sc_module.dump_gate_signal_dict())
        
        self.dump_gate_signal_dict()


######################################### sc_module_generator ###########################################
class sc_module_gen():
    """The class that generates sc_module given the json object of the module.
 
    More details.
    """
    def __init__(self, top_module_name, top_module_prop, technology_parameter) -> None:
        self.top_module = top_module_prop
        self.sc_module = ""
        # if ("hdlname" in self.top_module["attributes"].keys()):
        #     self.module_name = re.sub("['.~:\[\]!@#$%^&*\\\+=-]", "_", self.top_module["attributes"]["hdlname"])
        # else:
        # self.module_name = re.sub("['.~:\[\]!@#$%^&*\\\+=-]", "_", top_module_name)
        self.module_name = top_module_name

        self.technology_parameter = technology_parameter
        self.gate_index = dict()
        self.gate_signal_dict = dict()
        self.ports_list = list(self.top_module["ports"])
        # self.gate_signal_file = gate_signal_file
        self.net_dict = self.net_declartion()
        self.yosys_qflow_compatible = False

        # self.generate_systemc()


    # @def: add standard library library  
    def includes(self):
        include_lib = ""
        list_of_lib_cells = list()
        for cell_group in self.technology_parameter.cells: # under the assumption that only non-technology cells have "src" attr.
            list_of_lib_cells.append(cell_group.args[0])
        for cell_name, cell_prop in self.top_module["cells"].items():
            # if ("src" in cell_prop["attributes"].keys()): # under the assumption that only non-technology cells have "src" attr.
            if not (cell_prop["type"] in list_of_lib_cells):
                cell_definition_file = re.sub("['.~:\[\]!@#$%^&*\\\+=-]", "_", cell_prop["type"])
                include_lib += f'#include "{cell_definition_file}.h"' + "\n"

        return include_lib

    # @def: define sc_core namespace
    def namespace_decl(self):
        namespace_decl = "using namespace sc_core;"
        return namespace_decl


    def net_declartion(self):
        """ 
        @def: create a dictionary of nets (excluding ports) and their corresponding integer number
                if net has a valid name, use it. if not, assign an arbitrary name
            input: -
            output: dictionary of nets (as key) and list of their correspondence net_number (as value)
        """
        i = 0
        net_dict = dict()

        # if it's not a port choose a name
        for net_name, net_prop in self.top_module["netnames"].items():
            # check if name is auto generated, if so, assign new name "S##"
                                # if (net_prop["hide_name"]):
                                #     if (len(net_prop["bits"]) == 1):
                                #         net_name = f'S{str(i)}'
                                #         # append net name and corresponding number (net value)
                                #         net_dict.update({net_name: [net_prop["bits"][0]]})
                                #     elif (len(net_prop["bits"]) > 1):
                                #         for j in range(len(net_prop["bits"])):
                                #             net_name = f'S{str(i)}[{j}]'
                                #             # append net name and corresponding number (net value)
                                #             net_dict.update({net_name: [net_prop["bits"][j]]})
                                # elif not (net_name in self.ports_list): # if it's not auto generated, keep the name but remove symbols "[,],."
                                #     if (len(net_prop["bits"]) == 1):
                                #         net_name = net_name.replace("[", "_")
                                #         net_name = net_name.replace("]", "")
                                #         net_name = net_name.replace(".", "_")
                                #         # append net name and corresponding number (net value)
                                #         net_dict.update({net_name: [net_prop["bits"][0]]})
                                #     elif (len(net_prop["bits"]) > 1):
                                #         for j in range(len(net_prop["bits"])):
                                #             net_name = net_name.replace("[", "_")
                                #             net_name = net_name.replace("]", "")
                                #             net_name = net_name.replace(".", "_")
                                #             net_name = f'{net_name}[{j}]'
                                #             # append net name and corresponding number (net value)
                                #             net_dict.update({net_name: [net_prop["bits"][j]]})
            if (net_prop["hide_name"]):
                net_name = f'S{str(i)}'
            elif not (net_name in self.ports_list):
                # replace all the symbol '.~!@#$%^&*\\\+=- in name and type with "_"
                net_name = re.sub("['.~:\[\]!@#$%^&*\\\+=-]", "_", net_name)

            i += 1

            # if net is multi-bits, create a list of corresponding bits
            # lis = list()
            # for bit in net_prop["bits"]:
            #     lis.append(bit)
            
            # append net name and corresponding number (net value)
            net_dict.update({net_name: net_prop["bits"]})
        
        return net_dict

    def gate_indexing(self, cell_type):
        """
        @def: based on whether gate names are compatible with yosys/qflow generate index
            if yosys is the target, just increment a predefined index by 1 (don't consider the gate type)
            if qflow is the target, increment based on gate type (each type is incremented separately)
            cell_type: type of input gate
            output: index"""
        i = 0
        if(self.yosys_qflow_compatible):
            if(self.gate_index.get("cell_type") == None): # if it's the first of a kind, add to dictionary
                self.gate_index["cell_type"] = 1
            else: # if already exist in dictionary, increment by one
                self.gate_index["cell_type"] = self.gate_index["cell_type"] + 1
            i = self.gate_index["cell_type"]
        else:
            if(self.gate_index.get(cell_type) == None):
                self.gate_index[cell_type] = 1
            else:
                self.gate_index[cell_type] = self.gate_index[cell_type] + 1
            i = self.gate_index[cell_type]
        
        return i

    # TODO: add method
    """ @def: 
        number_of_DFF; helper function to find number of DFFs in design """

    def find_net(self, net_number):
        """ @def: find actual net name using net integer value
            input: net integer value
            output: net name """
        
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

    def port_declaration(self):
        """
        @def: declare ports
        """

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

    def signal_declartion(self):
        """
        @def: declare signals
            input: net integer value
            output: net name
        """

        signal_declartion = ""

        signal_declartion += self.sc_logic_signals()[0] + "\n"

        for key, values in self.net_dict.items():
            if not (key in self.ports_list):
                if len(values) == 1:
                    signal_declartion += WHITE_SPACE 
                    signal_declartion += f'sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> {key} = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("{key}");' + "\n"
                else:
                    signal_declartion += WHITE_SPACE 
                    signal_declartion += f'sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> {key}[{str(len(values))}];' + "\n"
        return signal_declartion
    

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

    def get_each_cell(self, cell_name, cell, index):
        """
            @def: retrieve cell parameters for each cell and pass it to cells_declaration()
              input: 
                  cell: dictionary of cell {hide_name, type, parameters, attributes, connections}
                  index: an index to name and address cells with (get appended at the end of cell name)
              output: two separate string to append at different location module decelaration
                  instance_pointer: create a pointer to gate type
                  cell_instantiation: instantiation of cells inside constructor"""
        
        # retrieve cell type, parameters and connection as a dictionary
        cell_type = re.sub("['.~:\[\]!@#$%^&*\\\+=-]", "_", cell["type"])
        # cell_type = re.sub("['.~:\[\]!@#$%^&*\\\+=-]", "_", cell_name)
        cell_parameter = cell["parameters"]
        cell_connections = cell["connections"]
        # cell_port_direction = cell["port_directions"]

        instance_pointer = ""
        cell_instantiation = ""

        if (cell["hide_name"]):
            instatnce_name = cell_type + "_" + str(index)
        else:
            instatnce_name = re.sub("['.~:\[\]!@#$%^&*\\\+=-]", "_", cell_name)

        # start string
        instance_pointer = WHITE_SPACE + cell_type + "* " + instatnce_name + ";\n"
 
        cell_instantiation = WHITE_SPACE + instatnce_name + " = new " + cell_type + '("' + instatnce_name + '");\n'
        
        # add new key to gate_signal dictionary
        self.gate_signal_dict.update({f'{self.module_name}_{instatnce_name}':[]})

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
                self.gate_signal_dict[f'{self.module_name}_{instatnce_name}'].append({con_name: self.find_net(con_value[0])})
                    
            else: # if net is multi-bit, slice the port loop through each bit
                i = 0
                for connection in con_value:
                    cell_instantiation += WHITE_SPACE + WHITE_SPACE
                    cell_instantiation += instatnce_name + "->" + con_name + "[" + str(i) + "]" + "(" + self.find_net(connection) + ");\n"
                    i += 1

                    # if( cell_port_direction[con_name] == "output" ):
                    #     self.gate_signal_dict[instatnce_name].insert(0, {con_name: self.find_net(connection)})
                    # else:
                    self.gate_signal_dict[f'{self.module_name}_{instatnce_name}'].append({con_name: self.find_net(connection)})
                        
                    
        return instance_pointer, cell_instantiation


    def cells_declaration(self):
        """
        @def: instance all the required modules, define pointers outside constructor and port binding inside
        """
        instance_pointer = ""
        cell_instantiation = ""
        i = 0
        
        for cell_name, cell_prop in self.top_module["cells"].items():
            i = self.gate_indexing(cell_prop["type"])
            instance_pointer_temp, cell_instantiation_temp = self.get_each_cell(cell_name, cell_prop, i)
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

    def dump_gate_signal_dict(self):
        return self.gate_signal_dict


    # @def: concatinate pieces and output final systemc module
    def generate_systemc(self):

        self.sc_module += self.includes() + "\n"
        self.sc_module += "\n"
        self.sc_module += f'#ifndef __{self.module_name.upper()}_H__' + "\n"
        self.sc_module += f'#define __{self.module_name.upper()}_H__' + "\n"
        self.sc_module += self.namespace_decl() + "\n"
        self.sc_module += "\n"
        self.sc_module += self.module_declaration() + "\n"
        self.sc_module += f'#endif /* __{self.module_name.upper()}_H__ */' + "\n"

        # self.dump_gate_signal_dict()

        return self.sc_module
    


  
    # # @def: 
    # #   number_of_DFF; helper function to find number of DFFs in design
    # def number_of_DFF(self):
    #     cells_dic = self.top_module["cells"]
    #     numb_DFF = 0

    #     for cell in cells_dic.values():
    #         if ((cell["type"].find("DFF") > -1) or (cell["type"].find("dff") > -1)):
    #             numb_DFF = numb_DFF + 1

    #     return numb_DFF
   
    # # @def: find actual net name using net integer value
    # #   input: net integer value
    # #   output: net name
    # def find_net(self, net_number):
    #     # is net_number string
    #     # some net are set to constant string 1/0 
    #     if not (isinstance(net_number, str)):
    #         for key, values in self.net_dict.items():
    #             if len(values) == 1:
    #                 if (values[0] == net_number):
    #                     return key
    #             else:
    #                 for value in values:
    #                     if (value == net_number):
    #                         return key + "[" + str(values.index(value)) + "]"
    #     else:
    #         return "sc_logic_" + net_number + "_signal"
 
    # # @def: define sc_logic_signals to be use for port binding
    # #   @output: a list of three string
    # #       sc_logic_signal_declr: that goes to signal_declartion()
    # #       sc_logic_method_declr: that goes to constructor_declaration()
    # #       sc_logic_function_declr: that goes to module_declaration()
    # def sc_logic_signals(self):
    #     sc_logic_signal_declr = ""
    #     sc_logic_method_declr = ""
    #     sc_logic_function_declr = ""

    #     # singals that provide SC_LOGIC_(0/1) for port binding process
    #     sc_logic_signal_declr += WHITE_SPACE 
    #     sc_logic_signal_declr += "sc_signal<sc_logic> sc_logic_1_signal;\n"
    #     sc_logic_signal_declr += WHITE_SPACE 
    #     sc_logic_signal_declr += "sc_signal<sc_logic> sc_logic_0_signal;\n"

    #     sc_logic_method_declr += WHITE_SPACE + f'SC_METHOD(sc_logic_signal_assignment);\n'
        
    #     sc_logic_function_declr += WHITE_SPACE + "void sc_logic_signal_assignment(void){ \n"
    #     sc_logic_function_declr += WHITE_SPACE + WHITE_SPACE + "sc_logic_1_signal.write(SC_LOGIC_1);\n"
    #     sc_logic_function_declr += WHITE_SPACE + WHITE_SPACE + "sc_logic_0_signal.write(SC_LOGIC_0);\n"
    #     sc_logic_function_declr += WHITE_SPACE + "}\n"
        
    #     return sc_logic_signal_declr, sc_logic_method_declr, sc_logic_function_declr

    # # @def: declare ports
    # def port_declaration(self):

    #     port_declaration = ""

    #     for port_name, port_prop in self.top_module["ports"].items():
    #         port_declaration += WHITE_SPACE 

    #         if port_prop["direction"] == "input":
    #             if len(port_prop["bits"]) == 1:
    #                 port_declaration += f'sc_in<sc_logic> {port_name};\n'
    #             else:
    #                 port_declaration += f'sc_in<sc_logic> {port_name}[{str(len(port_prop["bits"]))}];\n'
                
    #         elif port_prop["direction"] == "output":
    #             if len(port_prop["bits"]) == 1:
    #                 port_declaration += f'sc_out<sc_logic> {port_name};\n'
    #             else:
    #                 port_declaration += f'sc_out<sc_logic> {port_name}[{str(len(port_prop["bits"]))}];\n'
                
    #     return port_declaration

    # # @def: find actual net name using net integer value
    # #   input: net integer value
    # #   output: net name
    # def signal_declartion(self):

    #     signal_declartion = ""

    #     signal_declartion += self.sc_logic_signals()[0] + "\n"

    #     for net in self.net_dict:
    #         if not (net in self.ports_list):
    #             signal_declartion += WHITE_SPACE 
    #             signal_declartion += f'sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> {net} = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("{net}");' + "\n"

    #     return signal_declartion
  
    # # @def: retrieve cell parameters for each cell and pass it to cells_declaration()
    # #   input: 
    # #       cell: dictionary of cell {hide_name, type, parameters, attributes, connections}
    # #       index: an index to name and address cells with (get appended at the end of cell name)
    # #   output: two separate string to append at different location module decelaration
    # #       instance_pointer: create a pointer to gate type
    # #       cell_instantiation: instantiation of cells inside constructor
    # def get_each_cell(self, cell, index):
    #     # retrieve cell type, parameters and connection as a dictionary
    #     cell_type = cell["type"]
    #     cell_parameter = cell["parameters"]
    #     cell_connections = cell["connections"]
    #     # cell_port_direction = cell["port_directions"]

    #     instance_pointer = ""
    #     cell_instantiation = ""

    #     instatnce_name = cell_type + "_" + str(index)
    #     # start string
    #     instance_pointer = WHITE_SPACE + cell_type + "* " + instatnce_name + ";\n"
 
    #     cell_instantiation = WHITE_SPACE + instatnce_name + " = new " + cell_type + '("' + instatnce_name + '");\n'
        
    #     # add new key to gate_signal dictionary
    #     self.gate_signal_dict.update({instatnce_name:[]})

    #     # port mapping 
    #     # loop through each connection, get corresponding net-name
    #     for con_name, con_value in cell_connections.items():
    #         # is port multi-bit
    #         if (len(con_value) == 1):
    #             cell_instantiation += WHITE_SPACE + WHITE_SPACE
    #             cell_instantiation += instatnce_name + "->" + con_name + "(" + self.find_net(con_value[0]) + ");\n"
                
    #             # first element *can be* be output (change association to by-name), so the order is not that important
    #             # if( cell_port_direction[con_name] == "output" ):
    #             #     self.gate_signal_dict[instatnce_name].insert(0, {con_name: self.find_net(con_value[0])})
    #             # else:
    #             self.gate_signal_dict[instatnce_name].append({con_name: self.find_net(con_value[0])})
                    
    #         else: # if net is multi-bit, slice the port loop through each bit
    #             i = 0
    #             for connection in con_value:
    #                 cell_instantiation += WHITE_SPACE + WHITE_SPACE
    #                 cell_instantiation += instatnce_name + "->" + con_name + "[" + str(i) + "]" + "(" + self.find_net(connection) + ");\n"
    #                 i += 1

    #                 # if( cell_port_direction[con_name] == "output" ):
    #                 #     self.gate_signal_dict[instatnce_name].insert(0, {con_name: self.find_net(connection)})
    #                 # else:
    #                 self.gate_signal_dict[instatnce_name].append({con_name: self.find_net(connection)})
                        
                    
    #     return instance_pointer, cell_instantiation


    # # @def: instance all the required modules, define pointers outside constructor and port binding inside
    # def cells_declaration(self):
    #     instance_pointer = ""
    #     cell_instantiation = ""
    #     i = 0
        
        
    #     for cell_name, cell_prop in self.top_module["cells"].items():
    #         i = self.gate_indexing(cell_prop["type"])
    #         instance_pointer_temp, cell_instantiation_temp = self.get_each_cell(cell_prop, i)
    #         instance_pointer += instance_pointer_temp
    #         cell_instantiation += cell_instantiation_temp + "\n"

    #     return instance_pointer, cell_instantiation

    # # @def: declare module signature 
    # def constructor_declaration(self, cell_in_constructor_declaration):
    #     constructor_declaration = ""
    #     constructor_declaration += f'SC_CTOR( {self.module_name} ) ' + '{\n'
        
    #     # add cell instantiation and binding
    #     constructor_declaration += cell_in_constructor_declaration + "\n"
        
    #     # add sc_module for sc_logic_signals
    #     constructor_declaration += self.sc_logic_signals()[1] + "\n"

    #     constructor_declaration += WHITE_SPACE + "}\n"

    #     return constructor_declaration

    # # @def: declare module signature 
    # def module_declaration(self):
    #     # cell instantiation must get called only one time
    #     cell_pointer_instantiation, cell_in_constructor_declaration = self.cells_declaration()

    #     entity_declaration = ""
    #     entity_declaration += f'SC_MODULE( {self.module_name} ) ' + '{\n'
        
    #     entity_declaration += "\n"
    #     entity_declaration += self.port_declaration()
    #     entity_declaration += "\n"
    #     entity_declaration += self.signal_declartion()
    #     entity_declaration += "\n"
    #     entity_declaration += cell_pointer_instantiation
    #     entity_declaration += "\n"
    #     entity_declaration += self.constructor_declaration(cell_in_constructor_declaration)
    #     entity_declaration += "\n"
    #     entity_declaration += self.sc_logic_signals()[2]

    #     entity_declaration += "};"
    #     return entity_declaration

