#include <systemc.h>
#include "component_library.h"

using namespace sc_core;

SC_MODULE( and3 ) {

    sc_in<sc_logic> i0;
    sc_in<sc_logic> i1;
    sc_in<sc_logic> i2;
    sc_out<sc_logic> o;

    sc_signal<sc_logic> sc_logic_1_signal;
    sc_signal<sc_logic> sc_logic_0_signal;

    sc_signal<sc_logic> _0_;

    AND3_X1* AND3_X1_1;
    BUF_X1* BUF_X1_1;

SC_CTOR( and3 ) {
    AND3_X1_1 = new AND3_X1("AND3_X1_1");
        AND3_X1_1->A1(i2);
        AND3_X1_1->A2(i0);
        AND3_X1_1->A3(i1);
        AND3_X1_1->ZN(_0_);

    BUF_X1_1 = new BUF_X1("BUF_X1_1");
        BUF_X1_1->A(_0_);
        BUF_X1_1->Z(o);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
