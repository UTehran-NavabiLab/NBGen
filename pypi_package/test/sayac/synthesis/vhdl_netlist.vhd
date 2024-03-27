LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY LGC IS
    PORT (
        clk : IN STD_LOGIC;
        rst : IN STD_LOGIC;
        readyMEM : IN STD_LOGIC;
        dataBusIn : IN STD_LOGIC_VECTOR (15 DOWNTO 0);
        p1TRF : IN STD_LOGIC_VECTOR (15 DOWNTO 0);
        p2TRF : IN STD_LOGIC_VECTOR (15 DOWNTO 0);
        readMM : OUT STD_LOGIC;
        writeMM : OUT STD_LOGIC;
        dataBusOut : OUT STD_LOGIC_VECTOR (15 DOWNTO 0);
        addrBus : OUT STD_LOGIC_VECTOR (15 DOWNTO 0);
        outMuxrs1 : OUT STD_LOGIC_VECTOR (3 DOWNTO 0);
        outMuxrs2 : OUT STD_LOGIC_VECTOR (3 DOWNTO 0);
        outMuxrd : OUT STD_LOGIC_VECTOR (3 DOWNTO 0);
        inDataTRF : OUT STD_LOGIC_VECTOR (15 DOWNTO 0);
        writeTRF : OUT STD_LOGIC;
        readInst : OUT STD_LOGIC);
END ENTITY LGC;

ARCHITECTURE arch OF LGC IS
    SIGNAL S0 : STD_LOGIC;
    SIGNAL S1 : STD_LOGIC;
    SIGNAL S2 : STD_LOGIC;
    SIGNAL S3 : STD_LOGIC;
    SIGNAL S4 : STD_LOGIC;
    SIGNAL S5 : STD_LOGIC;
    SIGNAL S6 : STD_LOGIC;
    SIGNAL S7 : STD_LOGIC;
    SIGNAL S8 : STD_LOGIC;
    SIGNAL S9 : STD_LOGIC;
    SIGNAL S10 : STD_LOGIC;
    SIGNAL S11 : STD_LOGIC;
    SIGNAL S12 : STD_LOGIC;
    SIGNAL S13 : STD_LOGIC;
    SIGNAL S14 : STD_LOGIC;
    SIGNAL S15 : STD_LOGIC;
    SIGNAL S16 : STD_LOGIC;
    SIGNAL S17 : STD_LOGIC;
    SIGNAL S18 : STD_LOGIC;
    SIGNAL S19 : STD_LOGIC;
    SIGNAL arithadd : STD_LOGIC;
    SIGNAL arithdiv : STD_LOGIC;
    SIGNAL arithmul : STD_LOGIC;
    SIGNAL arithsh : STD_LOGIC;
    SIGNAL arithsub : STD_LOGIC;
    SIGNAL drivedatabus : STD_LOGIC;
    SIGNAL enflag : STD_LOGIC;
    SIGNAL fib_0 : STD_LOGIC;
    SIGNAL fib_1 : STD_LOGIC;
    SIGNAL fib_2 : STD_LOGIC;
    SIGNAL fib_3 : STD_LOGIC;
    SIGNAL fib_4 : STD_LOGIC;
    SIGNAL ldadr : STD_LOGIC;
    SIGNAL ldir : STD_LOGIC;
    SIGNAL ldmdu1 : STD_LOGIC;
    SIGNAL ldmdu2 : STD_LOGIC;
    SIGNAL ldpc : STD_LOGIC;
    SIGNAL logicand : STD_LOGIC;
    SIGNAL logicsh : STD_LOGIC;
    SIGNAL onescomp : STD_LOGIC;
    SIGNAL opcode_0 : STD_LOGIC;
    SIGNAL opcode_1 : STD_LOGIC;
    SIGNAL opcode_2 : STD_LOGIC;
    SIGNAL opcode_3 : STD_LOGIC;
    SIGNAL opcode_4 : STD_LOGIC;
    SIGNAL opcode_5 : STD_LOGIC;
    SIGNAL opcode_6 : STD_LOGIC;
    SIGNAL opcode_7 : STD_LOGIC;
    SIGNAL outflag_0 : STD_LOGIC;
    SIGNAL outflag_1 : STD_LOGIC;
    SIGNAL outflag_2 : STD_LOGIC;
    SIGNAL outflag_3 : STD_LOGIC;
    SIGNAL outflag_4 : STD_LOGIC;
    SIGNAL outflag_5 : STD_LOGIC;
    SIGNAL outflag_6 : STD_LOGIC;
    SIGNAL outflag_7 : STD_LOGIC;
    SIGNAL p1lowbits : STD_LOGIC;
    SIGNAL readio : STD_LOGIC;
    SIGNAL readmem : STD_LOGIC;
    SIGNAL readymdu : STD_LOGIC;
    SIGNAL se5bits : STD_LOGIC;
    SIGNAL se6bits : STD_LOGIC;
    SIGNAL se8bits : STD_LOGIC;
    SIGNAL seladr_mem : STD_LOGIC;
    SIGNAL selasu_trf : STD_LOGIC;
    SIGNAL seldatabus_trf : STD_LOGIC;
    SIGNAL selflag_0 : STD_LOGIC;
    SIGNAL selflag_1 : STD_LOGIC;
    SIGNAL selflag_2 : STD_LOGIC;
    SIGNAL selflag_3 : STD_LOGIC;
    SIGNAL selflag_4 : STD_LOGIC;
    SIGNAL selflag_5 : STD_LOGIC;
    SIGNAL selflag_6 : STD_LOGIC;
    SIGNAL selflag_7 : STD_LOGIC;
    SIGNAL selimm_asu : STD_LOGIC;
    SIGNAL selimm_pcp : STD_LOGIC;
    SIGNAL selimm_trf : STD_LOGIC;
    SIGNAL selllu_trf : STD_LOGIC;
    SIGNAL selmdu1_trf : STD_LOGIC;
    SIGNAL selmdu2_trf : STD_LOGIC;
    SIGNAL selp1_pc : STD_LOGIC;
    SIGNAL selp1_pcp : STD_LOGIC;
    SIGNAL selp2_asu : STD_LOGIC;
    SIGNAL selp2_shu : STD_LOGIC;
    SIGNAL selpc1_pc : STD_LOGIC;
    SIGNAL selpc1_trf : STD_LOGIC;
    SIGNAL selpcadd_pc : STD_LOGIC;
    SIGNAL selrd0_trf : STD_LOGIC;
    SIGNAL selrd1_trf : STD_LOGIC;
    SIGNAL selrd_1_trf : STD_LOGIC;
    SIGNAL selrd_2_trf : STD_LOGIC;
    SIGNAL selrs1_trf : STD_LOGIC;
    SIGNAL selrs2_trf : STD_LOGIC;
    SIGNAL selshim_shu : STD_LOGIC;
    SIGNAL selshu_trf : STD_LOGIC;
    SIGNAL setflags : STD_LOGIC;
    SIGNAL startmdu : STD_LOGIC;
    SIGNAL twoscomp : STD_LOGIC;
    SIGNAL use8bits : STD_LOGIC;
    SIGNAL writeio : STD_LOGIC;
    SIGNAL writemem : STD_LOGIC;

