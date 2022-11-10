#include <systemc>
#include <uvm>
#include "vip/fi.h"
#include "vip/fi_signal_if.h"
#include "test_lib.h" 
#include "reg/ut_fault_registry.h"
#include "systemC_netlist.h"


using namespace sc_core;

SC_MODULE( testbench ) {

    c17* dut;
    c17* dut_ref;
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
        dut = new c17("dut");
            dut->N1.bind(vif->add_and_bind("N1"));
            dut->N2.bind(vif->add_and_bind("N2"));
            dut->N3.bind(vif->add_and_bind("N3"));
            dut->N6.bind(vif->add_and_bind("N6"));
            dut->N7.bind(vif->add_and_bind("N7"));
            dut->N22.bind(vif->add_and_bind("N22_mod"));
            dut->N23.bind(vif->add_and_bind("N23_mod"));
        // Instantiate the DUT and bind ports to interface
        dut_ref = new c17("dut_ref");
            dut_ref->N1.bind(vif->get_signal("N1"));
            dut_ref->N2.bind(vif->get_signal("N2"));
            dut_ref->N3.bind(vif->get_signal("N3"));
            dut_ref->N6.bind(vif->get_signal("N6"));
            dut_ref->N7.bind(vif->get_signal("N7"));
            dut_ref->N22.bind(vif->add_and_bind("N22_ref"));
            dut_ref->N23.bind(vif->add_and_bind("N23_ref"));
        // creating fault registration module
        flt_reg = new ut_fault_registry();
            flt_reg->add_object(dut->_0_);
            flt_reg->add_object(dut->_1_);
            flt_reg->add_object(dut->_2_);
            flt_reg->add_object(dut->_3_);
            flt_reg->add_object(dut->_4_);
                                                                                    
        // group signals into two 
        vif->set_as_stimulated("N1");
        vif->set_as_stimulated("N2");
        vif->set_as_stimulated("N3");
        vif->set_as_stimulated("N6");
        vif->set_as_stimulated("N7");
        vif->set_as_observable_mod("N22_mod");
        vif->set_as_observable_ref("N22_ref");
        vif->set_as_observable_mod("N23_mod");
        vif->set_as_observable_ref("N23_ref");

        // Add interface to configuration database
        uvm::uvm_config_db<ut_fault_registry*>::set(
          uvm::uvm_root::get(), "*", "flt_reg", flt_reg);
    }
};
