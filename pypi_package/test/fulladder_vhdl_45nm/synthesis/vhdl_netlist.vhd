LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY fulladder IS
    PORT (
        i0 : IN STD_LOGIC;
        i1 : IN STD_LOGIC;
        ci : IN STD_LOGIC;
        s : OUT STD_LOGIC;
        co : OUT STD_LOGIC);
END ENTITY fulladder;

ARCHITECTURE arch OF fulladder IS
    SIGNAL S0 : STD_LOGIC;
    SIGNAL S1 : STD_LOGIC;
    SIGNAL S2 : STD_LOGIC;
    SIGNAL S3 : STD_LOGIC;
    SIGNAL S4 : STD_LOGIC;
    SIGNAL S5 : STD_LOGIC;
    SIGNAL S6 : STD_LOGIC;
    SIGNAL S7 : STD_LOGIC;

BEGIN
OAI21_X1_0: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => S5,
        B1 => S3,
        B2 => S6,
        ZN => S2
    );
NAND2_X1_1: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S0,
        A2 => S2,
        ZN => S4
    );
NAND2_X1_2: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S6,
        A2 => S3,
        ZN => S0
    );
XNOR2_X1_3: ENTITY WORK.XNOR2_X1
    PORT MAP (
        A => S6,
        B => S3,
        ZN => S1
    );
XNOR2_X1_4: ENTITY WORK.XNOR2_X1
    PORT MAP (
        A => S5,
        B => S1,
        ZN => S7
    );
BUF_X1_5: ENTITY WORK.BUF_X1
    PORT MAP (
        A => ci,
        Z => S3
    );
BUF_X1_6: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S4,
        Z => co
    );
BUF_X1_7: ENTITY WORK.BUF_X1
    PORT MAP (
        A => i0,
        Z => S5
    );
BUF_X1_8: ENTITY WORK.BUF_X1
    PORT MAP (
        A => i1,
        Z => S6
    );
BUF_X1_9: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S7,
        Z => s
    );

END ARCHITECTURE arch;