BEGIN
INV_X1_1: ENTITY WORK.INV_X1
    PORT MAP (
        A => readio,
        ZN => S2
    );
INV_X1_2: ENTITY WORK.INV_X1
    PORT MAP (
        A => readmem,
        ZN => S3
    );
NAND2_X1_1: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S2,
        A2 => S3,
        ZN => S15
    );
INV_X1_3: ENTITY WORK.INV_X1
    PORT MAP (
        A => writeio,
        ZN => S0
    );
INV_X1_4: ENTITY WORK.INV_X1
    PORT MAP (
        A => writemem,
        ZN => S1
    );
NAND2_X1_2: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S0,
        A2 => S1,
        ZN => S18
    );
BUF_X1_1: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S4(0),
        Z => addrBus(0)
    );
BUF_X1_2: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S4(1),
        Z => addrBus(1)
    );
BUF_X1_3: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S4(10),
        Z => addrBus(10)
    );
BUF_X1_4: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S4(11),
        Z => addrBus(11)
    );
BUF_X1_5: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S4(12),
        Z => addrBus(12)
    );
BUF_X1_6: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S4(13),
        Z => addrBus(13)
    );
BUF_X1_7: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S4(14),
        Z => addrBus(14)
    );
BUF_X1_8: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S4(15),
        Z => addrBus(15)
    );
BUF_X1_9: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S4(2),
        Z => addrBus(2)
    );
