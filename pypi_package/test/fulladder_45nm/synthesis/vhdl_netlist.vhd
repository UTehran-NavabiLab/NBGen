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
    SIGNAL new__0_ : STD_LOGIC;
    SIGNAL new__10_ : STD_LOGIC;
    SIGNAL new__1_ : STD_LOGIC;
    SIGNAL new__2_ : STD_LOGIC;
    SIGNAL new__3_ : STD_LOGIC;
    SIGNAL new__4_ : STD_LOGIC;
    SIGNAL new__5_ : STD_LOGIC;
    SIGNAL new__6_ : STD_LOGIC;
    SIGNAL new__7_ : STD_LOGIC;
    SIGNAL new__8_ : STD_LOGIC;
    SIGNAL new__9_ : STD_LOGIC;

BEGIN
INV_X1_0: ENTITY WORK.INV_X1
    PORT MAP (
        A => i0,
        ZN => new__8_
    );
NAND2_X1_1: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => i1,
        A2 => ci,
        ZN => new__0_
    );
INV_X1_2: ENTITY WORK.INV_X1
    PORT MAP (
        A => i1,
        ZN => new__1_
    );
INV_X1_3: ENTITY WORK.INV_X1
    PORT MAP (
        A => ci,
        ZN => new__2_
    );
NAND2_X1_4: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => new__1_,
        A2 => new__2_,
        ZN => new__3_
    );
NAND3_X1_5: ENTITY WORK.NAND3_X1
    PORT MAP (
        A1 => new__3_,
        A2 => new__8_,
        A3 => new__0_,
        ZN => new__4_
    );
NAND2_X1_6: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => new__7_,
        A2 => new__4_,
        ZN => new__10_
    );
OAI21_X1_7: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => new__0_,
        B1 => new__6_,
        B2 => new__8_,
        ZN => new__9_
    );
AND2_X1_8: ENTITY WORK.AND2_X1
    PORT MAP (
        A1 => ci,
        A2 => i1,
        ZN => new__5_
    );
NOR2_X1_9: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => i1,
        A2 => ci,
        ZN => new__6_
    );
OAI21_X1_10: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => i0,
        B1 => new__5_,
        B2 => new__6_,
        ZN => new__7_
    );
BUF_X1_11: ENTITY WORK.BUF_X1
    PORT MAP (
        A => new__9_,
        Z => co
    );
BUF_X1_12: ENTITY WORK.BUF_X1
    PORT MAP (
        A => new__10_,
        Z => s
    );

END ARCHITECTURE arch;
