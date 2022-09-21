LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY and3 IS
    PORT (
        i0 : IN STD_LOGIC;
        i1 : IN STD_LOGIC;
        i2 : IN STD_LOGIC;
        o : OUT STD_LOGIC);
END ENTITY and3;

ARCHITECTURE arch OF and3 IS
    SIGNAL _0_ : STD_LOGIC;

BEGIN
AND3_X1_1: ENTITY WORK.AND3_X1
    PORT MAP (
        A1 => i2,
        A2 => i0,
        A3 => i1,
        ZN => _0_
    );
BUF_X1_1: ENTITY WORK.BUF_X1
    PORT MAP (
        A => _0_,
        Z => o
    );

END ARCHITECTURE arch;