BUF_X1_10: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S4(3),
        Z => addrBus(3)
    );
BUF_X1_11: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S4(4),
        Z => addrBus(4)
    );
BUF_X1_12: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S4(5),
        Z => addrBus(5)
    );
BUF_X1_13: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S4(6),
        Z => addrBus(6)
    );
BUF_X1_14: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S4(7),
        Z => addrBus(7)
    );
BUF_X1_15: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S4(8),
        Z => addrBus(8)
    );
BUF_X1_16: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S4(9),
        Z => addrBus(9)
    );
BUF_X1_17: ENTITY WORK.BUF_X1
    PORT MAP (
        A => clk,
        Z => S5
    );
BUF_X1_18: ENTITY WORK.BUF_X1
    PORT MAP (
        A => dataBusIn(0),
        Z => S6(0)
    );
BUF_X1_19: ENTITY WORK.BUF_X1
    PORT MAP (
        A => dataBusIn(1),
        Z => S6(1)
    );
BUF_X1_20: ENTITY WORK.BUF_X1
    PORT MAP (
        A => dataBusIn(10),
        Z => S6(10)
    );
BUF_X1_21: ENTITY WORK.BUF_X1
    PORT MAP (
        A => dataBusIn(11),
        Z => S6(11)
    );
BUF_X1_22: ENTITY WORK.BUF_X1
    PORT MAP (
        A => dataBusIn(12),
        Z => S6(12)
    );
BUF_X1_23: ENTITY WORK.BUF_X1
    PORT MAP (
        A => dataBusIn(13),
        Z => S6(13)
    );
BUF_X1_24: ENTITY WORK.BUF_X1
    PORT MAP (
        A => dataBusIn(14),
        Z => S6(14)
    );
BUF_X1_25: ENTITY WORK.BUF_X1
    PORT MAP (
        A => dataBusIn(15),
        Z => S6(15)
    );
BUF_X1_26: ENTITY WORK.BUF_X1
    PORT MAP (
        A => dataBusIn(2),
        Z => S6(2)
    );
BUF_X1_27: ENTITY WORK.BUF_X1
    PORT MAP (
        A => dataBusIn(3),
        Z => S6(3)
    );
BUF_X1_28: ENTITY WORK.BUF_X1
    PORT MAP (
        A => dataBusIn(4),
        Z => S6(4)
    );
BUF_X1_29: ENTITY WORK.BUF_X1
    PORT MAP (
        A => dataBusIn(5),
        Z => S6(5)
    );
BUF_X1_30: ENTITY WORK.BUF_X1
    PORT MAP (
        A => dataBusIn(6),
        Z => S6(6)
    );
BUF_X1_31: ENTITY WORK.BUF_X1
    PORT MAP (
        A => dataBusIn(7),
        Z => S6(7)
    );
BUF_X1_32: ENTITY WORK.BUF_X1
    PORT MAP (
        A => dataBusIn(8),
        Z => S6(8)
    );
BUF_X1_33: ENTITY WORK.BUF_X1
    PORT MAP (
        A => dataBusIn(9),
        Z => S6(9)
    );
BUF_X1_34: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S7(0),
        Z => dataBusOut(0)
    );
BUF_X1_35: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S7(1),
        Z => dataBusOut(1)
    );
BUF_X1_36: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S7(2),
        Z => dataBusOut(2)
    );
BUF_X1_37: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S7(3),
        Z => dataBusOut(3)
    );
BUF_X1_38: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S7(4),
        Z => dataBusOut(4)
    );
BUF_X1_39: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S7(5),
        Z => dataBusOut(5)
    );
BUF_X1_40: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S7(6),
        Z => dataBusOut(6)
    );
BUF_X1_41: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S7(7),
        Z => dataBusOut(7)
    );
BUF_X1_42: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S8(0),
        Z => inDataTRF(0)
    );
BUF_X1_43: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S8(1),
        Z => inDataTRF(1)
    );
BUF_X1_44: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S8(10),
        Z => inDataTRF(10)
    );
BUF_X1_45: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S8(11),
        Z => inDataTRF(11)
    );
BUF_X1_46: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S8(12),
        Z => inDataTRF(12)
    );
BUF_X1_47: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S8(13),
        Z => inDataTRF(13)
    );
BUF_X1_48: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S8(14),
        Z => inDataTRF(14)
    );
