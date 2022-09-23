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
    SIGNAL n4 : STD_LOGIC;
    SIGNAL n5 : STD_LOGIC;

BEGIN
XOR2_X1_1: ENTITY WORK.XOR2_X1
    PORT MAP (
        A => i1,
        B => n4,
        Z => s
    );
INV_X1_1: ENTITY WORK.INV_X1
    PORT MAP (
        A => n5,
        ZN => co
    );
AOI22_X1_1: ENTITY WORK.AOI22_X1
    PORT MAP (
        A1 => i0,
        A2 => ci,
        B1 => n4,
        B2 => i1,
        ZN => n5
    );
XOR2_X1_2: ENTITY WORK.XOR2_X1
    PORT MAP (
        A => ci,
        B => i0,
        Z => n4
    );

END ARCHITECTURE arch;
