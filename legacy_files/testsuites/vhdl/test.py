import os
import sys
import json
import subprocess

lib_dir = "/Users/ebinouri/Documents/UNi/NBGen/examples/vhdl/lib"
yosys_script_dir = os.path.join(lib_dir, "yosys_script.ys")
# read config file
with open(os.path.join(lib_dir, "config.json"), "r") as json_file:
    config = json.load(json_file)

print(config["yosys_bin"])
print(yosys_script_dir)
yosys_log = subprocess.run([config["yosys_bin"], yosys_script_dir], stdout=subprocess.PIPE, text=True, check=True)
print(yosys_log)