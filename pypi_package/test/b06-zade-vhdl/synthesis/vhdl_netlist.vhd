LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY b01 IS
    PORT (
        line1 : IN STD_LOGIC;
        line2 : IN STD_LOGIC;
        reset : IN STD_LOGIC;
        clock : IN STD_LOGIC;
        outp : OUT STD_LOGIC;
        overflw : OUT STD_LOGIC);
END ENTITY b01;

ARCHITECTURE arch OF b01 IS
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
    SIGNAL S20 : STD_LOGIC;
    SIGNAL S21 : STD_LOGIC;
    SIGNAL S22 : STD_LOGIC;
    SIGNAL S23 : STD_LOGIC;
    SIGNAL S24 : STD_LOGIC;
    SIGNAL S25 : STD_LOGIC;
    SIGNAL S26 : STD_LOGIC;
    SIGNAL S27 : STD_LOGIC;
    SIGNAL S28 : STD_LOGIC;
    SIGNAL S29 : STD_LOGIC;
    SIGNAL S30 : STD_LOGIC;
    SIGNAL S31 : STD_LOGIC;
    SIGNAL S32 : STD_LOGIC;
    SIGNAL S33 : STD_LOGIC;
    SIGNAL S34 : STD_LOGIC;
    SIGNAL S35 : STD_LOGIC;
    SIGNAL S36 : STD_LOGIC;
    SIGNAL S37 : STD_LOGIC;
    SIGNAL S38 : STD_LOGIC;
    SIGNAL S39 : STD_LOGIC;
    SIGNAL S40 : STD_LOGIC;
    SIGNAL S41 : STD_LOGIC;
    SIGNAL S42 : STD_LOGIC;
    SIGNAL S43 : STD_LOGIC;
    SIGNAL S44 : STD_LOGIC;
    SIGNAL S45 : STD_LOGIC;
    SIGNAL S46 : STD_LOGIC;
    SIGNAL S47 : STD_LOGIC;
    SIGNAL \2_stato_0 : STD_LOGIC;
    SIGNAL \2_stato_1 : STD_LOGIC;
    SIGNAL \2_stato_2 : STD_LOGIC;
    SIGNAL \79_Y_0 : STD_LOGIC;
    SIGNAL \79_Y_1 : STD_LOGIC;
    SIGNAL \79_Y_2 : STD_LOGIC;

BEGIN
INV_X1_1: ENTITY WORK.INV_X1
    PORT MAP (
        A => S2,
        ZN => S4
    );
INV_X1_2: ENTITY WORK.INV_X1
    PORT MAP (
        A => \2_stato_0,
        ZN => S5
    );
NAND3_X1_1: ENTITY WORK.NAND3_X1
    PORT MAP (
        A1 => S5,
        A2 => \2_stato_1,
        A3 => \2_stato_2,
        ZN => S6
    );
NAND2_X1_1: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S6,
        A2 => S4,
        ZN => S7
    );
NAND2_X1_2: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S44,
        A2 => S43,
        ZN => S8
    );
INV_X1_3: ENTITY WORK.INV_X1
    PORT MAP (
        A => S8,
        ZN => S9
    );
NOR2_X1_1: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S44,
        A2 => S43,
        ZN => S10
    );
NOR2_X1_2: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S9,
        A2 => S10,
        ZN => S11
    );
XNOR2_X1_1: ENTITY WORK.XNOR2_X1
    PORT MAP (
        A => S11,
        B => S7,
        ZN => S0
    );
INV_X1_4: ENTITY WORK.INV_X1
    PORT MAP (
        A => S10,
        ZN => S12
    );
INV_X1_5: ENTITY WORK.INV_X1
    PORT MAP (
        A => \2_stato_1,
        ZN => S13
    );
NAND3_X1_2: ENTITY WORK.NAND3_X1
    PORT MAP (
        A1 => S13,
        A2 => \2_stato_0,
        A3 => \2_stato_2,
        ZN => S14
    );
AOI21_X1_1: ENTITY WORK.AOI21_X1
    PORT MAP (
        A => S2,
        B1 => S5,
        B2 => S13,
        ZN => S15
    );
NAND4_X1_1: ENTITY WORK.NAND4_X1
    PORT MAP (
        A1 => S15,
        A2 => S12,
        A3 => S14,
        A4 => S6,
        ZN => S16
    );
NOR3_X1_1: ENTITY WORK.NOR3_X1
    PORT MAP (
        A1 => S4,
        A2 => S13,
        A3 => \2_stato_0,
        ZN => S17
    );
NOR3_X1_2: ENTITY WORK.NOR3_X1
    PORT MAP (
        A1 => \2_stato_1,
        A2 => \2_stato_0,
        A3 => S2,
        ZN => S18
    );
AOI22_X1_1: ENTITY WORK.AOI22_X1
    PORT MAP (
        A1 => S17,
        A2 => S9,
        B1 => S18,
        B2 => S12,
        ZN => S19
    );
