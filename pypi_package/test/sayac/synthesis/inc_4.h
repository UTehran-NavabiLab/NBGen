#include <systemc.h>
#include "Complex_NAgate_45.h"



#ifndef __INC_4_H__
#define __INC_4_H__
using namespace sc_core;

SC_MODULE( inc_4 ) {

    sc_in<sc_logic> ininc[4];
    sc_out<sc_logic> outinc[4];

    sc_signal<sc_logic> sc_logic_1_signal;
    sc_signal<sc_logic> sc_logic_0_signal;

    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S0 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S0");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S1 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S1");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S2 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S2");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S3 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S3");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S4 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S4");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S5 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S5");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S6 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S6");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S7 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S7");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S8[4];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S9[4];

    INV_X1* INV_X1_1;
    XOR2_X1* XOR2_X1_1;
    NAND2_X1* NAND2_X1_1;
    NAND2_X1* NAND2_X1_2;
    INV_X1* INV_X1_2;
    NAND3_X1* NAND3_X1_1;
    NAND2_X1* NAND2_X1_3;
    NAND3_X1* NAND3_X1_2;
    NAND2_X1* NAND2_X1_4;
    INV_X1* INV_X1_3;
    NAND4_X1* NAND4_X1_1;
    NAND2_X1* NAND2_X1_5;
    BUF_X1* BUF_X1_1;
    BUF_X1* BUF_X1_2;
    BUF_X1* BUF_X1_3;
    BUF_X1* BUF_X1_4;
    BUF_X1* BUF_X1_5;
    BUF_X1* BUF_X1_6;
    BUF_X1* BUF_X1_7;
    BUF_X1* BUF_X1_8;

SC_CTOR( inc_4 ) {
    INV_X1_1 = new INV_X1("INV_X1_1");
        INV_X1_1->A(S8[0]);
        INV_X1_1->ZN(S9[0]);

    XOR2_X1_1 = new XOR2_X1("XOR2_X1_1");
        XOR2_X1_1->A(S8[0]);
        XOR2_X1_1->B(S8[1]);
        XOR2_X1_1->Z(S9[1]);

    NAND2_X1_1 = new NAND2_X1("NAND2_X1_1");
        NAND2_X1_1->A1(S8[0]);
        NAND2_X1_1->A2(S8[1]);
        NAND2_X1_1->ZN(S0);

    NAND2_X1_2 = new NAND2_X1("NAND2_X1_2");
        NAND2_X1_2->A1(S0);
        NAND2_X1_2->A2(S8[2]);
        NAND2_X1_2->ZN(S1);

    INV_X1_2 = new INV_X1("INV_X1_2");
        INV_X1_2->A(S8[2]);
        INV_X1_2->ZN(S2);

    NAND3_X1_1 = new NAND3_X1("NAND3_X1_1");
        NAND3_X1_1->A1(S2);
        NAND3_X1_1->A2(S8[0]);
        NAND3_X1_1->A3(S8[1]);
        NAND3_X1_1->ZN(S3);

    NAND2_X1_3 = new NAND2_X1("NAND2_X1_3");
        NAND2_X1_3->A1(S1);
        NAND2_X1_3->A2(S3);
        NAND2_X1_3->ZN(S9[2]);

    NAND3_X1_2 = new NAND3_X1("NAND3_X1_2");
        NAND3_X1_2->A1(S8[0]);
        NAND3_X1_2->A2(S8[1]);
        NAND3_X1_2->A3(S8[2]);
        NAND3_X1_2->ZN(S4);

    NAND2_X1_4 = new NAND2_X1("NAND2_X1_4");
        NAND2_X1_4->A1(S4);
        NAND2_X1_4->A2(S8[3]);
        NAND2_X1_4->ZN(S5);

    INV_X1_3 = new INV_X1("INV_X1_3");
        INV_X1_3->A(S8[3]);
        INV_X1_3->ZN(S6);

    NAND4_X1_1 = new NAND4_X1("NAND4_X1_1");
        NAND4_X1_1->A1(S6);
        NAND4_X1_1->A2(S8[2]);
        NAND4_X1_1->A3(S8[1]);
        NAND4_X1_1->A4(S8[0]);
        NAND4_X1_1->ZN(S7);

    NAND2_X1_5 = new NAND2_X1("NAND2_X1_5");
        NAND2_X1_5->A1(S5);
        NAND2_X1_5->A2(S7);
        NAND2_X1_5->ZN(S9[3]);

    BUF_X1_1 = new BUF_X1("BUF_X1_1");
        BUF_X1_1->A(ininc[0]);
        BUF_X1_1->Z(S8[0]);

    BUF_X1_2 = new BUF_X1("BUF_X1_2");
        BUF_X1_2->A(ininc[1]);
        BUF_X1_2->Z(S8[1]);

    BUF_X1_3 = new BUF_X1("BUF_X1_3");
        BUF_X1_3->A(ininc[2]);
        BUF_X1_3->Z(S8[2]);

    BUF_X1_4 = new BUF_X1("BUF_X1_4");
        BUF_X1_4->A(ininc[3]);
        BUF_X1_4->Z(S8[3]);

    BUF_X1_5 = new BUF_X1("BUF_X1_5");
        BUF_X1_5->A(S9[0]);
        BUF_X1_5->Z(outinc[0]);

    BUF_X1_6 = new BUF_X1("BUF_X1_6");
        BUF_X1_6->A(S9[1]);
        BUF_X1_6->Z(outinc[1]);

    BUF_X1_7 = new BUF_X1("BUF_X1_7");
        BUF_X1_7->A(S9[2]);
        BUF_X1_7->Z(outinc[2]);

    BUF_X1_8 = new BUF_X1("BUF_X1_8");
        BUF_X1_8->A(S9[3]);
        BUF_X1_8->Z(outinc[3]);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
#endif /* __INC_4_H__ */

