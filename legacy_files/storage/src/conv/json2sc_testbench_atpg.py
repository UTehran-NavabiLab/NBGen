from utdate.src.conv.json2sc_testbench import json2sc_testbench

# TODO: 
    # consider multi-bit port input/outputs

WHITE_SPACE = "    "

class json2sc_testbench_atpg(json2sc_testbench):
    def __init__(self, json_file, config_json, technology_parameter, testbench, instance) -> None:
        json2sc_testbench.__init__(self, json_file, config_json, technology_parameter, testbench, instance)

    # @def: add standard library library  
    def includes(self):
        include_lib = '#include <iostream>' + "\n"
        include_lib += '#include <fstream>' + "\n"
        include_lib += '#include <string>' + "\n"
        include_lib += '#include <vector>' + "\n"
        include_lib += '#include <map>' + "\n"
        include_lib += '#include <math.h>' + "\n"
        include_lib += '#include "systemc.h"' + "\n"
        include_lib += '#include "systemC_netlist.h"' + "\n"
        include_lib += '#include "idd_testing.h"' + "\n"
        include_lib += '#include "utilities.h"' + "\n"

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
                signal_declaration += f'sc_signal<sc_logic> {port_name} = sc_signal<sc_logic>("{port_name}");\n'
            else:
                signal_declaration += f'sc_signal<sc_logic> {port_name}[{str(len(port_prop["bits"]))}] = sc_signal<sc_logic>("{port_name}");\n'

        return signal_declaration
  
    # @def: declare sc_event
    def event_declartion(self):

        event_declaration = ""

        # define sc_event
        event_declaration += WHITE_SPACE + f'sc_event ready2update;' + '\n'
        # event_declaration += WHITE_SPACE + f'sc_event ready2reset;' + '\n'

        return event_declaration
  

    # @def: instance all the required modules, define pointers outside constructor and port binding inside
    def cells_declaration(self):

        instance_pointer = ""
        cell_instantiation = ""

        instatnce_name = self.instance_name
        
        # pointer to faulty module under test
        instance_pointer = WHITE_SPACE + self.module_name + "* " + instatnce_name + ";\n"
        instance_pointer += WHITE_SPACE + f'itest idd_test = itest("gate_signal_json_file.json", "gate_properties.json");' + "\n"

        instance_pointer += WHITE_SPACE + f'std::array<sc_core::sc_signal<sc_dt::sc_logic>*, {len(self.net_dict)}> signal_arr;' + '\n'

        input_buffer = ""

        # if ("inbufcell" in self.config_js):
        #     if (self.config_js["inbufcell"] != ""):
        #         input_buffer = self.config_js["inbufcell"]
        #     else:
        #         input_buffer = self.config_js["bufcell"]
        # else:
        #     print("no buf gate in library")
            

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

    def access_signals_function(self):
        access_signals_function = ""

        SC_THREAD_definition = WHITE_SPACE + WHITE_SPACE + f'access_signals();\n'

        access_signals_function += WHITE_SPACE + f'void access_signals(void)'+ '{\n'

        i = 0
        for port_name, port_prop in self.top_module["ports"].items():
            if len(port_prop["bits"]) == 1:
                access_signals_function += WHITE_SPACE + WHITE_SPACE + f'signal_arr[{i}] = &({port_name});' + '\n'
                if port_prop["direction"] == "input":
                        access_signals_function += WHITE_SPACE + WHITE_SPACE + f'idd_test.add_to_port_list("{port_name}");' + '\n'
                i += 1
            else: # if port is multi-bit, slice the port loop through each bit
                for j in range(len(port_prop["bits"])):
                    access_signals_function += WHITE_SPACE + WHITE_SPACE + f'signal_arr[{i}] = &({port_name}[{str(j)}]);' + '\n'
                    # ********** what to do for multiport inputs
                    if port_prop["direction"] == "input":
                        access_signals_function += WHITE_SPACE + WHITE_SPACE + f'idd_test.add_to_port_list("{port_name}");' + '\n'
                    i += 1

        for net in self.net_dict:
            if not (net in self.ports_list):
                access_signals_function += WHITE_SPACE + WHITE_SPACE + f'signal_arr[{i}] = &({self.instance_name}->{net});' + '\n'
                i += 1

        access_signals_function += WHITE_SPACE + '}\n'

        return SC_THREAD_definition, access_signals_function

    def run_idd_testing_method(self):
        run_idd_testing = ""
        SC_THREAD_definition = ""

        SC_THREAD_definition += WHITE_SPACE + WHITE_SPACE + f'SC_METHOD(run_idd_testing);\n'
        SC_THREAD_definition += WHITE_SPACE + WHITE_SPACE + WHITE_SPACE + f'sensitive << ready2update;\n'
        SC_THREAD_definition += WHITE_SPACE + WHITE_SPACE + WHITE_SPACE + f'dont_initialize();\n'

        run_idd_testing += WHITE_SPACE + f'void run_idd_testing(void)' + '{\n'
        run_idd_testing += WHITE_SPACE + WHITE_SPACE + f'idd_test.update_signal<sc_dt::sc_logic, {len(self.net_dict)}>(signal_arr);' + '\n'
        
        for port_name, port_prop in self.top_module["ports"].items():
            if port_prop["direction"] == "output":
                run_idd_testing += WHITE_SPACE + WHITE_SPACE + f'idd_test.back_trace("{port_name}");' + '\n'

        run_idd_testing += WHITE_SPACE + WHITE_SPACE + f'idd_test.mark_multiplath();' + '\n'
        run_idd_testing += WHITE_SPACE + WHITE_SPACE + f'idd_test.print_critical_path_list();' + '\n'
        run_idd_testing += WHITE_SPACE + WHITE_SPACE + f'idd_test.clear_critical_path_list();' + '\n'
        run_idd_testing += WHITE_SPACE + '}\n'

        return SC_THREAD_definition, run_idd_testing

    def signaling_thread(self):
        signaling_proc = ""

        SC_THREAD_definition = WHITE_SPACE + WHITE_SPACE + f'SC_THREAD(signaling);\n'

        signaling_proc += WHITE_SPACE + f'void signaling(void)' + '{\n'
        signaling_proc += WHITE_SPACE + WHITE_SPACE + f'for (int i=0; i < pow(2, {self.size_Of_Ports()[0]}); i++)' + '{\n'
        
        str_input_values = ""
        str_input_vector = "input signals: "
        port_indx = 0
        for port_name, port_prop in self.top_module["ports"].items():
            if port_prop["direction"] == "input":
                signaling_proc += WHITE_SPACE + WHITE_SPACE + WHITE_SPACE + f'{port_name}.write(input_signalling({port_indx}, i));' + '\n'
                str_input_vector += f' {port_name},'
                str_input_values += f'<< {port_name}.read() '
                port_indx += 1

        str_input_vector = str_input_vector[:-1] + " = " 
        
        signaling_proc += WHITE_SPACE + WHITE_SPACE + WHITE_SPACE + f'wait(SC_ZERO_TIME);' + '\n'
        signaling_proc += WHITE_SPACE + WHITE_SPACE + WHITE_SPACE + f'std::cout << "--------- Apply New input vector: " << std::endl; ' + '\n'
        signaling_proc += WHITE_SPACE + WHITE_SPACE + WHITE_SPACE + f'std::cout << "{str_input_vector}" {str_input_values} << std::endl; ' + '\n'
        signaling_proc += WHITE_SPACE + WHITE_SPACE + WHITE_SPACE + f'wait(5, SC_NS);' + '\n'
        signaling_proc += WHITE_SPACE + WHITE_SPACE + WHITE_SPACE + f'ready2update.notify();' + '\n'
        signaling_proc += WHITE_SPACE + WHITE_SPACE + WHITE_SPACE + f'wait(SC_ZERO_TIME);' + '\n'
        signaling_proc += WHITE_SPACE + WHITE_SPACE + '}\n'
        signaling_proc += WHITE_SPACE + '}\n'

        return SC_THREAD_definition, signaling_proc

    def thread_declaration(self):
        SC_THREAD_definition = ""
        processes = ""

        SC_THREAD_definition_tmp, processes_tmp = self.signaling_thread()
        SC_THREAD_definition += SC_THREAD_definition_tmp + '\n'
        processes += processes_tmp + '\n'

        SC_THREAD_definition_tmp, processes_tmp = self.run_idd_testing_method()
        SC_THREAD_definition += SC_THREAD_definition_tmp + '\n'
        processes += processes_tmp + '\n'

        SC_THREAD_definition_tmp, processes_tmp = self.access_signals_function()
        SC_THREAD_definition += SC_THREAD_definition_tmp + '\n'
        processes += processes_tmp + '\n'
        
        return SC_THREAD_definition, processes


    # @def: declare module signature 
    def constructor_declaration(self, SC_THREAD_definition, cell_in_constructor_declaration):
        constructor_declaration = ""
        constructor_declaration += WHITE_SPACE + f'SC_HAS_PROCESS({self.testbench_name});\n'
        constructor_declaration += WHITE_SPACE + f'{self.testbench_name}(sc_module_name _name)' + "{\n"
        
        # add cell instantiation and binding
        # constructor_declaration += self.cells_declaration()[1] + "\n"
        constructor_declaration += cell_in_constructor_declaration + "\n"
        constructor_declaration += SC_THREAD_definition + "\n"

        constructor_declaration += WHITE_SPACE + "}\n"

        return constructor_declaration

    # @def: declare module signature 
    def module_declaration(self):
        entity_declaration = ""
        SC_THREAD_definition, processes = self.thread_declaration()
        # cell instantiation must get called only one time
        cell_pointer_instantiation, cell_in_constructor_declaration = self.cells_declaration()

        entity_declaration += f'SC_MODULE( {self.testbench_name} ) ' + '{\n'
        entity_declaration += "\n"
        entity_declaration += self.signal_declartion()
        entity_declaration += "\n"
        entity_declaration += self.event_declartion()
        entity_declaration += "\n"
        entity_declaration += cell_pointer_instantiation
        # entity_declaration += self.cells_declaration()[0]
        entity_declaration += "\n"
        entity_declaration += self.constructor_declaration(SC_THREAD_definition, cell_in_constructor_declaration)
        entity_declaration += "\n"
        entity_declaration += processes

        entity_declaration += "};"
        return entity_declaration


