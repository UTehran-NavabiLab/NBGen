#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include "systemc.h"
#include "power_netlist.h"
#include "utilities.h"
#include "power_analysis.h"


using namespace sc_core;

SC_MODULE( testbench ) {

    sc_signal_pw<sc_logic> N1 = sc_signal_pw<sc_logic>("N1");
    sc_signal_pw<sc_logic> N4 = sc_signal_pw<sc_logic>("N4");
    sc_signal_pw<sc_logic> N8 = sc_signal_pw<sc_logic>("N8");
    sc_signal_pw<sc_logic> N11 = sc_signal_pw<sc_logic>("N11");
    sc_signal_pw<sc_logic> N14 = sc_signal_pw<sc_logic>("N14");
    sc_signal_pw<sc_logic> N17 = sc_signal_pw<sc_logic>("N17");
    sc_signal_pw<sc_logic> N21 = sc_signal_pw<sc_logic>("N21");
    sc_signal_pw<sc_logic> N24 = sc_signal_pw<sc_logic>("N24");
    sc_signal_pw<sc_logic> N27 = sc_signal_pw<sc_logic>("N27");
    sc_signal_pw<sc_logic> N30 = sc_signal_pw<sc_logic>("N30");
    sc_signal_pw<sc_logic> N34 = sc_signal_pw<sc_logic>("N34");
    sc_signal_pw<sc_logic> N37 = sc_signal_pw<sc_logic>("N37");
    sc_signal_pw<sc_logic> N40 = sc_signal_pw<sc_logic>("N40");
    sc_signal_pw<sc_logic> N43 = sc_signal_pw<sc_logic>("N43");
    sc_signal_pw<sc_logic> N47 = sc_signal_pw<sc_logic>("N47");
    sc_signal_pw<sc_logic> N50 = sc_signal_pw<sc_logic>("N50");
    sc_signal_pw<sc_logic> N53 = sc_signal_pw<sc_logic>("N53");
    sc_signal_pw<sc_logic> N56 = sc_signal_pw<sc_logic>("N56");
    sc_signal_pw<sc_logic> N60 = sc_signal_pw<sc_logic>("N60");
    sc_signal_pw<sc_logic> N63 = sc_signal_pw<sc_logic>("N63");
    sc_signal_pw<sc_logic> N66 = sc_signal_pw<sc_logic>("N66");
    sc_signal_pw<sc_logic> N69 = sc_signal_pw<sc_logic>("N69");
    sc_signal_pw<sc_logic> N73 = sc_signal_pw<sc_logic>("N73");
    sc_signal_pw<sc_logic> N76 = sc_signal_pw<sc_logic>("N76");
    sc_signal_pw<sc_logic> N79 = sc_signal_pw<sc_logic>("N79");
    sc_signal_pw<sc_logic> N82 = sc_signal_pw<sc_logic>("N82");
    sc_signal_pw<sc_logic> N86 = sc_signal_pw<sc_logic>("N86");
    sc_signal_pw<sc_logic> N89 = sc_signal_pw<sc_logic>("N89");
    sc_signal_pw<sc_logic> N92 = sc_signal_pw<sc_logic>("N92");
    sc_signal_pw<sc_logic> N95 = sc_signal_pw<sc_logic>("N95");
    sc_signal_pw<sc_logic> N99 = sc_signal_pw<sc_logic>("N99");
    sc_signal_pw<sc_logic> N102 = sc_signal_pw<sc_logic>("N102");
    sc_signal_pw<sc_logic> N105 = sc_signal_pw<sc_logic>("N105");
    sc_signal_pw<sc_logic> N108 = sc_signal_pw<sc_logic>("N108");
    sc_signal_pw<sc_logic> N112 = sc_signal_pw<sc_logic>("N112");
    sc_signal_pw<sc_logic> N115 = sc_signal_pw<sc_logic>("N115");
    sc_signal_pw<sc_logic> N223 = sc_signal_pw<sc_logic>("N223");
    sc_signal_pw<sc_logic> N329 = sc_signal_pw<sc_logic>("N329");
    sc_signal_pw<sc_logic> N370 = sc_signal_pw<sc_logic>("N370");
    sc_signal_pw<sc_logic> N421 = sc_signal_pw<sc_logic>("N421");
    sc_signal_pw<sc_logic> N430 = sc_signal_pw<sc_logic>("N430");
    sc_signal_pw<sc_logic> N431 = sc_signal_pw<sc_logic>("N431");
    sc_signal_pw<sc_logic> N432 = sc_signal_pw<sc_logic>("N432");
    sc_event ready2update;
    sc_event ready2reset;

    c432* cut;
    power_analysis* power_module;
    std::array<sc_signal_pw<sc_logic>*, 175> signal_arr;
    std::array<sc_signal_pw<sc_logic>*, 36> input_arr;

    SC_HAS_PROCESS(testbench);
    testbench(sc_module_name _name){
        power_module = new power_analysis();
            power_module->read_gate_prop_json("gate_properties.json");
            power_module->read_gate_signal_json("gate_signal_json_file.json", "gate_properties.json");
            power_module->tech_parameter_json("45nm_timing_power.json");
            power_module->read_net_cap_json("gate_cap.json");
        cut = new c432("cut");
            cut->N1(N1);
            cut->N4(N4);
            cut->N8(N8);
            cut->N11(N11);
            cut->N14(N14);
            cut->N17(N17);
            cut->N21(N21);
            cut->N24(N24);
            cut->N27(N27);
            cut->N30(N30);
            cut->N34(N34);
            cut->N37(N37);
            cut->N40(N40);
            cut->N43(N43);
            cut->N47(N47);
            cut->N50(N50);
            cut->N53(N53);
            cut->N56(N56);
            cut->N60(N60);
            cut->N63(N63);
            cut->N66(N66);
            cut->N69(N69);
            cut->N73(N73);
            cut->N76(N76);
            cut->N79(N79);
            cut->N82(N82);
            cut->N86(N86);
            cut->N89(N89);
            cut->N92(N92);
            cut->N95(N95);
            cut->N99(N99);
            cut->N102(N102);
            cut->N105(N105);
            cut->N108(N108);
            cut->N112(N112);
            cut->N115(N115);
            cut->N223(N223);
            cut->N329(N329);
            cut->N370(N370);
            cut->N421(N421);
            cut->N430(N430);
            cut->N431(N431);
            cut->N432(N432);

        SC_THREAD(signaling);

        SC_METHOD(power_on_cycle);
            sensitive << ready2update;
            dont_initialize();

        access_signals();


    }

    void signaling(void){
        wait(SC_ZERO_TIME);
        reset_togglings();
        wait(10, SC_NS);
        apply_input_vector<sc_dt::sc_logic, 36>(input_arr, ("111111111111111111111111111111111111"));
        wait(SC_ZERO_TIME);
        wait(10, SC_NS);
        ready2update.notify();
    }

    void power_on_cycle(void){
        power_module->update_signal<sc_dt::sc_logic, 175>(signal_arr);
        std::vector<std::string> input_signal_name = {"N1", "N4", "N8", "N11", "N14", "N17", "N21", "N24", "N27", "N30", "N34", "N37", "N40", "N43", "N47", "N50", "N53", "N56", "N60", "N63", "N66", "N69", "N73", "N76", "N79", "N82", "N86", "N89", "N92", "N95", "N99", "N102", "N105", "N108", "N112", "N115"};
        power_module->timing_analysis("test", input_signal_name);
        std::vector<float> pwr_AND2_X1_1 = power_module->power_per_gate("AND2_X1_1");
        std::vector<float> pwr_AND2_X1_2 = power_module->power_per_gate("AND2_X1_2");
        std::vector<float> pwr_AND2_X1_3 = power_module->power_per_gate("AND2_X1_3");
        std::vector<float> pwr_AND2_X1_4 = power_module->power_per_gate("AND2_X1_4");
        std::vector<float> pwr_AND4_X1_1 = power_module->power_per_gate("AND4_X1_1");
        std::vector<float> pwr_AND4_X1_2 = power_module->power_per_gate("AND4_X1_2");
        std::vector<float> pwr_AOI211_X1_1 = power_module->power_per_gate("AOI211_X1_1");
        std::vector<float> pwr_AOI21_X1_1 = power_module->power_per_gate("AOI21_X1_1");
        std::vector<float> pwr_AOI21_X1_2 = power_module->power_per_gate("AOI21_X1_2");
        std::vector<float> pwr_AOI21_X1_3 = power_module->power_per_gate("AOI21_X1_3");
        std::vector<float> pwr_AOI21_X1_4 = power_module->power_per_gate("AOI21_X1_4");
        std::vector<float> pwr_AOI21_X1_5 = power_module->power_per_gate("AOI21_X1_5");
        std::vector<float> pwr_AOI21_X1_6 = power_module->power_per_gate("AOI21_X1_6");
        std::vector<float> pwr_AOI21_X1_7 = power_module->power_per_gate("AOI21_X1_7");
        std::vector<float> pwr_AOI21_X1_8 = power_module->power_per_gate("AOI21_X1_8");
        std::vector<float> pwr_AOI21_X1_9 = power_module->power_per_gate("AOI21_X1_9");
        std::vector<float> pwr_AOI22_X1_1 = power_module->power_per_gate("AOI22_X1_1");
        std::vector<float> pwr_AOI22_X1_2 = power_module->power_per_gate("AOI22_X1_2");
        std::vector<float> pwr_AOI22_X1_3 = power_module->power_per_gate("AOI22_X1_3");
        std::vector<float> pwr_AOI22_X1_4 = power_module->power_per_gate("AOI22_X1_4");
        std::vector<float> pwr_AOI22_X1_5 = power_module->power_per_gate("AOI22_X1_5");
        std::vector<float> pwr_AOI22_X1_6 = power_module->power_per_gate("AOI22_X1_6");
        std::vector<float> pwr_AOI22_X1_7 = power_module->power_per_gate("AOI22_X1_7");
        std::vector<float> pwr_AOI22_X1_8 = power_module->power_per_gate("AOI22_X1_8");
        std::vector<float> pwr_AOI22_X1_9 = power_module->power_per_gate("AOI22_X1_9");
        std::vector<float> pwr_AOI22_X1_10 = power_module->power_per_gate("AOI22_X1_10");
        std::vector<float> pwr_AOI22_X1_11 = power_module->power_per_gate("AOI22_X1_11");
        std::vector<float> pwr_BUF_X1_1 = power_module->power_per_gate("BUF_X1_1");
        std::vector<float> pwr_BUF_X1_2 = power_module->power_per_gate("BUF_X1_2");
        std::vector<float> pwr_BUF_X1_3 = power_module->power_per_gate("BUF_X1_3");
        std::vector<float> pwr_BUF_X1_4 = power_module->power_per_gate("BUF_X1_4");
        std::vector<float> pwr_BUF_X1_5 = power_module->power_per_gate("BUF_X1_5");
        std::vector<float> pwr_BUF_X1_6 = power_module->power_per_gate("BUF_X1_6");
        std::vector<float> pwr_BUF_X1_7 = power_module->power_per_gate("BUF_X1_7");
        std::vector<float> pwr_INV_X1_1 = power_module->power_per_gate("INV_X1_1");
        std::vector<float> pwr_INV_X1_2 = power_module->power_per_gate("INV_X1_2");
        std::vector<float> pwr_INV_X1_3 = power_module->power_per_gate("INV_X1_3");
        std::vector<float> pwr_INV_X1_4 = power_module->power_per_gate("INV_X1_4");
        std::vector<float> pwr_INV_X1_5 = power_module->power_per_gate("INV_X1_5");
        std::vector<float> pwr_INV_X1_6 = power_module->power_per_gate("INV_X1_6");
        std::vector<float> pwr_INV_X1_7 = power_module->power_per_gate("INV_X1_7");
        std::vector<float> pwr_INV_X1_8 = power_module->power_per_gate("INV_X1_8");
        std::vector<float> pwr_INV_X1_9 = power_module->power_per_gate("INV_X1_9");
        std::vector<float> pwr_INV_X1_10 = power_module->power_per_gate("INV_X1_10");
        std::vector<float> pwr_INV_X1_11 = power_module->power_per_gate("INV_X1_11");
        std::vector<float> pwr_INV_X1_12 = power_module->power_per_gate("INV_X1_12");
        std::vector<float> pwr_INV_X1_13 = power_module->power_per_gate("INV_X1_13");
        std::vector<float> pwr_INV_X1_14 = power_module->power_per_gate("INV_X1_14");
        std::vector<float> pwr_INV_X1_15 = power_module->power_per_gate("INV_X1_15");
        std::vector<float> pwr_INV_X1_16 = power_module->power_per_gate("INV_X1_16");
        std::vector<float> pwr_INV_X1_17 = power_module->power_per_gate("INV_X1_17");
        std::vector<float> pwr_INV_X1_18 = power_module->power_per_gate("INV_X1_18");
        std::vector<float> pwr_INV_X1_19 = power_module->power_per_gate("INV_X1_19");
        std::vector<float> pwr_INV_X1_20 = power_module->power_per_gate("INV_X1_20");
        std::vector<float> pwr_INV_X1_21 = power_module->power_per_gate("INV_X1_21");
        std::vector<float> pwr_INV_X1_22 = power_module->power_per_gate("INV_X1_22");
        std::vector<float> pwr_INV_X1_23 = power_module->power_per_gate("INV_X1_23");
        std::vector<float> pwr_INV_X1_24 = power_module->power_per_gate("INV_X1_24");
        std::vector<float> pwr_INV_X1_25 = power_module->power_per_gate("INV_X1_25");
        std::vector<float> pwr_INV_X1_26 = power_module->power_per_gate("INV_X1_26");
        std::vector<float> pwr_NAND2_X1_1 = power_module->power_per_gate("NAND2_X1_1");
        std::vector<float> pwr_NAND2_X1_2 = power_module->power_per_gate("NAND2_X1_2");
        std::vector<float> pwr_NAND2_X1_3 = power_module->power_per_gate("NAND2_X1_3");
        std::vector<float> pwr_NAND2_X1_4 = power_module->power_per_gate("NAND2_X1_4");
        std::vector<float> pwr_NAND2_X1_5 = power_module->power_per_gate("NAND2_X1_5");
        std::vector<float> pwr_NAND2_X1_6 = power_module->power_per_gate("NAND2_X1_6");
        std::vector<float> pwr_NAND2_X1_7 = power_module->power_per_gate("NAND2_X1_7");
        std::vector<float> pwr_NAND2_X1_8 = power_module->power_per_gate("NAND2_X1_8");
        std::vector<float> pwr_NAND2_X1_9 = power_module->power_per_gate("NAND2_X1_9");
        std::vector<float> pwr_NAND2_X1_10 = power_module->power_per_gate("NAND2_X1_10");
        std::vector<float> pwr_NAND2_X1_11 = power_module->power_per_gate("NAND2_X1_11");
        std::vector<float> pwr_NAND2_X1_12 = power_module->power_per_gate("NAND2_X1_12");
        std::vector<float> pwr_NAND2_X1_13 = power_module->power_per_gate("NAND2_X1_13");
        std::vector<float> pwr_NAND2_X1_14 = power_module->power_per_gate("NAND2_X1_14");
        std::vector<float> pwr_NAND2_X1_15 = power_module->power_per_gate("NAND2_X1_15");
        std::vector<float> pwr_NAND2_X1_16 = power_module->power_per_gate("NAND2_X1_16");
        std::vector<float> pwr_NAND2_X1_17 = power_module->power_per_gate("NAND2_X1_17");
        std::vector<float> pwr_NAND2_X1_18 = power_module->power_per_gate("NAND2_X1_18");
        std::vector<float> pwr_NAND2_X1_19 = power_module->power_per_gate("NAND2_X1_19");
        std::vector<float> pwr_NAND2_X1_20 = power_module->power_per_gate("NAND2_X1_20");
        std::vector<float> pwr_NAND2_X1_21 = power_module->power_per_gate("NAND2_X1_21");
        std::vector<float> pwr_NAND2_X1_22 = power_module->power_per_gate("NAND2_X1_22");
        std::vector<float> pwr_NAND2_X1_23 = power_module->power_per_gate("NAND2_X1_23");
        std::vector<float> pwr_NAND2_X1_24 = power_module->power_per_gate("NAND2_X1_24");
        std::vector<float> pwr_NAND2_X1_25 = power_module->power_per_gate("NAND2_X1_25");
        std::vector<float> pwr_NAND2_X1_26 = power_module->power_per_gate("NAND2_X1_26");
        std::vector<float> pwr_NAND3_X1_1 = power_module->power_per_gate("NAND3_X1_1");
        std::vector<float> pwr_NAND3_X1_2 = power_module->power_per_gate("NAND3_X1_2");
        std::vector<float> pwr_NAND4_X1_1 = power_module->power_per_gate("NAND4_X1_1");
        std::vector<float> pwr_NAND4_X1_2 = power_module->power_per_gate("NAND4_X1_2");
        std::vector<float> pwr_NAND4_X1_3 = power_module->power_per_gate("NAND4_X1_3");
        std::vector<float> pwr_NAND4_X1_4 = power_module->power_per_gate("NAND4_X1_4");
        std::vector<float> pwr_NOR2_X1_1 = power_module->power_per_gate("NOR2_X1_1");
        std::vector<float> pwr_NOR2_X1_2 = power_module->power_per_gate("NOR2_X1_2");
        std::vector<float> pwr_NOR2_X1_3 = power_module->power_per_gate("NOR2_X1_3");
        std::vector<float> pwr_NOR2_X1_4 = power_module->power_per_gate("NOR2_X1_4");
        std::vector<float> pwr_NOR2_X1_5 = power_module->power_per_gate("NOR2_X1_5");
        std::vector<float> pwr_NOR2_X1_6 = power_module->power_per_gate("NOR2_X1_6");
        std::vector<float> pwr_NOR2_X1_7 = power_module->power_per_gate("NOR2_X1_7");
        std::vector<float> pwr_NOR2_X1_8 = power_module->power_per_gate("NOR2_X1_8");
        std::vector<float> pwr_NOR2_X1_9 = power_module->power_per_gate("NOR2_X1_9");
        std::vector<float> pwr_NOR2_X1_10 = power_module->power_per_gate("NOR2_X1_10");
        std::vector<float> pwr_NOR2_X1_11 = power_module->power_per_gate("NOR2_X1_11");
        std::vector<float> pwr_NOR2_X1_12 = power_module->power_per_gate("NOR2_X1_12");
        std::vector<float> pwr_NOR2_X1_13 = power_module->power_per_gate("NOR2_X1_13");
        std::vector<float> pwr_NOR2_X1_14 = power_module->power_per_gate("NOR2_X1_14");
        std::vector<float> pwr_NOR2_X1_15 = power_module->power_per_gate("NOR2_X1_15");
        std::vector<float> pwr_NOR2_X1_16 = power_module->power_per_gate("NOR2_X1_16");
        std::vector<float> pwr_NOR2_X1_17 = power_module->power_per_gate("NOR2_X1_17");
        std::vector<float> pwr_NOR2_X1_18 = power_module->power_per_gate("NOR2_X1_18");
        std::vector<float> pwr_NOR2_X1_19 = power_module->power_per_gate("NOR2_X1_19");
        std::vector<float> pwr_OAI211_X1_1 = power_module->power_per_gate("OAI211_X1_1");
        std::vector<float> pwr_OAI211_X1_2 = power_module->power_per_gate("OAI211_X1_2");
        std::vector<float> pwr_OAI21_X1_1 = power_module->power_per_gate("OAI21_X1_1");
        std::vector<float> pwr_OAI21_X1_2 = power_module->power_per_gate("OAI21_X1_2");
        std::vector<float> pwr_OAI21_X1_3 = power_module->power_per_gate("OAI21_X1_3");
        std::vector<float> pwr_OAI21_X1_4 = power_module->power_per_gate("OAI21_X1_4");
        std::vector<float> pwr_OAI21_X1_5 = power_module->power_per_gate("OAI21_X1_5");
        std::vector<float> pwr_OAI21_X1_6 = power_module->power_per_gate("OAI21_X1_6");
        std::vector<float> pwr_OAI21_X1_7 = power_module->power_per_gate("OAI21_X1_7");
        std::vector<float> pwr_OAI21_X1_8 = power_module->power_per_gate("OAI21_X1_8");
        std::vector<float> pwr_OAI21_X1_9 = power_module->power_per_gate("OAI21_X1_9");
        std::vector<float> pwr_OAI21_X1_10 = power_module->power_per_gate("OAI21_X1_10");
        std::vector<float> pwr_OAI21_X1_11 = power_module->power_per_gate("OAI21_X1_11");
        std::vector<float> pwr_OAI21_X1_12 = power_module->power_per_gate("OAI21_X1_12");
        std::vector<float> pwr_OAI21_X1_13 = power_module->power_per_gate("OAI21_X1_13");
        std::vector<float> pwr_OAI21_X1_14 = power_module->power_per_gate("OAI21_X1_14");
        std::vector<float> pwr_OAI21_X1_15 = power_module->power_per_gate("OAI21_X1_15");
        std::vector<float> pwr_OAI21_X1_16 = power_module->power_per_gate("OAI21_X1_16");
        std::vector<float> pwr_OAI21_X1_17 = power_module->power_per_gate("OAI21_X1_17");
        std::vector<float> pwr_OAI21_X1_18 = power_module->power_per_gate("OAI21_X1_18");
        std::vector<float> pwr_OAI21_X1_19 = power_module->power_per_gate("OAI21_X1_19");
        std::vector<float> pwr_OAI21_X1_20 = power_module->power_per_gate("OAI21_X1_20");
        std::vector<float> pwr_OAI21_X1_21 = power_module->power_per_gate("OAI21_X1_21");
        std::vector<float> pwr_OAI21_X1_22 = power_module->power_per_gate("OAI21_X1_22");
        std::vector<float> pwr_OAI21_X1_23 = power_module->power_per_gate("OAI21_X1_23");
        std::vector<float> pwr_OAI21_X1_24 = power_module->power_per_gate("OAI21_X1_24");
        std::vector<float> pwr_OAI21_X1_25 = power_module->power_per_gate("OAI21_X1_25");
        std::vector<float> pwr_OR2_X1_1 = power_module->power_per_gate("OR2_X1_1");

        float dynamic_power = pwr_AND2_X1_1[0] + pwr_AND2_X1_2[0] + pwr_AND2_X1_3[0] + pwr_AND2_X1_4[0] + pwr_AND4_X1_1[0] + pwr_AND4_X1_2[0] + pwr_AOI211_X1_1[0] + pwr_AOI21_X1_1[0] + pwr_AOI21_X1_2[0] + pwr_AOI21_X1_3[0] + pwr_AOI21_X1_4[0] + pwr_AOI21_X1_5[0] + pwr_AOI21_X1_6[0] + pwr_AOI21_X1_7[0] + pwr_AOI21_X1_8[0] + pwr_AOI21_X1_9[0] + pwr_AOI22_X1_1[0] + pwr_AOI22_X1_2[0] + pwr_AOI22_X1_3[0] + pwr_AOI22_X1_4[0] + pwr_AOI22_X1_5[0] + pwr_AOI22_X1_6[0] + pwr_AOI22_X1_7[0] + pwr_AOI22_X1_8[0] + pwr_AOI22_X1_9[0] + pwr_AOI22_X1_10[0] + pwr_AOI22_X1_11[0] + pwr_BUF_X1_1[0] + pwr_BUF_X1_2[0] + pwr_BUF_X1_3[0] + pwr_BUF_X1_4[0] + pwr_BUF_X1_5[0] + pwr_BUF_X1_6[0] + pwr_BUF_X1_7[0] + pwr_INV_X1_1[0] + pwr_INV_X1_2[0] + pwr_INV_X1_3[0] + pwr_INV_X1_4[0] + pwr_INV_X1_5[0] + pwr_INV_X1_6[0] + pwr_INV_X1_7[0] + pwr_INV_X1_8[0] + pwr_INV_X1_9[0] + pwr_INV_X1_10[0] + pwr_INV_X1_11[0] + pwr_INV_X1_12[0] + pwr_INV_X1_13[0] + pwr_INV_X1_14[0] + pwr_INV_X1_15[0] + pwr_INV_X1_16[0] + pwr_INV_X1_17[0] + pwr_INV_X1_18[0] + pwr_INV_X1_19[0] + pwr_INV_X1_20[0] + pwr_INV_X1_21[0] + pwr_INV_X1_22[0] + pwr_INV_X1_23[0] + pwr_INV_X1_24[0] + pwr_INV_X1_25[0] + pwr_INV_X1_26[0] + pwr_NAND2_X1_1[0] + pwr_NAND2_X1_2[0] + pwr_NAND2_X1_3[0] + pwr_NAND2_X1_4[0] + pwr_NAND2_X1_5[0] + pwr_NAND2_X1_6[0] + pwr_NAND2_X1_7[0] + pwr_NAND2_X1_8[0] + pwr_NAND2_X1_9[0] + pwr_NAND2_X1_10[0] + pwr_NAND2_X1_11[0] + pwr_NAND2_X1_12[0] + pwr_NAND2_X1_13[0] + pwr_NAND2_X1_14[0] + pwr_NAND2_X1_15[0] + pwr_NAND2_X1_16[0] + pwr_NAND2_X1_17[0] + pwr_NAND2_X1_18[0] + pwr_NAND2_X1_19[0] + pwr_NAND2_X1_20[0] + pwr_NAND2_X1_21[0] + pwr_NAND2_X1_22[0] + pwr_NAND2_X1_23[0] + pwr_NAND2_X1_24[0] + pwr_NAND2_X1_25[0] + pwr_NAND2_X1_26[0] + pwr_NAND3_X1_1[0] + pwr_NAND3_X1_2[0] + pwr_NAND4_X1_1[0] + pwr_NAND4_X1_2[0] + pwr_NAND4_X1_3[0] + pwr_NAND4_X1_4[0] + pwr_NOR2_X1_1[0] + pwr_NOR2_X1_2[0] + pwr_NOR2_X1_3[0] + pwr_NOR2_X1_4[0] + pwr_NOR2_X1_5[0] + pwr_NOR2_X1_6[0] + pwr_NOR2_X1_7[0] + pwr_NOR2_X1_8[0] + pwr_NOR2_X1_9[0] + pwr_NOR2_X1_10[0] + pwr_NOR2_X1_11[0] + pwr_NOR2_X1_12[0] + pwr_NOR2_X1_13[0] + pwr_NOR2_X1_14[0] + pwr_NOR2_X1_15[0] + pwr_NOR2_X1_16[0] + pwr_NOR2_X1_17[0] + pwr_NOR2_X1_18[0] + pwr_NOR2_X1_19[0] + pwr_OAI211_X1_1[0] + pwr_OAI211_X1_2[0] + pwr_OAI21_X1_1[0] + pwr_OAI21_X1_2[0] + pwr_OAI21_X1_3[0] + pwr_OAI21_X1_4[0] + pwr_OAI21_X1_5[0] + pwr_OAI21_X1_6[0] + pwr_OAI21_X1_7[0] + pwr_OAI21_X1_8[0] + pwr_OAI21_X1_9[0] + pwr_OAI21_X1_10[0] + pwr_OAI21_X1_11[0] + pwr_OAI21_X1_12[0] + pwr_OAI21_X1_13[0] + pwr_OAI21_X1_14[0] + pwr_OAI21_X1_15[0] + pwr_OAI21_X1_16[0] + pwr_OAI21_X1_17[0] + pwr_OAI21_X1_18[0] + pwr_OAI21_X1_19[0] + pwr_OAI21_X1_20[0] + pwr_OAI21_X1_21[0] + pwr_OAI21_X1_22[0] + pwr_OAI21_X1_23[0] + pwr_OAI21_X1_24[0] + pwr_OAI21_X1_25[0] + pwr_OR2_X1_1[0] ;
        float net_switching_power = pwr_AND2_X1_1[1] + pwr_AND2_X1_2[1] + pwr_AND2_X1_3[1] + pwr_AND2_X1_4[1] + pwr_AND4_X1_1[1] + pwr_AND4_X1_2[1] + pwr_AOI211_X1_1[1] + pwr_AOI21_X1_1[1] + pwr_AOI21_X1_2[1] + pwr_AOI21_X1_3[1] + pwr_AOI21_X1_4[1] + pwr_AOI21_X1_5[1] + pwr_AOI21_X1_6[1] + pwr_AOI21_X1_7[1] + pwr_AOI21_X1_8[1] + pwr_AOI21_X1_9[1] + pwr_AOI22_X1_1[1] + pwr_AOI22_X1_2[1] + pwr_AOI22_X1_3[1] + pwr_AOI22_X1_4[1] + pwr_AOI22_X1_5[1] + pwr_AOI22_X1_6[1] + pwr_AOI22_X1_7[1] + pwr_AOI22_X1_8[1] + pwr_AOI22_X1_9[1] + pwr_AOI22_X1_10[1] + pwr_AOI22_X1_11[1] + pwr_BUF_X1_1[1] + pwr_BUF_X1_2[1] + pwr_BUF_X1_3[1] + pwr_BUF_X1_4[1] + pwr_BUF_X1_5[1] + pwr_BUF_X1_6[1] + pwr_BUF_X1_7[1] + pwr_INV_X1_1[1] + pwr_INV_X1_2[1] + pwr_INV_X1_3[1] + pwr_INV_X1_4[1] + pwr_INV_X1_5[1] + pwr_INV_X1_6[1] + pwr_INV_X1_7[1] + pwr_INV_X1_8[1] + pwr_INV_X1_9[1] + pwr_INV_X1_10[1] + pwr_INV_X1_11[1] + pwr_INV_X1_12[1] + pwr_INV_X1_13[1] + pwr_INV_X1_14[1] + pwr_INV_X1_15[1] + pwr_INV_X1_16[1] + pwr_INV_X1_17[1] + pwr_INV_X1_18[1] + pwr_INV_X1_19[1] + pwr_INV_X1_20[1] + pwr_INV_X1_21[1] + pwr_INV_X1_22[1] + pwr_INV_X1_23[1] + pwr_INV_X1_24[1] + pwr_INV_X1_25[1] + pwr_INV_X1_26[1] + pwr_NAND2_X1_1[1] + pwr_NAND2_X1_2[1] + pwr_NAND2_X1_3[1] + pwr_NAND2_X1_4[1] + pwr_NAND2_X1_5[1] + pwr_NAND2_X1_6[1] + pwr_NAND2_X1_7[1] + pwr_NAND2_X1_8[1] + pwr_NAND2_X1_9[1] + pwr_NAND2_X1_10[1] + pwr_NAND2_X1_11[1] + pwr_NAND2_X1_12[1] + pwr_NAND2_X1_13[1] + pwr_NAND2_X1_14[1] + pwr_NAND2_X1_15[1] + pwr_NAND2_X1_16[1] + pwr_NAND2_X1_17[1] + pwr_NAND2_X1_18[1] + pwr_NAND2_X1_19[1] + pwr_NAND2_X1_20[1] + pwr_NAND2_X1_21[1] + pwr_NAND2_X1_22[1] + pwr_NAND2_X1_23[1] + pwr_NAND2_X1_24[1] + pwr_NAND2_X1_25[1] + pwr_NAND2_X1_26[1] + pwr_NAND3_X1_1[1] + pwr_NAND3_X1_2[1] + pwr_NAND4_X1_1[1] + pwr_NAND4_X1_2[1] + pwr_NAND4_X1_3[1] + pwr_NAND4_X1_4[1] + pwr_NOR2_X1_1[1] + pwr_NOR2_X1_2[1] + pwr_NOR2_X1_3[1] + pwr_NOR2_X1_4[1] + pwr_NOR2_X1_5[1] + pwr_NOR2_X1_6[1] + pwr_NOR2_X1_7[1] + pwr_NOR2_X1_8[1] + pwr_NOR2_X1_9[1] + pwr_NOR2_X1_10[1] + pwr_NOR2_X1_11[1] + pwr_NOR2_X1_12[1] + pwr_NOR2_X1_13[1] + pwr_NOR2_X1_14[1] + pwr_NOR2_X1_15[1] + pwr_NOR2_X1_16[1] + pwr_NOR2_X1_17[1] + pwr_NOR2_X1_18[1] + pwr_NOR2_X1_19[1] + pwr_OAI211_X1_1[1] + pwr_OAI211_X1_2[1] + pwr_OAI21_X1_1[1] + pwr_OAI21_X1_2[1] + pwr_OAI21_X1_3[1] + pwr_OAI21_X1_4[1] + pwr_OAI21_X1_5[1] + pwr_OAI21_X1_6[1] + pwr_OAI21_X1_7[1] + pwr_OAI21_X1_8[1] + pwr_OAI21_X1_9[1] + pwr_OAI21_X1_10[1] + pwr_OAI21_X1_11[1] + pwr_OAI21_X1_12[1] + pwr_OAI21_X1_13[1] + pwr_OAI21_X1_14[1] + pwr_OAI21_X1_15[1] + pwr_OAI21_X1_16[1] + pwr_OAI21_X1_17[1] + pwr_OAI21_X1_18[1] + pwr_OAI21_X1_19[1] + pwr_OAI21_X1_20[1] + pwr_OAI21_X1_21[1] + pwr_OAI21_X1_22[1] + pwr_OAI21_X1_23[1] + pwr_OAI21_X1_24[1] + pwr_OAI21_X1_25[1] + pwr_OR2_X1_1[1] ;
        float total_power = dynamic_power + net_switching_power;
        std::cout << "net switching power: " << net_switching_power << std::endl;
        std::cout << "dynamic power : " << dynamic_power << std::endl;
        std::cout << "total power per cycle: " << total_power << std::endl;
        reset_togglings();
    }

    void reset_togglings(void){
        for(auto& signal_pointer: signal_arr){
            signal_pointer->reset_toggling();
            }
    }

    void access_signals(void){
        signal_arr[0] = &(N1);
        input_arr[0] = &(N1);
        power_module->set_transition_time("N1", 0.0);
        signal_arr[1] = &(N4);
        input_arr[1] = &(N4);
        power_module->set_transition_time("N4", 0.0);
        signal_arr[2] = &(N8);
        input_arr[2] = &(N8);
        power_module->set_transition_time("N8", 0.0);
        signal_arr[3] = &(N11);
        input_arr[3] = &(N11);
        power_module->set_transition_time("N11", 0.0);
        signal_arr[4] = &(N14);
        input_arr[4] = &(N14);
        power_module->set_transition_time("N14", 0.0);
        signal_arr[5] = &(N17);
        input_arr[5] = &(N17);
        power_module->set_transition_time("N17", 0.0);
        signal_arr[6] = &(N21);
        input_arr[6] = &(N21);
        power_module->set_transition_time("N21", 0.0);
        signal_arr[7] = &(N24);
        input_arr[7] = &(N24);
        power_module->set_transition_time("N24", 0.0);
        signal_arr[8] = &(N27);
        input_arr[8] = &(N27);
        power_module->set_transition_time("N27", 0.0);
        signal_arr[9] = &(N30);
        input_arr[9] = &(N30);
        power_module->set_transition_time("N30", 0.0);
        signal_arr[10] = &(N34);
        input_arr[10] = &(N34);
        power_module->set_transition_time("N34", 0.0);
        signal_arr[11] = &(N37);
        input_arr[11] = &(N37);
        power_module->set_transition_time("N37", 0.0);
        signal_arr[12] = &(N40);
        input_arr[12] = &(N40);
        power_module->set_transition_time("N40", 0.0);
        signal_arr[13] = &(N43);
        input_arr[13] = &(N43);
        power_module->set_transition_time("N43", 0.0);
        signal_arr[14] = &(N47);
        input_arr[14] = &(N47);
        power_module->set_transition_time("N47", 0.0);
        signal_arr[15] = &(N50);
        input_arr[15] = &(N50);
        power_module->set_transition_time("N50", 0.0);
        signal_arr[16] = &(N53);
        input_arr[16] = &(N53);
        power_module->set_transition_time("N53", 0.0);
        signal_arr[17] = &(N56);
        input_arr[17] = &(N56);
        power_module->set_transition_time("N56", 0.0);
        signal_arr[18] = &(N60);
        input_arr[18] = &(N60);
        power_module->set_transition_time("N60", 0.0);
        signal_arr[19] = &(N63);
        input_arr[19] = &(N63);
        power_module->set_transition_time("N63", 0.0);
        signal_arr[20] = &(N66);
        input_arr[20] = &(N66);
        power_module->set_transition_time("N66", 0.0);
        signal_arr[21] = &(N69);
        input_arr[21] = &(N69);
        power_module->set_transition_time("N69", 0.0);
        signal_arr[22] = &(N73);
        input_arr[22] = &(N73);
        power_module->set_transition_time("N73", 0.0);
        signal_arr[23] = &(N76);
        input_arr[23] = &(N76);
        power_module->set_transition_time("N76", 0.0);
        signal_arr[24] = &(N79);
        input_arr[24] = &(N79);
        power_module->set_transition_time("N79", 0.0);
        signal_arr[25] = &(N82);
        input_arr[25] = &(N82);
        power_module->set_transition_time("N82", 0.0);
        signal_arr[26] = &(N86);
        input_arr[26] = &(N86);
        power_module->set_transition_time("N86", 0.0);
        signal_arr[27] = &(N89);
        input_arr[27] = &(N89);
        power_module->set_transition_time("N89", 0.0);
        signal_arr[28] = &(N92);
        input_arr[28] = &(N92);
        power_module->set_transition_time("N92", 0.0);
        signal_arr[29] = &(N95);
        input_arr[29] = &(N95);
        power_module->set_transition_time("N95", 0.0);
        signal_arr[30] = &(N99);
        input_arr[30] = &(N99);
        power_module->set_transition_time("N99", 0.0);
        signal_arr[31] = &(N102);
        input_arr[31] = &(N102);
        power_module->set_transition_time("N102", 0.0);
        signal_arr[32] = &(N105);
        input_arr[32] = &(N105);
        power_module->set_transition_time("N105", 0.0);
        signal_arr[33] = &(N108);
        input_arr[33] = &(N108);
        power_module->set_transition_time("N108", 0.0);
        signal_arr[34] = &(N112);
        input_arr[34] = &(N112);
        power_module->set_transition_time("N112", 0.0);
        signal_arr[35] = &(N115);
        input_arr[35] = &(N115);
        power_module->set_transition_time("N115", 0.0);
        signal_arr[36] = &(N223);
        signal_arr[37] = &(N329);
        signal_arr[38] = &(N370);
        signal_arr[39] = &(N421);
        signal_arr[40] = &(N430);
        signal_arr[41] = &(N431);
        signal_arr[42] = &(N432);
        signal_arr[86] = &(cut->_0_);
        signal_arr[87] = &(cut->_100_);
        signal_arr[88] = &(cut->_101_);
        signal_arr[89] = &(cut->_102_);
        signal_arr[90] = &(cut->_103_);
        signal_arr[91] = &(cut->_104_);
        signal_arr[92] = &(cut->_105_);
        signal_arr[93] = &(cut->_106_);
        signal_arr[94] = &(cut->_107_);
        signal_arr[95] = &(cut->_108_);
        signal_arr[96] = &(cut->_109_);
        signal_arr[97] = &(cut->_10_);
        signal_arr[98] = &(cut->_110_);
        signal_arr[99] = &(cut->_111_);
        signal_arr[100] = &(cut->_112_);
        signal_arr[101] = &(cut->_113_);
        signal_arr[102] = &(cut->_114_);
        signal_arr[103] = &(cut->_115_);
        signal_arr[104] = &(cut->_116_);
        signal_arr[105] = &(cut->_117_);
        signal_arr[106] = &(cut->_118_);
        signal_arr[107] = &(cut->_119_);
        signal_arr[108] = &(cut->_11_);
        signal_arr[109] = &(cut->_120_);
        signal_arr[110] = &(cut->_121_);
        signal_arr[111] = &(cut->_122_);
        signal_arr[112] = &(cut->_123_);
        signal_arr[113] = &(cut->_124_);
        signal_arr[114] = &(cut->_125_);
        signal_arr[115] = &(cut->_126_);
        signal_arr[116] = &(cut->_127_);
        signal_arr[117] = &(cut->_128_);
        signal_arr[118] = &(cut->_129_);
        signal_arr[119] = &(cut->_12_);
        signal_arr[120] = &(cut->_130_);
        signal_arr[121] = &(cut->_131_);
        signal_arr[122] = &(cut->_13_);
        signal_arr[123] = &(cut->_14_);
        signal_arr[124] = &(cut->_15_);
        signal_arr[125] = &(cut->_16_);
        signal_arr[126] = &(cut->_17_);
        signal_arr[127] = &(cut->_18_);
        signal_arr[128] = &(cut->_19_);
        signal_arr[129] = &(cut->_1_);
        signal_arr[130] = &(cut->_20_);
        signal_arr[131] = &(cut->_21_);
        signal_arr[132] = &(cut->_22_);
        signal_arr[133] = &(cut->_23_);
        signal_arr[134] = &(cut->_24_);
        signal_arr[135] = &(cut->_25_);
        signal_arr[136] = &(cut->_26_);
        signal_arr[137] = &(cut->_27_);
        signal_arr[138] = &(cut->_28_);
        signal_arr[139] = &(cut->_29_);
        signal_arr[140] = &(cut->_2_);
        signal_arr[141] = &(cut->_30_);
        signal_arr[142] = &(cut->_31_);
        signal_arr[143] = &(cut->_32_);
        signal_arr[144] = &(cut->_33_);
        signal_arr[145] = &(cut->_34_);
        signal_arr[146] = &(cut->_35_);
        signal_arr[147] = &(cut->_36_);
        signal_arr[148] = &(cut->_37_);
        signal_arr[149] = &(cut->_38_);
        signal_arr[150] = &(cut->_39_);
        signal_arr[151] = &(cut->_3_);
        signal_arr[152] = &(cut->_40_);
        signal_arr[153] = &(cut->_41_);
        signal_arr[154] = &(cut->_42_);
        signal_arr[155] = &(cut->_43_);
        signal_arr[156] = &(cut->_44_);
        signal_arr[157] = &(cut->_45_);
        signal_arr[158] = &(cut->_46_);
        signal_arr[159] = &(cut->_47_);
        signal_arr[160] = &(cut->_48_);
        signal_arr[161] = &(cut->_49_);
        signal_arr[162] = &(cut->_4_);
        signal_arr[163] = &(cut->_50_);
        signal_arr[164] = &(cut->_51_);
        signal_arr[165] = &(cut->_52_);
        signal_arr[166] = &(cut->_53_);
        signal_arr[167] = &(cut->_54_);
        signal_arr[168] = &(cut->_55_);
        signal_arr[169] = &(cut->_56_);
        signal_arr[170] = &(cut->_57_);
        signal_arr[171] = &(cut->_58_);
        signal_arr[172] = &(cut->_59_);
        signal_arr[173] = &(cut->_5_);
        signal_arr[174] = &(cut->_60_);
        signal_arr[175] = &(cut->_61_);
        signal_arr[176] = &(cut->_62_);
        signal_arr[177] = &(cut->_63_);
        signal_arr[178] = &(cut->_64_);
        signal_arr[179] = &(cut->_65_);
        signal_arr[180] = &(cut->_66_);
        signal_arr[181] = &(cut->_67_);
        signal_arr[182] = &(cut->_68_);
        signal_arr[183] = &(cut->_69_);
        signal_arr[184] = &(cut->_6_);
        signal_arr[185] = &(cut->_70_);
        signal_arr[186] = &(cut->_71_);
        signal_arr[187] = &(cut->_72_);
        signal_arr[188] = &(cut->_73_);
        signal_arr[189] = &(cut->_74_);
        signal_arr[190] = &(cut->_75_);
        signal_arr[191] = &(cut->_76_);
        signal_arr[192] = &(cut->_77_);
        signal_arr[193] = &(cut->_78_);
        signal_arr[194] = &(cut->_79_);
        signal_arr[195] = &(cut->_7_);
        signal_arr[196] = &(cut->_80_);
        signal_arr[197] = &(cut->_81_);
        signal_arr[198] = &(cut->_82_);
        signal_arr[199] = &(cut->_83_);
        signal_arr[200] = &(cut->_84_);
        signal_arr[201] = &(cut->_85_);
        signal_arr[202] = &(cut->_86_);
        signal_arr[203] = &(cut->_87_);
        signal_arr[204] = &(cut->_88_);
        signal_arr[205] = &(cut->_89_);
        signal_arr[206] = &(cut->_8_);
        signal_arr[207] = &(cut->_90_);
        signal_arr[208] = &(cut->_91_);
        signal_arr[209] = &(cut->_92_);
        signal_arr[210] = &(cut->_93_);
        signal_arr[211] = &(cut->_94_);
        signal_arr[212] = &(cut->_95_);
        signal_arr[213] = &(cut->_96_);
        signal_arr[214] = &(cut->_97_);
        signal_arr[215] = &(cut->_98_);
        signal_arr[216] = &(cut->_99_);
        signal_arr[217] = &(cut->_9_);
    }

};