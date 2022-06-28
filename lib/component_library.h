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

    sc_in< sc_logic> in1; 
    sc_out< sc_logic> out1;

    SC_CTOR(bufg){

        SC_METHOD(eval);
        sensitive << in1;

    }

    void eval(void){
        out1->write(in1->read());
    };
};

/////////////////////////////////////////////////////////////////////////////////////
//    Not
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(notg){

    sc_in< sc_logic > in1; 
    sc_out< sc_logic > out1;

    SC_CTOR(notg){

        SC_METHOD(eval);
        sensitive << in1;

    }

    void eval(void){
        if (in1->read() == SC_LOGIC_1){
            out1->write(SC_LOGIC_0);
        } else if (in1->read() == SC_LOGIC_0){
            out1->write(SC_LOGIC_1);
        }
    };
};

/////////////////////////////////////////////////////////////////////////////////////
//    And
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(and_n){

    sc_in< sc_logic> in1[2]; 
    sc_out< sc_logic> out1;

    SC_CTOR(and_n){

        SC_METHOD(eval);
        sensitive << in1[0] << in1[1];

    }

    void eval(void){
        if ((in1[0]->read() == SC_LOGIC_0) || (in1[1]->read() == SC_LOGIC_0)){
            out1->write(SC_LOGIC_0);
        } else {
            out1->write(SC_LOGIC_1);
        }
    };
};

/////////////////////////////////////////////////////////////////////////////////////
//    Or
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(or_n){

    sc_in< sc_logic> in1[2]; 
    sc_out< sc_logic> out1;

    SC_CTOR(or_n){

        SC_METHOD(eval);
        sensitive << in1[0] << in1[1];

    }

    void eval(void){
        if ((in1[0]->read() == SC_LOGIC_0) && (in1[1]->read() == SC_LOGIC_0)){
            out1->write(SC_LOGIC_0);
        } else {
            out1->write(SC_LOGIC_1);
        }
    };
};

/////////////////////////////////////////////////////////////////////////////////////
//    Nand
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(nand_n){

    sc_in< sc_logic > in1[2]; 
    sc_out< sc_logic > out1;

    SC_CTOR(nand_n){

        SC_METHOD(eval);
        sensitive << in1[0] << in1[1];

    }

    void eval(void){
        if ((in1[0]->read() == SC_LOGIC_1) && (in1[1]->read() == SC_LOGIC_1)){
            out1->write(SC_LOGIC_0);
        } else {
            out1->write(SC_LOGIC_1);
        }
    };
};

/////////////////////////////////////////////////////////////////////////////////////
//    Nor
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(nor_n){

    sc_in< sc_logic> in1[2]; 
    sc_out< sc_logic> out1;

    SC_CTOR(nor_n){

        SC_METHOD(eval);
        sensitive << in1[0] << in1[1];

    }

    void eval(void){
        if ((in1[0]->read() == SC_LOGIC_0) && (in1[1]->read() == SC_LOGIC_0)){
            out1->write(SC_LOGIC_1);
        } else {
            out1->write(SC_LOGIC_0);
        }
    };
};

/////////////////////////////////////////////////////////////////////////////////////
//    Xor
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(xor_n){

    sc_in< sc_logic> in1[2]; 
    sc_out< sc_logic> out1;

    SC_CTOR(xor_n){

        SC_METHOD(eval);
        sensitive << in1[0] << in1[1];

    }

    void eval(void){
        if (in1[0]->read() == in1[1]->read()){
            out1->write(SC_LOGIC_1);
        } else {
            out1->write(SC_LOGIC_0);
        }
    };
};

/////////////////////////////////////////////////////////////////////////////////////
//    Xnor
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(xnor_n){

    sc_in< sc_logic> in1[2]; 
    sc_out< sc_logic> out1;

    SC_CTOR(xnor_n){

        SC_METHOD(eval);
        sensitive << in1[0] << in1[1];

    }

    void eval(void){
        if (in1[0]->read() == in1[1]->read()){
            out1->write(SC_LOGIC_0);
        } else {
            out1->write(SC_LOGIC_1);
        }
    };
};

/////////////////////////////////////////////////////////////////////////////////////
//    Primary Input      
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(pin){

    sc_in< sc_logic > in1; 
    sc_out< sc_logic > out1;

    SC_CTOR(pin){

        SC_METHOD(eval);
        sensitive << in1;

    }

    void eval(void){
        out1->write(in1->read());
    };
};

/////////////////////////////////////////////////////////////////////////////////////
//    Primary Output      
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(pout){

    sc_in< sc_logic > in1; 
    sc_out< sc_logic > out1;

    SC_CTOR(pout){

        SC_METHOD(eval);
        sensitive << in1;

    }

    void eval(void){
        out1->write(in1->read());
    };
};

/////////////////////////////////////////////////////////////////////////////////////
//    D Flip Flop 
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(dff){

    sc_in< sc_logic > D, C, CLR, PRE, CE, NbarT, Si, global_reset; 
    sc_out< sc_logic > Q;

    SC_CTOR(dff){

        SC_METHOD(eval);
        sensitive << C.posedge_event() << PRE.posedge_event() << CLR.posedge_event() << global_reset.posedge_event();

    }

    void eval(void){
        if ((CLR->read() == SC_LOGIC_1) || (global_reset->read() == SC_LOGIC_1))
            Q->write(SC_LOGIC_0);
        else if (PRE->read() == SC_LOGIC_1)
            Q->write(SC_LOGIC_1);
        else if (NbarT->read() == SC_LOGIC_1)
            Q->write(Si->read());
        else if (CE->read() == SC_LOGIC_1)
            Q->write(D->read());
        
    };
};




#endif