BUF_X1_49: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S8(15),
        Z => inDataTRF(15)
    );
BUF_X1_50: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S8(2),
        Z => inDataTRF(2)
    );
BUF_X1_51: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S8(3),
        Z => inDataTRF(3)
    );
BUF_X1_52: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S8(4),
        Z => inDataTRF(4)
    );
BUF_X1_53: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S8(5),
        Z => inDataTRF(5)
    );
BUF_X1_54: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S8(6),
        Z => inDataTRF(6)
    );
BUF_X1_55: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S8(7),
        Z => inDataTRF(7)
    );
BUF_X1_56: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S8(8),
        Z => inDataTRF(8)
    );
BUF_X1_57: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S8(9),
        Z => inDataTRF(9)
    );
BUF_X1_58: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S9(0),
        Z => outMuxrd(0)
    );
BUF_X1_59: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S9(1),
        Z => outMuxrd(1)
    );
BUF_X1_60: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S9(2),
        Z => outMuxrd(2)
    );
BUF_X1_61: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S9(3),
        Z => outMuxrd(3)
    );
BUF_X1_62: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S10(0),
        Z => outMuxrs1(0)
    );
BUF_X1_63: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S10(1),
        Z => outMuxrs1(1)
    );
BUF_X1_64: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S10(2),
        Z => outMuxrs1(2)
    );
BUF_X1_65: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S10(3),
        Z => outMuxrs1(3)
    );
BUF_X1_66: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S11(0),
        Z => outMuxrs2(0)
    );
BUF_X1_67: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S11(1),
        Z => outMuxrs2(1)
    );
BUF_X1_68: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S11(2),
        Z => outMuxrs2(2)
    );
BUF_X1_69: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S11(3),
        Z => outMuxrs2(3)
    );
BUF_X1_70: ENTITY WORK.BUF_X1
    PORT MAP (
        A => p1TRF(0),
        Z => S12(0)
    );
BUF_X1_71: ENTITY WORK.BUF_X1
    PORT MAP (
        A => p1TRF(1),
        Z => S12(1)
    );
BUF_X1_72: ENTITY WORK.BUF_X1
    PORT MAP (
        A => p1TRF(10),
        Z => S12(10)
    );
BUF_X1_73: ENTITY WORK.BUF_X1
    PORT MAP (
        A => p1TRF(11),
        Z => S12(11)
    );
BUF_X1_74: ENTITY WORK.BUF_X1
    PORT MAP (
        A => p1TRF(12),
        Z => S12(12)
    );
BUF_X1_75: ENTITY WORK.BUF_X1
    PORT MAP (
        A => p1TRF(13),
        Z => S12(13)
    );
BUF_X1_76: ENTITY WORK.BUF_X1
    PORT MAP (
        A => p1TRF(14),
        Z => S12(14)
    );
BUF_X1_77: ENTITY WORK.BUF_X1
    PORT MAP (
        A => p1TRF(15),
        Z => S12(15)
    );
BUF_X1_78: ENTITY WORK.BUF_X1
    PORT MAP (
        A => p1TRF(2),
        Z => S12(2)
    );
BUF_X1_79: ENTITY WORK.BUF_X1
    PORT MAP (
        A => p1TRF(3),
        Z => S12(3)
    );
BUF_X1_80: ENTITY WORK.BUF_X1
    PORT MAP (
        A => p1TRF(4),
        Z => S12(4)
    );
BUF_X1_81: ENTITY WORK.BUF_X1
    PORT MAP (
        A => p1TRF(5),
        Z => S12(5)
    );
BUF_X1_82: ENTITY WORK.BUF_X1
    PORT MAP (
        A => p1TRF(6),
        Z => S12(6)
    );
BUF_X1_83: ENTITY WORK.BUF_X1
    PORT MAP (
        A => p1TRF(7),
        Z => S12(7)
    );
BUF_X1_84: ENTITY WORK.BUF_X1
    PORT MAP (
        A => p1TRF(8),
        Z => S12(8)
    );
BUF_X1_85: ENTITY WORK.BUF_X1
    PORT MAP (
        A => p1TRF(9),
        Z => S12(9)
    );
BUF_X1_86: ENTITY WORK.BUF_X1
    PORT MAP (
        A => p2TRF(0),
        Z => S13(0)
    );
BUF_X1_87: ENTITY WORK.BUF_X1
    PORT MAP (
        A => p2TRF(1),
        Z => S13(1)
    );
