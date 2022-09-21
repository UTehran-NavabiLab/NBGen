#include <systemc.h>
#include "component_library.h"

using namespace sc_core;

SC_MODULE( fulladder ) {

    sc_in<sc_logic> i0;
    sc_in<sc_logic> i1;
    sc_in<sc_logic> ci;
    sc_out<sc_logic> s;
    sc_out<sc_logic> co;

    sc_signal<sc_logic> sc_logic_1_signal;
    sc_signal<sc_logic> sc_logic_0_signal;

    sc_signal<sc_logic> n4;
    sc_signal<sc_logic> n5;

    XOR2_X1* XOR2_X1_1;
    INV_X1* INV_X1_1;
    AOI22_X1* AOI22_X1_1;
    XOR2_X1* XOR2_X1_2;

SC_CTOR( fulladder ) {
    XOR2_X1_1 = new XOR2_X1("XOR2_X1_1");
        XOR2_X1_1->A(i1);
        XOR2_X1_1->B(n4);
        XOR2_X1_1->Z(s);

    INV_X1_1 = new INV_X1("INV_X1_1");
        INV_X1_1->A(n5);
        INV_X1_1->ZN(co);

    AOI22_X1_1 = new AOI22_X1("AOI22_X1_1");
        AOI22_X1_1->A1(i0);
        AOI22_X1_1->A2(ci);
        AOI22_X1_1->B1(n4);
        AOI22_X1_1->B2(i1);
        AOI22_X1_1->ZN(n5);

    XOR2_X1_2 = new XOR2_X1("XOR2_X1_2");
        XOR2_X1_2->A(ci);
        XOR2_X1_2->B(i0);
        XOR2_X1_2->Z(n4);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
