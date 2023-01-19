#include <systemc.h>
#include "Complex_NAgate_45.h"

using namespace sc_core;

SC_MODULE( counter ) {

    sc_in<sc_logic> clk;
    sc_in<sc_logic> rst;
    sc_in<sc_logic> en;
    sc_in<sc_logic> clkEn;
    sc_out<sc_logic> count[4];
    sc_out<sc_logic> co;

    sc_signal<sc_logic> sc_logic_1_signal;
    sc_signal<sc_logic> sc_logic_0_signal;

    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _10_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_10_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _11_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_11_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _12_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_12_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _13_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_13_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _14_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_14_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _15_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_15_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _16_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_16_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _17_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_17_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _18_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_18_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _19_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_19_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _1_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_1_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _20_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_20_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _21_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_21_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _22_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_22_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _23_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_23_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _24_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_24_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _25_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_25_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_2_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _3_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_3_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _4_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_4_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _5_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_5_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _6_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_6_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _7_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_7_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _8_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_8_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _9_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_9_");

    INV_X1* INV_X1_1;
    AND4_X1* AND4_X1_1;
    INV_X1* INV_X1_2;
    NAND2_X1* NAND2_X1_1;
    INV_X1* INV_X1_3;
    OAI21_X1* OAI21_X1_1;
    AOI21_X1* AOI21_X1_1;
    INV_X1* INV_X1_4;
    NAND3_X1* NAND3_X1_1;
    NAND4_X1* NAND4_X1_1;
    NAND2_X1* NAND2_X1_2;
    AOI21_X1* AOI21_X1_2;
    NAND2_X1* NAND2_X1_3;
    OAI21_X1* OAI21_X1_2;
    AOI21_X1* AOI21_X1_3;
    OAI21_X1* OAI21_X1_3;
    INV_X1* INV_X1_5;
    AND3_X1* AND3_X1_1;
    AND2_X1* AND2_X1_1;
    NAND3_X1* NAND3_X1_2;
    AOI21_X1* AOI21_X1_4;
    DFF_X1* DFF_X1_1;
    DFF_X1* DFF_X1_2;
    DFF_X1* DFF_X1_3;
    DFF_X1* DFF_X1_4;
    BUF_X1* BUF_X1_1;
    BUF_X1* BUF_X1_2;
    BUF_X1* BUF_X1_3;
    BUF_X1* BUF_X1_4;
    BUF_X1* BUF_X1_5;

SC_CTOR( counter ) {
    INV_X1_1 = new INV_X1("INV_X1_1");
        INV_X1_1->A(_20_[2]);
        INV_X1_1->ZN(_4_);

    AND4_X1_1 = new AND4_X1("AND4_X1_1");
        AND4_X1_1->A1(_4_);
        AND4_X1_1->A2(_20_[3]);
        AND4_X1_1->A3(_20_[1]);
        AND4_X1_1->A4(_20_[0]);
        AND4_X1_1->ZN(_24_);

    INV_X1_2 = new INV_X1("INV_X1_2");
        INV_X1_2->A(_25_[0]);
        INV_X1_2->ZN(_5_);

    NAND2_X1_1 = new NAND2_X1("NAND2_X1_1");
        NAND2_X1_1->A1(clkEn);
        NAND2_X1_1->A2(en);
        NAND2_X1_1->ZN(_6_);

    INV_X1_3 = new INV_X1("INV_X1_3");
        INV_X1_3->A(rst);
        INV_X1_3->ZN(_7_);

    OAI21_X1_1 = new OAI21_X1("OAI21_X1_1");
        OAI21_X1_1->A(_7_);
        OAI21_X1_1->B1(_6_);
        OAI21_X1_1->B2(_20_[0]);
        OAI21_X1_1->ZN(_8_);

    AOI21_X1_1 = new AOI21_X1("AOI21_X1_1");
        AOI21_X1_1->A(_8_);
        AOI21_X1_1->B1(_6_);
        AOI21_X1_1->B2(_5_);
        AOI21_X1_1->ZN(_0_);

    INV_X1_4 = new INV_X1("INV_X1_4");
        INV_X1_4->A(_20_[1]);
        INV_X1_4->ZN(_9_);

    NAND3_X1_1 = new NAND3_X1("NAND3_X1_1");
        NAND3_X1_1->A1(clkEn);
        NAND3_X1_1->A2(en);
        NAND3_X1_1->A3(_25_[0]);
        NAND3_X1_1->ZN(_10_);

    NAND4_X1_1 = new NAND4_X1("NAND4_X1_1");
        NAND4_X1_1->A1(_20_[1]);
        NAND4_X1_1->A2(_25_[0]);
        NAND4_X1_1->A3(clkEn);
        NAND4_X1_1->A4(en);
        NAND4_X1_1->ZN(_11_);

    NAND2_X1_2 = new NAND2_X1("NAND2_X1_2");
        NAND2_X1_2->A1(_11_);
        NAND2_X1_2->A2(_7_);
        NAND2_X1_2->ZN(_12_);

    AOI21_X1_2 = new AOI21_X1("AOI21_X1_2");
        AOI21_X1_2->A(_12_);
        AOI21_X1_2->B1(_10_);
        AOI21_X1_2->B2(_9_);
        AOI21_X1_2->ZN(_1_);

    NAND2_X1_3 = new NAND2_X1("NAND2_X1_3");
        NAND2_X1_3->A1(_20_[2]);
        NAND2_X1_3->A2(_20_[1]);
        NAND2_X1_3->ZN(_13_);

    OAI21_X1_2 = new OAI21_X1("OAI21_X1_2");
        OAI21_X1_2->A(_7_);
        OAI21_X1_2->B1(_10_);
        OAI21_X1_2->B2(_13_);
        OAI21_X1_2->ZN(_14_);

    AOI21_X1_3 = new AOI21_X1("AOI21_X1_3");
        AOI21_X1_3->A(_14_);
        AOI21_X1_3->B1(_11_);
        AOI21_X1_3->B2(_4_);
        AOI21_X1_3->ZN(_2_);

    OAI21_X1_3 = new OAI21_X1("OAI21_X1_3");
        OAI21_X1_3->A(_20_[3]);
        OAI21_X1_3->B1(_10_);
        OAI21_X1_3->B2(_13_);
        OAI21_X1_3->ZN(_15_);

    INV_X1_5 = new INV_X1("INV_X1_5");
        INV_X1_5->A(_20_[3]);
        INV_X1_5->ZN(_16_);

    AND3_X1_1 = new AND3_X1("AND3_X1_1");
        AND3_X1_1->A1(_25_[0]);
        AND3_X1_1->A2(en);
        AND3_X1_1->A3(clkEn);
        AND3_X1_1->ZN(_17_);

    AND2_X1_1 = new AND2_X1("AND2_X1_1");
        AND2_X1_1->A1(_20_[1]);
        AND2_X1_1->A2(_20_[2]);
        AND2_X1_1->ZN(_18_);

    NAND3_X1_2 = new NAND3_X1("NAND3_X1_2");
        NAND3_X1_2->A1(_17_);
        NAND3_X1_2->A2(_16_);
        NAND3_X1_2->A3(_18_);
        NAND3_X1_2->ZN(_19_);

    AOI21_X1_4 = new AOI21_X1("AOI21_X1_4");
        AOI21_X1_4->A(rst);
        AOI21_X1_4->B1(_19_);
        AOI21_X1_4->B2(_15_);
        AOI21_X1_4->ZN(_3_);

    DFF_X1_1 = new DFF_X1("DFF_X1_1");
        DFF_X1_1->CK(clk);
        DFF_X1_1->D(_0_);
        DFF_X1_1->Q(_25_[0]);
        DFF_X1_1->QN(_20_[0]);

    DFF_X1_2 = new DFF_X1("DFF_X1_2");
        DFF_X1_2->CK(clk);
        DFF_X1_2->D(_1_);
        DFF_X1_2->Q(_20_[1]);
        DFF_X1_2->QN(_21_);

    DFF_X1_3 = new DFF_X1("DFF_X1_3");
        DFF_X1_3->CK(clk);
        DFF_X1_3->D(_2_);
        DFF_X1_3->Q(_20_[2]);
        DFF_X1_3->QN(_22_);

    DFF_X1_4 = new DFF_X1("DFF_X1_4");
        DFF_X1_4->CK(clk);
        DFF_X1_4->D(_3_);
        DFF_X1_4->Q(_20_[3]);
        DFF_X1_4->QN(_23_);

    BUF_X1_1 = new BUF_X1("BUF_X1_1");
        BUF_X1_1->A(_24_);
        BUF_X1_1->Z(co);

    BUF_X1_2 = new BUF_X1("BUF_X1_2");
        BUF_X1_2->A(_25_[0]);
        BUF_X1_2->Z(count[0]);

    BUF_X1_3 = new BUF_X1("BUF_X1_3");
        BUF_X1_3->A(_20_[1]);
        BUF_X1_3->Z(count[1]);

    BUF_X1_4 = new BUF_X1("BUF_X1_4");
        BUF_X1_4->A(_20_[2]);
        BUF_X1_4->Z(count[2]);

    BUF_X1_5 = new BUF_X1("BUF_X1_5");
        BUF_X1_5->A(_20_[3]);
        BUF_X1_5->Z(count[3]);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