BUF_X1_88: ENTITY WORK.BUF_X1
    PORT MAP (
        A => p2TRF(10),
        Z => S13(10)
    );
BUF_X1_89: ENTITY WORK.BUF_X1
    PORT MAP (
        A => p2TRF(11),
        Z => S13(11)
    );
BUF_X1_90: ENTITY WORK.BUF_X1
    PORT MAP (
        A => p2TRF(12),
        Z => S13(12)
    );
BUF_X1_91: ENTITY WORK.BUF_X1
    PORT MAP (
        A => p2TRF(13),
        Z => S13(13)
    );
BUF_X1_92: ENTITY WORK.BUF_X1
    PORT MAP (
        A => p2TRF(14),
        Z => S13(14)
    );
BUF_X1_93: ENTITY WORK.BUF_X1
    PORT MAP (
        A => p2TRF(15),
        Z => S13(15)
    );
BUF_X1_94: ENTITY WORK.BUF_X1
    PORT MAP (
        A => p2TRF(2),
        Z => S13(2)
    );
BUF_X1_95: ENTITY WORK.BUF_X1
    PORT MAP (
        A => p2TRF(3),
        Z => S13(3)
    );
BUF_X1_96: ENTITY WORK.BUF_X1
    PORT MAP (
        A => p2TRF(4),
        Z => S13(4)
    );
BUF_X1_97: ENTITY WORK.BUF_X1
    PORT MAP (
        A => p2TRF(5),
        Z => S13(5)
    );
BUF_X1_98: ENTITY WORK.BUF_X1
    PORT MAP (
        A => p2TRF(6),
        Z => S13(6)
    );
BUF_X1_99: ENTITY WORK.BUF_X1
    PORT MAP (
        A => p2TRF(7),
        Z => S13(7)
    );
BUF_X1_100: ENTITY WORK.BUF_X1
    PORT MAP (
        A => p2TRF(8),
        Z => S13(8)
    );
BUF_X1_101: ENTITY WORK.BUF_X1
    PORT MAP (
        A => p2TRF(9),
        Z => S13(9)
    );
BUF_X1_102: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S14,
        Z => readInst
    );
BUF_X1_103: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S15,
        Z => readMM
    );
BUF_X1_104: ENTITY WORK.BUF_X1
    PORT MAP (
        A => readyMEM,
        Z => S16
    );
BUF_X1_105: ENTITY WORK.BUF_X1
    PORT MAP (
        A => rst,
        Z => S17
    );
BUF_X1_106: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S18,
        Z => writeMM
    );
BUF_X1_107: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S19,
        Z => writeTRF
    );
ccu_1: ENTITY WORK.ccu
    PORT MAP (
        arithadd => arithadd,
        arithdiv => arithdiv,
        arithmul => arithmul,
        arithsh => arithsh,
        arithsub => arithsub,
        clk => S5,
        drivedatabus => drivedatabus,
        enflag => enflag,
        fib(0) => fib_0,
        fib(1) => fib_1,
        fib(2) => fib_2,
        fib(3) => fib_3,
        fib(4) => fib_4,
        ldadr => ldadr,
        ldir => ldir,
        ldmdu1 => ldmdu1,
        ldmdu2 => ldmdu2,
        ldpc => ldpc,
        logicand => logicand,
        logicsh => logicsh,
        onescomp => onescomp,
        opcode(0) => opcode_0,
        opcode(1) => opcode_1,
        opcode(2) => opcode_2,
        opcode(3) => opcode_3,
        opcode(4) => opcode_4,
        opcode(5) => opcode_5,
        opcode(6) => opcode_6,
        opcode(7) => opcode_7,
        outflag(0) => outflag_0,
        outflag(1) => outflag_1,
        outflag(2) => outflag_2,
        outflag(3) => outflag_3,
        outflag(4) => outflag_4,
        outflag(5) => outflag_5,
        outflag(6) => outflag_6,
        outflag(7) => outflag_7,
        p1lowbits => p1lowbits,
        readio => readio,
        readmem => readmem,
        readymdu => readymdu,
        readymem => S16,
        rst => S17,
        se5bits => se5bits,
        se6bits => se6bits,
        se8bits => se8bits,
        seladr_mem => seladr_mem,
        selasu_trf => selasu_trf,
        seldatabus_trf => seldatabus_trf,
        selflag(0) => selflag_0,
        selflag(1) => selflag_1,
        selflag(2) => selflag_2,
        selflag(3) => selflag_3,
        selflag(4) => selflag_4,
        selflag(5) => selflag_5,
        selflag(6) => selflag_6,
        selflag(7) => selflag_7,
        selimm_asu => selimm_asu,
        selimm_pcp => selimm_pcp,
        selimm_trf => selimm_trf,
        selllu_trf => selllu_trf,
        selmdu1_trf => selmdu1_trf,
        selmdu2_trf => selmdu2_trf,
        selp1_pc => selp1_pc,
        selp1_pcp => selp1_pcp,
        selp2_asu => selp2_asu,
        selp2_shu => selp2_shu,
        selpc1_pc => selpc1_pc,
        selpc1_trf => selpc1_trf,
        selpc_mem => S14,
        selpcadd_pc => selpcadd_pc,
        selrd0_trf => selrd0_trf,
        selrd1_trf => selrd1_trf,
        selrd_1_trf => selrd_1_trf,
        selrd_2_trf => selrd_2_trf,
        selrs1_trf => selrs1_trf,
        selrs2_trf => selrs2_trf,
        selshim_shu => selshim_shu,
        selshu_trf => selshu_trf,
        setflags => setflags,
        startmdu => startmdu,
        twoscomp => twoscomp,
        use8bits => use8bits,
        writeio => writeio,
        writemem => writemem,
        writetrf => S19
    );
