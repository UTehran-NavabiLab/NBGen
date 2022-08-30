#include "systemc.h"
//Verilog Library for Test Applications
//CAD Research Group
//School of ECE, University of Tehran

// TODO: parametrize gates

#ifndef __GATES_H__
#define __GATES_H__

/////////////////////////////////////////////////////////////////////////////////////
//    Buf
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(bufg){

    sc_in< sc_logic> A; 
    sc_out< sc_logic> Y;

    SC_CTOR(bufg){

        SC_METHOD(eval);
        sensitive << A;

    }

    void eval(void){
        Y->write(A->read());
    };
};

/////////////////////////////////////////////////////////////////////////////////////
//    Not
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(notg){

    sc_in< sc_logic > A; 
    sc_out< sc_logic > Y;

    SC_CTOR(notg){

        SC_METHOD(eval);
        sensitive << A;

    }

    void eval(void){
        if (A->read() == SC_LOGIC_1){
            Y->write(SC_LOGIC_0);
        } else if (A->read() == SC_LOGIC_0){
            Y->write(SC_LOGIC_1);
        }
    };
};

/////////////////////////////////////////////////////////////////////////////////////
//    And
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(and_n){

    sc_in< sc_logic> A[2]; 
    sc_out< sc_logic> Y;

    SC_CTOR(and_n){

        SC_METHOD(eval);
        sensitive << A[0] << A[1];

    }

    void eval(void){
        if ((A[0]->read() == SC_LOGIC_0) || (A[1]->read() == SC_LOGIC_0)){
            Y->write(SC_LOGIC_0);
        } else {
            Y->write(SC_LOGIC_1);
        }
    };
};

/////////////////////////////////////////////////////////////////////////////////////
//    Or
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(or_n){

    sc_in< sc_logic> A[2]; 
    sc_out< sc_logic> Y;

    SC_CTOR(or_n){

        SC_METHOD(eval);
        sensitive << A[0] << A[1];

    }

    void eval(void){
        if ((A[0]->read() == SC_LOGIC_0) && (A[1]->read() == SC_LOGIC_0)){
            Y->write(SC_LOGIC_0);
        } else {
            Y->write(SC_LOGIC_1);
        }
    };
};

/////////////////////////////////////////////////////////////////////////////////////
//    Nand
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(nand_n){

    sc_in< sc_logic > A[2]; 
    sc_out< sc_logic > Y;

    SC_CTOR(nand_n){

        SC_METHOD(eval);
        sensitive << A[0] << A[1];

    }

    void eval(void){
        if ((A[0]->read() == SC_LOGIC_1) && (A[1]->read() == SC_LOGIC_1)){
            Y->write(SC_LOGIC_0);
        } else {
            Y->write(SC_LOGIC_1);
        }
    };
};

/////////////////////////////////////////////////////////////////////////////////////
//    Nor
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(nor_n){

    sc_in< sc_logic> A[2]; 
    sc_out< sc_logic> Y;

    SC_CTOR(nor_n){

        SC_METHOD(eval);
        sensitive << A[0] << A[1];

    }

    void eval(void){
        if ((A[0]->read() == SC_LOGIC_0) && (A[1]->read() == SC_LOGIC_0)){
            Y->write(SC_LOGIC_1);
        } else {
            Y->write(SC_LOGIC_0);
        }
    };
};

/////////////////////////////////////////////////////////////////////////////////////
//    Xor
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(xor_n){

    sc_in< sc_logic> A[2]; 
    sc_out< sc_logic> Y;

    SC_CTOR(xor_n){

        SC_METHOD(eval);
        sensitive << A[0] << A[1];

    }

    void eval(void){
        if (A[0]->read() == A[1]->read()){
            Y->write(SC_LOGIC_1);
        } else {
            Y->write(SC_LOGIC_0);
        }
    };
};

/////////////////////////////////////////////////////////////////////////////////////
//    Xnor
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(xnor_n){

    sc_in< sc_logic> A[2]; 
    sc_out< sc_logic> Y;

    SC_CTOR(xnor_n){

        SC_METHOD(eval);
        sensitive << A[0] << A[1];

    }

    void eval(void){
        if (A[0]->read() == A[1]->read()){
            Y->write(SC_LOGIC_0);
        } else {
            Y->write(SC_LOGIC_1);
        }
    };
};

/////////////////////////////////////////////////////////////////////////////////////
//    Primary Input      
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(pin){

    sc_in< sc_logic > I; 
    sc_out< sc_logic > O;

    SC_CTOR(pin){

        SC_METHOD(eval);
        sensitive << I;

    }

    void eval(void){
        O->write(I->read());
    };
};

