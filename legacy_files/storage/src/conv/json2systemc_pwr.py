from utdate.src.conv.json2systemc import json2systemc
from json import dumps

# see if it's multi-bit port
# TODO: check if module name is also used for any other property
#   if so change module name, since it raise an error in systemc
#   add option to be yosys compatible

WHITE_SPACE = "    "

class json2systemc_pwr(json2systemc):
    def __init__(self, json_file, config_json, technology_parameter, gate_signal_file="") -> None:
        json2systemc.__init__(self, json_file, config_json, technology_parameter, gate_signal_file)

    # @def: add standard library library  
    def includes(self):
        include_lib = '#include <systemc.h>' + "\n"
        include_lib += f'#include "{self.config_js["systemC_library"]}"' + "\n"
        include_lib += f'#include "sc_signal_pw.h"'

        return include_lib

    # @def: find actual net name using net integer value
    #   input: net integer value
    #   output: net name
    def signal_declartion(self):

        signal_declartion = ""

        signal_declartion += self.sc_logic_signals()[0] + "\n"

        for net in self.net_dict:
            if not (net in self.ports_list):
                signal_declartion += WHITE_SPACE + f'sc_signal_pw<sc_logic> {net} = sc_signal_pw<sc_logic>("{net}");' + '\n'

        return signal_declartion