dpu_1: ENTITY WORK.dpu
    PORT MAP (
        addrbus(0) => S4(0),
        addrbus(1) => S4(1),
        addrbus(2) => S4(2),
        addrbus(3) => S4(3),
        addrbus(4) => S4(4),
        addrbus(5) => S4(5),
        addrbus(6) => S4(6),
        addrbus(7) => S4(7),
        addrbus(8) => S4(8),
        addrbus(9) => S4(9),
        addrbus(10) => S4(10),
        addrbus(11) => S4(11),
        addrbus(12) => S4(12),
        addrbus(13) => S4(13),
        addrbus(14) => S4(14),
        addrbus(15) => S4(15),
        arithadd => arithadd,
        arithdiv => arithdiv,
        arithmul => arithmul,
        arithsh => arithsh,
        arithsub => arithsub,
        clk => S5,
        databusin(0) => S6(0),
        databusin(1) => S6(1),
        databusin(2) => S6(2),
        databusin(3) => S6(3),
        databusin(4) => S6(4),
        databusin(5) => S6(5),
        databusin(6) => S6(6),
        databusin(7) => S6(7),
        databusin(8) => S6(8),
        databusin(9) => S6(9),
        databusin(10) => S6(10),
        databusin(11) => S6(11),
        databusin(12) => S6(12),
        databusin(13) => S6(13),
        databusin(14) => S6(14),
        databusin(15) => S6(15),
        databusout(0) => S7(0),
        databusout(1) => S7(1),
        databusout(2) => S7(2),
        databusout(3) => S7(3),
        databusout(4) => S7(4),
        databusout(5) => S7(5),
        databusout(6) => S7(6),
        databusout(7) => S7(7),
        databusout(8) => S7(8),
        databusout(9) => S7(9),
        databusout(10) => S7(10),
        databusout(11) => S7(11),
        databusout(12) => S7(12),
        databusout(13) => S7(13),
        databusout(14) => S7(14),
        databusout(15) => S7(15),
        drivedatabus => drivedatabus,
        enflag => enflag,
        fib(0) => fib_0,
        fib(1) => fib_1,
        fib(2) => fib_2,
        fib(3) => fib_3,
        fib(4) => fib_4,
        indatatrf(0) => S8(0),
        indatatrf(1) => S8(1),
        indatatrf(2) => S8(2),
        indatatrf(3) => S8(3),
        indatatrf(4) => S8(4),
        indatatrf(5) => S8(5),
        indatatrf(6) => S8(6),
        indatatrf(7) => S8(7),
        indatatrf(8) => S8(8),
        indatatrf(9) => S8(9),
        indatatrf(10) => S8(10),
        indatatrf(11) => S8(11),
        indatatrf(12) => S8(12),
        indatatrf(13) => S8(13),
        indatatrf(14) => S8(14),
        indatatrf(15) => S8(15),
        ldadr => ldadr,
        ldir => ldir,
        ldmdu1 => ldmdu1,
        ldmdu2 => ldmdu2,
        ldpc => ldpc,
        logicand => logicand,
        logicsh => logicsh,
        onescomp => onescomp,
        opcode(0) => opcode_0,
        opcode(1) => opcode_1,
        opcode(2) => opcode_2,
        opcode(3) => opcode_3,
        opcode(4) => opcode_4,
        opcode(5) => opcode_5,
        opcode(6) => opcode_6,
        opcode(7) => opcode_7,
        outflag(0) => outflag_0,
        outflag(1) => outflag_1,
        outflag(2) => outflag_2,
        outflag(3) => outflag_3,
        outflag(4) => outflag_4,
        outflag(5) => outflag_5,
        outflag(6) => outflag_6,
        outflag(7) => outflag_7,
        outmuxrd(0) => S9(0),
        outmuxrd(1) => S9(1),
        outmuxrd(2) => S9(2),
        outmuxrd(3) => S9(3),
        outmuxrs1(0) => S10(0),
        outmuxrs1(1) => S10(1),
        outmuxrs1(2) => S10(2),
        outmuxrs1(3) => S10(3),
        outmuxrs2(0) => S11(0),
        outmuxrs2(1) => S11(1),
        outmuxrs2(2) => S11(2),
        outmuxrs2(3) => S11(3),
        p1lowbits => p1lowbits,
        p1trf(0) => S12(0),
        p1trf(1) => S12(1),
        p1trf(2) => S12(2),
        p1trf(3) => S12(3),
        p1trf(4) => S12(4),
        p1trf(5) => S12(5),
        p1trf(6) => S12(6),
        p1trf(7) => S12(7),
        p1trf(8) => S12(8),
        p1trf(9) => S12(9),
        p1trf(10) => S12(10),
        p1trf(11) => S12(11),
        p1trf(12) => S12(12),
        p1trf(13) => S12(13),
        p1trf(14) => S12(14),
        p1trf(15) => S12(15),
        p2trf(0) => S13(0),
        p2trf(1) => S13(1),
        p2trf(2) => S13(2),
        p2trf(3) => S13(3),
        p2trf(4) => S13(4),
        p2trf(5) => S13(5),
        p2trf(6) => S13(6),
        p2trf(7) => S13(7),
        p2trf(8) => S13(8),
        p2trf(9) => S13(9),
        p2trf(10) => S13(10),
        p2trf(11) => S13(11),
        p2trf(12) => S13(12),
        p2trf(13) => S13(13),
        p2trf(14) => S13(14),
        p2trf(15) => S13(15),
        readymdu => readymdu,
        rst => S17,
        se5bits => se5bits,
        se6bits => se6bits,
        se8bits => se8bits,
        seladr_mem => seladr_mem,
        selasu_trf => selasu_trf,
        seldatabus_trf => seldatabus_trf,
        selflag(0) => selflag_0,
        selflag(1) => selflag_1,
        selflag(2) => selflag_2,
        selflag(3) => selflag_3,
        selflag(4) => selflag_4,
        selflag(5) => selflag_5,
        selflag(6) => selflag_6,
        selflag(7) => selflag_7,
        selimm_asu => selimm_asu,
        selimm_pcp => selimm_pcp,
        selimm_trf => selimm_trf,
        selllu_trf => selllu_trf,
        selmdu1_trf => selmdu1_trf,
        selmdu2_trf => selmdu2_trf,
        selp1_pc => selp1_pc,
        selp1_pcp => selp1_pcp,
        selp2_asu => selp2_asu,
        selp2_shu => selp2_shu,
        selpc1_pc => selpc1_pc,
        selpc1_trf => selpc1_trf,
        selpc_mem => S14,
        selpcadd_pc => selpcadd_pc,
        selrd0_trf => selrd0_trf,
        selrd1_trf => selrd1_trf,
        selrd_1_trf => selrd_1_trf,
        selrd_2_trf => selrd_2_trf,
        selrs1_trf => selrs1_trf,
        selrs2_trf => selrs2_trf,
        selshim_shu => selshim_shu,
        selshu_trf => selshu_trf,
        setflags => setflags,
        startmdu => startmdu,
        twoscomp => twoscomp,
        use8bits => use8bits
    );

END ARCHITECTURE arch;
