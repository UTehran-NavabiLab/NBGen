#include <systemc.h>
#include "Complex_NAgate_45.h"



#ifndef __IFF_H__
#define __IFF_H__
using namespace sc_core;

SC_MODULE( iff ) {

    sc_in<sc_logic> clk;
    sc_in<sc_logic> rst;
    sc_in<sc_logic> enflag;
    sc_in<sc_logic> setflags;
    sc_in<sc_logic> selflag;
    sc_in<sc_logic> inflag;
    sc_out<sc_logic> outflag;

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
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S8 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S8");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S9 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S9");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S10 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S10");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S11 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S11");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S12 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S12");

    INV_X1* INV_X1_1;
    OAI211_X1* OAI211_X1_1;
    OAI21_X1* OAI21_X1_1;
    NAND2_X1* NAND2_X1_1;
    NAND2_X1* NAND2_X1_2;
    DFFR_X1* DFFR_X1_1;
    BUF_X1* BUF_X1_1;
    BUF_X1* BUF_X1_2;
    BUF_X1* BUF_X1_3;
    BUF_X1* BUF_X1_4;
    BUF_X1* BUF_X1_5;
    BUF_X1* BUF_X1_6;
    BUF_X1* BUF_X1_7;

SC_CTOR( iff ) {
    INV_X1_1 = new INV_X1("INV_X1_1");
        INV_X1_1->A(S10);
        INV_X1_1->ZN(S0);

    OAI211_X1_1 = new OAI211_X1("OAI211_X1_1");
        OAI211_X1_1->A(S7);
        OAI211_X1_1->B(S8);
        OAI211_X1_1->C1(S11);
        OAI211_X1_1->C2(S12);
        OAI211_X1_1->ZN(S2);

    OAI21_X1_1 = new OAI21_X1("OAI21_X1_1");
        OAI21_X1_1->A(S7);
        OAI21_X1_1->B1(S12);
        OAI21_X1_1->B2(S11);
        OAI21_X1_1->ZN(S3);

    NAND2_X1_1 = new NAND2_X1("NAND2_X1_1");
        NAND2_X1_1->A1(S3);
        NAND2_X1_1->A2(S9);
        NAND2_X1_1->ZN(S4);

    NAND2_X1_2 = new NAND2_X1("NAND2_X1_2");
        NAND2_X1_2->A1(S4);
        NAND2_X1_2->A2(S2);
        NAND2_X1_2->ZN(S1);

    DFFR_X1_1 = new DFFR_X1("DFFR_X1_1");
        DFFR_X1_1->CK(S6);
        DFFR_X1_1->D(S1);
        DFFR_X1_1->Q(S9);
        DFFR_X1_1->QN(S5);
        DFFR_X1_1->RN(S0);

    BUF_X1_1 = new BUF_X1("BUF_X1_1");
        BUF_X1_1->A(clk);
        BUF_X1_1->Z(S6);

    BUF_X1_2 = new BUF_X1("BUF_X1_2");
        BUF_X1_2->A(enflag);
        BUF_X1_2->Z(S7);

    BUF_X1_3 = new BUF_X1("BUF_X1_3");
        BUF_X1_3->A(inflag);
        BUF_X1_3->Z(S8);

    BUF_X1_4 = new BUF_X1("BUF_X1_4");
        BUF_X1_4->A(S9);
        BUF_X1_4->Z(outflag);

    BUF_X1_5 = new BUF_X1("BUF_X1_5");
        BUF_X1_5->A(rst);
        BUF_X1_5->Z(S10);

    BUF_X1_6 = new BUF_X1("BUF_X1_6");
        BUF_X1_6->A(selflag);
        BUF_X1_6->Z(S11);

    BUF_X1_7 = new BUF_X1("BUF_X1_7");
        BUF_X1_7->A(setflags);
        BUF_X1_7->Z(S12);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
#endif /* __IFF_H__ */

