module Controller (
    input clk,
    input rst,
    input enSKP,
    input [15:0] inst,

    output reg ldIR,
    output reg ldOF,
    output reg ldPC,
    output reg ldIN,
    output reg ldAC,
    output reg zeroAC,
    output reg seldataBus,
    output reg selPC_OF,
    output reg selIMM_OF,
    output reg selINC_IN,
    output reg selMEM_IN,
    output reg selIMM_LGU,
    output reg selMEM_LGU,
    output reg sel1_ARU,
    output reg selMO_ARU,
    output reg selINC_PC,
    output reg selMEM_PC,
    output reg selIMM_PC,
    output reg selIN_ADR,
    output reg selIR_ADR,
    output reg selPC_ADR,
    output reg selAC_MEM,
    output reg selIMM_AC,
    output reg selMEM_AC,
    output reg selARU_AC,
    output reg selLGU_AC,
    output reg conOF,
    output reg SE12bits,
    output reg SE4bits,
    output reg AND,
    output reg NOT,
    output reg ADD,
    output reg MUL,
    output reg readMEM,
    output reg writeMEM,
    output reg selSET_SR,
    output reg INC1,
    output reg INC2,
    output reg selARU_SR,
    output reg selLGU_SR,
    output reg selIN_MEM,
    output reg selPC_MEM,
    output reg selLOP,
    output reg [1:0] SHF,
    output reg [3:0] ldSR
);

    reg [1:0] pstate;
    reg [1:0] nstate;

    parameter [3:0] LDm = 4'b0000;
    parameter [3:0] LDa = 4'b0001;
    parameter [3:0] LDn = 4'b0010;
    parameter [3:0] STa = 4'b0011;
    parameter [3:0] STn = 4'b0100;
    parameter [3:0] INa = 4'b0101;
    parameter [3:0] ANm = 4'b0110;
    parameter [3:0] ANa = 4'b0111;
    parameter [3:0] ADm = 4'b1000;
    parameter [3:0] ADa = 4'b1001;
    parameter [3:0] ADn = 4'b1010;
    parameter [3:0] MLa = 4'b1011;
    parameter [3:0] JMa = 4'b1100;
    parameter [3:0] JMn = 4'b1101;
    parameter [3:0] JSR = 4'b1110;
    parameter [3:0] INST15 = 4'b1111;
    parameter [3:0] LOm = 4'b0000;
    parameter [3:0] TYPE1 = 4'b0001;
    parameter [3:0] SRA = 4'b0010;
    parameter [3:0] SLL = 4'b0011;
    parameter [3:0] SRL = 4'b0100;
    parameter [3:0] SKP = 4'b1001;
    parameter [3:0] SET = 4'b0110;
    parameter [2:0] LPO = 3'b000;
    parameter [2:0] LOP = 3'b001;
    parameter [2:0] ACZ = 3'b010;
    parameter [2:0] ACN = 3'b011;
    parameter [2:0] ACI = 3'b100;

    parameter [1:0] fetch = 2'b00;
    parameter [1:0] exec1 = 2'b01;
    parameter [1:0] exec2 = 2'b10;

    always @(posedge clk, posedge rst)
        if (rst)
            pstate <= fetch;
        else
            pstate <= nstate;

    always @(pstate, inst) begin

        {ldSR, ldIR, ldOF, ldPC, ldIN, ldAC, zeroAC, seldataBus, selPC_OF, selIMM_OF, selINC_IN, selIN_ADR, selIR_ADR, selPC_ADR,
        selMEM_IN, selIMM_LGU, selMEM_LGU, sel1_ARU, selMO_ARU, selINC_PC, selMEM_PC, selIMM_PC, selIN_MEM, selPC_MEM, selAC_MEM, selIMM_AC,
        selMEM_AC, selARU_AC, selLGU_AC, conOF, SE12bits, SE4bits, selLOP, AND, NOT, SHF, ADD, MUL, readMEM, writeMEM, INC1, INC2, selSET_SR,
        selARU_SR, selLGU_SR} = 49'b0;

        case (pstate)
            fetch : begin
                {selPC_ADR, ldIR, readMEM} = 3'b111;
            end
            exec1 : begin
                case (inst[15:12])
                    LDm : begin
                        {SE4bits, selIMM_AC, ldAC, INC1, selINC_PC, ldPC} = 6'b111111;
                    end
                    LDa : begin
                        {selMEM_AC, ldAC, readMEM, selIR_ADR, conOF, INC1, selINC_PC, ldPC} = 8'b11111111;
                    end
                    LDn : begin
                        {selMEM_IN, ldIN, readMEM, selIR_ADR, conOF} = 5'b11111;
                    end
                    STa : begin
                        {selIR_ADR, conOF, selAC_MEM, writeMEM, seldataBus, INC1, selINC_PC, ldPC} = 8'b11111111;
                    end
                    STn : begin
                        {selIR_ADR, conOF, selMEM_IN, readMEM, ldIN} = 5'b11111;
                    end
                    INa : begin
                        {selIR_ADR, conOF, selINC_IN, readMEM, ldIN} = 5'b11111;
                    end
                    ANm : begin
                        {SE4bits, selIMM_LGU, selLGU_AC, AND, ldAC, selLGU_SR, ldSR, INC1, selINC_PC, ldPC} = 13'b1111111100111;
                    end
                    ANa : begin
                        {selIR_ADR, conOF, selMEM_LGU, readMEM, ldAC, selLGU_AC, AND, ldSR, INC1, selINC_PC, ldPC, selLGU_SR} = 15'b111111111001111;
                    end
                    ADm : begin
                        {SE4bits, selIMM_LGU, selARU_AC, ADD, selMO_ARU, ldAC, ldSR, selARU_SR, INC1, selINC_PC, ldPC} = 14'b11111111111111;
                    end
                    ADa : begin
                        {conOF, selIR_ADR, selMEM_LGU, readMEM, selMO_ARU, ADD, selARU_AC, ldAC, selARU_SR, ldSR, INC1, selINC_PC, ldPC} = 16'b1111111111111111;
                    end
                    ADn : begin
                        {conOF, selIR_ADR, selMEM_IN, readMEM, ldIN} = 5'b11111;
                    end
                    MLa : begin
                        {conOF, selIR_ADR, readMEM, selMEM_LGU, ldAC, selMO_ARU, selARU_AC, MUL, ldSR, selARU_SR, INC1, selINC_PC, ldPC} = 16'b1111111111000111;
                    end
                    JMa : begin
                        {conOF, selIMM_PC, ldPC} = 3'b111;
                    end
                    JMn : begin
                        {conOF, selIR_ADR, readMEM, selMEM_PC, ldPC} = 5'b11111;
                    end
                    JSR : begin
                        {conOF, selIR_ADR, selIMM_PC, writeMEM, seldataBus, INC1, selPC_MEM, ldPC} = 8'b11111111;
                    end
                    INST15 : begin
                        case (inst[11:8])
                            LOm : begin
                                {SE12bits, selIMM_OF, ldOF, INC1, selINC_PC, ldPC} = 6'b111111;
                            end
                            TYPE1 : begin
                                case (inst[7:5])
                                    LPO : begin
                                        {ldOF, selPC_OF, INC1, selINC_PC, ldPC} = 5'b11111;
                                    end
                                    LOP : begin
                                        {ldPC, selIMM_PC, selLOP} = 3'b111;
                                    end
                                    ACZ : begin
                                        {zeroAC, ldSR, INC1, selINC_PC, ldPC, selLGU_SR} = 9'b111001111;
                                    end
                                    ACN : begin
                                        {ldAC, NOT, selLGU_AC, ldSR, selLGU_SR, INC1, selINC_PC, ldPC} = 11'b11111001111;
                                    end
                                    ACI : begin
                                        {ldAC, selARU_AC, sel1_ARU, INC1, selINC_PC, ldPC, ADD} = 7'b1111111;
                                    end
                                    default : begin
                                        {INC1, selINC_PC, ldPC} = 3'b111;
                                    end
                                endcase
                            end
                            SRA : begin
                                {SE12bits, selIMM_LGU, ldAC, selLGU_AC, SHF, INC1, selINC_PC, ldPC} = 9'b111100111;
                            end
                            SLL : begin
                                {SE12bits, selIMM_LGU, ldAC, selLGU_AC, SHF, INC1, selINC_PC, ldPC} = 9'b111110111;
                            end
                            SRL : begin
                                {SE12bits, selIMM_LGU, ldAC, selLGU_AC, SHF, INC1, selINC_PC, ldPC} = 9'b111101111;
                            end
                            SKP : begin
                                if (enSKP == 1) begin
                                    INC2 = 1'b1;
                                end
                                else begin
                                    {INC1, selINC_PC, ldPC} = 3'b111;
                                end
                            end
                            SET : begin
                                {selSET_SR, ldSR, INC1, selINC_PC, ldPC} = {1'b1, inst[7:4], 3'b111};
                            end
                            default : begin
                                {INC1, selINC_PC, ldPC} = 3'b111;
                            end
                        endcase
                    end
                    default : begin
                        {INC1, selINC_PC, ldPC} = 3'b111;
                    end
                endcase
            end
            exec2 : begin
                case (inst[15:12])
                    LDn : begin
                        {selIN_ADR, readMEM, selMEM_AC, ldAC, INC1, selINC_PC, ldPC} = 7'b1111111;
                    end
                    STn : begin
                        {selIN_ADR, writeMEM, selAC_MEM, seldataBus, selINC_PC, ldPC, INC1} = 7'b1111111;
                    end
                    INa : begin
                        {selIN_MEM, writeMEM, selIR_ADR, seldataBus, conOF, INC1, selINC_PC, ldPC} = 8'b11111111;
                    end
                    ADn : begin
                        {selIN_ADR, readMEM, selMEM_LGU, selMO_ARU, selARU_AC, ldAC, ADD, ldSR, INC1, selINC_PC, ldPC, selARU_SR} = 15'b111111111111111;
                    end
                    JSR : begin
                        {selINC_PC, INC1, ldPC} = 3'b111;
                    end
                    default : begin
                        {selINC_PC, INC1, ldPC} = 3'b111;
                    end
                endcase
            end
        endcase
    end

    always @(pstate, inst) begin
        case (pstate)
            fetch :
                if (rst == 1)
                    nstate = fetch;
                else
                    nstate = exec1;
            exec1 : begin
                case (inst[15:12])
                    LDm :
                        nstate = fetch;
                    LDa :
                    	nstate = fetch;
                    LDn :
                      nstate = exec2;
                    STa :
                        nstate = fetch;
                    STn :
                        nstate = exec2;
                    INa :
                        nstate = exec2;
                    ANm :
                        nstate = fetch;
                    ANa :
                        nstate = fetch;
                    ADm :
                        nstate = fetch;
                    ADa :
                        nstate = fetch;
                    ADn :
                        nstate = exec2;
                    MLa :
                        nstate = fetch;
                    JMa :
                        nstate = fetch;
                    JMn :
                        nstate = fetch;
                    JSR :
                        nstate = exec2;
                    INST15 :
                        nstate = fetch;
                    default :
                        nstate = fetch;
            	endcase
            end
            exec2 : begin
            	nstate = fetch ;
            end
            default : begin
                nstate = fetch;
            end
		endcase
	end

endmodule