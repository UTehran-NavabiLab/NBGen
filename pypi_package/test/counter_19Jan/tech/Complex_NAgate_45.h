/*
* ******************************************************************************
*  This file includes the SystemC models of the Nangate 45 nm library cells    *                                             
*  Copyright (C) 2021 University of Teheran                                    *
*  This source file may be used and distributed without restriction provided   *
*  that this copyright statement is not removed from the file and that any     *
*  derivative work contains the original copyright notice and the associated   *
*  disclaimer.                                                                 *
*  Project: QFLOW                                                              *
*  Last Author : Katayoon                                                      *
* ******************************************************************************
*/


#include "systemc.h"

/*******************************------------------COMPLEX-----------------*******************************/

/////////////////////////////////////////////////////////////////////////////////////
//    MUX2_X1
/*
______________
|A	B	S	Z|
|L	-	L	L|
|H	-	L	H|
|-	L	H	L|
|-	H	H	H|
|____________|
*/
SC_MODULE(MUX2_X1){

    sc_in< sc_logic> A; 
	sc_in< sc_logic> B; 
	sc_in< sc_logic> S; 
    sc_out< sc_logic> Z;

    SC_CTOR(MUX2_X1){

        SC_METHOD(eval);
        sensitive << A << B << S;

    }

    void eval(void){
        if ((S->read() == SC_LOGIC_0)){
            Z->write(A->read());
        } else {
            Z->write(B->read());
        }
    };
};

/////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////
//    MUX2_X2
/*
______________
|A	B	S	Z|
|L	-	L	L|
|H	-	L	H|
|-	L	H	L|
|-	H	H	H|
|____________|
*/
SC_MODULE(MUX2_X2){

    sc_in< sc_logic> A; 
	sc_in< sc_logic> B; 
	sc_in< sc_logic> S; 
    sc_out< sc_logic> Z;

    SC_CTOR(MUX2_X2){

        SC_METHOD(eval);
        sensitive << A << B << S;

    }

    void eval(void){
        if ((S->read() == SC_LOGIC_0)){
            Z->write(A->read());
        } else {
            Z->write(B->read());
        }
    };
};

/////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////
//    AOI211_X1
/*
___________________
|A	B	C1	C2	ZN|
|L	L	L	-	 H|
|L	L	-	L	 H|
|H	-	-	-	 L|
|-	H	-	-	 L|
|-	-	H	H	 L|
|_________________|
*/
SC_MODULE(AOI211_X1){

    sc_in< sc_logic> A; 
	sc_in< sc_logic> B; 
	sc_in< sc_logic> C1;
	sc_in< sc_logic> C2; 	
    sc_out< sc_logic> ZN;

    SC_CTOR(AOI211_X1){

        SC_METHOD(eval);
        sensitive << A << B << C1 << C2;

    }

   void eval(void){
	   sc_logic result;
	   result = ~(((C1->read() & C2->read()) | B->read()) | A->read());
       ZN->write(result);
       
    };
};

/////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////
//    AOI211_X2
/*
___________________
|A	B	C1	C2	ZN|
|L	L	L	-	 H|
|L	L	-	L	 H|
|H	-	-	-	 L|
|-	H	-	-	 L|
|-	-	H	H	 L|
|_________________|
*/
SC_MODULE(AOI211_X2){

	sc_in< sc_logic> A;
	sc_in< sc_logic> B;
	sc_in< sc_logic> C1;
	sc_in< sc_logic> C2;
	sc_out< sc_logic> ZN;

	SC_CTOR(AOI211_X2){

		SC_METHOD(eval);
		sensitive << A << B << C1 << C2;

	}

	void eval(void){
		sc_logic result;
		result = ~(((C1->read() & C2->read()) | B->read()) | A->read());
		ZN->write(result);

	};
};

/////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////
//    AOI211_X4
/*
___________________
|A	B	C1	C2	ZN|
|L	L	L	-	 H|
|L	L	-	L	 H|
|H	-	-	-	 L|
|-	H	-	-	 L|
|-	-	H	H	 L|
|_________________|
*/
SC_MODULE(AOI211_X4){

	sc_in< sc_logic> A;
	sc_in< sc_logic> B;
	sc_in< sc_logic> C1;
	sc_in< sc_logic> C2;
	sc_out< sc_logic> ZN;

	SC_CTOR(AOI211_X4){

		SC_METHOD(eval);
		sensitive << A << B << C1 << C2;

	}

	void eval(void){
		sc_logic result;
		result = ~(((C1->read() & C2->read()) | B->read()) | A->read());
		ZN->write(result);

	};
};

