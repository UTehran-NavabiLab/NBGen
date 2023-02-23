module Datapath (
    input clk,
    input rst,
    input AND,
    input NOT,
    input ADD,
    input MUL,
    input sel1_ARU,
    input selIMM_LGU,
    input selMEM_LGU,
    input ldAC,
    input zeroAC,
    input selIMM_AC,
    input selMEM_AC,
    input selARU_AC,
    input selLGU_AC,
    input ldPC,
    input selINC_PC,
    input selMEM_PC,
    input selIMM_PC,
    input ldIN,
    input selINC_IN,
    input selMEM_IN,
    input conOF,
    input SE12bits,
    input SE4bits,
    input selLOP,
    input ldIR,
    input ldOF,
    input selPC_OF,
    input selIMM_OF,
    input selIN_ADR,
    input selPC_ADR,
    input selAC_MEM,
    input selIR_ADR,
    input seldataBus,
    input INC1,
    input INC2,
    input selSET_SR,
    input selLGU_SR,
    input selARU_SR,
    input selMO_ARU,
    input [1:0] SHF,
    input [3:0] ldSR,
    input [15:0] dataBusIn,
    input selIN_MEM,
    input selPC_MEM,

    output enSKP,
    output [15:0] addrBus,
    output [15:0] IRout,
    output [15:0] dataBusOut
);

    wire Z_LGU;
    wire Z_ARU;
    wire N_LGU;
    wire N_ARU;
    wire C_ARU;
    wire V_ARU;
    wire [1:0] PC_INC_val;
    wire [3:0] MUX4_OUT;
    wire [3:0] OFout;
    wire [3:0] toSR;
    wire [3:0] exp;
    wire [3:0] obs;
    wire [11:0] w;
    wire [15:0] ARU_OUT;
    wire [15:0] LGU_OUT;
    wire [15:0] data_bus;
    wire [15:0] IMM;
    wire [15:0] AC_OUT;
    wire [15:0] MO;
    wire [15:0] MUX1_OUT;
    wire [15:0] MUX3_OUT;
    wire [15:0] PC_OUT;
    wire [15:0] MUX5_OUT;
    wire [15:0] MUX6_OUT;
    wire [15:0] IN_OUT;
    wire [15:0] PC_INC_OUT;
    wire [15:0] DT_INC_OUT;
    wire [15:0] MUX7_OUT;

    LGU LGU (
        .in0(AC_OUT),
        .in1(MO),
        .out(LGU_OUT),
        .AND(AND),
        .NOT(NOT),
        .SHF(SHF),
        .Z(Z_LGU),
        .N(N_LGU)
    );

    ARU ARU (
        .ADD(ADD),
        .MUL(MUL),
        .in0(MUX1_OUT),
        .in1(AC_OUT),
        .Z(Z_ARU),
        .N(N_ARU),
        .C(C_ARU),
        .V(V_ARU),
        .res(ARU_OUT)
    );

    // MUXes
    mux2to1 #(16) mux1 (
        .sel0(sel1_ARU),
        .sel1(selMO_ARU),
        .in0(16'd1),
        .in1(MO),
        .out(MUX1_OUT)
    );

    mux2to1 #(16) mux2 (
        .sel0(selIMM_LGU),
        .sel1(selMEM_LGU),
        .in0(IMM),
        .in1(data_bus),
        .out(MO)
    );

    mux4to1 #(16) mux3 (
        .sel0(selIMM_AC),
        .sel1(selMEM_AC),
        .sel2(selARU_AC),
        .sel3(selLGU_AC),
        .in0(IMM),
        .in1(data_bus),
        .in2(ARU_OUT),
        .in3(LGU_OUT),
        .out(MUX3_OUT)
    );

    mux2to1 #(4) mux4 (
        .sel0(selPC_OF),
        .sel1(selIMM_OF),
        .in0(PC_OUT[15:12]),
        .in1(IMM[3:0]),
        .out(MUX4_OUT)
    );

    mux4to1 #(16) mux5 (
        .sel0(selINC_PC),
        .sel1(selMEM_PC),
        .sel2(selIMM_PC),
        .sel3(1'b0),
        .in0(PC_INC_OUT),
        .in1(data_bus),
        .in2(IMM),
        .in3(),
        .out(MUX5_OUT)
    );

    mux2to1 #(16) mux6 (
        .sel0(selINC_IN),
        .sel1(selMEM_IN),
        .in0(DT_INC_OUT),
        .in1(data_bus),
        .out(MUX6_OUT)
    );

    mux4to1 #(16) mux7 (
        .sel0(selIN_MEM),
        .sel1(selPC_MEM),
        .sel2(selAC_MEM),
        .sel3(1'b0),
        .in0(IN_OUT),
        .in1(PC_INC_OUT),
        .in2(AC_OUT),
        .in3(),
        .out(MUX7_OUT)
    );

    mux4to1 #(16) mux8 (
        .sel0(selIN_ADR),
        .sel1(selIR_ADR),
        .sel2(selPC_ADR),
        .sel3(1'b0),
        .in0(IN_OUT),
        .in1(IMM),
        .in2(PC_OUT),
        .in3(),
        .out(addrBus)
    );

    mux2to1 #(2) mux9 (
        .sel0(INC2),
        .sel1(INC1),
        .in0(2'd2),
        .in1(2'd1),
        .out(PC_INC_val)
    );

    mux4to1 #(4) mux10 (
        .in0(IRout[3:0]),
        .in1({Z_LGU, N_LGU, 2'bzz}),
        .in2({Z_ARU, N_ARU, C_ARU, V_ARU}),
        .in3(4'bz),
        .sel0(selSET_SR),
        .sel1(selLGU_SR),
        .sel2(selARU_SR),
        .sel3(1'bz),
        .out(toSR)
    );


    // Registers
    register #(4) OF (
        .clk(clk),
        .rst(rst),
        .ld(ldOF),
        .clr(1'b0),
        .in(MUX4_OUT),
        .out(OFout)
    );

    register #(1) SR_Z (
        .clk(clk),
        .rst(rst),
        .ld(ldSR[3]),
        .clr(1'b0),
        .in(toSR[3]),
        .out(w[3])
    );

    register #(1) SR_N (
        .clk(clk),
        .rst(rst),
        .ld(ldSR[2]),
        .clr(1'b0),
        .in(toSR[2]),
        .out(w[2])
    );

    register #(1) SR_C (
        .clk(clk),
        .rst(rst),
        .ld(ldSR[1]),
        .clr(1'b0),
        .in(toSR[1]),
        .out(w[1])
    );

    register #(1) SR_V (
        .clk(clk),
        .rst(rst),
        .ld(ldSR[0]),
        .clr(1'b0),
        .in(toSR[0]),
        .out(w[0])
    );

    register #(16) AC (
        .clk(clk),
        .rst(rst),
        .ld(ldAC),
        .clr(zeroAC),
        .in(MUX3_OUT),
        .out(AC_OUT)
    );

    register #(16) IR (
        .clk(clk),
        .rst(rst),
        .ld(ldIR),
        .clr(1'b0),
        .in(data_bus),
        .out(IRout)
    );

    register #(16) PC (
        .clk(clk),
        .rst(rst),
        .ld(ldPC),
        .clr(1'b0),
        .in(MUX5_OUT),
        .out(PC_OUT)
    );

    register #(16) IN (
        .clk(clk),
        .rst(rst),
        .ld(ldIN),
        .clr(1'b0),
        .in(MUX6_OUT),
        .out(IN_OUT)
    );


    // The Other Components
    IMM IMM1 (
        .conOF(conOF),
        .SE12bits(SE12bits),
        .SE4bits(SE4bits),
        .selLOP(selLOP),
        .inIR(IRout[11:0]),
        .inOF(OFout),
        .Imm(IMM)
    );

    INC PC_INC (
        .in(PC_OUT),
        .inc_val(PC_INC_val),
        .out(PC_INC_OUT)
    );

    INC DATA_INC (
        .in(data_bus),
        .inc_val(2'b01),
        .out(DT_INC_OUT)
    );

    /*Tristate TriBuff (
        .oe(seldataBus),
        .in(MUX7_OUT),
        .out(dataBusOut)
    );*/
    assign dataBusOut = MUX7_OUT;

    // Flags
    assign exp = IRout[3:0];

    assign w[4] = w[0] ~^ exp[0];
    assign w[5] = w[1] ~^ exp[1];
    assign w[6] = w[2] ~^ exp[2];
    assign w[7] = w[3] ~^ exp[3];

    assign obs = IRout[7:4];

    assign w[8]  = w[4] & obs[0];
    assign w[9]  = w[5] & obs[1];
    assign w[10] = w[6] & obs[2];
    assign w[11] = w[7] & obs[3];

    assign enSKP = w[8] | w[9] | w[10] | w[11];

    assign data_bus = dataBusIn;

endmodule