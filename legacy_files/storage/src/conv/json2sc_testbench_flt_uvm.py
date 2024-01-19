from utdate.src.conv.json2systemc import json2systemc

# see if it's multi-bit port
# TODO: check if module name is also used for any other property
#   if so change module name, since it raise an error in systemc

WHITE_SPACE = "    "

class json2sc_testbench_flt_uvm(json2systemc):
    def __init__(self, json_file, config_json, technology_parameter, testbench, instance) -> None:
        json2systemc.__init__(self, json_file, config_json, technology_parameter)
        self.testbench_name = testbench
        self.instance_name = instance

    # @def: add standard library library  
    def includes(self):

        include_lib =  '#include <systemc>' + "\n"
        include_lib += '#include <uvm>' + "\n"
        include_lib += '#include "vip/fi.h"' + "\n"
        include_lib += '#include "vip/fi_signal_if.h"' + "\n"
        include_lib += '#include "test_lib.h" ' + "\n"
        include_lib += '#include "reg/ut_fault_registry.h"' + "\n"
        
        # design specific include files
        include_lib += '#include "systemC_netlist.h"' + "\n"
        return include_lib


    # @def: instance all the required modules, define pointers outside constructor and port binding inside
    def cells_declaration(self):

        instance_pointer = ""
        cell_instantiation = ""

        instatnce_name = self.instance_name
        golden_instatnce_name = self.instance_name + "_ref"
        faulty_instatnce_name = self.instance_name
        
        # pointer to faulty module under test
        instance_pointer += WHITE_SPACE + self.module_name + "* " + faulty_instatnce_name + ";\n"
        # pointer to golden module under test
        instance_pointer += WHITE_SPACE + self.module_name + "* " + golden_instatnce_name + ";\n"
        # pointer to signal interface
        instance_pointer += WHITE_SPACE + "fi_signal_if* vif;\n"
        # pointer to faultRegistry
        instance_pointer += WHITE_SPACE + "ut_fault_registry* flt_reg;\n"

 
        # normally there are three module that must be declared [faultRegitry, golden & faulty model]
        for p in range(3):
            if (p == 0): # faulty design
                cell_instantiation += WHITE_SPACE + WHITE_SPACE + f'// Instantiate the DUT and bind ports to interface\n'
                cell_instantiation += WHITE_SPACE + WHITE_SPACE + f'{faulty_instatnce_name} = new {self.module_name}("{faulty_instatnce_name}");\n'
            elif(p == 1): # reference design
                cell_instantiation += WHITE_SPACE + WHITE_SPACE + f'// Instantiate the DUT and bind ports to interface\n'
                cell_instantiation += WHITE_SPACE + WHITE_SPACE + f'{golden_instatnce_name} = new {self.module_name}("{golden_instatnce_name}");\n'
            elif(p == 2): # fault Registry module
                cell_instantiation += WHITE_SPACE + WHITE_SPACE + f'// creating fault registration module\n'
                cell_instantiation += WHITE_SPACE + WHITE_SPACE + f'flt_reg = new ut_fault_registry();\n'
                for net in self.net_dict:
                    if not (net in self.ports_list):
                        cell_instantiation += WHITE_SPACE + WHITE_SPACE + WHITE_SPACE
                        cell_instantiation += f'flt_reg->add_object({faulty_instatnce_name}->{net});' + "\n"


            # port mapping 
            # loop through each connection, get corresponding net-name            
            for port_name, port_prop in self.top_module["ports"].items():
                if port_prop["direction"] == "input":
                    # is port single-bit
                    if len(port_prop["bits"]) == 1:
                        cell_instantiation += WHITE_SPACE + WHITE_SPACE + WHITE_SPACE
                        if (p == 0): # faulty design
                            cell_instantiation += f'{faulty_instatnce_name}->{port_name}.bind(vif->add_and_bind("{port_name}"));\n'
                        elif(p == 1): # reference design
                            cell_instantiation += f'{golden_instatnce_name}->{port_name}.bind(vif->get_signal("{port_name}"));\n'
                        # elif(p == 2): # fault Registry module
                            # cell_instantiation += f'flt_reg->add_object(vif->get_signal("{port_name}"));\n'
                    else: # if port is multi-bit, slice the port loop through each bit
                        for i in range(len(port_prop["bits"])):
                            cell_instantiation += WHITE_SPACE + WHITE_SPACE + WHITE_SPACE
                            if (p == 0): # faulty design
                                cell_instantiation += f'{faulty_instatnce_name}->{port_name}[{i}].bind(vif->add_and_bind("{port_name}[{i}]"));\n'
                            elif(p == 1): # reference design
                                cell_instantiation += f'{golden_instatnce_name}->{port_name}[{i}].bind(vif->get_signal("{port_name}[{i}]"));\n'
                            # elif(p == 2): # fault Registry module
                                # cell_instantiation += f'flt_reg->add_object(vif->get_signal("{port_name}[{i}]"));\n'
                        
                if port_prop["direction"] == "output":
                    # is port single-bit
                    if len(port_prop["bits"]) == 1:
                        cell_instantiation += WHITE_SPACE + WHITE_SPACE + WHITE_SPACE
                        if (p == 0): # faulty design
                            cell_instantiation += f'{faulty_instatnce_name}->{port_name}.bind(vif->add_and_bind("{port_name}_mod"));\n'
                        elif(p == 1): # reference design
                            cell_instantiation += f'{golden_instatnce_name}->{port_name}.bind(vif->add_and_bind("{port_name}_ref"));\n'
                    else: # if port is multi-bit, slice the port loop through each bit
                        for i in range(len(port_prop["bits"])):
                            cell_instantiation += WHITE_SPACE + WHITE_SPACE + WHITE_SPACE
                            if (p == 0): # faulty design
                                cell_instantiation += f'{faulty_instatnce_name}->{port_name}[{i}].bind(vif->add_and_bind("{port_name}[{i}]_mod"));\n'
                            elif(p == 1): # reference design
                                cell_instantiation += f'{golden_instatnce_name}->{port_name}[{i}].bind(vif->add_and_bind("{port_name}[{i}]_ref"));\n'

        return instance_pointer, cell_instantiation

    def group_signals(self):
        group_signals_ = ""

        group_signals_ += WHITE_SPACE + WHITE_SPACE + "// group signals into two \n"

        # port mapping 
        # loop through each connection, get corresponding net-name            
        for port_name, port_prop in self.top_module["ports"].items():
            if port_prop["direction"] == "input":
                # is port single-bit
                if len(port_prop["bits"]) == 1:
                    group_signals_ += WHITE_SPACE + WHITE_SPACE
                    group_signals_ += f'vif->set_as_stimulated("{port_name}");\n'
                else: # if port is multi-bit, slice the port loop through each bit
                    for i in range(len(port_prop["bits"])):
                        group_signals_ += WHITE_SPACE + WHITE_SPACE
                        group_signals_ += f'vif->set_as_stimulated("{port_name}[{i}]");\n'
            
            if port_prop["direction"] == "output":
                # is port single-bit
                if len(port_prop["bits"]) == 1:
                    group_signals_ += WHITE_SPACE + WHITE_SPACE
                    group_signals_ += f'vif->set_as_observable_mod("{port_name}_mod");\n'
                    group_signals_ += WHITE_SPACE + WHITE_SPACE
                    group_signals_ += f'vif->set_as_observable_ref("{port_name}_ref");\n'
                else: # if port is multi-bit, slice the port loop through each bit
                    for i in range(len(port_prop["bits"])):
                        group_signals_ += WHITE_SPACE + WHITE_SPACE
                        group_signals_ += f'vif->set_as_observable_mod("{port_name}[{i}]_mod");\n'
                        group_signals_ += WHITE_SPACE + WHITE_SPACE
                        group_signals_ += f'vif->set_as_observable_ref("{port_name}[{i}]_ref");\n'

        return group_signals_


    # @def: declare module signature 
    def constructor_declaration(self, cell_instantiation):
        constructor_declaration = ""
        
        # boilerplate codes
        constructor_declaration += WHITE_SPACE + f'SC_HAS_PROCESS(testbench);\n'
        constructor_declaration += WHITE_SPACE + f'testbench(sc_module_name _name)' + "{\n"
        
        constructor_declaration += WHITE_SPACE + WHITE_SPACE + '// Interface instantiation\n'
        constructor_declaration += WHITE_SPACE + WHITE_SPACE + 'vif = new fi_signal_if("vif");\n'
        constructor_declaration += WHITE_SPACE + WHITE_SPACE + '  assert(vif);\n'
        constructor_declaration += WHITE_SPACE + WHITE_SPACE + '// call function to read from file\n'
        constructor_declaration += WHITE_SPACE + WHITE_SPACE + 'std::string input_vector_file = "test_vector.vec";\n'
        constructor_declaration += WHITE_SPACE + WHITE_SPACE + '// add streams of file to resource database\n'
        constructor_declaration += WHITE_SPACE + WHITE_SPACE + '// uvm::uvm_resource_db<std::string>::set("*", "input_vector_file", input_vector_file, this);\n'
        constructor_declaration += WHITE_SPACE + WHITE_SPACE + 'uvm::uvm_config_db<std::string>::set(uvm::uvm_root::get(), "*", "input_vector_file", input_vector_file);\n'
        constructor_declaration += WHITE_SPACE + WHITE_SPACE + '// Add interface to configuration database\n'
        constructor_declaration += WHITE_SPACE + WHITE_SPACE + 'uvm::uvm_config_db<fi_signal_if*>::set(uvm::uvm_root::get(), "*", "vif", vif);\n'
       
        # add cell instantiation and binding
        constructor_declaration += cell_instantiation + "\n"
        
        constructor_declaration += self.group_signals() + "\n"

        constructor_declaration += WHITE_SPACE + WHITE_SPACE + '// Add interface to configuration database\n'
        constructor_declaration += WHITE_SPACE + WHITE_SPACE + 'uvm::uvm_config_db<ut_fault_registry*>::set(\n'
        constructor_declaration += WHITE_SPACE + WHITE_SPACE + '  uvm::uvm_root::get(), "*", "flt_reg", flt_reg);\n'

        constructor_declaration += WHITE_SPACE + "}\n"

        return constructor_declaration

    # @def: declare module signature 
    def module_declaration(self):
        entity_declaration = ""
        
        instance_pointer, cell_instantiation = self.cells_declaration()
        
        entity_declaration += f'SC_MODULE( testbench ) ' + '{\n'
        
        entity_declaration += "\n"
        entity_declaration += instance_pointer
        entity_declaration += "\n"
        entity_declaration += self.constructor_declaration(cell_instantiation)

        entity_declaration += "};"
        return entity_declaration


