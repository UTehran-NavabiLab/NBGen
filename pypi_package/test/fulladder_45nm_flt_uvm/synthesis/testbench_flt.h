#include <systemc>
#include <uvm>
#include "vip/fi.h"
#include "vip/fi_signal_if.h"
#include "test_lib.h" 
#include "reg/ut_fault_registry.h"
#include "systemC_netlist.h"


using namespace sc_core;

SC_MODULE( testbench ) {

    fulladder* dut;
    fulladder* dut_ref;
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
        dut = new fulladder("dut");
            dut->i0.bind(vif->add_and_bind("i0"));
            dut->i1.bind(vif->add_and_bind("i1"));
            dut->ci.bind(vif->add_and_bind("ci"));
            dut->s.bind(vif->add_and_bind("s_mod"));
            dut->co.bind(vif->add_and_bind("co_mod"));
        // Instantiate the DUT and bind ports to interface
        dut_ref = new fulladder("dut_ref");
            dut_ref->i0.bind(vif->get_signal("i0"));
            dut_ref->i1.bind(vif->get_signal("i1"));
            dut_ref->ci.bind(vif->get_signal("ci"));
            dut_ref->s.bind(vif->add_and_bind("s_ref"));
            dut_ref->co.bind(vif->add_and_bind("co_ref"));
        // creating fault registration module
        flt_reg = new ut_fault_registry();
            flt_reg->add_object(vif->get_signal("i0"));
            flt_reg->add_object(vif->get_signal("i1"));
            flt_reg->add_object(vif->get_signal("ci"));
                        
        // group signals into two 
        vif->set_as_stimulated("i0");
        vif->set_as_stimulated("i1");
        vif->set_as_stimulated("ci");
        vif->set_as_observable_mod("s_mod");
        vif->set_as_observable_mod("s_ref");
        vif->set_as_observable_mod("co_mod");
        vif->set_as_observable_mod("co_ref");

        // Add interface to configuration database
        uvm::uvm_config_db<ut_fault_registry*>::set(
          uvm::uvm_root::get(), "*", "flt_reg", flt_reg);
    }
};