/////////////////////////////////////////////////////////////////////////////////////
//    Primary Output      
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(pout){

    sc_in< sc_logic > I; 
    sc_out< sc_logic > O;

    SC_CTOR(pout){

        SC_METHOD(eval);
        sensitive << I;

    }

    void eval(void){
        O->write(I->read());
    };
};

/////////////////////////////////////////////////////////////////////////////////////
//    D Flip Flop 
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(dff){

    sc_in<sc_logic> D, C, R, PRE, CE, NbarT, Si, global_reset;
    sc_out<sc_logic> Q;

    sc_signal<sc_logic, SC_MANY_WRITERS> val;
    // sc_signal<sc_logic> val;

    // sc_time tphl; 
    // sc_time tplh;

    SC_HAS_PROCESS(dff);
    dff(sc_module_name _name) 
    : sc_module(_name) {
    // DFlipFlop(sc_module_name _name, sc_time tphl, sc_time tplh) 
    // : sc_module(_name), tphl(tphl), tplh(tplh) {

        SC_THREAD(eval);
            sensitive << val;
        SC_METHOD(set);
            sensitive << C;
        SC_METHOD(reset);
            sensitive << R << global_reset;
        SC_METHOD(preset);
            sensitive << PRE;
        
    }

    void eval(void){
        while(true){
                Q->write(val.read());
            wait();
        }
    }
    void set(void){
        if ((C->read() == SC_LOGIC_1) && ((PRE->read() == SC_LOGIC_0) && (R->read() == SC_LOGIC_0 && global_reset->read() == SC_LOGIC_0))){
            if (NbarT->read() == SC_LOGIC_1) val.write(Si->read());
            else if (CE->read() == SC_LOGIC_1) val.write(D->read());
        }
    }

    void reset(void){
        if (R->read() == SC_LOGIC_1 || global_reset->read() == SC_LOGIC_1) val.write(SC_LOGIC_0);
    }

    void preset(void){
        if ((PRE->read() == SC_LOGIC_1) && (R->read() == SC_LOGIC_0 && global_reset->read() == SC_LOGIC_0)) val.write(SC_LOGIC_1);
    }

};

/////////////////////////////////////////////////////////////////////////////////////
//    D Flip Flop: DFF_NP0
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(DFF_NP0){

    sc_in<sc_logic> D, C, R;
    sc_out<sc_logic> Q;

    sc_signal<sc_logic, SC_MANY_WRITERS> val;
    // sc_signal<sc_logic> val;

    // sc_time tphl; 
    // sc_time tplh;

    SC_HAS_PROCESS(DFF_NP0);
    DFF_NP0(sc_module_name _name) 
    : sc_module(_name) {

        SC_THREAD(eval);
            sensitive << val;
        SC_METHOD(set);
            sensitive << C;
        SC_METHOD(reset);
            sensitive << R;
    }

    void eval(void){
        while(true){
                Q->write(val.read());
            wait();
        }
    }
    void set(void){
        if ((C->read() == SC_LOGIC_0) && (R->read() == SC_LOGIC_0)){
            val.write(D->read());
        }
    }

    void reset(void){
        if (R->read() == SC_LOGIC_1) val.write(SC_LOGIC_0);
    }

};

/////////////////////////////////////////////////////////////////////////////////////
//    D Flip Flop: DFF_NP1
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(DFF_NP1){

    sc_in<sc_logic> D, C, R;
    sc_out<sc_logic> Q;

    sc_signal<sc_logic, SC_MANY_WRITERS> val;
    // sc_signal<sc_logic> val;

    // sc_time tphl; 
    // sc_time tplh;

    SC_HAS_PROCESS(DFF_NP1);
    DFF_NP1(sc_module_name _name) 
    : sc_module(_name) {
    // DFlipFlop(sc_module_name _name, sc_time tphl, sc_time tplh) 
    // : sc_module(_name), tphl(tphl), tplh(tplh) {

        SC_THREAD(eval);
            sensitive << val;
        SC_METHOD(set);
            sensitive << C;
        SC_METHOD(reset);
            sensitive << R;
    }

    void eval(void){
        while(true){
                Q->write(val.read());
            wait();
        }
    }
    void set(void){
        if ((C->read() == SC_LOGIC_0) && (R->read() == SC_LOGIC_0)){
            val.write(D->read());
        }
    }

    void reset(void){
        if (R->read() == SC_LOGIC_1) val.write(SC_LOGIC_1);
    }

};

#endif


