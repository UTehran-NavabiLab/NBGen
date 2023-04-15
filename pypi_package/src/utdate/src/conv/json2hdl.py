from json import load
from os import path
from utdate.src.technology_reader import Technology_file
from utdate.src.utility_functions import find_clk_rst_netNumber, find_clk_rst_name
import utdate.lib as lib

# assumptions: 
#   1. It's a flattend netlist which contains only one module as a top module
#   2. Numeric parameter and attribute values up are equ/less than 32 bits and are written as decimal
#       values.
#   
#   TODO: 
#       -  assumption 1. should change to a more general case where each module is converted through some
#                   sort of loop
#       - port declaration must support for multi-bit ports  
#       - add support for extra library as an input 


class json2hdl:
    def __init__(self, json_file, config_json, technology_parameters) -> None:
        with open(json_file, "r") as f:
            self.js = load(f)

        self.config_js = config_json
        self.module_name = ""

        for module_name, module in self.js["modules"].items():
            if "attributes" in module:
                if "top" in module["attributes"]:
                    if int(module["attributes"]["top"]) == 1:
                        self.module_name = module_name
        
        if self.module_name == "":
            try: 
                self.module_name = self.config_js["module_name"]
            except KeyError:
                self.module_name = list(self.js["modules"])[0]
        
        # read thenology file
        self.technology_parameter = technology_parameters
        self.gate_index = dict()
        self.yosys_qflow_compatible = False
        self.top_module = self.js["modules"][self.module_name]
        self.ports_list = list(self.top_module["ports"])
        self.net_dict = self.net_declartion()
        self.is_sequential = self.is_sequential_check()
        if self.is_sequential:
            clk_list, rst_list = find_clk_rst_netNumber(self.top_module["cells"], self.technology_parameter)
            self.clk_name, self.rst_name = find_clk_rst_name(self.top_module["ports"], clk_list, rst_list)

    # @def: based on whether gate names are compatible with yosys/qflow generate index
    #       if yosys is the target, just increment a predefined index by 1
    #       if qflow is the target, increment based on gate type
    #   cell_type: type of input gate
    #   output: index
    def gate_indexing(self, cell_type):
        i = 0
        if(self.yosys_qflow_compatible):
            if(self.gate_index.get("cell_type") == None):
                self.gate_index["cell_type"] = 1
            else:
                self.gate_index["cell_type"] = self.gate_index["cell_type"] + 1
            i = self.gate_index["cell_type"]
        else:
            if(self.gate_index.get(cell_type) == None):
                self.gate_index[cell_type] = 1
            else:
                self.gate_index[cell_type] = self.gate_index[cell_type] + 1
            i = self.gate_index[cell_type]
        
        return i

    # @def: 
    #   is_sequential_check ; check whether the circuit is combinational/sequential
    def is_sequential_check(self):
        is_seq = False

        # check whether the design is sequential/combinational (check for existance of dff)
        for cell in self.top_module["cells"].values():
            for dff_name, dff_ports in self.technology_parameter.dict_of_dff.items():
                if (cell["type"].find(dff_name) > -1):
                    is_seq = True

        return is_seq

    # @def: 
    #   size_Of_Ports; helper function to find size of input/output ports
    def size_Of_Ports(self):
        sizePI = 0
        sizePO = 0

        for port in self.top_module["ports"].values():
            if port["direction"] == "input":
                # considering ports can be multi-bit, add length of bits
                sizePI = sizePI + len(port["bits"])
            if port["direction"] == "output":
                sizePO = sizePO + len(port["bits"])

        return sizePI, sizePO
    
    # @def: find actual net name using net integer value
    #   input: -
    #   output: dictionary of nets (as key) and list of their correspondence net_number (as value)
    def net_declartion(self):
        i = 0
        net_dict = dict()
        for net_name, net_prop in self.top_module["netnames"].items():
            # check if name is auto generated, if so, assign new name "S##"
            if (net_prop["hide_name"]):
                # if it's a port choose a name
                # on assumption that all signals are single bit
                net_name = "S" + str(i)
                i += 1
            elif not (net_name in self.ports_list):
                # net_name = "new_" + net_name
                net_name = net_name.replace("[", "_")
                net_name = net_name.replace("]", "")
                net_name = net_name.replace(".", "_")

            # if net is multi-bits, create a list of corresponding bits
            # if (len(net_prop["bits"])):
            lis = list()
            for bit in net_prop["bits"]:
                lis.append(bit)
            
            # append net name and corresponding number (net value)
            net_dict.update({net_name: lis})
        
        return net_dict

    # @def: find actual net name using net integer value
    #   input: net integer value
    #   output: net name
    def cells_declaration(self):
        cells_declaration = ""
        i = 0
        
        for cell_name, cell_prop in self.top_module["cells"].items():
            i = self.gate_indexing(cell_prop["type"])
            cells_declaration += self.get_each_cell(cell_prop, i) + "\n"
            # i += 1
        return cells_declaration
    
    # @def: find actual net name using net integer value
    #   input: net integer value
    #   output: net name
    def find_net(self, net_number):
        # is net_number string
        # some net are set to constant string 1/0 
        if not (isinstance(net_number, str)):
            for key, values in self.net_dict.items():
                for value in values:
                    if (value == net_number):
                        return key
        else:
            return net_number 
