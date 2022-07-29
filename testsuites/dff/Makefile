
GHDL=/Users/ebinouri/Documents/UNi/OpenSourceTools/fpga-toolchain/bin/ghdl
FLAGS="--std=08"

all: clean
	$(GHDL) -a $(FLAGS) dff.vhd dff_tb.vhd
	$(GHDL) -e $(FLAGS) dff_tb
	$(GHDL) -r $(FLAGS) dff_tb --wave=wave.ghw --stop-time=100us

.PHONY: clean
clean:
	rm -rf work-*.cf
	rm -rf *.ghw