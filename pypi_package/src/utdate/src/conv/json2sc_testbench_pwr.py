from utdate.src.conv.json2sc_testbench import json2sc_testbench

# see if it's multi-bit port
# TODO: check if module name is also used for any other property
#   if so change module name, since it raise an error in systemc

WHITE_SPACE = "    "

class json2sc_testbench_pwr(json2sc_testbench):
    def __init__(self, json_file, tech_json, testbench, instance) -> None:
        json2sc_testbench.__init__(self, json_file, tech_json, testbench, instance)

    # @def: add standard library library  
    def includes(self):
        include_lib = '#include <iostream>' + "\n"
        include_lib += '#include <fstream>' + "\n"
        include_lib += '#include <string>' + "\n"
        include_lib += '#include <vector>' + "\n"
        include_lib += '#include <map>' + "\n"
        include_lib += '#include <math.h>' + "\n"
        include_lib += '#include "systemc.h"' + "\n"
        include_lib += '#include "power_netlist.h"' + "\n"
        include_lib += '#include "utilities.h"' + "\n"
        include_lib += '#include "power_analysis.h"' + "\n"

        return include_lib

    # @def: find actual net name using net integer value
    #   input: net integer value
    #   output: net name
    def signal_declartion(self):

        signal_declaration = ""

        for port_name, port_prop in self.top_module["ports"].items():
            signal_declaration += WHITE_SPACE 

            # check whether port is single bit
            if len(port_prop["bits"]) == 1:
                signal_declaration += f'sc_signal_pw<sc_logic> {port_name} = sc_signal_pw<sc_logic>("{port_name}");\n'
            else:
                signal_declaration += f'sc_signal_pw<sc_logic> {port_name}[{str(len(port_prop["bits"]))}] = sc_signal_pw<sc_logic>("{port_name}");\n'

        # define sc_event
        signal_declaration += WHITE_SPACE + f'sc_event ready2update;' + '\n'
        signal_declaration += WHITE_SPACE + f'sc_event ready2reset;' + '\n'
        
        return signal_declaration
  
    # @def: declare sc_event
    def event_declartion(self):

        event_declaration = ""

        # define sc_event
        event_declaration += WHITE_SPACE + f'sc_event ready2update;' + '\n'
        event_declaration += WHITE_SPACE + f'sc_event ready2reset;' + '\n'

        return event_declaration
  

    # @def: instance all the required modules, define pointers outside constructor and port binding inside
    def cells_declaration(self):

        instance_pointer = ""
        cell_instantiation = ""

        instatnce_name = self.instance_name
        
        # pointer to faulty module under test
        instance_pointer = WHITE_SPACE + self.module_name + "* " + instatnce_name + ";\n"
        # pointer to power module
        instance_pointer += WHITE_SPACE + "power_analysis* power_module;\n"
        instance_pointer += WHITE_SPACE + f'std::array<sc_signal_pw<sc_logic>*, {len(self.net_dict)}> signal_arr;\n'
        instance_pointer += WHITE_SPACE + f'std::array<sc_signal_pw<sc_logic>*, {self.size_Of_Ports()[0]}> input_arr;\n'
        
 
        cell_instantiation = WHITE_SPACE + WHITE_SPACE + f'power_module = new power_analysis();' + '\n'
        cell_instantiation += WHITE_SPACE + WHITE_SPACE + WHITE_SPACE + f'power_module->read_gate_prop_json("{self.tech_js["systemC_gate_properties_json"]}");' + '\n'
        cell_instantiation += WHITE_SPACE + WHITE_SPACE + WHITE_SPACE + f'power_module->read_gate_signal_json("{self.tech_js["systemC_gate_signal_json"]}", "{self.tech_js["systemC_gate_properties_json"]}");' + '\n'
        cell_instantiation += WHITE_SPACE + WHITE_SPACE + WHITE_SPACE + f'power_module->tech_parameter_json("{self.tech_js["systemC_tech_timing_power"]}");' + '\n'
        cell_instantiation += WHITE_SPACE + WHITE_SPACE + WHITE_SPACE + f'power_module->read_net_cap_json("{self.tech_js["systemC_gate_capacitance"]}");' + '\n'

        cell_instantiation += WHITE_SPACE + WHITE_SPACE + f'{instatnce_name} = new {self.module_name}("{instatnce_name}");\n'

        # port mapping 
        # loop through each connection, get corresponding net-name            
        for port_name, port_prop in self.top_module["ports"].items():
            # is port single-bit
            if len(port_prop["bits"]) == 1:
                cell_instantiation += WHITE_SPACE + WHITE_SPACE + WHITE_SPACE
                cell_instantiation += f'{instatnce_name}->{port_name}({port_name});\n'
            else: # if port is multi-bit, slice the port loop through each bit
                for i in range(len(port_prop["bits"])):
                    cell_instantiation += WHITE_SPACE + WHITE_SPACE + WHITE_SPACE
                    cell_instantiation += f'{instatnce_name}->{port_name}[{i}]({port_name}[{i}]);\n'

        return instance_pointer, cell_instantiation

    def access_signal_thread(self):
        access_signal_proc = ""
        SC_THREAD_definition = WHITE_SPACE + WHITE_SPACE + f'access_signals();\n'
        
        access_signal_proc += WHITE_SPACE + f'void access_signals(void)'+ '{\n'
        i = 0
        for port_name, port_prop in self.top_module["ports"].items():
            if len(port_prop["bits"]) == 1:
                access_signal_proc += WHITE_SPACE + WHITE_SPACE + f'signal_arr[{i}] = &({port_name});' + '\n'
                if port_prop["direction"] == "input":
                    access_signal_proc += WHITE_SPACE + WHITE_SPACE + f'input_arr[{i}] = &({port_name});' + '\n'
                    access_signal_proc += WHITE_SPACE + WHITE_SPACE + f'power_module->set_transition_time("{port_name}", 0.0);' + '\n'
                i += 1
            else: # if port is multi-bit, slice the port loop through each bit
                for j in range(len(port_prop["bits"])):
                    access_signal_proc += WHITE_SPACE + WHITE_SPACE + f'signal_arr[{i}] = &({port_name}[{str(j)}]);' + '\n'
                    if port_prop["direction"] == "input":
                        access_signal_proc += WHITE_SPACE + WHITE_SPACE + f'input_arr[{i}] = &({port_name}[{str(j)}]);' + '\n'
                        access_signal_proc += WHITE_SPACE + WHITE_SPACE + f'power_module->set_transition_time("{port_name}[{str(j)}]", 0.0);' + '\n'
                    i += 1
        for net in self.net_dict:
            if not (net in self.ports_list):
                access_signal_proc += WHITE_SPACE + WHITE_SPACE + f'signal_arr[{i}] = &({self.instance_name}->{net});' + '\n'
            i += 1

        access_signal_proc += WHITE_SPACE + '}\n'

        return SC_THREAD_definition, access_signal_proc

    def reset_toggling_thread(self):
        reset_toggling_proc = ""

        reset_toggling_proc += WHITE_SPACE + f'void reset_togglings(void)' + '{\n'
        reset_toggling_proc += WHITE_SPACE + WHITE_SPACE + f'for(auto& signal_pointer: signal_arr)' + '{\n'
        reset_toggling_proc += WHITE_SPACE + WHITE_SPACE + WHITE_SPACE + f'signal_pointer->reset_toggling();' + '\n'
        reset_toggling_proc += WHITE_SPACE + WHITE_SPACE + WHITE_SPACE + '}\n'
        reset_toggling_proc += WHITE_SPACE + '}\n'

        return reset_toggling_proc

    def signaling_thread(self):
        signaling_proc = ""

        SC_THREAD_definition = WHITE_SPACE + WHITE_SPACE + f'SC_THREAD(signaling);\n'

        signaling_proc += WHITE_SPACE + f'void signaling(void)' + '{\n'
        signaling_proc += WHITE_SPACE + WHITE_SPACE + f'wait(SC_ZERO_TIME);' + '\n'
        signaling_proc += WHITE_SPACE + WHITE_SPACE + f'reset_togglings();' + '\n'
        signaling_proc += WHITE_SPACE + WHITE_SPACE + f'wait(10, SC_NS);' + '\n'

        input_vec = ""
        for j in range(self.size_Of_Ports()[0]):
            input_vec += '1'
        signaling_proc += WHITE_SPACE + WHITE_SPACE + f'apply_input_vector<sc_dt::sc_logic, {self.size_Of_Ports()[0]}>(input_arr, ("{input_vec}"));' + '\n'
        # for port_name, port_prop in self.top_module["ports"].items():
        #     if port_prop["direction"] == "input":
        #         signaling_proc += WHITE_SPACE  + WHITE_SPACE
        #         if len(port_prop["bits"]) == 1:
        #             signaling_proc += f'{port_name}.write(SC_LOGIC_1);\n'
        #         else:
        #             for i in range(len(port_prop["bits"])):
        #                 signaling_proc += f'{port_name}[{str(i)}].write(SC_LOGIC_1);\n'
        
        signaling_proc += WHITE_SPACE + WHITE_SPACE + f'wait(SC_ZERO_TIME);' + '\n'
        signaling_proc += WHITE_SPACE + WHITE_SPACE + f'wait(10, SC_NS);' + '\n'
        signaling_proc += WHITE_SPACE + WHITE_SPACE + f'ready2update.notify();' + '\n'
        signaling_proc += WHITE_SPACE + '}\n'

        return SC_THREAD_definition, signaling_proc

    def power_per_cycle_thread(self):
        power_on_cycle_proc = ""

        SC_THREAD_definition = WHITE_SPACE + WHITE_SPACE + f'SC_METHOD(power_on_cycle);\n'
        SC_THREAD_definition += WHITE_SPACE + WHITE_SPACE + WHITE_SPACE + f'sensitive << ready2update;\n'
        SC_THREAD_definition += WHITE_SPACE + WHITE_SPACE + WHITE_SPACE + f'dont_initialize();\n'

        power_on_cycle_proc += WHITE_SPACE + f'void power_on_cycle(void)'+ '{\n'
        power_on_cycle_proc += WHITE_SPACE + WHITE_SPACE + f'power_module->update_signal<sc_dt::sc_logic, {len(self.net_dict)}>(signal_arr);' + '\n'
        
        power_on_cycle_proc += WHITE_SPACE + WHITE_SPACE + f'std::vector<std::string> input_signal_name = ' + '{'
        
        for port_name, port_prop in self.top_module["ports"].items():
            if port_prop["direction"] == "input":
                power_on_cycle_proc += f'"{port_name}", '
        power_on_cycle_proc = power_on_cycle_proc[:-2] + '};\n'

        power_on_cycle_proc += WHITE_SPACE + WHITE_SPACE + f'power_module->timing_analysis("test", input_signal_name);' + '\n'
        
        dynamic_power = ""
        net_switching_power = ""

        for cell_name, cell_prop in self.top_module["cells"].items():
            self.gate_indexing(cell_prop["type"])

        for cell_type, cell_type_indx in self.gate_index.items():
            for i in range(1, cell_type_indx + 1):
                power_on_cycle_proc += WHITE_SPACE + WHITE_SPACE + f'std::vector<float> pwr_{cell_type}_{str(i)} = power_module->power_per_gate("{cell_type}_{str(i)}");' + '\n'
                dynamic_power += f'pwr_{cell_type}_{str(i)}[0]' + ' + '
                net_switching_power += f'pwr_{cell_type}_{str(i)}[1]' + ' + '
        
        power_on_cycle_proc += '\n'

        # remove last "+" and add ";"
        dynamic_power = f'float dynamic_power = ' + dynamic_power[:-2] + ';'
        net_switching_power = f'float net_switching_power = ' + net_switching_power[:-2] + ';'
        total_power = f'float total_power = dynamic_power + net_switching_power;'

        power_on_cycle_proc += WHITE_SPACE + WHITE_SPACE + dynamic_power + '\n'
        power_on_cycle_proc += WHITE_SPACE + WHITE_SPACE + net_switching_power + '\n'
        power_on_cycle_proc += WHITE_SPACE + WHITE_SPACE + total_power + '\n'
        power_on_cycle_proc += WHITE_SPACE + WHITE_SPACE + f'std::cout << "net switching power: " << net_switching_power << std::endl;' + '\n'
        power_on_cycle_proc += WHITE_SPACE + WHITE_SPACE + f'std::cout << "dynamic power : " << dynamic_power << std::endl;' + '\n'
        power_on_cycle_proc += WHITE_SPACE + WHITE_SPACE + f'std::cout << "total power per cycle: " << total_power << std::endl;' + '\n'
        power_on_cycle_proc += WHITE_SPACE + WHITE_SPACE + f'reset_togglings();' + '\n'
        power_on_cycle_proc += WHITE_SPACE + '}\n'

        return SC_THREAD_definition, power_on_cycle_proc
        
    def thread_declaration(self):
        SC_THREAD_definition = ""
        processes = ""

        SC_THREAD_definition_tmp, processes_tmp = self.signaling_thread()
        SC_THREAD_definition += SC_THREAD_definition_tmp + '\n'
        processes += processes_tmp + '\n'
        
        SC_THREAD_definition_tmp, processes_tmp = self.power_per_cycle_thread()
        SC_THREAD_definition += SC_THREAD_definition_tmp + '\n'
        processes += processes_tmp + '\n'
        
        processes += self.reset_toggling_thread() + '\n'
        
        SC_THREAD_definition_tmp, processes_tmp = self.access_signal_thread()
        SC_THREAD_definition += SC_THREAD_definition_tmp + '\n'
        processes += processes_tmp + '\n'


        return SC_THREAD_definition, processes


    # @def: declare module signature 
    def constructor_declaration(self, SC_THREAD_definition):
        constructor_declaration = ""
        constructor_declaration += WHITE_SPACE + f'SC_HAS_PROCESS(testbench);\n'
        constructor_declaration += WHITE_SPACE + f'testbench(sc_module_name _name)' + "{\n"
        
        # add cell instantiation and binding
        constructor_declaration += self.cells_declaration()[1] + "\n"
        constructor_declaration += SC_THREAD_definition + "\n"

        constructor_declaration += WHITE_SPACE + "}\n"

        return constructor_declaration

    # @def: declare module signature 
    def module_declaration(self):
        entity_declaration = ""
        SC_THREAD_definition, processes = self.thread_declaration()

        entity_declaration += f'SC_MODULE( testbench ) ' + '{\n'
        entity_declaration += "\n"
        entity_declaration += self.signal_declartion()
        entity_declaration += "\n"
        entity_declaration += self.cells_declaration()[0]
        entity_declaration += "\n"
        entity_declaration += self.constructor_declaration(SC_THREAD_definition)
        entity_declaration += "\n"
        entity_declaration += processes

        entity_declaration += "};"
        return entity_declaration