NAND3_X1_3: ENTITY WORK.NAND3_X1
    PORT MAP (
        A1 => S13,
        A2 => \2_stato_0,
        A3 => S2,
        ZN => S20
    );
NOR2_X1_3: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S20,
        A2 => S8,
        ZN => S21
    );
NAND3_X1_4: ENTITY WORK.NAND3_X1
    PORT MAP (
        A1 => \2_stato_1,
        A2 => \2_stato_0,
        A3 => S2,
        ZN => S22
    );
NAND3_X1_5: ENTITY WORK.NAND3_X1
    PORT MAP (
        A1 => S13,
        A2 => S5,
        A3 => S2,
        ZN => S23
    );
AOI21_X1_2: ENTITY WORK.AOI21_X1
    PORT MAP (
        A => S9,
        B1 => S23,
        B2 => S22,
        ZN => S24
    );
NOR2_X1_4: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S24,
        A2 => S21,
        ZN => S25
    );
NOR2_X1_5: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S14,
        A2 => S10,
        ZN => S26
    );
NOR2_X1_6: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S6,
        A2 => S8,
        ZN => S27
    );
NOR2_X1_7: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S26,
        A2 => S27,
        ZN => S28
    );
NAND4_X1_2: ENTITY WORK.NAND4_X1
    PORT MAP (
        A1 => S25,
        A2 => S28,
        A3 => S16,
        A4 => S19,
        ZN => \79_Y_0
    );
NOR2_X1_8: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S20,
        A2 => S9,
        ZN => S29
    );
NOR2_X1_9: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S29,
        A2 => S27,
        ZN => S30
    );
NOR2_X1_10: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S5,
        A2 => \2_stato_1,
        ZN => S31
    );
AOI21_X1_3: ENTITY WORK.AOI21_X1
    PORT MAP (
        A => S17,
        B1 => S31,
        B2 => \2_stato_2,
        ZN => S32
    );
NAND2_X1_3: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S18,
        A2 => S10,
        ZN => S33
    );
NAND4_X1_3: ENTITY WORK.NAND4_X1
    PORT MAP (
        A1 => S30,
        A2 => S32,
        A3 => S16,
        A4 => S33,
        ZN => \79_Y_1
    );
AOI21_X1_4: ENTITY WORK.AOI21_X1
    PORT MAP (
        A => S21,
        B1 => S18,
        B2 => S12,
        ZN => S34
    );
NAND2_X1_4: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S23,
        A2 => S22,
        ZN => S35
    );
NAND2_X1_5: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S35,
        A2 => S9,
        ZN => S36
    );
NAND3_X1_6: ENTITY WORK.NAND3_X1
    PORT MAP (
        A1 => S34,
        A2 => S32,
        A3 => S36,
        ZN => \79_Y_2
    );
AOI21_X1_5: ENTITY WORK.AOI21_X1
    PORT MAP (
        A => S15,
        B1 => \2_stato_0,
        B2 => \2_stato_1,
        ZN => S37
    );
NOR2_X1_11: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S37,
        A2 => \2_stato_2,
        ZN => S1
    );
INV_X1_6: ENTITY WORK.INV_X1
    PORT MAP (
        A => S47,
        ZN => S3
    );
DFFR_X1_1: ENTITY WORK.DFFR_X1
    PORT MAP (
        CK => S42,
        D => \79_Y_0,
        Q => \2_stato_0,
        QN => S41,
        RN => S3
    );
DFFR_X1_2: ENTITY WORK.DFFR_X1
    PORT MAP (
        CK => S42,
        D => \79_Y_1,
        Q => \2_stato_1,
        QN => S40,
        RN => S3
    );
DFFR_X1_3: ENTITY WORK.DFFR_X1
    PORT MAP (
        CK => S42,
        D => \79_Y_2,
        Q => \2_stato_2,
        QN => S2,
        RN => S3
    );
DFFR_X1_4: ENTITY WORK.DFFR_X1
    PORT MAP (
        CK => S42,
        D => S0,
        Q => S45,
        QN => S39,
        RN => S3
    );
DFFR_X1_5: ENTITY WORK.DFFR_X1
    PORT MAP (
        CK => S42,
        D => S1,
        Q => S46,
        QN => S38,
        RN => S3
    );
BUF_X1_1: ENTITY WORK.BUF_X1
    PORT MAP (
        A => clock,
        Z => S42
    );
BUF_X1_2: ENTITY WORK.BUF_X1
    PORT MAP (
        A => line1,
        Z => S43
    );
BUF_X1_3: ENTITY WORK.BUF_X1
    PORT MAP (
        A => line2,
        Z => S44
    );
BUF_X1_4: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S45,
        Z => outp
    );
BUF_X1_5: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S46,
        Z => overflw
    );
BUF_X1_6: ENTITY WORK.BUF_X1
    PORT MAP (
        A => reset,
        Z => S47
    );

END ARCHITECTURE arch;
