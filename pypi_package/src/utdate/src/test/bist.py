from os import path, getcwd, chdir, mkdir
from utdate.src.utility_functions import split_page
import utdate.lib as lib
from shutil import copytree


class bist_insertion:
    # get bist_configuration containing all the neccessary information about the bist and design
    def __init__(self, bist_configuration: dict) -> None:
        self.configuration = bist_configuration
        # get directory of library inside package repository
        self.bist_lib = path.join((path.join(lib.__path__[0], "test")), "bist")
        self.working_dir = getcwd()
        self.bist_dir = ""

        # check wether the "test" directory exist in working directory
        #   - if not create a new one
        if (path.isdir(path.join(self.working_dir, "test"))):
            test_dir = path.join(self.working_dir, "test")
            self.bist_dir =(path.join(test_dir, "bist"))
        else:
            test_dir = mkdir("test", self.working_dir)
            self.bist_dir =(path.join(test_dir, "bist"))



    def rts(self):
        RTS_template_dir = path.join(self.bist_lib, "RTS")

        # check wether the "test" directory exist in working directory
        #   - if not create a new one
        # if (path.isdir(path.join(self.working_dir, "test"))):
        #     test_dir = path.join(self.working_dir, "test")
        #     if not (path.isdir(path.join(test_dir, "bist"))):
        #         self.bist_dir = mkdir(path.join(test_dir, "bist"))
        #     else:
        #         self.bist_dir = path.join(test_dir, "bist")
        # else:
        #     test_dir = mkdir("test", self.working_dir)
            # self.bist_dir = mkdir(path.join(test_dir, "bist"))

        # Copy entire unmodified bist folder from library into working directory
        copytree(RTS_template_dir, self.bist_dir)

        # construct values
        DUT_input_ports = ""
        DUT_output_ports = ""
        DUT_signals = ""
        DUT_instance = ""
        DUT_instance_port = ""
        MISR_In_ports = ""
        MUX_In1_ports = ""
        MUX_Out_ports = ""

        # separate input & output ports
        for port_name, port_attr in self.configuration["Primary_IO"].items():
            # Exclude clock from port list
            if port_name != self.configuration["clock_name"]:
                DUT_instance_port += "              " + f'{port_name} 		 => {port_name},' + "\n"
                if port_attr["direction"] == "input": # if input port
                    MUX_In1_ports += f'& {port_name}_pin '
                    MUX_Out_ports += f'& {port_name} '
                    if len(port_attr["bits"]) == 1: # if port is single bit
                        DUT_input_ports += "        " + f'{port_name}_pin   : IN STD_LOGIC;' + "\n"
                        DUT_signals += "    " + f'SIGNAL {port_name}: STD_LOGIC;' + "\n"
                    elif len(port_attr["bits"]) > 1: # if port is multi-bit
                        DUT_input_ports += "        " + f'{port_name}_pin   : IN STD_LOGIC_VECTOR ({len(port_attr["bits"])}-1 DOWNTO 0);' + "\n"
                        DUT_signals += "    " + f'SIGNAL {port_name}: STD_LOGIC_VECTOR ({len(port_attr["bits"])}-1 DOWNTO 0);' + "\n"
                elif port_attr["direction"] == "output": 
                    MISR_In_ports += f'& {port_name} '
                    if len(port_attr["bits"]) == 1:
                        DUT_output_ports += "        " + f'{port_name}   : OUT STD_LOGIC;' + "\n"
                    elif len(port_attr["bits"]) > 1:
                        DUT_output_ports += "        " + f'{port_name}   : OUT STD_LOGIC_VECTOR ({len(port_attr["bits"])}-1 DOWNTO 0);' + "\n"
            else:
                DUT_instance_port += "              " + f'{port_name} 		 => clk,' + "\n"

        # construct signal
        DUT_signals += "    " + f'SIGNAL {self.configuration["serial_input_name"][0]} : STD_LOGIC;' + "\n"
        DUT_signals += "    " + f'SIGNAL {self.configuration["serial_output_name"][0]} : STD_LOGIC;' + "\n"
        DUT_signals += "    " + "SIGNAL internalRst : STD_LOGIC;" + "\n"
        DUT_signals += "    " + "SIGNAL PbarS : STD_LOGIC;" + "\n"
        
        DUT_instance_port += "              " + f'global_reset => internalRst,' + "\n"
        DUT_instance_port += "              " + f'NbarT		 => PbarS,' + "\n"
        DUT_instance_port += "              " + f'{self.configuration["serial_input_name"][0]} 		 => {self.configuration["serial_input_name"][0]},' + "\n"
        DUT_instance_port += "              " + f'{self.configuration["serial_output_name"][0]} 		 => {self.configuration["serial_output_name"][0]}' + "\n"
        
        # DUT instantiation
        DUT_instance += "   DUT : ENTITY WORK.counter " + "\n"
        DUT_instance += "           PORT MAP (" + "\n"
        DUT_instance += DUT_instance_port
        DUT_instance += "           );" + "\n"

        # Top_level ----------------
        # Read from the template
        with open(path.join(RTS_template_dir, "Top_level.vhd"), "r") as rd:
            top_level = rd.read()

            # replace Primary_input_name
            p1, p2 = split_page(top_level, ["--", "PI_Size"])
            top_level = p1 + "\n" + "        " + f'PI_Size     : INTEGER := {str(self.configuration["Primary_input_size"])};' + p2

            # replace Primary_output_name
            p1, p2 = split_page(top_level, ["--", "PO_Size"])
            top_level = p1 + "\n" + "        " + f'PO_Size     : INTEGER := {str(self.configuration["Primary_output_size"])};' + p2

            # replace shiftSize 
            p1, p2 = split_page(top_level, ["--", "ShiftSize"])
            top_level = p1 + "\n" + "        " + f'ShiftSize     : INTEGER := {str(self.configuration["number_of_dffs"])};' + p2
            
            # replace Seed & Polynomial
            p1, p2 = split_page(top_level, ["--", "Seed", "&", "Polynomial"])
            top_level = p1 + "\n" \
            + "        " + f'PRPG_Seed	: STD_LOGIC_VECTOR := {str(self.configuration["prpg_seed"])};' + "\n" \
            + "        " + f'PRPG_Poly	: STD_LOGIC_VECTOR := {str(self.configuration["prpg_poly"])};' + "\n" \
            + "        " + f'MISR_Seed	: STD_LOGIC_VECTOR := {str(self.configuration["misr_seed"])};' + "\n" \
            + "        " + f'MISR_Poly	: STD_LOGIC_VECTOR := {str(self.configuration["misr_poly"])};' + "\n" \
            + "        " + f'SRSG_Seed	: STD_LOGIC_VECTOR := {str(self.configuration["srsg_seed"])};' + "\n" \
            + "        " + f'SRSG_Poly	: STD_LOGIC_VECTOR := {str(self.configuration["srsg_poly"])};' + "\n" \
            + "        " + f'SISA_Seed	: STD_LOGIC_VECTOR := {str(self.configuration["sisa_seed"])};' + "\n" \
            + "        " + f'SISA_Poly	: STD_LOGIC_VECTOR := {str(self.configuration["sisa_poly"])};' + "\n" \
            + p2
            
            # Enter DUT Inputs
            p1, p2 = split_page(top_level, ["--", "DUT", "Inputs"])
            top_level = p1 + "\n" + DUT_input_ports + p2

            # Enter DUT Outputs
            p1, p2 = split_page(top_level, ["--", "DUT", "Outputs"])
            top_level = p1 + "\n" + DUT_output_ports + p2

            # Enter Signals of DUT
            p1, p2 = split_page(top_level, ["--", "Signals", "of", "DUT"])
            top_level = p1 + "\n" + DUT_signals + p2

            # DUT instantiation
            p1, p2 = split_page(top_level, ["--", "DUT", "Instantiation"])
            top_level = p1 + "\n" + DUT_instance + p2
            
            # Assign outputs to MISR_In
            p1, p2 = split_page(top_level, ["--", "Assign", "outputs", "to", "MISR_In"])
            top_level = p1 + "\n" + "    " + f'MISR_In <= (Zeros {MISR_In_ports});' + p2

            # Assign input pins to MUX_In1
            # We start every pins with a & sign, this must be removed from the first pin entry [2:end]
            p1, p2 = split_page(top_level, ["--", "Assign", "input pins", "to", "MUX_In1"])
            top_level = p1 + "\n" + "    " + f'MUX_In1 <= ({MUX_In1_ports[2:]});' + p2
            
            # Assign MUX_Out to inputs
            # We start every pins with a & sign, this must be removed from the first pin entry [2:end]
            p1, p2 = split_page(top_level, ["--", "Assign", "MUX_Out", "to", "inputs"])
            top_level = p1 + "\n" + "    " + f'({MUX_Out_ports[2:]}) <= MUX_Out;' + p2

            with open(path.join(self.bist_dir, "Top_level.vhd"), "w") as wr:
                wr.write(top_level)

        # Virtual Tester ----------------