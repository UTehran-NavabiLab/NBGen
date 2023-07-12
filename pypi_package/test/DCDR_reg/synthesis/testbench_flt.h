#include <systemc>
#include <uvm>
#include "vip/fi.h"
#include "vip/fi_signal_if.h"
#include "test_lib.h" 
#include "reg/ut_fault_registry.h"
#include "systemC_netlist.h"


using namespace sc_core;

SC_MODULE( testbench ) {

    register* dut;
    register* dut_ref;
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
        dut = new register("dut");
            dut->clk.bind(vif->add_and_bind("clk"));
            dut->rst.bind(vif->add_and_bind("rst"));
            dut->A[0].bind(vif->add_and_bind("A[0]"));
            dut->A[1].bind(vif->add_and_bind("A[1]"));
            dut->A[2].bind(vif->add_and_bind("A[2]"));
            dut->A[3].bind(vif->add_and_bind("A[3]"));
            dut->B[0].bind(vif->add_and_bind("B[0]"));
            dut->B[1].bind(vif->add_and_bind("B[1]"));
            dut->B[2].bind(vif->add_and_bind("B[2]"));
            dut->B[3].bind(vif->add_and_bind("B[3]"));
            dut->C[0].bind(vif->add_and_bind("C[0]"));
            dut->C[1].bind(vif->add_and_bind("C[1]"));
            dut->C[2].bind(vif->add_and_bind("C[2]"));
            dut->C[3].bind(vif->add_and_bind("C[3]"));
            dut->Q1[0].bind(vif->add_and_bind("Q1[0]_mod"));
            dut->Q1[1].bind(vif->add_and_bind("Q1[1]_mod"));
            dut->Q1[2].bind(vif->add_and_bind("Q1[2]_mod"));
            dut->Q1[3].bind(vif->add_and_bind("Q1[3]_mod"));
            dut->Q2[0].bind(vif->add_and_bind("Q2[0]_mod"));
            dut->Q2[1].bind(vif->add_and_bind("Q2[1]_mod"));
            dut->Q2[2].bind(vif->add_and_bind("Q2[2]_mod"));
            dut->Q2[3].bind(vif->add_and_bind("Q2[3]_mod"));
            dut->Q3[0].bind(vif->add_and_bind("Q3[0]_mod"));
            dut->Q3[1].bind(vif->add_and_bind("Q3[1]_mod"));
            dut->Q3[2].bind(vif->add_and_bind("Q3[2]_mod"));
            dut->Q3[3].bind(vif->add_and_bind("Q3[3]_mod"));
        // Instantiate the DUT and bind ports to interface
        dut_ref = new register("dut_ref");
            dut_ref->clk.bind(vif->get_signal("clk"));
            dut_ref->rst.bind(vif->get_signal("rst"));
            dut_ref->A[0].bind(vif->get_signal("A[0]"));
            dut_ref->A[1].bind(vif->get_signal("A[1]"));
            dut_ref->A[2].bind(vif->get_signal("A[2]"));
            dut_ref->A[3].bind(vif->get_signal("A[3]"));
            dut_ref->B[0].bind(vif->get_signal("B[0]"));
            dut_ref->B[1].bind(vif->get_signal("B[1]"));
            dut_ref->B[2].bind(vif->get_signal("B[2]"));
            dut_ref->B[3].bind(vif->get_signal("B[3]"));
            dut_ref->C[0].bind(vif->get_signal("C[0]"));
            dut_ref->C[1].bind(vif->get_signal("C[1]"));
            dut_ref->C[2].bind(vif->get_signal("C[2]"));
            dut_ref->C[3].bind(vif->get_signal("C[3]"));
            dut_ref->Q1[0].bind(vif->add_and_bind("Q1[0]_ref"));
            dut_ref->Q1[1].bind(vif->add_and_bind("Q1[1]_ref"));
            dut_ref->Q1[2].bind(vif->add_and_bind("Q1[2]_ref"));
            dut_ref->Q1[3].bind(vif->add_and_bind("Q1[3]_ref"));
            dut_ref->Q2[0].bind(vif->add_and_bind("Q2[0]_ref"));
            dut_ref->Q2[1].bind(vif->add_and_bind("Q2[1]_ref"));
            dut_ref->Q2[2].bind(vif->add_and_bind("Q2[2]_ref"));
            dut_ref->Q2[3].bind(vif->add_and_bind("Q2[3]_ref"));
            dut_ref->Q3[0].bind(vif->add_and_bind("Q3[0]_ref"));
            dut_ref->Q3[1].bind(vif->add_and_bind("Q3[1]_ref"));
            dut_ref->Q3[2].bind(vif->add_and_bind("Q3[2]_ref"));
            dut_ref->Q3[3].bind(vif->add_and_bind("Q3[3]_ref"));
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
            flt_reg->add_object(dut->CK);
            flt_reg->add_object(dut->R);
            flt_reg->add_object(dut->cnt_0);
            flt_reg->add_object(dut->cnt_1);
            flt_reg->add_object(dut->cnt_2);
            flt_reg->add_object(dut->cnt_3);
                                                                                                                                                                                                                                                                                                                        
        // group signals into two 
        vif->set_as_stimulated("clk");
        vif->set_as_stimulated("rst");
        vif->set_as_stimulated("A[0]");
        vif->set_as_stimulated("A[1]");
        vif->set_as_stimulated("A[2]");
        vif->set_as_stimulated("A[3]");
        vif->set_as_stimulated("B[0]");
        vif->set_as_stimulated("B[1]");
        vif->set_as_stimulated("B[2]");
        vif->set_as_stimulated("B[3]");
        vif->set_as_stimulated("C[0]");
        vif->set_as_stimulated("C[1]");
        vif->set_as_stimulated("C[2]");
        vif->set_as_stimulated("C[3]");
        vif->set_as_observable_mod("Q1[0]_mod");
        vif->set_as_observable_ref("Q1[0]_ref");
        vif->set_as_observable_mod("Q1[1]_mod");
        vif->set_as_observable_ref("Q1[1]_ref");
        vif->set_as_observable_mod("Q1[2]_mod");
        vif->set_as_observable_ref("Q1[2]_ref");
        vif->set_as_observable_mod("Q1[3]_mod");
        vif->set_as_observable_ref("Q1[3]_ref");
        vif->set_as_observable_mod("Q2[0]_mod");
        vif->set_as_observable_ref("Q2[0]_ref");
        vif->set_as_observable_mod("Q2[1]_mod");
        vif->set_as_observable_ref("Q2[1]_ref");
        vif->set_as_observable_mod("Q2[2]_mod");
        vif->set_as_observable_ref("Q2[2]_ref");
        vif->set_as_observable_mod("Q2[3]_mod");
        vif->set_as_observable_ref("Q2[3]_ref");
        vif->set_as_observable_mod("Q3[0]_mod");
        vif->set_as_observable_ref("Q3[0]_ref");
        vif->set_as_observable_mod("Q3[1]_mod");
        vif->set_as_observable_ref("Q3[1]_ref");
        vif->set_as_observable_mod("Q3[2]_mod");
        vif->set_as_observable_ref("Q3[2]_ref");
        vif->set_as_observable_mod("Q3[3]_mod");
        vif->set_as_observable_ref("Q3[3]_ref");

        // Add interface to configuration database
        uvm::uvm_config_db<ut_fault_registry*>::set(
          uvm::uvm_root::get(), "*", "flt_reg", flt_reg);
    }
};
