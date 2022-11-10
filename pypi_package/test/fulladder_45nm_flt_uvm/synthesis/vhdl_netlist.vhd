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
    SIGNAL _0_ : STD_LOGIC;
    SIGNAL _1_ : STD_LOGIC;
    SIGNAL _2_ : STD_LOGIC;
    SIGNAL _3_ : STD_LOGIC;
    SIGNAL _4_ : STD_LOGIC;
    SIGNAL _5_ : STD_LOGIC;
    SIGNAL _6_ : STD_LOGIC;
    SIGNAL _7_ : STD_LOGIC;
    SIGNAL _8_ : STD_LOGIC;

BEGIN
NAND2_X1_1: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => i1,
        A2 => ci,
        ZN => _0_
    );
INV_X1_1: ENTITY WORK.INV_X1
    PORT MAP (
        A => i1,
        ZN => _1_
    );
INV_X1_2: ENTITY WORK.INV_X1
    PORT MAP (
        A => ci,
        ZN => _2_
    );
NAND2_X1_2: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => _1_,
        A2 => _2_,
        ZN => _3_
    );
NAND3_X1_1: ENTITY WORK.NAND3_X1
    PORT MAP (
        A1 => _3_,
        A2 => _8_,
        A3 => _0_,
        ZN => _4_
    );
NAND2_X1_3: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => _7_,
        A2 => _4_,
        ZN => s
    );
OAI21_X1_1: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => _0_,
        B1 => _6_,
        B2 => _8_,
        ZN => co
    );
AND2_X1_1: ENTITY WORK.AND2_X1
    PORT MAP (
        A1 => ci,
        A2 => i1,
        ZN => _5_
    );
NOR2_X1_1: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => i1,
        A2 => ci,
        ZN => _6_
    );
OAI21_X1_2: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => i0,
        B1 => _5_,
        B2 => _6_,
        ZN => _7_
    );
INV_X1_3: ENTITY WORK.INV_X1
    PORT MAP (
        A => i0,
        ZN => _8_
    );

END ARCHITECTURE arch;
