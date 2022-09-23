#include <systemc.h>
#include "Complex_NAgate_45.h"
#include "sc_signal_pw.h"

using namespace sc_core;

SC_MODULE( Circuit432 ) {

    sc_in<sc_logic> in4;
    sc_in<sc_logic> in17;
    sc_in<sc_logic> in30;
    sc_in<sc_logic> in43;
    sc_in<sc_logic> in56;
    sc_in<sc_logic> in69;
    sc_in<sc_logic> in82;
    sc_in<sc_logic> in95;
    sc_in<sc_logic> in108;
    sc_in<sc_logic> in1;
    sc_in<sc_logic> in11;
    sc_in<sc_logic> in24;
    sc_in<sc_logic> in37;
    sc_in<sc_logic> in50;
    sc_in<sc_logic> in63;
    sc_in<sc_logic> in76;
    sc_in<sc_logic> in89;
    sc_in<sc_logic> in102;
    sc_in<sc_logic> in8;
    sc_in<sc_logic> in21;
    sc_in<sc_logic> in34;
    sc_in<sc_logic> in47;
    sc_in<sc_logic> in60;
    sc_in<sc_logic> in73;
    sc_in<sc_logic> in86;
    sc_in<sc_logic> in99;
    sc_in<sc_logic> in112;
    sc_in<sc_logic> in14;
    sc_in<sc_logic> in27;
    sc_in<sc_logic> in40;
    sc_in<sc_logic> in53;
    sc_in<sc_logic> in66;
    sc_in<sc_logic> in79;
    sc_in<sc_logic> in92;
    sc_in<sc_logic> in105;
    sc_in<sc_logic> in115;
    sc_out<sc_logic> out223;
    sc_out<sc_logic> out329;
    sc_out<sc_logic> out370;
    sc_out<sc_logic> out421;
    sc_out<sc_logic> out430;
    sc_out<sc_logic> out431;
    sc_out<sc_logic> out432;

    sc_signal<sc_logic> sc_logic_1_signal;
    sc_signal<sc_logic> sc_logic_0_signal;

    sc_signal_pw<sc_logic> Ckt432_I_0 = sc_signal_pw<sc_logic>("Ckt432_I_0");
    sc_signal_pw<sc_logic> Ckt432_I_1 = sc_signal_pw<sc_logic>("Ckt432_I_1");
    sc_signal_pw<sc_logic> Ckt432_I_2 = sc_signal_pw<sc_logic>("Ckt432_I_2");
    sc_signal_pw<sc_logic> Ckt432_I_3 = sc_signal_pw<sc_logic>("Ckt432_I_3");
    sc_signal_pw<sc_logic> Ckt432_I_4 = sc_signal_pw<sc_logic>("Ckt432_I_4");
    sc_signal_pw<sc_logic> Ckt432_I_5 = sc_signal_pw<sc_logic>("Ckt432_I_5");
    sc_signal_pw<sc_logic> Ckt432_I_6 = sc_signal_pw<sc_logic>("Ckt432_I_6");
    sc_signal_pw<sc_logic> Ckt432_I_7 = sc_signal_pw<sc_logic>("Ckt432_I_7");
    sc_signal_pw<sc_logic> Ckt432_I_8 = sc_signal_pw<sc_logic>("Ckt432_I_8");
    sc_signal_pw<sc_logic> Ckt432_M1_X1_0 = sc_signal_pw<sc_logic>("Ckt432_M1_X1_0");
    sc_signal_pw<sc_logic> Ckt432_M1_X1_1 = sc_signal_pw<sc_logic>("Ckt432_M1_X1_1");
    sc_signal_pw<sc_logic> Ckt432_M1_X1_2 = sc_signal_pw<sc_logic>("Ckt432_M1_X1_2");
    sc_signal_pw<sc_logic> Ckt432_M1_X1_3 = sc_signal_pw<sc_logic>("Ckt432_M1_X1_3");
    sc_signal_pw<sc_logic> Ckt432_M1_X1_4 = sc_signal_pw<sc_logic>("Ckt432_M1_X1_4");
    sc_signal_pw<sc_logic> Ckt432_M1_X1_5 = sc_signal_pw<sc_logic>("Ckt432_M1_X1_5");
    sc_signal_pw<sc_logic> Ckt432_M1_X1_6 = sc_signal_pw<sc_logic>("Ckt432_M1_X1_6");
    sc_signal_pw<sc_logic> Ckt432_M1_X1_7 = sc_signal_pw<sc_logic>("Ckt432_M1_X1_7");
    sc_signal_pw<sc_logic> Ckt432_M1_X1_8 = sc_signal_pw<sc_logic>("Ckt432_M1_X1_8");
    sc_signal_pw<sc_logic> Ckt432_M1_n1 = sc_signal_pw<sc_logic>("Ckt432_M1_n1");
    sc_signal_pw<sc_logic> Ckt432_M1_n10 = sc_signal_pw<sc_logic>("Ckt432_M1_n10");
    sc_signal_pw<sc_logic> Ckt432_M1_n11 = sc_signal_pw<sc_logic>("Ckt432_M1_n11");
    sc_signal_pw<sc_logic> Ckt432_M1_n12 = sc_signal_pw<sc_logic>("Ckt432_M1_n12");
    sc_signal_pw<sc_logic> Ckt432_M1_n13 = sc_signal_pw<sc_logic>("Ckt432_M1_n13");
    sc_signal_pw<sc_logic> Ckt432_M1_n14 = sc_signal_pw<sc_logic>("Ckt432_M1_n14");
    sc_signal_pw<sc_logic> Ckt432_M1_n15 = sc_signal_pw<sc_logic>("Ckt432_M1_n15");
    sc_signal_pw<sc_logic> Ckt432_M1_n2 = sc_signal_pw<sc_logic>("Ckt432_M1_n2");
    sc_signal_pw<sc_logic> Ckt432_M1_n3 = sc_signal_pw<sc_logic>("Ckt432_M1_n3");
    sc_signal_pw<sc_logic> Ckt432_M1_n4 = sc_signal_pw<sc_logic>("Ckt432_M1_n4");
    sc_signal_pw<sc_logic> Ckt432_M1_n5 = sc_signal_pw<sc_logic>("Ckt432_M1_n5");
    sc_signal_pw<sc_logic> Ckt432_M1_n6 = sc_signal_pw<sc_logic>("Ckt432_M1_n6");
    sc_signal_pw<sc_logic> Ckt432_M1_n7 = sc_signal_pw<sc_logic>("Ckt432_M1_n7");
    sc_signal_pw<sc_logic> Ckt432_M1_n8 = sc_signal_pw<sc_logic>("Ckt432_M1_n8");
    sc_signal_pw<sc_logic> Ckt432_M1_n9 = sc_signal_pw<sc_logic>("Ckt432_M1_n9");
    sc_signal_pw<sc_logic> Ckt432_M2_X2_0 = sc_signal_pw<sc_logic>("Ckt432_M2_X2_0");
    sc_signal_pw<sc_logic> Ckt432_M2_X2_1 = sc_signal_pw<sc_logic>("Ckt432_M2_X2_1");
    sc_signal_pw<sc_logic> Ckt432_M2_X2_2 = sc_signal_pw<sc_logic>("Ckt432_M2_X2_2");
    sc_signal_pw<sc_logic> Ckt432_M2_X2_3 = sc_signal_pw<sc_logic>("Ckt432_M2_X2_3");
    sc_signal_pw<sc_logic> Ckt432_M2_X2_4 = sc_signal_pw<sc_logic>("Ckt432_M2_X2_4");
    sc_signal_pw<sc_logic> Ckt432_M2_X2_5 = sc_signal_pw<sc_logic>("Ckt432_M2_X2_5");
    sc_signal_pw<sc_logic> Ckt432_M2_X2_6 = sc_signal_pw<sc_logic>("Ckt432_M2_X2_6");
    sc_signal_pw<sc_logic> Ckt432_M2_X2_7 = sc_signal_pw<sc_logic>("Ckt432_M2_X2_7");
    sc_signal_pw<sc_logic> Ckt432_M2_X2_8 = sc_signal_pw<sc_logic>("Ckt432_M2_X2_8");
    sc_signal_pw<sc_logic> Ckt432_M2_n1 = sc_signal_pw<sc_logic>("Ckt432_M2_n1");
    sc_signal_pw<sc_logic> Ckt432_M2_n10 = sc_signal_pw<sc_logic>("Ckt432_M2_n10");
    sc_signal_pw<sc_logic> Ckt432_M2_n11 = sc_signal_pw<sc_logic>("Ckt432_M2_n11");
    sc_signal_pw<sc_logic> Ckt432_M2_n12 = sc_signal_pw<sc_logic>("Ckt432_M2_n12");
    sc_signal_pw<sc_logic> Ckt432_M2_n13 = sc_signal_pw<sc_logic>("Ckt432_M2_n13");
    sc_signal_pw<sc_logic> Ckt432_M2_n14 = sc_signal_pw<sc_logic>("Ckt432_M2_n14");
    sc_signal_pw<sc_logic> Ckt432_M2_n15 = sc_signal_pw<sc_logic>("Ckt432_M2_n15");
    sc_signal_pw<sc_logic> Ckt432_M2_n16 = sc_signal_pw<sc_logic>("Ckt432_M2_n16");
    sc_signal_pw<sc_logic> Ckt432_M2_n17 = sc_signal_pw<sc_logic>("Ckt432_M2_n17");
    sc_signal_pw<sc_logic> Ckt432_M2_n18 = sc_signal_pw<sc_logic>("Ckt432_M2_n18");
    sc_signal_pw<sc_logic> Ckt432_M2_n19 = sc_signal_pw<sc_logic>("Ckt432_M2_n19");
    sc_signal_pw<sc_logic> Ckt432_M2_n2 = sc_signal_pw<sc_logic>("Ckt432_M2_n2");
    sc_signal_pw<sc_logic> Ckt432_M2_n20 = sc_signal_pw<sc_logic>("Ckt432_M2_n20");
    sc_signal_pw<sc_logic> Ckt432_M2_n3 = sc_signal_pw<sc_logic>("Ckt432_M2_n3");
    sc_signal_pw<sc_logic> Ckt432_M2_n4 = sc_signal_pw<sc_logic>("Ckt432_M2_n4");
    sc_signal_pw<sc_logic> Ckt432_M2_n5 = sc_signal_pw<sc_logic>("Ckt432_M2_n5");
    sc_signal_pw<sc_logic> Ckt432_M2_n6 = sc_signal_pw<sc_logic>("Ckt432_M2_n6");
    sc_signal_pw<sc_logic> Ckt432_M2_n7 = sc_signal_pw<sc_logic>("Ckt432_M2_n7");
    sc_signal_pw<sc_logic> Ckt432_M2_n8 = sc_signal_pw<sc_logic>("Ckt432_M2_n8");
    sc_signal_pw<sc_logic> Ckt432_M2_n9 = sc_signal_pw<sc_logic>("Ckt432_M2_n9");
    sc_signal_pw<sc_logic> Ckt432_M3_n1 = sc_signal_pw<sc_logic>("Ckt432_M3_n1");
    sc_signal_pw<sc_logic> Ckt432_M3_n10 = sc_signal_pw<sc_logic>("Ckt432_M3_n10");
    sc_signal_pw<sc_logic> Ckt432_M3_n11 = sc_signal_pw<sc_logic>("Ckt432_M3_n11");
    sc_signal_pw<sc_logic> Ckt432_M3_n12 = sc_signal_pw<sc_logic>("Ckt432_M3_n12");
    sc_signal_pw<sc_logic> Ckt432_M3_n13 = sc_signal_pw<sc_logic>("Ckt432_M3_n13");
    sc_signal_pw<sc_logic> Ckt432_M3_n14 = sc_signal_pw<sc_logic>("Ckt432_M3_n14");
    sc_signal_pw<sc_logic> Ckt432_M3_n15 = sc_signal_pw<sc_logic>("Ckt432_M3_n15");
    sc_signal_pw<sc_logic> Ckt432_M3_n16 = sc_signal_pw<sc_logic>("Ckt432_M3_n16");
    sc_signal_pw<sc_logic> Ckt432_M3_n17 = sc_signal_pw<sc_logic>("Ckt432_M3_n17");
    sc_signal_pw<sc_logic> Ckt432_M3_n18 = sc_signal_pw<sc_logic>("Ckt432_M3_n18");
    sc_signal_pw<sc_logic> Ckt432_M3_n19 = sc_signal_pw<sc_logic>("Ckt432_M3_n19");
    sc_signal_pw<sc_logic> Ckt432_M3_n2 = sc_signal_pw<sc_logic>("Ckt432_M3_n2");
    sc_signal_pw<sc_logic> Ckt432_M3_n20 = sc_signal_pw<sc_logic>("Ckt432_M3_n20");
    sc_signal_pw<sc_logic> Ckt432_M3_n3 = sc_signal_pw<sc_logic>("Ckt432_M3_n3");
    sc_signal_pw<sc_logic> Ckt432_M3_n4 = sc_signal_pw<sc_logic>("Ckt432_M3_n4");
    sc_signal_pw<sc_logic> Ckt432_M3_n5 = sc_signal_pw<sc_logic>("Ckt432_M3_n5");
    sc_signal_pw<sc_logic> Ckt432_M3_n6 = sc_signal_pw<sc_logic>("Ckt432_M3_n6");
    sc_signal_pw<sc_logic> Ckt432_M3_n7 = sc_signal_pw<sc_logic>("Ckt432_M3_n7");
    sc_signal_pw<sc_logic> Ckt432_M3_n8 = sc_signal_pw<sc_logic>("Ckt432_M3_n8");
    sc_signal_pw<sc_logic> Ckt432_M3_n9 = sc_signal_pw<sc_logic>("Ckt432_M3_n9");
    sc_signal_pw<sc_logic> Ckt432_M4_n1 = sc_signal_pw<sc_logic>("Ckt432_M4_n1");
    sc_signal_pw<sc_logic> Ckt432_M4_n10 = sc_signal_pw<sc_logic>("Ckt432_M4_n10");
    sc_signal_pw<sc_logic> Ckt432_M4_n11 = sc_signal_pw<sc_logic>("Ckt432_M4_n11");
    sc_signal_pw<sc_logic> Ckt432_M4_n12 = sc_signal_pw<sc_logic>("Ckt432_M4_n12");
    sc_signal_pw<sc_logic> Ckt432_M4_n13 = sc_signal_pw<sc_logic>("Ckt432_M4_n13");
    sc_signal_pw<sc_logic> Ckt432_M4_n14 = sc_signal_pw<sc_logic>("Ckt432_M4_n14");
    sc_signal_pw<sc_logic> Ckt432_M4_n15 = sc_signal_pw<sc_logic>("Ckt432_M4_n15");
    sc_signal_pw<sc_logic> Ckt432_M4_n16 = sc_signal_pw<sc_logic>("Ckt432_M4_n16");
    sc_signal_pw<sc_logic> Ckt432_M4_n17 = sc_signal_pw<sc_logic>("Ckt432_M4_n17");
    sc_signal_pw<sc_logic> Ckt432_M4_n18 = sc_signal_pw<sc_logic>("Ckt432_M4_n18");
    sc_signal_pw<sc_logic> Ckt432_M4_n2 = sc_signal_pw<sc_logic>("Ckt432_M4_n2");
    sc_signal_pw<sc_logic> Ckt432_M4_n3 = sc_signal_pw<sc_logic>("Ckt432_M4_n3");
    sc_signal_pw<sc_logic> Ckt432_M4_n4 = sc_signal_pw<sc_logic>("Ckt432_M4_n4");
    sc_signal_pw<sc_logic> Ckt432_M4_n5 = sc_signal_pw<sc_logic>("Ckt432_M4_n5");
    sc_signal_pw<sc_logic> Ckt432_M4_n6 = sc_signal_pw<sc_logic>("Ckt432_M4_n6");
    sc_signal_pw<sc_logic> Ckt432_M4_n7 = sc_signal_pw<sc_logic>("Ckt432_M4_n7");
    sc_signal_pw<sc_logic> Ckt432_M4_n8 = sc_signal_pw<sc_logic>("Ckt432_M4_n8");
    sc_signal_pw<sc_logic> Ckt432_M4_n9 = sc_signal_pw<sc_logic>("Ckt432_M4_n9");
    sc_signal_pw<sc_logic> Ckt432_M5_n1 = sc_signal_pw<sc_logic>("Ckt432_M5_n1");
    sc_signal_pw<sc_logic> Ckt432_M5_n2 = sc_signal_pw<sc_logic>("Ckt432_M5_n2");
    sc_signal_pw<sc_logic> Ckt432_M5_n3 = sc_signal_pw<sc_logic>("Ckt432_M5_n3");
    sc_signal_pw<sc_logic> Ckt432_M5_n4 = sc_signal_pw<sc_logic>("Ckt432_M5_n4");
    sc_signal_pw<sc_logic> Ckt432_M5_n5 = sc_signal_pw<sc_logic>("Ckt432_M5_n5");
    sc_signal_pw<sc_logic> Ckt432_M5_n6 = sc_signal_pw<sc_logic>("Ckt432_M5_n6");
    sc_signal_pw<sc_logic> Ckt432_M5_n7 = sc_signal_pw<sc_logic>("Ckt432_M5_n7");
    sc_signal_pw<sc_logic> Ckt432_M5_n8 = sc_signal_pw<sc_logic>("Ckt432_M5_n8");
    sc_signal_pw<sc_logic> Ckt432_M5_n9 = sc_signal_pw<sc_logic>("Ckt432_M5_n9");

    OAI21_X1* OAI21_X1_1;
    OR2_X1* OR2_X1_1;
    OAI221_X1* OAI221_X1_1;
    INV_X1* INV_X1_1;
    OAI222_X1* OAI222_X1_1;
    INV_X1* INV_X1_2;
    INV_X1* INV_X1_3;
    INV_X1* INV_X1_4;
    INV_X1* INV_X1_5;
    INV_X1* INV_X1_6;
    OAI221_X1* OAI221_X1_2;
    OAI21_X1* OAI21_X1_2;
    INV_X1* INV_X1_7;
    OAI22_X1* OAI22_X1_1;
    INV_X1* INV_X1_8;
    INV_X1* INV_X1_9;
    INV_X1* INV_X1_10;
    INV_X1* INV_X1_11;
    OAI21_X1* OAI21_X1_3;
    OAI21_X1* OAI21_X1_4;
    OAI21_X1* OAI21_X1_5;
    OAI21_X1* OAI21_X1_6;
    OAI21_X1* OAI21_X1_7;
    OAI21_X1* OAI21_X1_8;
    OAI21_X1* OAI21_X1_9;
    NAND2_X1* NAND2_X1_1;
    NAND4_X1* NAND4_X1_1;
    AND4_X1* AND4_X1_1;
    NAND3_X1* NAND3_X1_1;
    INV_X1* INV_X1_12;
    NAND3_X1* NAND3_X1_2;
    INV_X1* INV_X1_13;
    NAND3_X1* NAND3_X1_3;
    INV_X1* INV_X1_14;
    NAND3_X1* NAND3_X1_4;
    INV_X1* INV_X1_15;
    NAND2_X1* NAND2_X1_2;
    AND3_X1* AND3_X1_1;
    NAND3_X1* NAND3_X1_5;
    INV_X1* INV_X1_16;
    NAND3_X1* NAND3_X1_6;
    INV_X1* INV_X1_17;
    NAND3_X1* NAND3_X1_7;
    INV_X1* INV_X1_18;
    NAND3_X1* NAND3_X1_8;
    INV_X1* INV_X1_19;
    NAND3_X1* NAND3_X1_9;
    NAND2_X1* NAND2_X1_3;
    INV_X1* INV_X1_20;
    NAND2_X1* NAND2_X1_4;
    NAND2_X1* NAND2_X1_5;
    NAND2_X1* NAND2_X1_6;
    NAND2_X1* NAND2_X1_7;
    NAND2_X1* NAND2_X1_8;
    NAND2_X1* NAND2_X1_9;
    NAND4_X1* NAND4_X1_2;
    INV_X1* INV_X1_21;
    AND3_X1* AND3_X1_2;
    NAND4_X1* NAND4_X1_3;
    INV_X1* INV_X1_22;
    NAND4_X1* NAND4_X1_4;
    INV_X1* INV_X1_23;
    NAND4_X1* NAND4_X1_5;
    INV_X1* INV_X1_24;
    NAND4_X1* NAND4_X1_6;
    INV_X1* INV_X1_25;
    AND4_X1* AND4_X1_2;
    NAND4_X1* NAND4_X1_7;
    INV_X1* INV_X1_26;
    NAND4_X1* NAND4_X1_8;
    INV_X1* INV_X1_27;
    NAND4_X1* NAND4_X1_9;
    INV_X1* INV_X1_28;
    NAND4_X1* NAND4_X1_10;
    INV_X1* INV_X1_29;
    NAND4_X1* NAND4_X1_11;
    NAND3_X1* NAND3_X1_10;
    NAND3_X1* NAND3_X1_11;
    AOI22_X1* AOI22_X1_1;
    NAND2_X1* NAND2_X1_10;
    NAND3_X1* NAND3_X1_12;
    AOI22_X1* AOI22_X1_2;
    NAND2_X1* NAND2_X1_11;
    NAND3_X1* NAND3_X1_13;
    AOI22_X1* AOI22_X1_3;
    NAND2_X1* NAND2_X1_12;
    NAND3_X1* NAND3_X1_14;
    AOI22_X1* AOI22_X1_4;
    AOI22_X1* AOI22_X1_5;
    NAND2_X1* NAND2_X1_13;
    NAND3_X1* NAND3_X1_15;
    AOI22_X1* AOI22_X1_6;
    NAND2_X1* NAND2_X1_14;
    NAND3_X1* NAND3_X1_16;
    AOI22_X1* AOI22_X1_7;
    NAND2_X1* NAND2_X1_15;
    NAND2_X1* NAND2_X1_16;
    NAND3_X1* NAND3_X1_17;
    AOI22_X1* AOI22_X1_8;
    NAND2_X1* NAND2_X1_17;
    NAND3_X1* NAND3_X1_18;
    AOI22_X1* AOI22_X1_9;
    NAND2_X1* NAND2_X1_18;
    AND2_X1* AND2_X1_1;
    AOI221_X1* AOI221_X1_1;
    INV_X1* INV_X1_30;
    INV_X1* INV_X1_31;
    INV_X1* INV_X1_32;
    OR4_X1* OR4_X1_1;
    INV_X1* INV_X1_33;
    NAND4_X1* NAND4_X1_12;
    NAND3_X1* NAND3_X1_19;
    NAND3_X1* NAND3_X1_20;
    NAND2_X1* NAND2_X1_19;
    OAI21_X1* OAI21_X1_10;
    INV_X1* INV_X1_34;

SC_CTOR( Circuit432 ) {
    OAI21_X1_1 = new OAI21_X1("OAI21_X1_1");
        OAI21_X1_1->A(out223);
        OAI21_X1_1->B1(in1);
        OAI21_X1_1->B2(Ckt432_M1_n1);
        OAI21_X1_1->ZN(Ckt432_M1_X1_8);

    OR2_X1_1 = new OR2_X1("OR2_X1_1");
        OR2_X1_1->A1(Ckt432_M1_n10);
        OR2_X1_1->A2(Ckt432_M1_n11);
        OR2_X1_1->ZN(out223);

    OAI221_X1_1 = new OAI221_X1("OAI221_X1_1");
        OAI221_X1_1->A(Ckt432_M1_n12);
        OAI221_X1_1->B1(Ckt432_M1_n6);
        OAI221_X1_1->B2(in63);
        OAI221_X1_1->C1(Ckt432_M1_n5);
        OAI221_X1_1->C2(in50);
        OAI221_X1_1->ZN(Ckt432_M1_n11);

    INV_X1_1 = new INV_X1("INV_X1_1");
        INV_X1_1->A(Ckt432_M1_n13);
        INV_X1_1->ZN(Ckt432_M1_n12);

    OAI222_X1_1 = new OAI222_X1("OAI222_X1_1");
        OAI222_X1_1->A1(in89);
        OAI222_X1_1->A2(Ckt432_M1_n8);
        OAI222_X1_1->B1(in102);
        OAI222_X1_1->B2(Ckt432_M1_n9);
        OAI222_X1_1->C1(in76);
        OAI222_X1_1->C2(Ckt432_M1_n7);
        OAI222_X1_1->ZN(Ckt432_M1_n13);

    INV_X1_2 = new INV_X1("INV_X1_2");
        INV_X1_2->A(in82);
        INV_X1_2->ZN(Ckt432_M1_n7);

    INV_X1_3 = new INV_X1("INV_X1_3");
        INV_X1_3->A(in108);
        INV_X1_3->ZN(Ckt432_M1_n9);

    INV_X1_4 = new INV_X1("INV_X1_4");
        INV_X1_4->A(in95);
        INV_X1_4->ZN(Ckt432_M1_n8);

    INV_X1_5 = new INV_X1("INV_X1_5");
        INV_X1_5->A(in56);
        INV_X1_5->ZN(Ckt432_M1_n5);

    INV_X1_6 = new INV_X1("INV_X1_6");
        INV_X1_6->A(in69);
        INV_X1_6->ZN(Ckt432_M1_n6);

    OAI221_X1_2 = new OAI221_X1("OAI221_X1_2");
        OAI221_X1_2->A(Ckt432_M1_n14);
        OAI221_X1_2->B1(Ckt432_M1_n2);
        OAI221_X1_2->B2(in11);
        OAI221_X1_2->C1(Ckt432_M1_n1);
        OAI221_X1_2->C2(in1);
        OAI221_X1_2->ZN(Ckt432_M1_n10);

    OAI21_X1_2 = new OAI21_X1("OAI21_X1_2");
        OAI21_X1_2->A(out223);
        OAI21_X1_2->B1(in11);
        OAI21_X1_2->B2(Ckt432_M1_n2);
        OAI21_X1_2->ZN(Ckt432_M1_X1_7);

    INV_X1_7 = new INV_X1("INV_X1_7");
        INV_X1_7->A(Ckt432_M1_n15);
        INV_X1_7->ZN(Ckt432_M1_n14);

    OAI22_X1_1 = new OAI22_X1("OAI22_X1_1");
        OAI22_X1_1->A1(in24);
        OAI22_X1_1->A2(Ckt432_M1_n3);
        OAI22_X1_1->B1(in37);
        OAI22_X1_1->B2(Ckt432_M1_n4);
        OAI22_X1_1->ZN(Ckt432_M1_n15);

    INV_X1_8 = new INV_X1("INV_X1_8");
        INV_X1_8->A(in43);
        INV_X1_8->ZN(Ckt432_M1_n4);

    INV_X1_9 = new INV_X1("INV_X1_9");
        INV_X1_9->A(in30);
        INV_X1_9->ZN(Ckt432_M1_n3);

    INV_X1_10 = new INV_X1("INV_X1_10");
        INV_X1_10->A(in4);
        INV_X1_10->ZN(Ckt432_M1_n1);

    INV_X1_11 = new INV_X1("INV_X1_11");
        INV_X1_11->A(in17);
        INV_X1_11->ZN(Ckt432_M1_n2);

    OAI21_X1_3 = new OAI21_X1("OAI21_X1_3");
        OAI21_X1_3->A(out223);
        OAI21_X1_3->B1(in24);
        OAI21_X1_3->B2(Ckt432_M1_n3);
        OAI21_X1_3->ZN(Ckt432_M1_X1_6);

    OAI21_X1_4 = new OAI21_X1("OAI21_X1_4");
        OAI21_X1_4->A(out223);
        OAI21_X1_4->B1(in37);
        OAI21_X1_4->B2(Ckt432_M1_n4);
        OAI21_X1_4->ZN(Ckt432_M1_X1_5);

    OAI21_X1_5 = new OAI21_X1("OAI21_X1_5");
        OAI21_X1_5->A(out223);
        OAI21_X1_5->B1(in50);
        OAI21_X1_5->B2(Ckt432_M1_n5);
        OAI21_X1_5->ZN(Ckt432_M1_X1_4);

    OAI21_X1_6 = new OAI21_X1("OAI21_X1_6");
        OAI21_X1_6->A(out223);
        OAI21_X1_6->B1(in63);
        OAI21_X1_6->B2(Ckt432_M1_n6);
        OAI21_X1_6->ZN(Ckt432_M1_X1_3);

    OAI21_X1_7 = new OAI21_X1("OAI21_X1_7");
        OAI21_X1_7->A(out223);
        OAI21_X1_7->B1(in76);
        OAI21_X1_7->B2(Ckt432_M1_n7);
        OAI21_X1_7->ZN(Ckt432_M1_X1_2);

    OAI21_X1_8 = new OAI21_X1("OAI21_X1_8");
        OAI21_X1_8->A(out223);
        OAI21_X1_8->B1(in89);
        OAI21_X1_8->B2(Ckt432_M1_n8);
        OAI21_X1_8->ZN(Ckt432_M1_X1_1);

    OAI21_X1_9 = new OAI21_X1("OAI21_X1_9");
        OAI21_X1_9->A(out223);
        OAI21_X1_9->B1(in102);
        OAI21_X1_9->B2(Ckt432_M1_n9);
        OAI21_X1_9->ZN(Ckt432_M1_X1_0);

    NAND2_X1_1 = new NAND2_X1("NAND2_X1_1");
        NAND2_X1_1->A1(out329);
        NAND2_X1_1->A2(Ckt432_M2_n1);
        NAND2_X1_1->ZN(Ckt432_M2_X2_8);

    NAND4_X1_1 = new NAND4_X1("NAND4_X1_1");
        NAND4_X1_1->A1(Ckt432_M2_n5);
        NAND4_X1_1->A2(Ckt432_M2_n4);
        NAND4_X1_1->A3(Ckt432_M2_n10);
        NAND4_X1_1->A4(Ckt432_M2_n11);
        NAND4_X1_1->ZN(out329);

    AND4_X1_1 = new AND4_X1("AND4_X1_1");
        AND4_X1_1->A1(Ckt432_M2_n6);
        AND4_X1_1->A2(Ckt432_M2_n7);
        AND4_X1_1->A3(Ckt432_M2_n8);
        AND4_X1_1->A4(Ckt432_M2_n9);
        AND4_X1_1->ZN(Ckt432_M2_n11);

    NAND3_X1_1 = new NAND3_X1("NAND3_X1_1");
        NAND3_X1_1->A1(in108);
        NAND3_X1_1->A2(Ckt432_M2_n12);
        NAND3_X1_1->A3(Ckt432_M1_X1_0);
        NAND3_X1_1->ZN(Ckt432_M2_n9);

    INV_X1_12 = new INV_X1("INV_X1_12");
        INV_X1_12->A(in112);
        INV_X1_12->ZN(Ckt432_M2_n12);

    NAND3_X1_2 = new NAND3_X1("NAND3_X1_2");
        NAND3_X1_2->A1(in95);
        NAND3_X1_2->A2(Ckt432_M2_n13);
        NAND3_X1_2->A3(Ckt432_M1_X1_1);
        NAND3_X1_2->ZN(Ckt432_M2_n8);

    INV_X1_13 = new INV_X1("INV_X1_13");
        INV_X1_13->A(in99);
        INV_X1_13->ZN(Ckt432_M2_n13);

    NAND3_X1_3 = new NAND3_X1("NAND3_X1_3");
        NAND3_X1_3->A1(in82);
        NAND3_X1_3->A2(Ckt432_M2_n14);
        NAND3_X1_3->A3(Ckt432_M1_X1_2);
        NAND3_X1_3->ZN(Ckt432_M2_n7);

    INV_X1_14 = new INV_X1("INV_X1_14");
        INV_X1_14->A(in86);
        INV_X1_14->ZN(Ckt432_M2_n14);

    NAND3_X1_4 = new NAND3_X1("NAND3_X1_4");
        NAND3_X1_4->A1(in69);
        NAND3_X1_4->A2(Ckt432_M2_n15);
        NAND3_X1_4->A3(Ckt432_M1_X1_3);
        NAND3_X1_4->ZN(Ckt432_M2_n6);

    INV_X1_15 = new INV_X1("INV_X1_15");
        INV_X1_15->A(in73);
        INV_X1_15->ZN(Ckt432_M2_n15);

    NAND2_X1_2 = new NAND2_X1("NAND2_X1_2");
        NAND2_X1_2->A1(out329);
        NAND2_X1_2->A2(Ckt432_M2_n2);
        NAND2_X1_2->ZN(Ckt432_M2_X2_7);

    AND3_X1_1 = new AND3_X1("AND3_X1_1");
        AND3_X1_1->A1(Ckt432_M2_n3);
        AND3_X1_1->A2(Ckt432_M2_n1);
        AND3_X1_1->A3(Ckt432_M2_n2);
        AND3_X1_1->ZN(Ckt432_M2_n10);

    NAND3_X1_5 = new NAND3_X1("NAND3_X1_5");
        NAND3_X1_5->A1(in17);
        NAND3_X1_5->A2(Ckt432_M2_n16);
        NAND3_X1_5->A3(Ckt432_M1_X1_7);
        NAND3_X1_5->ZN(Ckt432_M2_n2);

    INV_X1_16 = new INV_X1("INV_X1_16");
        INV_X1_16->A(in21);
        INV_X1_16->ZN(Ckt432_M2_n16);

    NAND3_X1_6 = new NAND3_X1("NAND3_X1_6");
        NAND3_X1_6->A1(in4);
        NAND3_X1_6->A2(Ckt432_M2_n17);
        NAND3_X1_6->A3(Ckt432_M1_X1_8);
        NAND3_X1_6->ZN(Ckt432_M2_n1);

    INV_X1_17 = new INV_X1("INV_X1_17");
        INV_X1_17->A(in8);
        INV_X1_17->ZN(Ckt432_M2_n17);

    NAND3_X1_7 = new NAND3_X1("NAND3_X1_7");
        NAND3_X1_7->A1(in30);
        NAND3_X1_7->A2(Ckt432_M2_n18);
        NAND3_X1_7->A3(Ckt432_M1_X1_6);
        NAND3_X1_7->ZN(Ckt432_M2_n3);

    INV_X1_18 = new INV_X1("INV_X1_18");
        INV_X1_18->A(in34);
        INV_X1_18->ZN(Ckt432_M2_n18);

    NAND3_X1_8 = new NAND3_X1("NAND3_X1_8");
        NAND3_X1_8->A1(in43);
        NAND3_X1_8->A2(Ckt432_M2_n19);
        NAND3_X1_8->A3(Ckt432_M1_X1_5);
        NAND3_X1_8->ZN(Ckt432_M2_n4);

    INV_X1_19 = new INV_X1("INV_X1_19");
        INV_X1_19->A(in47);
        INV_X1_19->ZN(Ckt432_M2_n19);

    NAND3_X1_9 = new NAND3_X1("NAND3_X1_9");
        NAND3_X1_9->A1(in56);
        NAND3_X1_9->A2(Ckt432_M2_n20);
        NAND3_X1_9->A3(Ckt432_M1_X1_4);
        NAND3_X1_9->ZN(Ckt432_M2_n5);

    NAND2_X1_3 = new NAND2_X1("NAND2_X1_3");
        NAND2_X1_3->A1(out329);
        NAND2_X1_3->A2(Ckt432_M2_n3);
        NAND2_X1_3->ZN(Ckt432_M2_X2_6);

    INV_X1_20 = new INV_X1("INV_X1_20");
        INV_X1_20->A(in60);
        INV_X1_20->ZN(Ckt432_M2_n20);

    NAND2_X1_4 = new NAND2_X1("NAND2_X1_4");
        NAND2_X1_4->A1(out329);
        NAND2_X1_4->A2(Ckt432_M2_n4);
        NAND2_X1_4->ZN(Ckt432_M2_X2_5);

    NAND2_X1_5 = new NAND2_X1("NAND2_X1_5");
        NAND2_X1_5->A1(out329);
        NAND2_X1_5->A2(Ckt432_M2_n5);
        NAND2_X1_5->ZN(Ckt432_M2_X2_4);

    NAND2_X1_6 = new NAND2_X1("NAND2_X1_6");
        NAND2_X1_6->A1(out329);
        NAND2_X1_6->A2(Ckt432_M2_n6);
        NAND2_X1_6->ZN(Ckt432_M2_X2_3);

    NAND2_X1_7 = new NAND2_X1("NAND2_X1_7");
        NAND2_X1_7->A1(out329);
        NAND2_X1_7->A2(Ckt432_M2_n7);
        NAND2_X1_7->ZN(Ckt432_M2_X2_2);

    NAND2_X1_8 = new NAND2_X1("NAND2_X1_8");
        NAND2_X1_8->A1(out329);
        NAND2_X1_8->A2(Ckt432_M2_n8);
        NAND2_X1_8->ZN(Ckt432_M2_X2_1);

    NAND2_X1_9 = new NAND2_X1("NAND2_X1_9");
        NAND2_X1_9->A1(out329);
        NAND2_X1_9->A2(Ckt432_M2_n9);
        NAND2_X1_9->ZN(Ckt432_M2_X2_0);

    NAND4_X1_2 = new NAND4_X1("NAND4_X1_2");
        NAND4_X1_2->A1(Ckt432_M3_n1);
        NAND4_X1_2->A2(Ckt432_M3_n2);
        NAND4_X1_2->A3(Ckt432_M3_n3);
        NAND4_X1_2->A4(Ckt432_M3_n4);
        NAND4_X1_2->ZN(out370);

    INV_X1_21 = new INV_X1("INV_X1_21");
        INV_X1_21->A(in14);
        INV_X1_21->ZN(Ckt432_M3_n12);

    AND3_X1_2 = new AND3_X1("AND3_X1_2");
        AND3_X1_2->A1(Ckt432_M3_n13);
        AND3_X1_2->A2(Ckt432_M3_n14);
        AND3_X1_2->A3(Ckt432_M3_n15);
        AND3_X1_2->ZN(Ckt432_M3_n3);

    NAND4_X1_3 = new NAND4_X1("NAND4_X1_3");
        NAND4_X1_3->A1(Ckt432_M2_X2_2);
        NAND4_X1_3->A2(Ckt432_M1_X1_2);
        NAND4_X1_3->A3(in82);
        NAND4_X1_3->A4(Ckt432_M3_n16);
        NAND4_X1_3->ZN(Ckt432_M3_n15);

    INV_X1_22 = new INV_X1("INV_X1_22");
        INV_X1_22->A(in92);
        INV_X1_22->ZN(Ckt432_M3_n16);

    NAND4_X1_4 = new NAND4_X1("NAND4_X1_4");
        NAND4_X1_4->A1(Ckt432_M2_X2_0);
        NAND4_X1_4->A2(Ckt432_M1_X1_0);
        NAND4_X1_4->A3(in108);
        NAND4_X1_4->A4(Ckt432_M3_n17);
        NAND4_X1_4->ZN(Ckt432_M3_n14);

    INV_X1_23 = new INV_X1("INV_X1_23");
        INV_X1_23->A(in115);
        INV_X1_23->ZN(Ckt432_M3_n17);

    NAND4_X1_5 = new NAND4_X1("NAND4_X1_5");
        NAND4_X1_5->A1(Ckt432_M2_X2_1);
        NAND4_X1_5->A2(Ckt432_M1_X1_1);
        NAND4_X1_5->A3(in95);
        NAND4_X1_5->A4(Ckt432_M3_n18);
        NAND4_X1_5->ZN(Ckt432_M3_n13);

    INV_X1_24 = new INV_X1("INV_X1_24");
        INV_X1_24->A(in105);
        INV_X1_24->ZN(Ckt432_M3_n18);

    NAND4_X1_6 = new NAND4_X1("NAND4_X1_6");
        NAND4_X1_6->A1(Ckt432_M2_X2_3);
        NAND4_X1_6->A2(Ckt432_M1_X1_3);
        NAND4_X1_6->A3(in69);
        NAND4_X1_6->A4(Ckt432_M3_n19);
        NAND4_X1_6->ZN(Ckt432_M3_n2);

    INV_X1_25 = new INV_X1("INV_X1_25");
        INV_X1_25->A(in79);
        INV_X1_25->ZN(Ckt432_M3_n19);

    AND4_X1_2 = new AND4_X1("AND4_X1_2");
        AND4_X1_2->A1(Ckt432_M3_n5);
        AND4_X1_2->A2(Ckt432_M3_n6);
        AND4_X1_2->A3(Ckt432_M3_n7);
        AND4_X1_2->A4(Ckt432_M3_n8);
        AND4_X1_2->ZN(Ckt432_M3_n4);

    NAND4_X1_7 = new NAND4_X1("NAND4_X1_7");
        NAND4_X1_7->A1(Ckt432_M2_X2_4);
        NAND4_X1_7->A2(Ckt432_M1_X1_4);
        NAND4_X1_7->A3(in56);
        NAND4_X1_7->A4(Ckt432_M3_n20);
        NAND4_X1_7->ZN(Ckt432_M3_n1);

    INV_X1_26 = new INV_X1("INV_X1_26");
        INV_X1_26->A(in66);
        INV_X1_26->ZN(Ckt432_M3_n20);

    NAND4_X1_8 = new NAND4_X1("NAND4_X1_8");
        NAND4_X1_8->A1(Ckt432_M2_X2_5);
        NAND4_X1_8->A2(Ckt432_M1_X1_5);
        NAND4_X1_8->A3(in43);
        NAND4_X1_8->A4(Ckt432_M3_n9);
        NAND4_X1_8->ZN(Ckt432_M3_n8);

    INV_X1_27 = new INV_X1("INV_X1_27");
        INV_X1_27->A(in53);
        INV_X1_27->ZN(Ckt432_M3_n9);

    NAND4_X1_9 = new NAND4_X1("NAND4_X1_9");
        NAND4_X1_9->A1(Ckt432_M2_X2_6);
        NAND4_X1_9->A2(Ckt432_M1_X1_6);
        NAND4_X1_9->A3(in30);
        NAND4_X1_9->A4(Ckt432_M3_n10);
        NAND4_X1_9->ZN(Ckt432_M3_n7);

    INV_X1_28 = new INV_X1("INV_X1_28");
        INV_X1_28->A(in40);
        INV_X1_28->ZN(Ckt432_M3_n10);

    NAND4_X1_10 = new NAND4_X1("NAND4_X1_10");
        NAND4_X1_10->A1(Ckt432_M2_X2_7);
        NAND4_X1_10->A2(Ckt432_M1_X1_7);
        NAND4_X1_10->A3(in17);
        NAND4_X1_10->A4(Ckt432_M3_n11);
        NAND4_X1_10->ZN(Ckt432_M3_n6);

    INV_X1_29 = new INV_X1("INV_X1_29");
        INV_X1_29->A(in27);
        INV_X1_29->ZN(Ckt432_M3_n11);

    NAND4_X1_11 = new NAND4_X1("NAND4_X1_11");
        NAND4_X1_11->A1(Ckt432_M2_X2_8);
        NAND4_X1_11->A2(Ckt432_M1_X1_8);
        NAND4_X1_11->A3(in4);
        NAND4_X1_11->A4(Ckt432_M3_n12);
        NAND4_X1_11->ZN(Ckt432_M3_n5);

    NAND3_X1_10 = new NAND3_X1("NAND3_X1_10");
        NAND3_X1_10->A1(in4);
        NAND3_X1_10->A2(Ckt432_M4_n1);
        NAND3_X1_10->A3(Ckt432_M4_n2);
        NAND3_X1_10->ZN(Ckt432_I_8);

    NAND3_X1_11 = new NAND3_X1("NAND3_X1_11");
        NAND3_X1_11->A1(in43);
        NAND3_X1_11->A2(Ckt432_M4_n7);
        NAND3_X1_11->A3(Ckt432_M4_n8);
        NAND3_X1_11->ZN(Ckt432_I_5);

    AOI22_X1_1 = new AOI22_X1("AOI22_X1_1");
        AOI22_X1_1->A1(in37);
        AOI22_X1_1->A2(out223);
        AOI22_X1_1->B1(in47);
        AOI22_X1_1->B2(out329);
        AOI22_X1_1->ZN(Ckt432_M4_n8);

    NAND2_X1_10 = new NAND2_X1("NAND2_X1_10");
        NAND2_X1_10->A1(in53);
        NAND2_X1_10->A2(out370);
        NAND2_X1_10->ZN(Ckt432_M4_n7);

    NAND3_X1_12 = new NAND3_X1("NAND3_X1_12");
        NAND3_X1_12->A1(in56);
        NAND3_X1_12->A2(Ckt432_M4_n9);
        NAND3_X1_12->A3(Ckt432_M4_n10);
        NAND3_X1_12->ZN(Ckt432_I_4);

    AOI22_X1_2 = new AOI22_X1("AOI22_X1_2");
        AOI22_X1_2->A1(in50);
        AOI22_X1_2->A2(out223);
        AOI22_X1_2->B1(in60);
        AOI22_X1_2->B2(out329);
        AOI22_X1_2->ZN(Ckt432_M4_n10);

    NAND2_X1_11 = new NAND2_X1("NAND2_X1_11");
        NAND2_X1_11->A1(in66);
        NAND2_X1_11->A2(out370);
        NAND2_X1_11->ZN(Ckt432_M4_n9);

    NAND3_X1_13 = new NAND3_X1("NAND3_X1_13");
        NAND3_X1_13->A1(in69);
        NAND3_X1_13->A2(Ckt432_M4_n11);
        NAND3_X1_13->A3(Ckt432_M4_n12);
        NAND3_X1_13->ZN(Ckt432_I_3);

    AOI22_X1_3 = new AOI22_X1("AOI22_X1_3");
        AOI22_X1_3->A1(in63);
        AOI22_X1_3->A2(out223);
        AOI22_X1_3->B1(in73);
        AOI22_X1_3->B2(out329);
        AOI22_X1_3->ZN(Ckt432_M4_n12);

    NAND2_X1_12 = new NAND2_X1("NAND2_X1_12");
        NAND2_X1_12->A1(in79);
        NAND2_X1_12->A2(out370);
        NAND2_X1_12->ZN(Ckt432_M4_n11);

    NAND3_X1_14 = new NAND3_X1("NAND3_X1_14");
        NAND3_X1_14->A1(in82);
        NAND3_X1_14->A2(Ckt432_M4_n13);
        NAND3_X1_14->A3(Ckt432_M4_n14);
        NAND3_X1_14->ZN(Ckt432_I_2);

    AOI22_X1_4 = new AOI22_X1("AOI22_X1_4");
        AOI22_X1_4->A1(out223);
        AOI22_X1_4->A2(in1);
        AOI22_X1_4->B1(out329);
        AOI22_X1_4->B2(in8);
        AOI22_X1_4->ZN(Ckt432_M4_n2);

    AOI22_X1_5 = new AOI22_X1("AOI22_X1_5");
        AOI22_X1_5->A1(in76);
        AOI22_X1_5->A2(out223);
        AOI22_X1_5->B1(in86);
        AOI22_X1_5->B2(out329);
        AOI22_X1_5->ZN(Ckt432_M4_n14);

    NAND2_X1_13 = new NAND2_X1("NAND2_X1_13");
        NAND2_X1_13->A1(in92);
        NAND2_X1_13->A2(out370);
        NAND2_X1_13->ZN(Ckt432_M4_n13);

    NAND3_X1_15 = new NAND3_X1("NAND3_X1_15");
        NAND3_X1_15->A1(in95);
        NAND3_X1_15->A2(Ckt432_M4_n15);
        NAND3_X1_15->A3(Ckt432_M4_n16);
        NAND3_X1_15->ZN(Ckt432_I_1);

    AOI22_X1_6 = new AOI22_X1("AOI22_X1_6");
        AOI22_X1_6->A1(in89);
        AOI22_X1_6->A2(out223);
        AOI22_X1_6->B1(in99);
        AOI22_X1_6->B2(out329);
        AOI22_X1_6->ZN(Ckt432_M4_n16);

    NAND2_X1_14 = new NAND2_X1("NAND2_X1_14");
        NAND2_X1_14->A1(in105);
        NAND2_X1_14->A2(out370);
        NAND2_X1_14->ZN(Ckt432_M4_n15);

    NAND3_X1_16 = new NAND3_X1("NAND3_X1_16");
        NAND3_X1_16->A1(in108);
        NAND3_X1_16->A2(Ckt432_M4_n17);
        NAND3_X1_16->A3(Ckt432_M4_n18);
        NAND3_X1_16->ZN(Ckt432_I_0);

    AOI22_X1_7 = new AOI22_X1("AOI22_X1_7");
        AOI22_X1_7->A1(in102);
        AOI22_X1_7->A2(out223);
        AOI22_X1_7->B1(in112);
        AOI22_X1_7->B2(out329);
        AOI22_X1_7->ZN(Ckt432_M4_n18);

    NAND2_X1_15 = new NAND2_X1("NAND2_X1_15");
        NAND2_X1_15->A1(in115);
        NAND2_X1_15->A2(out370);
        NAND2_X1_15->ZN(Ckt432_M4_n17);

    NAND2_X1_16 = new NAND2_X1("NAND2_X1_16");
        NAND2_X1_16->A1(out370);
        NAND2_X1_16->A2(in14);
        NAND2_X1_16->ZN(Ckt432_M4_n1);

    NAND3_X1_17 = new NAND3_X1("NAND3_X1_17");
        NAND3_X1_17->A1(in17);
        NAND3_X1_17->A2(Ckt432_M4_n3);
        NAND3_X1_17->A3(Ckt432_M4_n4);
        NAND3_X1_17->ZN(Ckt432_I_7);

    AOI22_X1_8 = new AOI22_X1("AOI22_X1_8");
        AOI22_X1_8->A1(in11);
        AOI22_X1_8->A2(out223);
        AOI22_X1_8->B1(in21);
        AOI22_X1_8->B2(out329);
        AOI22_X1_8->ZN(Ckt432_M4_n4);

    NAND2_X1_17 = new NAND2_X1("NAND2_X1_17");
        NAND2_X1_17->A1(in27);
        NAND2_X1_17->A2(out370);
        NAND2_X1_17->ZN(Ckt432_M4_n3);

    NAND3_X1_18 = new NAND3_X1("NAND3_X1_18");
        NAND3_X1_18->A1(in30);
        NAND3_X1_18->A2(Ckt432_M4_n5);
        NAND3_X1_18->A3(Ckt432_M4_n6);
        NAND3_X1_18->ZN(Ckt432_I_6);

    AOI22_X1_9 = new AOI22_X1("AOI22_X1_9");
        AOI22_X1_9->A1(in24);
        AOI22_X1_9->A2(out223);
        AOI22_X1_9->B1(in34);
        AOI22_X1_9->B2(out329);
        AOI22_X1_9->ZN(Ckt432_M4_n6);

    NAND2_X1_18 = new NAND2_X1("NAND2_X1_18");
        NAND2_X1_18->A1(in40);
        NAND2_X1_18->A2(out370);
        NAND2_X1_18->ZN(Ckt432_M4_n5);

    AND2_X1_1 = new AND2_X1("AND2_X1_1");
        AND2_X1_1->A1(Ckt432_I_8);
        AND2_X1_1->A2(Ckt432_M5_n1);
        AND2_X1_1->ZN(out421);

    AOI221_X1_1 = new AOI221_X1("AOI221_X1_1");
        AOI221_X1_1->A(Ckt432_M5_n9);
        AOI221_X1_1->B1(Ckt432_I_2);
        AOI221_X1_1->B2(Ckt432_M5_n2);
        AOI221_X1_1->C1(Ckt432_I_4);
        AOI221_X1_1->C2(Ckt432_M5_n8);
        AOI221_X1_1->ZN(Ckt432_M5_n6);

    INV_X1_30 = new INV_X1("INV_X1_30");
        INV_X1_30->A(Ckt432_I_5);
        INV_X1_30->ZN(Ckt432_M5_n9);

    INV_X1_31 = new INV_X1("INV_X1_31");
        INV_X1_31->A(Ckt432_I_3);
        INV_X1_31->ZN(Ckt432_M5_n8);

    INV_X1_32 = new INV_X1("INV_X1_32");
        INV_X1_32->A(Ckt432_I_1);
        INV_X1_32->ZN(Ckt432_M5_n2);

    OR4_X1_1 = new OR4_X1("OR4_X1_1");
        OR4_X1_1->A1(Ckt432_M5_n2);
        OR4_X1_1->A2(Ckt432_M5_n3);
        OR4_X1_1->A3(Ckt432_M5_n4);
        OR4_X1_1->A4(out430);
        OR4_X1_1->ZN(Ckt432_M5_n1);

    INV_X1_33 = new INV_X1("INV_X1_33");
        INV_X1_33->A(Ckt432_I_0);
        INV_X1_33->ZN(Ckt432_M5_n3);

    NAND4_X1_12 = new NAND4_X1("NAND4_X1_12");
        NAND4_X1_12->A1(Ckt432_I_7);
        NAND4_X1_12->A2(Ckt432_I_6);
        NAND4_X1_12->A3(Ckt432_I_5);
        NAND4_X1_12->A4(Ckt432_I_4);
        NAND4_X1_12->ZN(out430);

    NAND3_X1_19 = new NAND3_X1("NAND3_X1_19");
        NAND3_X1_19->A1(Ckt432_I_6);
        NAND3_X1_19->A2(Ckt432_M5_n5);
        NAND3_X1_19->A3(Ckt432_I_7);
        NAND3_X1_19->ZN(out431);

    NAND3_X1_20 = new NAND3_X1("NAND3_X1_20");
        NAND3_X1_20->A1(Ckt432_I_4);
        NAND3_X1_20->A2(Ckt432_M5_n4);
        NAND3_X1_20->A3(Ckt432_I_5);
        NAND3_X1_20->ZN(Ckt432_M5_n5);

    NAND2_X1_19 = new NAND2_X1("NAND2_X1_19");
        NAND2_X1_19->A1(Ckt432_I_3);
        NAND2_X1_19->A2(Ckt432_I_2);
        NAND2_X1_19->ZN(Ckt432_M5_n4);

    OAI21_X1_10 = new OAI21_X1("OAI21_X1_10");
        OAI21_X1_10->A(Ckt432_I_7);
        OAI21_X1_10->B1(Ckt432_M5_n6);
        OAI21_X1_10->B2(Ckt432_M5_n7);
        OAI21_X1_10->ZN(out432);

    INV_X1_34 = new INV_X1("INV_X1_34");
        INV_X1_34->A(Ckt432_I_6);
        INV_X1_34->ZN(Ckt432_M5_n7);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
