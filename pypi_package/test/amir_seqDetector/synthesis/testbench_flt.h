#include <systemc>
#include <uvm>
#include "vip/fi.h"
#include "vip/fi_signal_if.h"
#include "test_lib.h" 
#include "reg/ut_fault_registry.h"
#include "systemC_netlist.h"


using namespace sc_core;

SC_MODULE( testbench ) {

    seqDetector* dut;
    seqDetector* dut_ref;
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
        dut = new seqDetector("dut");
            dut->clk.bind(vif->add_and_bind("clk"));
            dut->rst.bind(vif->add_and_bind("rst"));
            dut->serIn.bind(vif->add_and_bind("serIn"));
            dut->serOutValid.bind(vif->add_and_bind("serOutValid_mod"));
        // Instantiate the DUT and bind ports to interface
        dut_ref = new seqDetector("dut_ref");
            dut_ref->clk.bind(vif->get_signal("clk"));
            dut_ref->rst.bind(vif->get_signal("rst"));
            dut_ref->serIn.bind(vif->get_signal("serIn"));
            dut_ref->serOutValid.bind(vif->add_and_bind("serOutValid_ref"));
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
            flt_reg->add_object(dut->ps_0);
            flt_reg->add_object(dut->ps_1);
            flt_reg->add_object(dut->ps_2);
                                                
        // group signals into two 
        vif->set_as_stimulated("clk");
        vif->set_as_stimulated("rst");
        vif->set_as_stimulated("serIn");
        vif->set_as_observable_mod("serOutValid_mod");
        vif->set_as_observable_ref("serOutValid_ref");

        // Add interface to configuration database
        uvm::uvm_config_db<ut_fault_registry*>::set(
          uvm::uvm_root::get(), "*", "flt_reg", flt_reg);
    }
};
