LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY counter IS
    PORT (
        clk : IN STD_LOGIC;
        rst : IN STD_LOGIC;
        en : IN STD_LOGIC;
        clkEn : IN STD_LOGIC;
        count : OUT STD_LOGIC_VECTOR (3 DOWNTO 0);
        co : OUT STD_LOGIC);
END ENTITY counter;

ARCHITECTURE arch OF counter IS
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

BEGIN
INV_X1_1: ENTITY WORK.INV_X1
    PORT MAP (
        A => S27(2),
        ZN => S4
    );
AND4_X1_1: ENTITY WORK.AND4_X1
    PORT MAP (
        A1 => S4,
        A2 => S27(3),
        A3 => S27(1),
        A4 => S20,
        ZN => S26
    );
INV_X1_2: ENTITY WORK.INV_X1
    PORT MAP (
        A => S27(0),
        ZN => S5
    );
NAND2_X1_1: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S25,
        A2 => S28,
        ZN => S6
    );
INV_X1_3: ENTITY WORK.INV_X1
    PORT MAP (
        A => S29,
        ZN => S7
    );
OAI21_X1_1: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => S7,
        B1 => S6,
        B2 => S20,
        ZN => S8
    );
AOI21_X1_1: ENTITY WORK.AOI21_X1
    PORT MAP (
        A => S8,
        B1 => S6,
        B2 => S5,
        ZN => S0
    );
INV_X1_4: ENTITY WORK.INV_X1
    PORT MAP (
        A => S27(1),
        ZN => S9
    );
NAND3_X1_1: ENTITY WORK.NAND3_X1
    PORT MAP (
        A1 => S25,
        A2 => S28,
        A3 => S27(0),
        ZN => S10
    );
NAND4_X1_1: ENTITY WORK.NAND4_X1
    PORT MAP (
        A1 => S27(1),
        A2 => S27(0),
        A3 => S25,
        A4 => S28,
        ZN => S11
    );
NAND2_X1_2: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S11,
        A2 => S7,
        ZN => S12
    );
AOI21_X1_2: ENTITY WORK.AOI21_X1
    PORT MAP (
        A => S12,
        B1 => S10,
        B2 => S9,
        ZN => S1
    );
NAND2_X1_3: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S27(2),
        A2 => S27(1),
        ZN => S13
    );
OAI21_X1_2: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => S7,
        B1 => S10,
        B2 => S13,
        ZN => S14
    );
AOI21_X1_3: ENTITY WORK.AOI21_X1
    PORT MAP (
        A => S14,
        B1 => S11,
        B2 => S4,
        ZN => S2
    );
OAI21_X1_3: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => S27(3),
        B1 => S10,
        B2 => S13,
        ZN => S15
    );
INV_X1_5: ENTITY WORK.INV_X1
    PORT MAP (
        A => S27(3),
        ZN => S16
    );
AND3_X1_1: ENTITY WORK.AND3_X1
    PORT MAP (
        A1 => S27(0),
        A2 => S28,
        A3 => S25,
        ZN => S17
    );
AND2_X1_1: ENTITY WORK.AND2_X1
    PORT MAP (
        A1 => S27(1),
        A2 => S27(2),
        ZN => S18
    );
NAND3_X1_2: ENTITY WORK.NAND3_X1
    PORT MAP (
        A1 => S17,
        A2 => S16,
        A3 => S18,
        ZN => S19
    );
AOI21_X1_4: ENTITY WORK.AOI21_X1
    PORT MAP (
        A => S29,
        B1 => S19,
        B2 => S15,
        ZN => S3
    );
DFF_X1_1: ENTITY WORK.DFF_X1
    PORT MAP (
        CK => S24,
        D => S0,
        Q => S27(0),
        QN => S20
    );
DFF_X1_2: ENTITY WORK.DFF_X1
    PORT MAP (
        CK => S24,
        D => S1,
        Q => S27(1),
        QN => S23
    );
DFF_X1_3: ENTITY WORK.DFF_X1
    PORT MAP (
        CK => S24,
        D => S2,
        Q => S27(2),
        QN => S22
    );
DFF_X1_4: ENTITY WORK.DFF_X1
    PORT MAP (
        CK => S24,
        D => S3,
        Q => S27(3),
        QN => S21
    );
BUF_X1_1: ENTITY WORK.BUF_X1
    PORT MAP (
        A => clk,
        Z => S24
    );
BUF_X1_2: ENTITY WORK.BUF_X1
    PORT MAP (
        A => clkEn,
        Z => S25
    );
BUF_X1_3: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S26,
        Z => co
    );
BUF_X1_4: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S27(0),
        Z => count(0)
    );
BUF_X1_5: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S27(1),
        Z => count(1)
    );
BUF_X1_6: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S27(2),
        Z => count(2)
    );
BUF_X1_7: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S27(3),
        Z => count(3)
    );
BUF_X1_8: ENTITY WORK.BUF_X1
    PORT MAP (
        A => en,
        Z => S28
    );
BUF_X1_9: ENTITY WORK.BUF_X1
    PORT MAP (
        A => rst,
        Z => S29
    );

END ARCHITECTURE arch;
