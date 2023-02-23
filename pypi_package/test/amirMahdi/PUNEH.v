module PUNEH (
    input clk,
    input rst,
    input [15:0] dataBusIn,

    output writeMEM,
    output readMEM,
    output [15:0] addrBus,
    output [15:0] dataBusOut
);

    wire enSKP;
    wire ldIR;
    wire ldOF;
    wire ldPC;
    wire ldIN;
    wire ldAC;
    wire zeroAC;
    wire seldataBus;
    wire selPC_OF;
    wire selIMM_OF;
    wire selMEM_IN;
    wire selIMM_LGU;
    wire selMEM_LGU;
    wire sel1_ARU;
    wire selMO_ARU;
    wire selINC_PC;
    wire selMEM_PC;
    wire selIMM_PC;
    wire selIN_ADR;
    wire selIR_ADR;
    wire selPC_ADR;
    wire selAC_MEM;
    wire selIMM_AC;
    wire selMEM_AC;
    wire selARU_AC;
    wire selLGU_AC;
    wire conOF;
    wire SE12bits;
    wire SE4bits;
    wire selLOP;
    wire AND;
    wire NOT;
    wire ADD;
    wire MUL;
    wire elSET_SR;
    wire selINC_IN;
    wire INC1;
    wire INC2;
    wire selARU_SR;
    wire selLGU_SR;
    wire selIN_MEM;
    wire selPC_MEM;

    wire [1:0] SHF;
    wire [3:0] ldSR;
    wire [15:0] inst;


    Datapath DP (
        .clk(clk),
        .rst(rst),
        .AND(AND),
        .NOT(NOT),
        .ADD(ADD),
        .MUL(MUL),
        .sel1_ARU(sel1_ARU),
        .selIMM_LGU(selIMM_LGU),
        .selMEM_LGU(selMEM_LGU),
        .ldAC(ldAC),
        .zeroAC(zeroAC),
        .selIMM_AC(selIMM_AC),
        .selMEM_AC(selMEM_AC),
        .selARU_AC(selARU_AC),
        .selLGU_AC(selLGU_AC),
        .ldPC(ldPC),
        .selINC_PC(selINC_PC),
        .selMEM_PC(selMEM_PCselMEM_PC),
        .selIMM_PC(selIMM_PC),
        .ldIN(ldIN),
        .selINC_IN(selINC_IN),
        .selMEM_IN(selMEM_IN),
        .conOF(conOF),
        .SE12bits(SE12bits),
        .SE4bits(SE4bits),
        .selLOP(selLOP),
        .ldIR(ldIR),
        .ldOF(ldOF),
        .selPC_OF(selPC_OF),
        .selIMM_OF(selIMM_OF),
        .selIN_ADR(selIN_ADR),
        .selPC_ADR(selPC_ADR),
        .selAC_MEM(selAC_MEM),
        .selIR_ADR(selIR_ADR),
        .seldataBus(seldataBus),
        .INC1(INC1),
        .INC2(INC2),
        .selSET_SR(selSET_SR),
        .selLGU_SR(selLGU_SR),
        .selARU_SR(selARU_SR),
        .selMO_ARU(selMO_ARU),
        .SHF(SHF),
        .ldSR(ldSR),
        .dataBusIn(dataBusIn),
        .selIN_MEM(selIN_MEM),
        .selPC_MEM(selPC_MEM),

        .enSKP(enSKP),
        .addrBus(addrBus),
        .IRout(inst),
        .dataBusOut(dataBusOut)
    );

    Controller CU (
        .clk(clk),
        .rst(rst),
        .enSKP(enSKP),
        .inst(inst),

        .ldIR(ldIR),
        .ldOF(ldOF),
        .ldPC(ldPC),
        .ldIN(ldIN),
        .ldAC(ldAC),
        .zeroAC(zeroAC),
        .seldataBus(seldataBus),
        .selPC_OF(selPC_OF),
        .selIMM_OF(selIMM_OF),
        .selMEM_IN(selMEM_IN),
        .selIMM_LGU(selIMM_LGU),
        .selMEM_LGU(selMEM_LGU),
        .sel1_ARU(sel1_ARU),
        .selMO_ARU(selMO_ARU),
        .selINC_PC(selINC_PC),
        .selMEM_PC(selMEM_PC),
        .selIMM_PC(selIMM_PC),
        .selIN_ADR(selIN_ADR),
        .selIR_ADR(selIR_ADR),
        .selPC_ADR(selPC_ADR),
        .selAC_MEM(selAC_MEM),
        .selIMM_AC(selIMM_AC),
        .selMEM_AC(selMEM_AC),
        .selARU_AC(selARU_AC),
        .selLGU_AC(selLGU_AC),
        .conOF(conOF),
        .SE12bits(SE12bits),
        .SE4bits(SE4bits),
        .selLOP(selLOP),
        .AND(AND),
        .NOT(NOT),
        .ADD(ADD),
        .MUL(MUL),
        .readMEM(readMEM),
        .writeMEM(writeMEM),
        .selSET_SR(selSET_SR),
        .selINC_IN(selINC_IN),
        .INC1(INC1),
        .INC2(INC2),
        .selARU_SR(selARU_SR),
        .selLGU_SR(selLGU_SR),
        .selIN_MEM(selIN_MEM),
        .selPC_MEM(selPC_MEM),
        .SHF(SHF),
        .ldSR(ldSR)
    );

endmodule