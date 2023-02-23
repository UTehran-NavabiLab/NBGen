from utdate.src.technology_reader import Technology_file
from utdate.src.utility_functions import find_clk_rst_netNumber, find_clk_rst_name, rm_float_net
import utdate.lib as lib
from os import path

technology_parameter = Technology_file(path.join(lib.__path__[0], "mycells_abc.lib"))
js = "/Users/ebinouri/Documents/UNi/NBGen/pypi_package/test/Puneh_Test1401_Hosein/2/synthesis/synth_premap.json"
bench = "/Users/ebinouri/Documents/UNi/NBGen/pypi_package/test/Puneh_Test1401_Hosein/2/test/abc_bench.bench"
out_bench = rm_float_net(js, bench, technology_parameter)
# print(out_bench)