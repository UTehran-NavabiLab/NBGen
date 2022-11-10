LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY c17 IS
    PORT (
        N1 : IN STD_LOGIC;
        N2 : IN STD_LOGIC;
        N3 : IN STD_LOGIC;
        N6 : IN STD_LOGIC;
        N7 : IN STD_LOGIC;
        N22 : OUT STD_LOGIC;
        N23 : OUT STD_LOGIC);
END ENTITY c17;

ARCHITECTURE arch OF c17 IS
    SIGNAL _0_ : STD_LOGIC;
    SIGNAL _1_ : STD_LOGIC;
    SIGNAL _2_ : STD_LOGIC;
    SIGNAL _3_ : STD_LOGIC;
    SIGNAL _4_ : STD_LOGIC;

BEGIN
INV_X1_1: ENTITY WORK.INV_X1
    PORT MAP (
        A => N7,
        ZN => _2_
    );
AOI22_X1_1: ENTITY WORK.AOI22_X1
    PORT MAP (
        A1 => _1_,
        A2 => _2_,
        B1 => N3,
        B2 => N6,
        ZN => N23
    );
NAND2_X1_1: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => N6,
        A2 => N3,
        ZN => _3_
    );
NAND2_X1_2: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => _3_,
        A2 => N2,
        ZN => _4_
    );
NAND2_X1_3: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => N3,
        A2 => N1,
        ZN => _0_
    );
NAND2_X1_4: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => _4_,
        A2 => _0_,
        ZN => N22
    );
INV_X1_2: ENTITY WORK.INV_X1
    PORT MAP (
        A => N2,
        ZN => _1_
    );

END ARCHITECTURE arch;
