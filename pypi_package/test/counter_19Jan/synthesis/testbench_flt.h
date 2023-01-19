#include <systemc>
#include <uvm>
#include "vip/fi.h"
#include "vip/fi_signal_if.h"
#include "test_lib.h" 
#include "reg/ut_fault_registry.h"
#include "systemC_netlist.h"


using namespace sc_core;

SC_MODULE( testbench ) {

    counter* dut;
    counter* dut_ref;
    fi_signal_if* vif;
    ut_fault_registry* flt_reg;

    SC_HAS_PROCESS(testbench);
    testbench(sc_module_name _name){
        // Interface instantiation
        vif = new fi_signal_if("vif");
          assert(vif);
        // call function to read from file
        std::string input_vector_file = "test_vector.vec";
        // add streams of file to resource database
        // uvm::uvm_resource_db<std::string>::set("*", "input_vector_file", input_vector_file, this);
        uvm::uvm_config_db<std::string>::set(uvm::uvm_root::get(), "*", "input_vector_file", input_vector_file);
        // Add interface to configuration database
        uvm::uvm_config_db<fi_signal_if*>::set(uvm::uvm_root::get(), "*", "vif", vif);
        // Instantiate the DUT and bind ports to interface
        dut = new counter("dut");
            dut->clk.bind(vif->add_and_bind("clk"));
            dut->rst.bind(vif->add_and_bind("rst"));
            dut->en.bind(vif->add_and_bind("en"));
            dut->clkEn.bind(vif->add_and_bind("clkEn"));
            dut->count[0].bind(vif->add_and_bind("count[0]_mod"));
            dut->count[1].bind(vif->add_and_bind("count[1]_mod"));
            dut->count[2].bind(vif->add_and_bind("count[2]_mod"));
            dut->count[3].bind(vif->add_and_bind("count[3]_mod"));
            dut->co.bind(vif->add_and_bind("co_mod"));
        // Instantiate the DUT and bind ports to interface
        dut_ref = new counter("dut_ref");
            dut_ref->clk.bind(vif->get_signal("clk"));
            dut_ref->rst.bind(vif->get_signal("rst"));
            dut_ref->en.bind(vif->get_signal("en"));
            dut_ref->clkEn.bind(vif->get_signal("clkEn"));
            dut_ref->count[0].bind(vif->add_and_bind("count[0]_ref"));
            dut_ref->count[1].bind(vif->add_and_bind("count[1]_ref"));
            dut_ref->count[2].bind(vif->add_and_bind("count[2]_ref"));
            dut_ref->count[3].bind(vif->add_and_bind("count[3]_ref"));
            dut_ref->co.bind(vif->add_and_bind("co_ref"));
        // creating fault registration module
        flt_reg = new ut_fault_registry();
            flt_reg->add_object(dut->_0_);
            flt_reg->add_object(dut->_10_);
            flt_reg->add_object(dut->_11_);
            flt_reg->add_object(dut->_12_);
            flt_reg->add_object(dut->_13_);
            flt_reg->add_object(dut->_14_);
            flt_reg->add_object(dut->_15_);
            flt_reg->add_object(dut->_16_);
            flt_reg->add_object(dut->_17_);
            flt_reg->add_object(dut->_18_);
            flt_reg->add_object(dut->_19_);
            flt_reg->add_object(dut->_1_);
            flt_reg->add_object(dut->_20_);
            flt_reg->add_object(dut->_21_);
            flt_reg->add_object(dut->_22_);
            flt_reg->add_object(dut->_23_);
            flt_reg->add_object(dut->_24_);
            flt_reg->add_object(dut->_25_);
            flt_reg->add_object(dut->_2_);
            flt_reg->add_object(dut->_3_);
            flt_reg->add_object(dut->_4_);
            flt_reg->add_object(dut->_5_);
            flt_reg->add_object(dut->_6_);
            flt_reg->add_object(dut->_7_);
            flt_reg->add_object(dut->_8_);
            flt_reg->add_object(dut->_9_);
                                                                                                            
        // group signals into two 
        vif->set_as_stimulated("clk");
        vif->set_as_stimulated("rst");
        vif->set_as_stimulated("en");
        vif->set_as_stimulated("clkEn");
        vif->set_as_observable_mod("count[0]_mod");
        vif->set_as_observable_ref("count[0]_ref");
        vif->set_as_observable_mod("count[1]_mod");
        vif->set_as_observable_ref("count[1]_ref");
        vif->set_as_observable_mod("count[2]_mod");
        vif->set_as_observable_ref("count[2]_ref");
        vif->set_as_observable_mod("count[3]_mod");
        vif->set_as_observable_ref("count[3]_ref");
        vif->set_as_observable_mod("co_mod");
        vif->set_as_observable_ref("co_ref");

        // Add interface to configuration database
        uvm::uvm_config_db<ut_fault_registry*>::set(
          uvm::uvm_root::get(), "*", "flt_reg", flt_reg);
    }
};
