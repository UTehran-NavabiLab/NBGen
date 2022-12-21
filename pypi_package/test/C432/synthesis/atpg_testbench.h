#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include "systemc.h"
#include "systemC_netlist.h"
#include "idd_testing.h"
#include "utilities.h"


using namespace sc_core;

SC_MODULE( testbench ) {

    sc_signal<sc_logic> in4 = sc_signal<sc_logic>("in4");
    sc_signal<sc_logic> in17 = sc_signal<sc_logic>("in17");
    sc_signal<sc_logic> in30 = sc_signal<sc_logic>("in30");
    sc_signal<sc_logic> in43 = sc_signal<sc_logic>("in43");
    sc_signal<sc_logic> in56 = sc_signal<sc_logic>("in56");
    sc_signal<sc_logic> in69 = sc_signal<sc_logic>("in69");
    sc_signal<sc_logic> in82 = sc_signal<sc_logic>("in82");
    sc_signal<sc_logic> in95 = sc_signal<sc_logic>("in95");
    sc_signal<sc_logic> in108 = sc_signal<sc_logic>("in108");
    sc_signal<sc_logic> in1 = sc_signal<sc_logic>("in1");
    sc_signal<sc_logic> in11 = sc_signal<sc_logic>("in11");
    sc_signal<sc_logic> in24 = sc_signal<sc_logic>("in24");
    sc_signal<sc_logic> in37 = sc_signal<sc_logic>("in37");
    sc_signal<sc_logic> in50 = sc_signal<sc_logic>("in50");
    sc_signal<sc_logic> in63 = sc_signal<sc_logic>("in63");
    sc_signal<sc_logic> in76 = sc_signal<sc_logic>("in76");
    sc_signal<sc_logic> in89 = sc_signal<sc_logic>("in89");
    sc_signal<sc_logic> in102 = sc_signal<sc_logic>("in102");
    sc_signal<sc_logic> in8 = sc_signal<sc_logic>("in8");
    sc_signal<sc_logic> in21 = sc_signal<sc_logic>("in21");
    sc_signal<sc_logic> in34 = sc_signal<sc_logic>("in34");
    sc_signal<sc_logic> in47 = sc_signal<sc_logic>("in47");
    sc_signal<sc_logic> in60 = sc_signal<sc_logic>("in60");
    sc_signal<sc_logic> in73 = sc_signal<sc_logic>("in73");
    sc_signal<sc_logic> in86 = sc_signal<sc_logic>("in86");
    sc_signal<sc_logic> in99 = sc_signal<sc_logic>("in99");
    sc_signal<sc_logic> in112 = sc_signal<sc_logic>("in112");
    sc_signal<sc_logic> in14 = sc_signal<sc_logic>("in14");
    sc_signal<sc_logic> in27 = sc_signal<sc_logic>("in27");
    sc_signal<sc_logic> in40 = sc_signal<sc_logic>("in40");
    sc_signal<sc_logic> in53 = sc_signal<sc_logic>("in53");
    sc_signal<sc_logic> in66 = sc_signal<sc_logic>("in66");
    sc_signal<sc_logic> in79 = sc_signal<sc_logic>("in79");
    sc_signal<sc_logic> in92 = sc_signal<sc_logic>("in92");
    sc_signal<sc_logic> in105 = sc_signal<sc_logic>("in105");
    sc_signal<sc_logic> in115 = sc_signal<sc_logic>("in115");
    sc_signal<sc_logic> out223 = sc_signal<sc_logic>("out223");
    sc_signal<sc_logic> out329 = sc_signal<sc_logic>("out329");
    sc_signal<sc_logic> out370 = sc_signal<sc_logic>("out370");
    sc_signal<sc_logic> out421 = sc_signal<sc_logic>("out421");
    sc_signal<sc_logic> out430 = sc_signal<sc_logic>("out430");
    sc_signal<sc_logic> out431 = sc_signal<sc_logic>("out431");
    sc_signal<sc_logic> out432 = sc_signal<sc_logic>("out432");

    sc_event ready2update;

    Circuit432* cut;
    itest idd_test = itest("gate_signal_json_file.json", "gate_properties.json");
    std::array<sc_core::sc_signal<sc_dt::sc_logic>*, 152> signal_arr;

    SC_HAS_PROCESS(testbench);
    testbench(sc_module_name _name){
        cut = new Circuit432("cut");
            cut->in4(in4);
            cut->in17(in17);
            cut->in30(in30);
            cut->in43(in43);
            cut->in56(in56);
            cut->in69(in69);
            cut->in82(in82);
            cut->in95(in95);
            cut->in108(in108);
            cut->in1(in1);
            cut->in11(in11);
            cut->in24(in24);
            cut->in37(in37);
            cut->in50(in50);
            cut->in63(in63);
            cut->in76(in76);
            cut->in89(in89);
            cut->in102(in102);
            cut->in8(in8);
            cut->in21(in21);
            cut->in34(in34);
            cut->in47(in47);
            cut->in60(in60);
            cut->in73(in73);
            cut->in86(in86);
            cut->in99(in99);
            cut->in112(in112);
            cut->in14(in14);
            cut->in27(in27);
            cut->in40(in40);
            cut->in53(in53);
            cut->in66(in66);
            cut->in79(in79);
            cut->in92(in92);
            cut->in105(in105);
            cut->in115(in115);
            cut->out223(out223);
            cut->out329(out329);
            cut->out370(out370);
            cut->out421(out421);
            cut->out430(out430);
            cut->out431(out431);
            cut->out432(out432);

        SC_THREAD(signaling);

        SC_METHOD(run_idd_testing);
            sensitive << ready2update;
            dont_initialize();

        access_signals();


    }

    void signaling(void){
        for (int i=0; i < pow(2, 36); i++){
            in4.write(input_signalling(0, i));
            in17.write(input_signalling(1, i));
            in30.write(input_signalling(2, i));
            in43.write(input_signalling(3, i));
            in56.write(input_signalling(4, i));
            in69.write(input_signalling(5, i));
            in82.write(input_signalling(6, i));
            in95.write(input_signalling(7, i));
            in108.write(input_signalling(8, i));
            in1.write(input_signalling(9, i));
            in11.write(input_signalling(10, i));
            in24.write(input_signalling(11, i));
            in37.write(input_signalling(12, i));
            in50.write(input_signalling(13, i));
            in63.write(input_signalling(14, i));
            in76.write(input_signalling(15, i));
            in89.write(input_signalling(16, i));
            in102.write(input_signalling(17, i));
            in8.write(input_signalling(18, i));
            in21.write(input_signalling(19, i));
            in34.write(input_signalling(20, i));
            in47.write(input_signalling(21, i));
            in60.write(input_signalling(22, i));
            in73.write(input_signalling(23, i));
            in86.write(input_signalling(24, i));
            in99.write(input_signalling(25, i));
            in112.write(input_signalling(26, i));
            in14.write(input_signalling(27, i));
            in27.write(input_signalling(28, i));
            in40.write(input_signalling(29, i));
            in53.write(input_signalling(30, i));
            in66.write(input_signalling(31, i));
            in79.write(input_signalling(32, i));
            in92.write(input_signalling(33, i));
            in105.write(input_signalling(34, i));
            in115.write(input_signalling(35, i));
            wait(SC_ZERO_TIME);
            std::cout << "--------- Apply New input vector: " << std::endl; 
            std::cout << "input signals:  in4, in17, in30, in43, in56, in69, in82, in95, in108, in1, in11, in24, in37, in50, in63, in76, in89, in102, in8, in21, in34, in47, in60, in73, in86, in99, in112, in14, in27, in40, in53, in66, in79, in92, in105, in115 = " << in4.read() << in17.read() << in30.read() << in43.read() << in56.read() << in69.read() << in82.read() << in95.read() << in108.read() << in1.read() << in11.read() << in24.read() << in37.read() << in50.read() << in63.read() << in76.read() << in89.read() << in102.read() << in8.read() << in21.read() << in34.read() << in47.read() << in60.read() << in73.read() << in86.read() << in99.read() << in112.read() << in14.read() << in27.read() << in40.read() << in53.read() << in66.read() << in79.read() << in92.read() << in105.read() << in115.read()  << std::endl; 
            wait(5, SC_NS);
            ready2update.notify();
            wait(SC_ZERO_TIME);
        }
    }

    void run_idd_testing(void){
        idd_test.update_signal<sc_dt::sc_logic, 152>(signal_arr);
        idd_test.back_trace("out223");
        idd_test.back_trace("out329");
        idd_test.back_trace("out370");
        idd_test.back_trace("out421");
        idd_test.back_trace("out430");
        idd_test.back_trace("out431");
        idd_test.back_trace("out432");
        idd_test.mark_multiplath();
        idd_test.print_critical_path_list();
        idd_test.clear_critical_path_list();
    }

    void access_signals(void){
        signal_arr[0] = &(in4);
        idd_test.add_to_port_list("in4");
        signal_arr[1] = &(in17);
        idd_test.add_to_port_list("in17");
        signal_arr[2] = &(in30);
        idd_test.add_to_port_list("in30");
        signal_arr[3] = &(in43);
        idd_test.add_to_port_list("in43");
        signal_arr[4] = &(in56);
        idd_test.add_to_port_list("in56");
        signal_arr[5] = &(in69);
        idd_test.add_to_port_list("in69");
        signal_arr[6] = &(in82);
        idd_test.add_to_port_list("in82");
        signal_arr[7] = &(in95);
        idd_test.add_to_port_list("in95");
        signal_arr[8] = &(in108);
        idd_test.add_to_port_list("in108");
        signal_arr[9] = &(in1);
        idd_test.add_to_port_list("in1");
        signal_arr[10] = &(in11);
        idd_test.add_to_port_list("in11");
        signal_arr[11] = &(in24);
        idd_test.add_to_port_list("in24");
        signal_arr[12] = &(in37);
        idd_test.add_to_port_list("in37");
        signal_arr[13] = &(in50);
        idd_test.add_to_port_list("in50");
        signal_arr[14] = &(in63);
        idd_test.add_to_port_list("in63");
        signal_arr[15] = &(in76);
        idd_test.add_to_port_list("in76");
        signal_arr[16] = &(in89);
        idd_test.add_to_port_list("in89");
        signal_arr[17] = &(in102);
        idd_test.add_to_port_list("in102");
        signal_arr[18] = &(in8);
        idd_test.add_to_port_list("in8");
        signal_arr[19] = &(in21);
        idd_test.add_to_port_list("in21");
        signal_arr[20] = &(in34);
        idd_test.add_to_port_list("in34");
        signal_arr[21] = &(in47);
        idd_test.add_to_port_list("in47");
        signal_arr[22] = &(in60);
        idd_test.add_to_port_list("in60");
        signal_arr[23] = &(in73);
        idd_test.add_to_port_list("in73");
        signal_arr[24] = &(in86);
        idd_test.add_to_port_list("in86");
        signal_arr[25] = &(in99);
        idd_test.add_to_port_list("in99");
        signal_arr[26] = &(in112);
        idd_test.add_to_port_list("in112");
        signal_arr[27] = &(in14);
        idd_test.add_to_port_list("in14");
        signal_arr[28] = &(in27);
        idd_test.add_to_port_list("in27");
        signal_arr[29] = &(in40);
        idd_test.add_to_port_list("in40");
        signal_arr[30] = &(in53);
        idd_test.add_to_port_list("in53");
        signal_arr[31] = &(in66);
        idd_test.add_to_port_list("in66");
        signal_arr[32] = &(in79);
        idd_test.add_to_port_list("in79");
        signal_arr[33] = &(in92);
        idd_test.add_to_port_list("in92");
        signal_arr[34] = &(in105);
        idd_test.add_to_port_list("in105");
        signal_arr[35] = &(in115);
        idd_test.add_to_port_list("in115");
        signal_arr[36] = &(out223);
        signal_arr[37] = &(out329);
        signal_arr[38] = &(out370);
        signal_arr[39] = &(out421);
        signal_arr[40] = &(out430);
        signal_arr[41] = &(out431);
        signal_arr[42] = &(out432);
        signal_arr[43] = &(cut->Ckt432_I_0);
        signal_arr[44] = &(cut->Ckt432_I_1);
        signal_arr[45] = &(cut->Ckt432_I_2);
        signal_arr[46] = &(cut->Ckt432_I_3);
        signal_arr[47] = &(cut->Ckt432_I_4);
        signal_arr[48] = &(cut->Ckt432_I_5);
        signal_arr[49] = &(cut->Ckt432_I_6);
        signal_arr[50] = &(cut->Ckt432_I_7);
        signal_arr[51] = &(cut->Ckt432_I_8);
        signal_arr[52] = &(cut->Ckt432_M1_X1_0);
        signal_arr[53] = &(cut->Ckt432_M1_X1_1);
        signal_arr[54] = &(cut->Ckt432_M1_X1_2);
        signal_arr[55] = &(cut->Ckt432_M1_X1_3);
        signal_arr[56] = &(cut->Ckt432_M1_X1_4);
        signal_arr[57] = &(cut->Ckt432_M1_X1_5);
        signal_arr[58] = &(cut->Ckt432_M1_X1_6);
        signal_arr[59] = &(cut->Ckt432_M1_X1_7);
        signal_arr[60] = &(cut->Ckt432_M1_X1_8);
        signal_arr[61] = &(cut->Ckt432_M1_n1);
        signal_arr[62] = &(cut->Ckt432_M1_n10);
        signal_arr[63] = &(cut->Ckt432_M1_n11);
        signal_arr[64] = &(cut->Ckt432_M1_n12);
        signal_arr[65] = &(cut->Ckt432_M1_n13);
        signal_arr[66] = &(cut->Ckt432_M1_n14);
        signal_arr[67] = &(cut->Ckt432_M1_n15);
        signal_arr[68] = &(cut->Ckt432_M1_n2);
        signal_arr[69] = &(cut->Ckt432_M1_n3);
        signal_arr[70] = &(cut->Ckt432_M1_n4);
        signal_arr[71] = &(cut->Ckt432_M1_n5);
        signal_arr[72] = &(cut->Ckt432_M1_n6);
        signal_arr[73] = &(cut->Ckt432_M1_n7);
        signal_arr[74] = &(cut->Ckt432_M1_n8);
        signal_arr[75] = &(cut->Ckt432_M1_n9);
        signal_arr[76] = &(cut->Ckt432_M2_X2_0);
        signal_arr[77] = &(cut->Ckt432_M2_X2_1);
        signal_arr[78] = &(cut->Ckt432_M2_X2_2);
        signal_arr[79] = &(cut->Ckt432_M2_X2_3);
        signal_arr[80] = &(cut->Ckt432_M2_X2_4);
        signal_arr[81] = &(cut->Ckt432_M2_X2_5);
        signal_arr[82] = &(cut->Ckt432_M2_X2_6);
        signal_arr[83] = &(cut->Ckt432_M2_X2_7);
        signal_arr[84] = &(cut->Ckt432_M2_X2_8);
        signal_arr[85] = &(cut->Ckt432_M2_n1);
        signal_arr[86] = &(cut->Ckt432_M2_n10);
        signal_arr[87] = &(cut->Ckt432_M2_n11);
        signal_arr[88] = &(cut->Ckt432_M2_n12);
        signal_arr[89] = &(cut->Ckt432_M2_n13);
        signal_arr[90] = &(cut->Ckt432_M2_n14);
        signal_arr[91] = &(cut->Ckt432_M2_n15);
        signal_arr[92] = &(cut->Ckt432_M2_n16);
        signal_arr[93] = &(cut->Ckt432_M2_n17);
        signal_arr[94] = &(cut->Ckt432_M2_n18);
        signal_arr[95] = &(cut->Ckt432_M2_n19);
        signal_arr[96] = &(cut->Ckt432_M2_n2);
        signal_arr[97] = &(cut->Ckt432_M2_n20);
        signal_arr[98] = &(cut->Ckt432_M2_n3);
        signal_arr[99] = &(cut->Ckt432_M2_n4);
        signal_arr[100] = &(cut->Ckt432_M2_n5);
        signal_arr[101] = &(cut->Ckt432_M2_n6);
        signal_arr[102] = &(cut->Ckt432_M2_n7);
        signal_arr[103] = &(cut->Ckt432_M2_n8);
        signal_arr[104] = &(cut->Ckt432_M2_n9);
        signal_arr[105] = &(cut->Ckt432_M3_n1);
        signal_arr[106] = &(cut->Ckt432_M3_n10);
        signal_arr[107] = &(cut->Ckt432_M3_n11);
        signal_arr[108] = &(cut->Ckt432_M3_n12);
        signal_arr[109] = &(cut->Ckt432_M3_n13);
        signal_arr[110] = &(cut->Ckt432_M3_n14);
        signal_arr[111] = &(cut->Ckt432_M3_n15);
        signal_arr[112] = &(cut->Ckt432_M3_n16);
        signal_arr[113] = &(cut->Ckt432_M3_n17);
        signal_arr[114] = &(cut->Ckt432_M3_n18);
        signal_arr[115] = &(cut->Ckt432_M3_n19);
        signal_arr[116] = &(cut->Ckt432_M3_n2);
        signal_arr[117] = &(cut->Ckt432_M3_n20);
        signal_arr[118] = &(cut->Ckt432_M3_n3);
        signal_arr[119] = &(cut->Ckt432_M3_n4);
        signal_arr[120] = &(cut->Ckt432_M3_n5);
        signal_arr[121] = &(cut->Ckt432_M3_n6);
        signal_arr[122] = &(cut->Ckt432_M3_n7);
        signal_arr[123] = &(cut->Ckt432_M3_n8);
        signal_arr[124] = &(cut->Ckt432_M3_n9);
        signal_arr[125] = &(cut->Ckt432_M4_n1);
        signal_arr[126] = &(cut->Ckt432_M4_n10);
        signal_arr[127] = &(cut->Ckt432_M4_n11);
        signal_arr[128] = &(cut->Ckt432_M4_n12);
        signal_arr[129] = &(cut->Ckt432_M4_n13);
        signal_arr[130] = &(cut->Ckt432_M4_n14);
        signal_arr[131] = &(cut->Ckt432_M4_n15);
        signal_arr[132] = &(cut->Ckt432_M4_n16);
        signal_arr[133] = &(cut->Ckt432_M4_n17);
        signal_arr[134] = &(cut->Ckt432_M4_n18);
        signal_arr[135] = &(cut->Ckt432_M4_n2);
        signal_arr[136] = &(cut->Ckt432_M4_n3);
        signal_arr[137] = &(cut->Ckt432_M4_n4);
        signal_arr[138] = &(cut->Ckt432_M4_n5);
        signal_arr[139] = &(cut->Ckt432_M4_n6);
        signal_arr[140] = &(cut->Ckt432_M4_n7);
        signal_arr[141] = &(cut->Ckt432_M4_n8);
        signal_arr[142] = &(cut->Ckt432_M4_n9);
        signal_arr[143] = &(cut->Ckt432_M5_n1);
        signal_arr[144] = &(cut->Ckt432_M5_n2);
        signal_arr[145] = &(cut->Ckt432_M5_n3);
        signal_arr[146] = &(cut->Ckt432_M5_n4);
        signal_arr[147] = &(cut->Ckt432_M5_n5);
        signal_arr[148] = &(cut->Ckt432_M5_n6);
        signal_arr[149] = &(cut->Ckt432_M5_n7);
        signal_arr[150] = &(cut->Ckt432_M5_n8);
        signal_arr[151] = &(cut->Ckt432_M5_n9);
    }

};