/////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////
//    AOI21_X1
/*
_______________
|A	B1	B2	ZN|
|L	L	-	 H|
|L	-	L	 H|
|H	-	-	 L|
|-	H	H	 L|
|_____________|
*/
SC_MODULE(AOI21_X1){

	sc_in< sc_logic> A;
	sc_in< sc_logic> B1;
	sc_in< sc_logic> B2;
	sc_out< sc_logic> ZN;

	SC_CTOR(AOI21_X1){

		SC_METHOD(eval);
		sensitive << A << B1 << B2;

	}

	void eval(void){
		sc_logic result;
		result = ~((B1->read() & B2->read()) | A->read());
		ZN->write(result);

	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    AOI21_X2
/*
_______________
|A	B1	B2	ZN|
|L	L	-	 H|
|L	-	L	 H|
|H	-	-	 L|
|-	H	H	 L|
|_____________|
*/
SC_MODULE(AOI21_X2){

	sc_in< sc_logic> A;
	sc_in< sc_logic> B1;
	sc_in< sc_logic> B2;
	sc_out< sc_logic> ZN;

	SC_CTOR(AOI21_X2){

		SC_METHOD(eval);
		sensitive << A << B1 << B2;

	}

	void eval(void){
		sc_logic result;
		result = ~((B1->read() & B2->read()) | A->read());
		ZN->write(result);

	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    AOI21_X4
/*
_______________
|A	B1	B2	ZN|
|L	L	-	 H|
|L	-	L	 H|
|H	-	-	 L|
|-	H	H	 L|
|_____________|
*/
SC_MODULE(AOI21_X4){

	sc_in< sc_logic> A;
	sc_in< sc_logic> B1;
	sc_in< sc_logic> B2;
	sc_out< sc_logic> ZN;

	SC_CTOR(AOI21_X4){

		SC_METHOD(eval);
		sensitive << A << B1 << B2;

	}

	void eval(void){
		sc_logic result;
		result = ~((B1->read() & B2->read()) | A->read());
		ZN->write(result);

	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    AOI221_X1
/*
______________________
|A	B1	B2	C1	C2	ZN|
|L	L	-	L	-	 H|
|L	L	-	-	L	 H|
|L	-	L	L	-	 H|
|L	-	L	-	L	 H|
|H	-	-	-	-	 L|
|-	H	H	-	-	 L|
|-	-	-	H	H	 L|
|_____________________|
*/
SC_MODULE(AOI221_X1){

	sc_in< sc_logic> A;
	sc_in< sc_logic> B1;
	sc_in< sc_logic> B2;
	sc_in< sc_logic> C1;
	sc_in< sc_logic> C2;
	sc_out< sc_logic> ZN;

	SC_CTOR(AOI221_X1){

		SC_METHOD(eval);
		sensitive << A << B1 << B2 << C1 << C2;

	}

	void eval(void){
		sc_logic result;
		result = ~(((C1->read() & C2->read()) | A->read()) | (B1->read() & B2->read()));
		ZN->write(result);

	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    AOI221_X2
/*
______________________
|A	B1	B2	C1	C2	ZN|
|L	L	-	L	-	 H|
|L	L	-	-	L	 H|
|L	-	L	L	-	 H|
|L	-	L	-	L	 H|
|H	-	-	-	-	 L|
|-	H	H	-	-	 L|
|-	-	-	H	H	 L|
|_____________________|
*/
SC_MODULE(AOI221_X2){

	sc_in< sc_logic> A;
	sc_in< sc_logic> B1;
	sc_in< sc_logic> B2;
	sc_in< sc_logic> C1;
	sc_in< sc_logic> C2;
	sc_out< sc_logic> ZN;

	SC_CTOR(AOI221_X2){

		SC_METHOD(eval);
		sensitive << A << B1 << B2 << C1 << C2;

	}

	void eval(void){
		sc_logic result;
		result = ~(((C1->read() & C2->read()) | A->read()) | (B1->read() & B2->read()));
		ZN->write(result);

	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    AOI221_X4
/*
______________________
|A	B1	B2	C1	C2	ZN|
|L	L	-	L	-	 H|
|L	L	-	-	L	 H|
|L	-	L	L	-	 H|
|L	-	L	-	L	 H|
|H	-	-	-	-	 L|
|-	H	H	-	-	 L|
|-	-	-	H	H	 L|
|_____________________|
*/
SC_MODULE(AOI221_X4){

	sc_in< sc_logic> A;
	sc_in< sc_logic> B1;
	sc_in< sc_logic> B2;
	sc_in< sc_logic> C1;
	sc_in< sc_logic> C2;
	sc_out< sc_logic> ZN;

	SC_CTOR(AOI221_X4){

		SC_METHOD(eval);
		sensitive << A << B1 << B2 << C1 << C2;

	}

	void eval(void){
		sc_logic result;
		result = ~(((C1->read() & C2->read()) | A->read()) | (B1->read() & B2->read()));
		ZN->write(result);

	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    AOI222_X1
/*
__________________________
|A1	A2	B1	B2	C1	C2	ZN|
|L	-	L	-	L	-	 H|
|L	-	L	-	-	L	 H|
|L	-	-	L	L	-	 H|
|L	-	-	L	-	L	 H|
|H	H	-	-	-	-	 L|
|-	L	L	-	L	-	 H|
|-	L	L	-	-	L	 H|
|-	L	-	L	L	-	 H|
|-	L	-	L	-	L	 H|
|-	-	H	H	-	-	 L|
|-	-	-	-	H	H	 L|
|_________________________|
*/
SC_MODULE(AOI222_X1){

	sc_in< sc_logic> A1;
	sc_in< sc_logic> A2;
	sc_in< sc_logic> B1;
	sc_in< sc_logic> B2;
	sc_in< sc_logic> C1;
	sc_in< sc_logic> C2;
	sc_out< sc_logic> ZN;

	SC_CTOR(AOI222_X1){

		SC_METHOD(eval);
		sensitive << A1 << A2 << B1 << B2 << C1 << C2;

	}

	void eval(void){
		sc_logic result;
		result = ~(((A1->read() & A2->read()) | (B1->read() & B2->read())) | (C1->read() & C2->read()));
		ZN->write(result);

	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    AOI222_X2
/*
__________________________
|A1	A2	B1	B2	C1	C2	ZN|
|L	-	L	-	L	-	 H|
|L	-	L	-	-	L	 H|
|L	-	-	L	L	-	 H|
|L	-	-	L	-	L	 H|
|H	H	-	-	-	-	 L|
|-	L	L	-	L	-	 H|
|-	L	L	-	-	L	 H|
|-	L	-	L	L	-	 H|
|-	L	-	L	-	L	 H|
|-	-	H	H	-	-	 L|
|-	-	-	-	H	H	 L|
|_________________________|
*/
SC_MODULE(AOI222_X2){

	sc_in< sc_logic> A1;
	sc_in< sc_logic> A2;
	sc_in< sc_logic> B1;
	sc_in< sc_logic> B2;
	sc_in< sc_logic> C1;
	sc_in< sc_logic> C2;
	sc_out< sc_logic> ZN;

	SC_CTOR(AOI222_X2){

		SC_METHOD(eval);
		sensitive << A1 << A2 << B1 << B2 << C1 << C2;

	}

	void eval(void){
		sc_logic result;
		result = ~(((A1->read() & A2->read()) | (B1->read() & B2->read())) | (C1->read() & C2->read()));
		ZN->write(result);

	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    AOI222_X4
/*
__________________________
|A1	A2	B1	B2	C1	C2	ZN|
|L	-	L	-	L	-	 H|
|L	-	L	-	-	L	 H|
|L	-	-	L	L	-	 H|
|L	-	-	L	-	L	 H|
|H	H	-	-	-	-	 L|
|-	L	L	-	L	-	 H|
|-	L	L	-	-	L	 H|
|-	L	-	L	L	-	 H|
|-	L	-	L	-	L	 H|
|-	-	H	H	-	-	 L|
|-	-	-	-	H	H	 L|
|_________________________|
*/
SC_MODULE(AOI222_X4){

	sc_in< sc_logic> A1;
	sc_in< sc_logic> A2;
	sc_in< sc_logic> B1;
	sc_in< sc_logic> B2;
	sc_in< sc_logic> C1;
	sc_in< sc_logic> C2;
	sc_out< sc_logic> ZN;

	SC_CTOR(AOI222_X4){

		SC_METHOD(eval);
		sensitive << A1 << A2 << B1 << B2 << C1 << C2;

	}

	void eval(void){
		sc_logic result;
		result = ~(((A1->read() & A2->read()) | (B1->read() & B2->read())) | (C1->read() & C2->read()));
		ZN->write(result);

	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    AOI22_X1
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(AOI22_X1){

	sc_in< sc_logic> A1;
	sc_in< sc_logic> A2;
	sc_in< sc_logic> B1;
	sc_in< sc_logic> B2;
	sc_out< sc_logic> ZN;

	SC_CTOR(AOI22_X1){

		SC_METHOD(eval);
		sensitive << A1 << A2 << B1 << B2;

	}

	void eval(void){
		sc_logic result;
		result = ~((A1->read() & A2->read()) | (B1->read() & B2->read()));
		ZN->write(result);

	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    AOI22_X2
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(AOI22_X2){

	sc_in< sc_logic> A1;
	sc_in< sc_logic> A2;
	sc_in< sc_logic> B1;
	sc_in< sc_logic> B2;
	sc_out< sc_logic> ZN;

	SC_CTOR(AOI22_X2){

		SC_METHOD(eval);
		sensitive << A1 << A2 << B1 << B2;

	}

	void eval(void){
		sc_logic result;
		result = ~((A1->read() & A2->read()) | (B1->read() & B2->read()));
		ZN->write(result);

	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    AOI22_X4
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(AOI22_X4){

	sc_in< sc_logic> A1;
	sc_in< sc_logic> A2;
	sc_in< sc_logic> B1;
	sc_in< sc_logic> B2;
	sc_out< sc_logic> ZN;

	SC_CTOR(AOI22_X4){

		SC_METHOD(eval);
		sensitive << A1 << A2 << B1 << B2;

	}

	void eval(void){
		sc_logic result;
		result = ~((A1->read() & A2->read()) | (B1->read() & B2->read()));
		ZN->write(result);

	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    OAI211_X1	
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(OAI211_X1){

	sc_in< sc_logic> A;
	sc_in< sc_logic> B;
	sc_in< sc_logic> C1;
	sc_in< sc_logic> C2;
	sc_out< sc_logic> ZN;

	SC_CTOR(OAI211_X1){

		SC_METHOD(eval);
		sensitive << A << B << C1 << C2;

	}

	void eval(void){
		sc_logic result;
		result = ~(((C1->read() | C2->read()) & B->read()) & A->read());
		ZN->write(result);

	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    OAI211_X2
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(OAI211_X2){

	sc_in< sc_logic> A;
	sc_in< sc_logic> B;
	sc_in< sc_logic> C1;
	sc_in< sc_logic> C2;
	sc_out< sc_logic> ZN;

	SC_CTOR(OAI211_X2){

		SC_METHOD(eval);
		sensitive << A << B << C1 << C2;

	}

	void eval(void){
		sc_logic result;
		result = ~(((C1->read() | C2->read()) & B->read()) & A->read());
		ZN->write(result);

	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    OAI211_X4
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(OAI211_X4){

	sc_in< sc_logic> A;
	sc_in< sc_logic> B;
	sc_in< sc_logic> C1;
	sc_in< sc_logic> C2;
	sc_out< sc_logic> ZN;

	SC_CTOR(OAI211_X4){

		SC_METHOD(eval);
		sensitive << A << B << C1 << C2;

	}

	void eval(void){
		sc_logic result;
		result = ~(((C1->read() | C2->read()) & B->read()) & A->read());
		ZN->write(result);

	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    OAI21_X1
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(OAI21_X1){

	sc_in< sc_logic> A;
	sc_in< sc_logic> B1;
	sc_in< sc_logic> B2;
	sc_out< sc_logic> ZN;

	SC_CTOR(OAI21_X1){

		SC_METHOD(eval);
		sensitive << A << B1 << B2;

	}

	void eval(void){
		sc_logic result;
		result = ~((B1->read() | B2->read()) & A->read());
		ZN->write(result);

	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    OAI21_X2
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(OAI21_X2){

	sc_in< sc_logic> A;
	sc_in< sc_logic> B1;
	sc_in< sc_logic> B2;
	sc_out< sc_logic> ZN;

	SC_CTOR(OAI21_X2){

		SC_METHOD(eval);
		sensitive << A << B1 << B2;

	}

	void eval(void){
		sc_logic result;
		result = ~((B1->read() | B2->read()) & A->read());
		ZN->write(result);

	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    OAI21_X4
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(OAI21_X4){

	sc_in< sc_logic> A;
	sc_in< sc_logic> B1;
	sc_in< sc_logic> B2;
	sc_out< sc_logic> ZN;

	SC_CTOR(OAI21_X4){

		SC_METHOD(eval);
		sensitive << A << B1 << B2;

	}

	void eval(void){
		sc_logic result;
		result = ~((B1->read() | B2->read()) & A->read());
		ZN->write(result);

	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    OAI221_X1
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(OAI221_X1){

	sc_in< sc_logic> A;
	sc_in< sc_logic> B1;
	sc_in< sc_logic> B2;
	sc_in< sc_logic> C1;
	sc_in< sc_logic> C2;
	sc_out< sc_logic> ZN;

	SC_CTOR(OAI221_X1){

		SC_METHOD(eval);
		sensitive << A << B1 << B2 << C1 << C2;

	}

	void eval(void){
		sc_logic result;
		result = ~(((C1->read() | C2->read()) & A->read()) & (B1->read() | B2->read()));
		ZN->write(result);

	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    OAI221_X2
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(OAI221_X2){

	sc_in< sc_logic> A;
	sc_in< sc_logic> B1;
	sc_in< sc_logic> B2;
	sc_in< sc_logic> C1;
	sc_in< sc_logic> C2;
	sc_out< sc_logic> ZN;

	SC_CTOR(OAI221_X2){

		SC_METHOD(eval);
		sensitive << A << B1 << B2 << C1 << C2;

	}

	void eval(void){
		sc_logic result;
		result = ~(((C1->read() | C2->read()) & A->read()) & (B1->read() | B2->read()));
		ZN->write(result);

	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    OAI221_X4
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(OAI221_X4){

	sc_in< sc_logic> A;
	sc_in< sc_logic> B1;
	sc_in< sc_logic> B2;
	sc_in< sc_logic> C1;
	sc_in< sc_logic> C2;
	sc_out< sc_logic> ZN;

	SC_CTOR(OAI221_X4){

		SC_METHOD(eval);
		sensitive << A << B1 << B2 << C1 << C2;

	}

	void eval(void){
		sc_logic result;
		result = ~(((C1->read() | C2->read()) & A->read()) & (B1->read() | B2->read()));
		ZN->write(result);

	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    OAI222_X1
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(OAI222_X1){

	sc_in< sc_logic> A1;
	sc_in< sc_logic> A2;
	sc_in< sc_logic> B1;
	sc_in< sc_logic> B2;
	sc_in< sc_logic> C1;
	sc_in< sc_logic> C2;
	sc_out< sc_logic> ZN;

	SC_CTOR(OAI222_X1){

		SC_METHOD(eval);
		sensitive << A1 << A2 << B1 << B2 << C1 << C2;

	}

	void eval(void){
		sc_logic result;
		result = ~(((A1->read() | A2->read()) & (B1->read() | B2->read())) & (C1->read() | C2->read()));
		ZN->write(result);

	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    OAI222_X2
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(OAI222_X2){

	sc_in< sc_logic> A1;
	sc_in< sc_logic> A2;
	sc_in< sc_logic> B1;
	sc_in< sc_logic> B2;
	sc_in< sc_logic> C1;
	sc_in< sc_logic> C2;
	sc_out< sc_logic> ZN;

	SC_CTOR(OAI222_X2){

		SC_METHOD(eval);
		sensitive << A1 << A2 << B1 << B2 << C1 << C2;

	}

	void eval(void){
		sc_logic result;
		result = ~(((A1->read() | A2->read()) & (B1->read() | B2->read())) & (C1->read() | C2->read()));
		ZN->write(result);

	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    OAI222_X4
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(OAI222_X4){

	sc_in< sc_logic> A1;
	sc_in< sc_logic> A2;
	sc_in< sc_logic> B1;
	sc_in< sc_logic> B2;
	sc_in< sc_logic> C1;
	sc_in< sc_logic> C2;
	sc_out< sc_logic> ZN;

	SC_CTOR(OAI222_X4){

		SC_METHOD(eval);
		sensitive << A1 << A2 << B1 << B2 << C1 << C2;

	}

	void eval(void){
		sc_logic result;
		result = ~(((A1->read() | A2->read()) & (B1->read() | B2->read())) & (C1->read() | C2->read()));
		ZN->write(result);

	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    OAI22_X1
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(OAI22_X1){

	sc_in< sc_logic> A1;
	sc_in< sc_logic> A2;
	sc_in< sc_logic> B1;
	sc_in< sc_logic> B2;
	sc_out< sc_logic> ZN;

	SC_CTOR(OAI22_X1){

		SC_METHOD(eval);
		sensitive << A1 << A2 << B1 << B2;

	}

	void eval(void){
		sc_logic result;
		result = ~((A1->read() | A2->read()) & (B1->read() | B2->read()));
		ZN->write(result);

	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    OAI22_X2
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(OAI22_X2){

	sc_in< sc_logic> A1;
	sc_in< sc_logic> A2;
	sc_in< sc_logic> B1;
	sc_in< sc_logic> B2;
	sc_out< sc_logic> ZN;

	SC_CTOR(OAI22_X2){

		SC_METHOD(eval);
		sensitive << A1 << A2 << B1 << B2;

	}

	void eval(void){
		sc_logic result;
		result = ~((A1->read() | A2->read()) & (B1->read() | B2->read()));
		ZN->write(result);

	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    OAI22_X4
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(OAI22_X4){

	sc_in< sc_logic> A1;
	sc_in< sc_logic> A2;
	sc_in< sc_logic> B1;
	sc_in< sc_logic> B2;
	sc_out< sc_logic> ZN;

	SC_CTOR(OAI22_X4){

		SC_METHOD(eval);
		sensitive << A1 << A2 << B1 << B2;

	}

	void eval(void){
		sc_logic result;
		result = ~((A1->read() | A2->read()) & (B1->read() | B2->read()));
		ZN->write(result);

	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    OAI33_X1
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(OAI33_X1){

	sc_in< sc_logic> A1;
	sc_in< sc_logic> A2;
	sc_in< sc_logic> A3;
	sc_in< sc_logic> B1;
	sc_in< sc_logic> B2;
	sc_in< sc_logic> B3;
	sc_out< sc_logic> ZN;

	SC_CTOR(OAI33_X1){

		SC_METHOD(eval);
		sensitive << A1 << A2 << A3 << B1 << B2 << B3;

	}

	void eval(void){
		sc_logic result;
		result = ~(((A1->read() | A2->read()) | A3->read()) & ((B1->read() | B2->read()) | B3->read()));
		ZN->write(result);

	};
};

/////////////////////////////////////////////////////////////////////////////////////


/*******************************------------------ADDERS-----------------*******************************/
/////////////////////////////////////////////////////////////////////////////////////
//    FA_X1
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(FA_X1){

	sc_in< sc_logic> A;
	sc_in< sc_logic> B;
	sc_in< sc_logic> CI;
	sc_out< sc_logic> CO;
	sc_out< sc_logic> S;

	sc_signal<sc_logic> CIN;
	sc_signal<sc_logic> AB;

	SC_CTOR(FA_X1){

		SC_METHOD(eval);
		sensitive << A << B << CI << CIN << AB;

	}

	void eval(void){
		if (CI->read() == SC_LOGIC_1){
			CIN = SC_LOGIC_0;
		}
		else if (CI->read() == SC_LOGIC_0){
			CIN = SC_LOGIC_1;
		}
		if ((A->read() == SC_LOGIC_0) || (B->read() == SC_LOGIC_0)){
			AB = SC_LOGIC_0;
		}
		else {
			AB = SC_LOGIC_1;
		}
		if (A->read() == B->read()){
			CO->write(AB);
		}
		else {
			CO->write(CI->read());
		}
		if (A->read() == B->read()){
			S->write(CI->read());
		}
		else {
			S->write(CIN);
		}
	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    HA_X1
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(HA_X1){

	sc_in< sc_logic> A;
	sc_in< sc_logic> B;
	sc_out< sc_logic> CO;
	sc_out< sc_logic> S;

	SC_CTOR(HA_X1){

		SC_METHOD(eval);
		sensitive << A << B;

	}

	void eval(void){
		if ((A->read() == SC_LOGIC_0) || (B->read() == SC_LOGIC_0)){
			CO->write(SC_LOGIC_0);
		}
		else {
			CO->write(SC_LOGIC_1);
		}
		if (A->read() == B->read()){
			S->write(SC_LOGIC_0);
		}
		else {
			S->write(SC_LOGIC_1);
		}
	};
};

/////////////////////////////////////////////////////////////////////////////////////

/*******************************------------------MISC-----------------*******************************/
/////////////////////////////////////////////////////////////////////////////////////
//    BUF_X1
/*
______
|A	Z|
|L	L|
|H	H|
|____|
*/
SC_MODULE(BUF_X1){

	sc_in< sc_logic> A;
	sc_out< sc_logic> Z;

	SC_CTOR(BUF_X1){

		SC_METHOD(eval);
		sensitive << A;

	}

	void eval(void){
		Z->write(A->read());
	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    BUF_X16
/*
______
|A	Z|
|L	L|
|H	H|
|____|
*/
SC_MODULE(BUF_X16){

	sc_in< sc_logic> A;
	sc_out< sc_logic> Z;

	SC_CTOR(BUF_X16){

		SC_METHOD(eval);
		sensitive << A;

	}

	void eval(void){
		Z->write(A->read());
	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    BUF_X2
/*
______
|A	Z|
|L	L|
|H	H|
|____|
*/
SC_MODULE(BUF_X2){

	sc_in< sc_logic> A;
	sc_out< sc_logic> Z;

	SC_CTOR(BUF_X2){

		SC_METHOD(eval);
		sensitive << A;

	}

	void eval(void){
		Z->write(A->read());
	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    BUF_X32
/*
______
|A	Z|
|L	L|
|H	H|
|____|
*/
SC_MODULE(BUF_X32){

	sc_in< sc_logic> A;
	sc_out< sc_logic> Z;

	SC_CTOR(BUF_X32){

		SC_METHOD(eval);
		sensitive << A;

	}

	void eval(void){
		Z->write(A->read());
	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    BUF_X4
/*
______
|A	Z|
|L	L|
|H	H|
|____|
*/
SC_MODULE(BUF_X4){

	sc_in< sc_logic> A;
	sc_out< sc_logic> Z;

	SC_CTOR(BUF_X4){

		SC_METHOD(eval);
		sensitive << A;

	}

	void eval(void){
		Z->write(A->read());
	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    BUF_X8
/*
______
|A	Z|
|L	L|
|H	H|
|____|
*/
SC_MODULE(BUF_X8){

	sc_in< sc_logic> A;
	sc_out< sc_logic> Z;

	SC_CTOR(BUF_X8){

		SC_METHOD(eval);
		sensitive << A;

	}

	void eval(void){
		Z->write(A->read());
	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    CLKBUF_X1
/*
______
|A	Z|
|L	L|
|H	H|
|____|
*/
SC_MODULE(CLKBUF_X1){

	sc_in< sc_logic> A;
	sc_out< sc_logic> Z;

	SC_CTOR(CLKBUF_X1){

		SC_METHOD(eval);
		sensitive << A;

	}

	void eval(void){
		Z->write(A->read());
	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    CLKBUF_X2
/*
______
|A	Z|
|L	L|
|H	H|
|____|
*/
SC_MODULE(CLKBUF_X2){

	sc_in< sc_logic> A;
	sc_out< sc_logic> Z;

	SC_CTOR(CLKBUF_X2){

		SC_METHOD(eval);
		sensitive << A;

	}

	void eval(void){
		Z->write(A->read());
	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    CLKBUF_X3
/*
______
|A	Z|
|L	L|
|H	H|
|____|
*/
SC_MODULE(CLKBUF_X3){

	sc_in< sc_logic> A;
	sc_out< sc_logic> Z;

	SC_CTOR(CLKBUF_X3){

		SC_METHOD(eval);
		sensitive << A;

	}

	void eval(void){
		Z->write(A->read());
	};
};

/////////////////////////////////////////////////////////////////////////////////////

/*******************************------------------TRI_BUF-----------------*******************************/
/////////////////////////////////////////////////////////////////////////////////////
//    TBUF_X1
/*
__________
|A	EN	Z|
|L	L	L|
|H	L	H|
|-	H	Z|
|________|
*/
SC_MODULE(TBUF_X1){

	sc_in< sc_logic> A;
	sc_in< sc_logic> EN;
	sc_out< sc_logic> Z;

	SC_CTOR(TBUF_X1){

		SC_METHOD(eval);
		sensitive << A << EN;

	}

	void eval(void){
		if (EN->read() == SC_LOGIC_0){
			Z->write(A->read());
		}
		else
			Z->write(SC_LOGIC_Z);
	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    TBUF_X16
/*
__________
|A	EN	Z|
|L	L	L|
|H	L	H|
|-	H	Z|
|________|
*/
SC_MODULE(TBUF_X16){

	sc_in< sc_logic> A;
	sc_in< sc_logic> EN;
	sc_out< sc_logic> Z;

	SC_CTOR(TBUF_X16){

		SC_METHOD(eval);
		sensitive << A << EN;

	}

	void eval(void){
		if (EN->read() == SC_LOGIC_0){
			Z->write(A->read());
		}
		else
			Z->write(SC_LOGIC_Z);
	};
};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    TBUF_X12
/*
__________
|A	EN	Z|
|L	L	L|
|H	L	H|
|-	H	Z|
|________|
*/
SC_MODULE(TBUF_X2){

	sc_in< sc_logic> A;
	sc_in< sc_logic> EN;
	sc_out< sc_logic> Z;

	SC_CTOR(TBUF_X2){

		SC_METHOD(eval);
		sensitive << A << EN;

	}

	void eval(void){
		if (EN->read() == SC_LOGIC_0){
			Z->write(A->read());
		}
		else
			Z->write(SC_LOGIC_Z);
	};
};

/////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////
//    TBUF_X8
/*
__________
|A	EN	Z|
|L	L	L|
|H	L	H|
|-	H	Z|
|________|
*/
SC_MODULE(TBUF_X8){

	sc_in< sc_logic> A;
	sc_in< sc_logic> EN;
	sc_out< sc_logic> Z;

	SC_CTOR(TBUF_X8){

		SC_METHOD(eval);
		sensitive << A << EN;

	}

	void eval(void){
		if (EN->read() == SC_LOGIC_0){
			Z->write(A->read());
		}
		else
			Z->write(SC_LOGIC_Z);
	};
};

/////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////
//    TINV_X1
/*
___________
|I	EN	ZN|
|L	L	 H|
|H	L	 L|
|-	H	 Z|
|_________|
*/
SC_MODULE(TINV_X1){

	sc_in< sc_logic> I;
	sc_in< sc_logic> EN;
	sc_out< sc_logic> ZN;

	SC_CTOR(TINV_X1){

		SC_METHOD(eval);
		sensitive << I << EN;

	}

	void eval(void){
		if (EN->read() == SC_LOGIC_0){
			ZN->write(~(I->read()));
		}
		else
			ZN->write(SC_LOGIC_Z);
	};
};

/////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////
//    TLAT_X1:High enable Latch 
/*
_________________________________
|OE	D	G	IQ(int)	IQN(int)	Q|
|L	-	-	-		-			Z|
|H	L	H	-		-			L|
|H	H	H	-		-			H|
|H	-	L	L		H			L|
|H	-	L	H		L			H|
|________________________________|
*/

SC_MODULE(TLAT_X1){

	sc_in<sc_logic> OE, D, G;
	sc_out<sc_logic> Q;

	sc_signal<sc_logic, SC_MANY_WRITERS> val;

	SC_HAS_PROCESS(TLAT_X1);
	TLAT_X1(sc_module_name _name)
		: sc_module(_name) {

		SC_THREAD(eval);
		sensitive << val << OE;
		SC_METHOD(set);
		sensitive << D << G;
	}

	void eval(void){
		while (true){
			if (OE->read() == SC_LOGIC_1)
				Q->write(val.read());
			else
				Q->write(SC_LOGIC_Z);
			wait();
		}
	}
	void set(void){
		if (G->read() == SC_LOGIC_1){
			val.write(D->read());
		}
	}

};

/////////////////////////////////////////////////////////////////////////////////////

/*******************************------------------LOGIC-----------------*******************************/

/////////////////////////////////////////////////////////////////////////////////////
//    LOGIC0_X1
SC_MODULE(LOGIC0_X1){

	sc_out< sc_logic> Z;

	SC_CTOR(LOGIC0_X1){

		SC_METHOD(eval);

	}

	void eval(void){
		Z->write(SC_LOGIC_0);
	};
};

/////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////
//    LOGIC1_X1
SC_MODULE(LOGIC1_X1){

	sc_out< sc_logic> Z;

	SC_CTOR(LOGIC1_X1){

		SC_METHOD(eval);

	}

	void eval(void){
		Z->write(SC_LOGIC_1);
	};
};

/////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////
//    DLH_X1: High Enable D-Latch
/*
______________________________
|D	GN	IQ(int)	IQN(int)	Q|
|L	H	-		-			L|
|H	H	-		-			H|
|-	L	L		H			L|
|-	L	H		L			H|
|____________________________|
*/

SC_MODULE(DLH_X1){

	sc_in<sc_logic> D, G;
	sc_out<sc_logic> Q;

	sc_signal<sc_logic, SC_MANY_WRITERS> val;

	SC_HAS_PROCESS(DLH_X1);
	DLH_X1(sc_module_name _name)
		: sc_module(_name) {

		SC_THREAD(eval);
		sensitive << val;
		SC_METHOD(set);
		sensitive << G << D;
	}

	void eval(void){
		while (true){
			Q->write(val.read());
			wait();
		}
	}
	void set(void){
		if ((G->read() == SC_LOGIC_1)){
			val.write(D->read());
		}
	}

};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    DLL_X1: Low Enable D-Latch
/*
______________________________
|D	GN	IQ(int)	IQN(int)	Q|
|L	L	-		-			L|
|H	L	-		-			H|
|-	H	L		H			L|
|-	H	H		L			H|
|____________________________|
*/

SC_MODULE(DLL_X1){

	sc_in<sc_logic> D, G;
	sc_out<sc_logic> Q;

	sc_signal<sc_logic, SC_MANY_WRITERS> val;

	SC_HAS_PROCESS(DLL_X1);
	DLL_X1(sc_module_name _name)
		: sc_module(_name) {

		SC_THREAD(eval);
		sensitive << val;
		SC_METHOD(set);
		sensitive << G << D;
	}

	void eval(void){
		while (true){
			Q->write(val.read());
			wait();
		}
	}
	void set(void){
		if ((G->read() == SC_LOGIC_0)){
			val.write(D->read());
		}
	}

};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    DLH_X2: High Enable D-Latch
/*
______________________________
|D	GN	IQ(int)	IQN(int)	Q|
|L	H	-		-			L|
|H	H	-		-			H|
|-	L	L		H			L|
|-	L	H		L			H|
|____________________________|
*/

SC_MODULE(DLH_X2){

	sc_in<sc_logic> D, G;
	sc_out<sc_logic> Q;

	sc_signal<sc_logic, SC_MANY_WRITERS> val;

	SC_HAS_PROCESS(DLH_X2);
	DLH_X2(sc_module_name _name)
		: sc_module(_name) {

		SC_THREAD(eval);
		sensitive << val;
		SC_METHOD(set);
		sensitive << G << D;
	}

	void eval(void){
		while (true){
			Q->write(val.read());
			wait();
		}
	}
	void set(void){
		if ((G->read() == SC_LOGIC_1)){
			val.write(D->read());
		}
	}

};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    DLL_X2: Low Enable D-Latch
/*
______________________________
|D	GN	IQ(int)	IQN(int)	Q|
|L	L	-		-			L|
|H	L	-		-			H|
|-	H	L		H			L|
|-	H	H		L			H|
|____________________________|
*/

SC_MODULE(DLL_X2){

	sc_in<sc_logic> D, G;
	sc_out<sc_logic> Q;

	sc_signal<sc_logic, SC_MANY_WRITERS> val;

	SC_HAS_PROCESS(DLL_X2);
	DLL_X2(sc_module_name _name)
		: sc_module(_name) {

		SC_THREAD(eval);
		sensitive << val;
		SC_METHOD(set);
		sensitive << G << D;
	}

	void eval(void){
		while (true){
			Q->write(val.read());
			wait();
		}
	}
	void set(void){
		if ((G->read() == SC_LOGIC_0)){
			val.write(D->read());
		}
	}

};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    CLKGATETST_X1: Gated Clock with Test Mode
/*
___________________________
|CK	E	SE	IQ(int)	   GCK|
|L	L	L	  -			 L|
|L	L	H	  -			 L|
|L	H	L	  -			 L|
|L	H	H	  -			 L|
|H	L	L	  L			 L|
|H	L	L	  H			 H|
|H	L	H	  L			 L|
|H	L	H	  H			 H|
|H	H	L	  L			 L|
|H	H	L	  H			 H|
|H	H	H	  L			 L|
|H	H	H	  H			 H|
__________________________|
*/

SC_MODULE(CLKGATETST_X1){

	sc_in<sc_logic> E, SE, CK;
	sc_out<sc_logic> GCK;

	sc_signal<sc_logic, SC_MANY_WRITERS> val;

	SC_HAS_PROCESS(CLKGATETST_X1);
	CLKGATETST_X1(sc_module_name _name)
		: sc_module(_name) {

		SC_THREAD(eval);
		sensitive << val << CK;
		SC_METHOD(set);
		sensitive << E << SE << CK;
	}

	void eval(void){
		while (true){
			if (CK->read() == SC_LOGIC_1)
				GCK->write(val.read());
			else
				GCK->write(SC_LOGIC_0);
			wait();
		}
	}
	void set(void){
		if (CK ->read() == SC_LOGIC_0){
			val.write((E->read() | SE->read()));
		}
	}

};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    CLKGATETST_X2: Gated Clock with Test Mode
/*
___________________________
|CK	E	SE	IQ(int)		GCK
|L	L	L	  -			 L|
|L	L	H	  -			 L|
|L	H	L	  -			 L|
|L	H	H	  -			 L|
|H	L	L	  L			 L|
|H	L	L	  H			 H|
|H	L	H	  L			 L|
|H	L	H	  H			 H|
|H	H	L	  L			 L|
|H	H	L	  H			 H|
|H	H	H	  L			 L|
|H	H	H	  H			 H|
__________________________|
*/

SC_MODULE(CLKGATETST_X2){

	sc_in<sc_logic> E, SE, CK;
	sc_out<sc_logic> GCK;

	sc_signal<sc_logic, SC_MANY_WRITERS> val;

	SC_HAS_PROCESS(CLKGATETST_X2);
	CLKGATETST_X2(sc_module_name _name)
		: sc_module(_name) {

		SC_THREAD(eval);
		sensitive << val << CK;
		SC_METHOD(set);
		sensitive << E << SE << CK;
	}

	void eval(void){
		while (true){
			if (CK->read() == SC_LOGIC_1)
				GCK->write(val.read());
			else
				GCK->write(SC_LOGIC_0);
			wait();
		}
	}
	void set(void){
		if (CK->read() == SC_LOGIC_0){
			val.write((E->read() | SE->read()));
		}
	}

};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    CLKGATETST_X4: Gated Clock with Test Mode
/*
___________________________
|CK	E	SE	IQ(int)		GCK
|L	L	L	  -			 L|
|L	L	H	  -			 L|
|L	H	L	  -			 L|
|L	H	H	  -			 L|
|H	L	L	  L			 L|
|H	L	L	  H			 H|
|H	L	H	  L			 L|
|H	L	H	  H			 H|
|H	H	L	  L			 L|
|H	H	L	  H			 H|
|H	H	H	  L			 L|
|H	H	H	  H			 H|
__________________________|
*/

SC_MODULE(CLKGATETST_X4){

	sc_in<sc_logic> E, SE, CK;
	sc_out<sc_logic> GCK;

	sc_signal<sc_logic, SC_MANY_WRITERS> val;

	SC_HAS_PROCESS(CLKGATETST_X4);
	CLKGATETST_X4(sc_module_name _name)
		: sc_module(_name) {

		SC_THREAD(eval);
		sensitive << val << CK;
		SC_METHOD(set);
		sensitive << E << SE << CK;
	}

	void eval(void){
		while (true){
			if (CK->read() == SC_LOGIC_1)
				GCK->write(val.read());
			else
				GCK->write(SC_LOGIC_0);
			wait();
		}
	}
	void set(void){
		if (CK->read() == SC_LOGIC_0){
			val.write((E->read() | SE->read()));
		}
	}

};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    CLKGATETST_X8: Gated Clock with Test Mode
/*
___________________________
|CK	E	SE	IQ(int)		GCK
|L	L	L	  -			 L|
|L	L	H	  -			 L|
|L	H	L	  -			 L|
|L	H	H	  -			 L|
|H	L	L	  L			 L|
|H	L	L	  H			 H|
|H	L	H	  L			 L|
|H	L	H	  H			 H|
|H	H	L	  L			 L|
|H	H	L	  H			 H|
|H	H	H	  L			 L|
|H	H	H	  H			 H|
__________________________|
*/

SC_MODULE(CLKGATETST_X8){

	sc_in<sc_logic> E, SE, CK;
	sc_out<sc_logic> GCK;

	sc_signal<sc_logic, SC_MANY_WRITERS> val;

	SC_HAS_PROCESS(CLKGATETST_X8);
	CLKGATETST_X8(sc_module_name _name)
		: sc_module(_name) {

		SC_THREAD(eval);
		sensitive << val << CK;
		SC_METHOD(set);
		sensitive << E << SE << CK;
	}

	void eval(void){
		while (true){
			if (CK->read() == SC_LOGIC_1)
				GCK->write(val.read());
			else
				GCK->write(SC_LOGIC_0);
			wait();
		}
	}
	void set(void){
		if (CK->read() == SC_LOGIC_0){
			val.write((E->read() | SE->read()));
		}
	}

};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    CLKGATE_X1: Gated Clock 
/*
____________________
|CK	E	IQ(int)	GCK|
|L	L	-		L  |
|L	H	-		L  |
|H	L	L		L  |
|H	L	H		H  |
|H	H	L		L  |
|H	H	H		H  |
___________________|
*/

SC_MODULE(CLKGATE_X1){

	sc_in<sc_logic> E, CK;
	sc_out<sc_logic> GCK;

	sc_signal<sc_logic, SC_MANY_WRITERS> val;

	SC_HAS_PROCESS(CLKGATE_X1);
	CLKGATE_X1(sc_module_name _name)
		: sc_module(_name) {

		SC_THREAD(eval);
		sensitive << val << CK;
		SC_METHOD(set);
		sensitive << E << CK;
	}

	void eval(void){
		while (true){
			if (CK->read() == SC_LOGIC_1)
				GCK->write(val.read());
			else
				GCK->write(SC_LOGIC_0);
			wait();
		}
	}
	void set(void){
		if (CK->read() == SC_LOGIC_0){
			val.write(E->read());
		}
	}

};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    CLKGATE_X2: Gated Clock 
/*
____________________
|CK	E	IQ(int)	GCK|
|L	L	-		L  |
|L	H	-		L  |
|H	L	L		L  |
|H	L	H		H  |
|H	H	L		L  |
|H	H	H		H  |
___________________|
*/

SC_MODULE(CLKGATE_X2){

	sc_in<sc_logic> E, CK;
	sc_out<sc_logic> GCK;

	sc_signal<sc_logic, SC_MANY_WRITERS> val;

	SC_HAS_PROCESS(CLKGATE_X2);
	CLKGATE_X2(sc_module_name _name)
		: sc_module(_name) {

		SC_THREAD(eval);
		sensitive << val << CK;
		SC_METHOD(set);
		sensitive << E << CK;
	}

	void eval(void){
		while (true){
			if (CK->read() == SC_LOGIC_1)
				GCK->write(val.read());
			else
				GCK->write(SC_LOGIC_0);
			wait();
		}
	}
	void set(void){
		if (CK->read() == SC_LOGIC_0){
			val.write(E->read());
		}
	}

};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    CLKGATE_X4: Gated Clock 
/*
____________________
|CK	E	IQ(int)	GCK|
|L	L	-		L  |
|L	H	-		L  |
|H	L	L		L  |
|H	L	H		H  |
|H	H	L		L  |
|H	H	H		H  |
___________________|
*/

SC_MODULE(CLKGATE_X4){

	sc_in<sc_logic> E, CK;
	sc_out<sc_logic> GCK;

	sc_signal<sc_logic, SC_MANY_WRITERS> val;

	SC_HAS_PROCESS(CLKGATE_X4);
	CLKGATE_X4(sc_module_name _name)
		: sc_module(_name) {

		SC_THREAD(eval);
		sensitive << val << CK;
		SC_METHOD(set);
		sensitive << E << CK;
	}

	void eval(void){
		while (true){
			if (CK->read() == SC_LOGIC_1)
				GCK->write(val.read());
			else
				GCK->write(SC_LOGIC_0);
			wait();
		}
	}
	void set(void){
		if (CK->read() == SC_LOGIC_0){
			val.write(E->read());
		}
	}

};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    CLKGATE_X8: Gated Clock 
/*
____________________
|CK	E	IQ(int)	GCK|
|L	L	-		L  |
|L	H	-		L  |
|H	L	L		L  |
|H	L	H		H  |
|H	H	L		L  |
|H	H	H		H  |
___________________|
*/

SC_MODULE(CLKGATE_X8){

	sc_in<sc_logic> E, CK;
	sc_out<sc_logic> GCK;

	sc_signal<sc_logic, SC_MANY_WRITERS> val;

	SC_HAS_PROCESS(CLKGATE_X8);
	CLKGATE_X8(sc_module_name _name)
		: sc_module(_name) {

		SC_THREAD(eval);
		sensitive << val << CK;
		SC_METHOD(set);
		sensitive << E << CK;
	}

	void eval(void){
		while (true){
			if (CK->read() == SC_LOGIC_1)
				GCK->write(val.read());
			else
				GCK->write(SC_LOGIC_0);
			wait();
		}
	}
	void set(void){
		if (CK->read() == SC_LOGIC_0){
			val.write(E->read());
		}
	}

};

/////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////
//    FILLCELL_X1
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(FILLCELL_X1){

};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    FILLCELL_X16
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(FILLCELL_X16){

};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    FILLCELL_X2
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(FILLCELL_X2){

};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    FILLCELL_X32
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(FILLCELL_X32){

};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    FILLCELL_X4
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(FILLCELL_X4){

};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    FILLCELL_X8
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(FILLCELL_X8){

};

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//    ANTENNA_X1
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(ANTENNA_X1){

	sc_in< sc_logic> A;

};

/////////////////////////////////////////////////////////////////////////////////////






SC_MODULE(AND2_X1){

    sc_in< sc_logic> A1; 
    sc_in< sc_logic> A2; 
    sc_out< sc_logic> ZN;

    SC_CTOR(AND2_X1){

        SC_METHOD(eval);
        sensitive << A1 << A2;

    }

    void eval(void){
        if ((A1->read() == SC_LOGIC_0) || (A2->read() == SC_LOGIC_0)){
            ZN->write(SC_LOGIC_0);
        } else {
            ZN->write(SC_LOGIC_1);
        }
    };
};


SC_MODULE(AND2_X2){

    sc_in< sc_logic> A1; 
    sc_in< sc_logic> A2; 
    sc_out< sc_logic> ZN;

    SC_CTOR(AND2_X2){

        SC_METHOD(eval);
        sensitive << A1 << A2;

    }

    void eval(void){
        if ((A1->read() == SC_LOGIC_0) || (A2->read() == SC_LOGIC_0)){
            ZN->write(SC_LOGIC_0);
        } else {
            ZN->write(SC_LOGIC_1);
        }
    };
};


SC_MODULE(AND2_X4){

    sc_in< sc_logic> A1; 
    sc_in< sc_logic> A2; 
    sc_out< sc_logic> ZN;

    SC_CTOR(AND2_X4){

        SC_METHOD(eval);
        sensitive << A1 << A2;

    }

    void eval(void){
        if ((A1->read() == SC_LOGIC_0) || (A2->read() == SC_LOGIC_0)){
            ZN->write(SC_LOGIC_0);
        } else {
            ZN->write(SC_LOGIC_1);
        }
    };
};

SC_MODULE(AND3_X1){

    sc_in< sc_logic> A1; 
    sc_in< sc_logic> A2; 
    sc_in< sc_logic> A3; 
    sc_out< sc_logic> ZN;

    SC_CTOR(AND3_X1){

        SC_METHOD(eval);
        sensitive << A1 << A2 << A3;

    }

    void eval(void){
        if ((A1->read() == SC_LOGIC_0) || (A2->read() == SC_LOGIC_0)|| (A3->read() == SC_LOGIC_0)){
            ZN->write(SC_LOGIC_0);
        } else {
            ZN->write(SC_LOGIC_1);
        }
    };
};

SC_MODULE(AND3_X2){

    sc_in< sc_logic> A1; 
    sc_in< sc_logic> A2; 
    sc_in< sc_logic> A3; 
    sc_out< sc_logic> ZN;

    SC_CTOR(AND3_X2){

        SC_METHOD(eval);
        sensitive << A1 << A2 << A3;

    }

    void eval(void){
        if ((A1->read() == SC_LOGIC_0) || (A2->read() == SC_LOGIC_0)|| (A3->read() == SC_LOGIC_0)){
            ZN->write(SC_LOGIC_0);
        } else {
            ZN->write(SC_LOGIC_1);
        }
    };
};

SC_MODULE(AND3_X4){

    sc_in< sc_logic> A1; 
    sc_in< sc_logic> A2; 
    sc_in< sc_logic> A3; 
    sc_out< sc_logic> ZN;

    SC_CTOR(AND3_X4){

        SC_METHOD(eval);
        sensitive << A1 << A2 << A3;

    }

    void eval(void){
        if ((A1->read() == SC_LOGIC_0) || (A2->read() == SC_LOGIC_0)|| (A3->read() == SC_LOGIC_0)){
            ZN->write(SC_LOGIC_0);
        } else {
            ZN->write(SC_LOGIC_1);
        }
    };
};


SC_MODULE(AND4_X1){

    sc_in< sc_logic> A1; 
    sc_in< sc_logic> A2; 
    sc_in< sc_logic> A3; 
    sc_in< sc_logic> A4; 
    sc_out< sc_logic> ZN;

    SC_CTOR(AND4_X1){

        SC_METHOD(eval);
        sensitive << A1 << A2 << A3 << A4;

    }

    void eval(void){
        if ((A1->read() == SC_LOGIC_0) || (A2->read() == SC_LOGIC_0) || (A3->read() == SC_LOGIC_0) || (A4->read() == SC_LOGIC_0)){
            ZN->write(SC_LOGIC_0);
        } else {
            ZN->write(SC_LOGIC_1);
        }
    };
};


SC_MODULE(AND4_X2){

    sc_in< sc_logic> A1; 
    sc_in< sc_logic> A2; 
    sc_in< sc_logic> A3; 
    sc_in< sc_logic> A4; 
    sc_out< sc_logic> ZN;

    SC_CTOR(AND4_X2){

        SC_METHOD(eval);
        sensitive << A1 << A2 << A3 << A4;

    }

    void eval(void){
        if ((A1->read() == SC_LOGIC_0) || (A2->read() == SC_LOGIC_0) || (A3->read() == SC_LOGIC_0) || (A4->read() == SC_LOGIC_0)){
            ZN->write(SC_LOGIC_0);
        } else {
            ZN->write(SC_LOGIC_1);
        }
    };
};


SC_MODULE(AND4_X4){

    sc_in< sc_logic> A1; 
    sc_in< sc_logic> A2; 
    sc_in< sc_logic> A3; 
    sc_in< sc_logic> A4; 
    sc_out< sc_logic> ZN;

    SC_CTOR(AND4_X4){

        SC_METHOD(eval);
        sensitive << A1 << A2 << A3 << A4;

    }

    void eval(void){
        if ((A1->read() == SC_LOGIC_0) || (A2->read() == SC_LOGIC_0) || (A3->read() == SC_LOGIC_0) || (A4->read() == SC_LOGIC_0)){
            ZN->write(SC_LOGIC_0);
        } else {
            ZN->write(SC_LOGIC_1);
        }
    };
};

SC_MODULE(NAND2_X1){

    sc_in< sc_logic> A1; 
    sc_in< sc_logic> A2; 
    sc_out< sc_logic> ZN;

    SC_CTOR(NAND2_X1){

        SC_METHOD(eval);
        sensitive << A1 << A2;

    }

    void eval(void){
        if ((A1->read() == SC_LOGIC_1) && (A2->read() == SC_LOGIC_1)){
            ZN->write(SC_LOGIC_0);
        } else {
            ZN->write(SC_LOGIC_1);
        }
    };
};


SC_MODULE(NAND2_X2){

    sc_in< sc_logic> A1; 
    sc_in< sc_logic> A2; 
    sc_out< sc_logic> ZN;

    SC_CTOR(NAND2_X2){

        SC_METHOD(eval);
        sensitive << A1 << A2;

    }

    void eval(void){
        if ((A1->read() == SC_LOGIC_1) && (A2->read() == SC_LOGIC_1)){
            ZN->write(SC_LOGIC_0);
        } else {
            ZN->write(SC_LOGIC_1);
        }
    };
};


SC_MODULE(NAND2_X4){

    sc_in< sc_logic> A1; 
    sc_in< sc_logic> A2; 
    sc_out< sc_logic> ZN;

    SC_CTOR(NAND2_X4){

        SC_METHOD(eval);
        sensitive << A1 << A2;

    }

    void eval(void){
        if ((A1->read() == SC_LOGIC_1) && (A2->read() == SC_LOGIC_1)){
            ZN->write(SC_LOGIC_0);
        } else {
            ZN->write(SC_LOGIC_1);
        }
    };
};

SC_MODULE(NAND3_X1){

    sc_in< sc_logic> A1; 
    sc_in< sc_logic> A2; 
    sc_in< sc_logic> A3; 
    sc_out< sc_logic> ZN;

    SC_CTOR(NAND3_X1){

        SC_METHOD(eval);
        sensitive << A1 << A2 << A3;

    }

    void eval(void){
        if ((A1->read() == SC_LOGIC_1) && (A2->read() == SC_LOGIC_1) && (A3->read() == SC_LOGIC_1)){
            ZN->write(SC_LOGIC_0);
        } else {
            ZN->write(SC_LOGIC_1);
        }
    };
};

SC_MODULE(NAND3_X2){

    sc_in< sc_logic> A1; 
    sc_in< sc_logic> A2; 
    sc_in< sc_logic> A3; 
    sc_out< sc_logic> ZN;

    SC_CTOR(NAND3_X2){

        SC_METHOD(eval);
        sensitive << A1 << A2 << A3;

    }

    void eval(void){
        if ((A1->read() == SC_LOGIC_1) && (A2->read() == SC_LOGIC_1) && (A3->read() == SC_LOGIC_1)){
            ZN->write(SC_LOGIC_0);
        } else {
            ZN->write(SC_LOGIC_1);
        }
    };
};

SC_MODULE(NAND3_X4){

    sc_in< sc_logic> A1; 
    sc_in< sc_logic> A2; 
    sc_in< sc_logic> A3; 
    sc_out< sc_logic> ZN;

    SC_CTOR(NAND3_X4){

        SC_METHOD(eval);
        sensitive << A1 << A2 << A3;

    }

    void eval(void){
        if ((A1->read() == SC_LOGIC_1) && (A2->read() == SC_LOGIC_1) && (A3->read() == SC_LOGIC_1)){
            ZN->write(SC_LOGIC_0);
        } else {
            ZN->write(SC_LOGIC_1);
        }
    };
};


SC_MODULE(NAND4_X1){

    sc_in< sc_logic> A1; 
    sc_in< sc_logic> A2; 
    sc_in< sc_logic> A3; 
    sc_in< sc_logic> A4; 
    sc_out< sc_logic > ZN;

    SC_CTOR(NAND4_X1){

        SC_METHOD(eval);
        sensitive << A1 << A2 << A3 << A4;

    }

    void eval(void){
        if ((A1->read() == SC_LOGIC_1) && (A2->read() == SC_LOGIC_1) && (A3->read() == SC_LOGIC_1) && (A4->read() == SC_LOGIC_1)){
            ZN->write(SC_LOGIC_0);
        } else {
            ZN->write(SC_LOGIC_1);
        }
    };
};


SC_MODULE(NAND4_X2){

    sc_in< sc_logic> A1; 
    sc_in< sc_logic> A2; 
    sc_in< sc_logic> A3; 
    sc_in< sc_logic> A4; 
    sc_out< sc_logic > ZN;

    SC_CTOR(NAND4_X2){

        SC_METHOD(eval);
        sensitive << A1 << A2 << A3 << A4;

    }

    void eval(void){
        if ((A1->read() == SC_LOGIC_1) && (A2->read() == SC_LOGIC_1) && (A3->read() == SC_LOGIC_1) && (A4->read() == SC_LOGIC_1)){
            ZN->write(SC_LOGIC_0);
        } else {
            ZN->write(SC_LOGIC_1);
        }
    };
};


SC_MODULE(NAND4_X4){

    sc_in< sc_logic> A1; 
    sc_in< sc_logic> A2; 
    sc_in< sc_logic> A3; 
    sc_in< sc_logic> A4; 
    sc_out< sc_logic > ZN;

    SC_CTOR(NAND4_X4){

        SC_METHOD(eval);
        sensitive << A1 << A2 << A3 << A4;

    }

    void eval(void){
        if ((A1->read() == SC_LOGIC_1) && (A2->read() == SC_LOGIC_1) && (A3->read() == SC_LOGIC_1) && (A4->read() == SC_LOGIC_1)){
            ZN->write(SC_LOGIC_0);
        } else {
            ZN->write(SC_LOGIC_1);
        }
    };
};

SC_MODULE(OR2_X1){

    sc_in< sc_logic> A1; 
    sc_in< sc_logic> A2; 
    sc_out< sc_logic> ZN;

    SC_CTOR(OR2_X1){

        SC_METHOD(eval);
        sensitive << A1 << A2;

    }

    void eval(void){
        if ((A1->read() == SC_LOGIC_0) && (A2->read() == SC_LOGIC_0)){
            ZN->write(SC_LOGIC_0);
        } else {
            ZN->write(SC_LOGIC_1);
        }
    };
};


SC_MODULE(OR2_X2){

    sc_in< sc_logic> A1; 
    sc_in< sc_logic> A2; 
    sc_out< sc_logic> ZN;

    SC_CTOR(OR2_X2){

        SC_METHOD(eval);
        sensitive << A1 << A2;

    }

    void eval(void){
        if ((A1->read() == SC_LOGIC_0) && (A2->read() == SC_LOGIC_0)){
            ZN->write(SC_LOGIC_0);
        } else {
            ZN->write(SC_LOGIC_1);
        }
    };
};


SC_MODULE(OR2_X4){

    sc_in< sc_logic> A1; 
    sc_in< sc_logic> A2; 
    sc_out< sc_logic> ZN;

    SC_CTOR(OR2_X4){

        SC_METHOD(eval);
        sensitive << A1 << A2;

    }

    void eval(void){
        if ((A1->read() == SC_LOGIC_0) && (A2->read() == SC_LOGIC_0)){
            ZN->write(SC_LOGIC_0);
        } else {
            ZN->write(SC_LOGIC_1);
        }
    };
};

SC_MODULE(OR3_X1){

    sc_in< sc_logic> A1; 
    sc_in< sc_logic> A2; 
    sc_in< sc_logic> A3; 
    sc_out< sc_logic> ZN;

    SC_CTOR(OR3_X1){

        SC_METHOD(eval);
        sensitive << A1 << A2 << A3;

    }

    void eval(void){
        if ((A1->read() == SC_LOGIC_0) && (A2->read() == SC_LOGIC_0) && (A3->read() == SC_LOGIC_0)){
            ZN->write(SC_LOGIC_0);
        } else {
            ZN->write(SC_LOGIC_1);
        }
    };
};

SC_MODULE(OR3_X2){

    sc_in< sc_logic> A1; 
    sc_in< sc_logic> A2; 
    sc_in< sc_logic> A3; 
    sc_out< sc_logic> ZN;

    SC_CTOR(OR3_X2){

        SC_METHOD(eval);
        sensitive << A1 << A2 << A3;

    }

    void eval(void){
        if ((A1->read() == SC_LOGIC_0) && (A2->read() == SC_LOGIC_0) && (A3->read() == SC_LOGIC_0)){
            ZN->write(SC_LOGIC_0);
        } else {
            ZN->write(SC_LOGIC_1);
        }
    };
};

SC_MODULE(OR3_X4){

    sc_in< sc_logic> A1; 
    sc_in< sc_logic> A2; 
    sc_in< sc_logic> A3; 
    sc_out< sc_logic> ZN;

    SC_CTOR(OR3_X4){

        SC_METHOD(eval);
        sensitive << A1 << A2 << A3;

    }

    void eval(void){
        if ((A1->read() == SC_LOGIC_0) && (A2->read() == SC_LOGIC_0) && (A3->read() == SC_LOGIC_0)){
            ZN->write(SC_LOGIC_0);
        } else {
            ZN->write(SC_LOGIC_1);
        }
    };
};


SC_MODULE(OR4_X1){

    sc_in< sc_logic> A1; 
    sc_in< sc_logic> A2; 
    sc_in< sc_logic> A3; 
    sc_in< sc_logic> A4; 
    sc_out< sc_logic > ZN;

    SC_CTOR(OR4_X1){

        SC_METHOD(eval);
        sensitive << A1 << A2 << A3 << A4;

    }

    void eval(void){
        if ((A1->read() == SC_LOGIC_0) && (A2->read() == SC_LOGIC_0) && (A3->read() == SC_LOGIC_0) && (A4->read() == SC_LOGIC_0)){
            ZN->write(SC_LOGIC_0);
        } else {
            ZN->write(SC_LOGIC_1);
        }
    };
};


SC_MODULE(OR4_X2){

    sc_in< sc_logic> A1; 
    sc_in< sc_logic> A2; 
    sc_in< sc_logic> A3; 
    sc_in< sc_logic> A4; 
    sc_out< sc_logic > ZN;

    SC_CTOR(OR4_X2){

        SC_METHOD(eval);
        sensitive << A1 << A2 << A3 << A4;

    }

    void eval(void){
        if ((A1->read() == SC_LOGIC_0) && (A2->read() == SC_LOGIC_0) && (A3->read() == SC_LOGIC_0) && (A4->read() == SC_LOGIC_0)){
            ZN->write(SC_LOGIC_0);
        } else {
            ZN->write(SC_LOGIC_1);
        }
    };
};


SC_MODULE(OR4_X4){

    sc_in< sc_logic> A1; 
    sc_in< sc_logic> A2; 
    sc_in< sc_logic> A3; 
    sc_in< sc_logic> A4; 
    sc_out< sc_logic > ZN;

    SC_CTOR(OR4_X4){

        SC_METHOD(eval);
        sensitive << A1 << A2 << A3 << A4;

    }

    void eval(void){
        if ((A1->read() == SC_LOGIC_0) && (A2->read() == SC_LOGIC_0) && (A3->read() == SC_LOGIC_0) && (A4->read() == SC_LOGIC_0)){
            ZN->write(SC_LOGIC_0);
        } else {
            ZN->write(SC_LOGIC_1);
        }
    };
};

SC_MODULE(NOR2_X1){

    sc_in< sc_logic> A1; 
    sc_in< sc_logic> A2; 
    sc_out< sc_logic> ZN;

    SC_CTOR(NOR2_X1){

        SC_METHOD(eval);
        sensitive << A1 << A2;

    }

    void eval(void){
        if ((A1->read() == SC_LOGIC_0) && (A2->read() == SC_LOGIC_0)){
            ZN->write(SC_LOGIC_1);
        } else {
            ZN->write(SC_LOGIC_0);
        }
    };
};


SC_MODULE(NOR2_X2){

    sc_in< sc_logic> A1; 
    sc_in< sc_logic> A2; 
    sc_out< sc_logic> ZN;

    SC_CTOR(NOR2_X2){

        SC_METHOD(eval);
        sensitive << A1 << A2;

    }

    void eval(void){
        if ((A1->read() == SC_LOGIC_0) && (A2->read() == SC_LOGIC_0)){
            ZN->write(SC_LOGIC_1);
        } else {
            ZN->write(SC_LOGIC_0);
        }
    };
};


SC_MODULE(NOR2_X4){

    sc_in< sc_logic> A1; 
    sc_in< sc_logic> A2; 
    sc_out< sc_logic> ZN;

    SC_CTOR(NOR2_X4){

        SC_METHOD(eval);
        sensitive << A1 << A2;

    }

    void eval(void){
        if ((A1->read() == SC_LOGIC_0) && (A2->read() == SC_LOGIC_0)){
            ZN->write(SC_LOGIC_1);
        } else {
            ZN->write(SC_LOGIC_0);
        }
    };
};

SC_MODULE(NOR3_X1){

    sc_in< sc_logic> A1; 
    sc_in< sc_logic> A2; 
    sc_in< sc_logic> A3; 
    sc_out< sc_logic> ZN;

    SC_CTOR(NOR3_X1){

        SC_METHOD(eval);
        sensitive << A1 << A2 << A3;

    }

    void eval(void){
        if ((A1->read() == SC_LOGIC_0) && (A2->read() == SC_LOGIC_0) && (A3->read() == SC_LOGIC_0)){
            ZN->write(SC_LOGIC_1);
        } else {
            ZN->write(SC_LOGIC_0);
        }
    };
};

SC_MODULE(NOR3_X2){

    sc_in< sc_logic> A1; 
    sc_in< sc_logic> A2; 
    sc_in< sc_logic> A3; 
    sc_out< sc_logic> ZN;

    SC_CTOR(NOR3_X2){

        SC_METHOD(eval);
        sensitive << A1 << A2 << A3;

    }

    void eval(void){
        if ((A1->read() == SC_LOGIC_0) && (A2->read() == SC_LOGIC_0) && (A3->read() == SC_LOGIC_0)){
            ZN->write(SC_LOGIC_1);
        } else {
            ZN->write(SC_LOGIC_0);
        }
    };
};

SC_MODULE(NOR3_X4){

    sc_in< sc_logic> A1; 
    sc_in< sc_logic> A2; 
    sc_in< sc_logic> A3; 
    sc_out< sc_logic> ZN;

    SC_CTOR(NOR3_X4){

        SC_METHOD(eval);
        sensitive << A1 << A2 << A3;

    }

    void eval(void){
        if ((A1->read() == SC_LOGIC_0) && (A2->read() == SC_LOGIC_0) && (A3->read() == SC_LOGIC_0)){
            ZN->write(SC_LOGIC_1);
        } else {
            ZN->write(SC_LOGIC_0);
        }
    };
};


SC_MODULE(NOR4_X1){

    sc_in< sc_logic> A1; 
    sc_in< sc_logic> A2; 
    sc_in< sc_logic> A3; 
    sc_in< sc_logic> A4; 
    sc_out< sc_logic > ZN;

    SC_CTOR(NOR4_X1){

        SC_METHOD(eval);
        sensitive << A1 << A2 << A3 << A4;

    }

    void eval(void){
        if ((A1->read() == SC_LOGIC_0) && (A2->read() == SC_LOGIC_0) && (A3->read() == SC_LOGIC_0) && (A4->read() == SC_LOGIC_0)){
            ZN->write(SC_LOGIC_1);
        } else {
            ZN->write(SC_LOGIC_0);
        }
    };
};


SC_MODULE(NOR4_X2){

    sc_in< sc_logic> A1; 
    sc_in< sc_logic> A2; 
    sc_in< sc_logic> A3; 
    sc_in< sc_logic> A4; 
    sc_out< sc_logic > ZN;

    SC_CTOR(NOR4_X2){

        SC_METHOD(eval);
        sensitive << A1 << A2 << A3 << A4;

    }

    void eval(void){
        if ((A1->read() == SC_LOGIC_0) && (A2->read() == SC_LOGIC_0) && (A3->read() == SC_LOGIC_0) && (A4->read() == SC_LOGIC_0)){
            ZN->write(SC_LOGIC_1);
        } else {
            ZN->write(SC_LOGIC_0);
        }
    };
};


SC_MODULE(NOR4_X4){

    sc_in< sc_logic> A1; 
    sc_in< sc_logic> A2; 
    sc_in< sc_logic> A3; 
    sc_in< sc_logic> A4; 
    sc_out< sc_logic > ZN;

    SC_CTOR(NOR4_X4){

        SC_METHOD(eval);
        sensitive << A1 << A2 << A3 << A4;

    }

    void eval(void){
        if ((A1->read() == SC_LOGIC_0) && (A2->read() == SC_LOGIC_0) && (A3->read() == SC_LOGIC_0) && (A4->read() == SC_LOGIC_0)){
            ZN->write(SC_LOGIC_1);
        } else {
            ZN->write(SC_LOGIC_0);
        }
    };
};

/////////////////////////////////////////////////////////////////////////////////////
//    Xor
/////////////////////////////////////////////////////////////////////////////////////
SC_MODULE(XOR2_X1){

    sc_in< sc_logic> A; 
    sc_in< sc_logic> B; 
    sc_out< sc_logic> Z;

    SC_CTOR(XOR2_X1){

        SC_METHOD(eval);
        sensitive << A << B;

    }

    void eval(void){
        if (A->read() == B->read()){
            Z->write(SC_LOGIC_0);
        } else {
            Z->write(SC_LOGIC_1);
        }
    };
};

SC_MODULE(XOR2_X2){

    sc_in< sc_logic> A; 
    sc_in< sc_logic> B; 
    sc_out< sc_logic> Z;

    SC_CTOR(XOR2_X2){

        SC_METHOD(eval);
        sensitive << A << B;

    }

    void eval(void){
        if (A->read() == B->read()){
            Z->write(SC_LOGIC_0);
        } else {
            Z->write(SC_LOGIC_1);
        }
    };
};

SC_MODULE(XNOR2_X1){

    sc_in< sc_logic> A; 
    sc_in< sc_logic> B; 
    sc_out< sc_logic> ZN;

    SC_CTOR(XNOR2_X1){

        SC_METHOD(eval);
        sensitive << A << B;

    }

    void eval(void){
        if (A->read() == B->read()){
            ZN->write(SC_LOGIC_1);
        } else {
            ZN->write(SC_LOGIC_0);
        }
    };
};

SC_MODULE(XNOR2_X2){

    sc_in< sc_logic> A; 
    sc_in< sc_logic> B; 
    sc_out< sc_logic> ZN;

    SC_CTOR(XNOR2_X2){

        SC_METHOD(eval);
        sensitive << A << B;

    }

    void eval(void){
        if (A->read() == B->read()){
            ZN->write(SC_LOGIC_1);
        } else {
            ZN->write(SC_LOGIC_0);
        }
    };
};

SC_MODULE(INV_X1){

    sc_in< sc_logic > A; 
    sc_out< sc_logic > ZN;

    SC_CTOR(INV_X1){

        SC_METHOD(eval);
        sensitive << A;

    }

    void eval(void){
        if (A->read() == SC_LOGIC_1){
            ZN->write(SC_LOGIC_0);
        } else if (A->read() == SC_LOGIC_0){
            ZN->write(SC_LOGIC_1);
        }
    };
};


SC_MODULE(INV_X16){

    sc_in< sc_logic > A; 
    sc_out< sc_logic > ZN;

    SC_CTOR(INV_X16){

        SC_METHOD(eval);
        sensitive << A;

    }

    void eval(void){
        if (A->read() == SC_LOGIC_1){
            ZN->write(SC_LOGIC_0);
        } else if (A->read() == SC_LOGIC_0){
            ZN->write(SC_LOGIC_1);
        }
    };
};


SC_MODULE(INV_X2){

    sc_in< sc_logic > A; 
    sc_out< sc_logic > ZN;

    SC_CTOR(INV_X2){

        SC_METHOD(eval);
        sensitive << A;

    }

    void eval(void){
        if (A->read() == SC_LOGIC_1){
            ZN->write(SC_LOGIC_0);
        } else if (A->read() == SC_LOGIC_0){
            ZN->write(SC_LOGIC_1);
        }
    };
};


SC_MODULE(INV_X32){

    sc_in< sc_logic > A; 
    sc_out< sc_logic > ZN;

    SC_CTOR(INV_X32){

        SC_METHOD(eval);
        sensitive << A;

    }

    void eval(void){
        if (A->read() == SC_LOGIC_1){
            ZN->write(SC_LOGIC_0);
        } else if (A->read() == SC_LOGIC_0){
            ZN->write(SC_LOGIC_1);
        }
    };
};


SC_MODULE(INV_X4){

    sc_in< sc_logic > A; 
    sc_out< sc_logic > ZN;

    SC_CTOR(INV_X4){

        SC_METHOD(eval);
        sensitive << A;

    }

    void eval(void){
        if (A->read() == SC_LOGIC_1){
            ZN->write(SC_LOGIC_0);
        } else if (A->read() == SC_LOGIC_0){
            ZN->write(SC_LOGIC_1);
        }
    };
};


SC_MODULE(INV_X8){

    sc_in< sc_logic > A; 
    sc_out< sc_logic > ZN;

    SC_CTOR(INV_X8){

        SC_METHOD(eval);
        sensitive << A;

    }

    void eval(void){
        if (A->read() == SC_LOGIC_1){
            ZN->write(SC_LOGIC_0);
        } else if (A->read() == SC_LOGIC_0){
            ZN->write(SC_LOGIC_1);
        }
    };
};
