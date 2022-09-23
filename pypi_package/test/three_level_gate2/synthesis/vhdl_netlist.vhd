LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY three_level_gate IS
    PORT (
        i0 : IN STD_LOGIC;
        i1 : IN STD_LOGIC;
        i2 : IN STD_LOGIC;
        o : OUT STD_LOGIC);
END ENTITY three_level_gate;

ARCHITECTURE arch OF three_level_gate IS
    SIGNAL _0_ : STD_LOGIC;
    SIGNAL _1_ : STD_LOGIC;

BEGIN
INV_X1_1: ENTITY WORK.INV_X1
    PORT MAP (
        A => i2,
        ZN => _0_
    );
NAND2_X1_1: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => i1,
        A2 => i0,
        ZN => _1_
    );
NAND2_X1_2: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => _1_,
        A2 => _0_,
        ZN => o
    );

END ARCHITECTURE arch;
