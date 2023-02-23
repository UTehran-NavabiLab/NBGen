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
            flt_reg->add_object(dut->S0);
            flt_reg->add_object(dut->S1);
            flt_reg->add_object(dut->S2);
            flt_reg->add_object(dut->S3);
            flt_reg->add_object(dut->S4);
            flt_reg->add_object(dut->S5);
            flt_reg->add_object(dut->S6);
            flt_reg->add_object(dut->S7);
            flt_reg->add_object(dut->S8);
            flt_reg->add_object(dut->S9);
            flt_reg->add_object(dut->S10);
            flt_reg->add_object(dut->S11);
            flt_reg->add_object(dut->S12);
            flt_reg->add_object(dut->S13);
            flt_reg->add_object(dut->S14);
            flt_reg->add_object(dut->S15);
            flt_reg->add_object(dut->S16);
            flt_reg->add_object(dut->S17);
            flt_reg->add_object(dut->S18);
            flt_reg->add_object(dut->S19);
            flt_reg->add_object(dut->S20);
            flt_reg->add_object(dut->S21);
            flt_reg->add_object(dut->S22);
            flt_reg->add_object(dut->S23);
            flt_reg->add_object(dut->S24);
            flt_reg->add_object(dut->S25);
            flt_reg->add_object(dut->S26);
            flt_reg->add_object(dut->S27);
            flt_reg->add_object(dut->S28);
            flt_reg->add_object(dut->S29);
            flt_reg->add_object(dut->S30);
            flt_reg->add_object(dut->S31);
            flt_reg->add_object(dut->S32);
            flt_reg->add_object(dut->S33);
            flt_reg->add_object(dut->S34);
            flt_reg->add_object(dut->S35);
            flt_reg->add_object(dut->S36);
            flt_reg->add_object(dut->S37);
            flt_reg->add_object(dut->S38);
            flt_reg->add_object(dut->S39);
            flt_reg->add_object(dut->S40);
                                                                                                            
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
