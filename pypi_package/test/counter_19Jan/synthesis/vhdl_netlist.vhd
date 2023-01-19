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
    SIGNAL _0_ : STD_LOGIC;
    SIGNAL _10_ : STD_LOGIC;
    SIGNAL _11_ : STD_LOGIC;
    SIGNAL _12_ : STD_LOGIC;
    SIGNAL _13_ : STD_LOGIC;
    SIGNAL _14_ : STD_LOGIC;
    SIGNAL _15_ : STD_LOGIC;
    SIGNAL _16_ : STD_LOGIC;
    SIGNAL _17_ : STD_LOGIC;
    SIGNAL _18_ : STD_LOGIC;
    SIGNAL _19_ : STD_LOGIC;
    SIGNAL _1_ : STD_LOGIC;
    SIGNAL _20_ : STD_LOGIC;
    SIGNAL _21_ : STD_LOGIC;
    SIGNAL _22_ : STD_LOGIC;
    SIGNAL _23_ : STD_LOGIC;
    SIGNAL _24_ : STD_LOGIC;
    SIGNAL _25_ : STD_LOGIC;
    SIGNAL _2_ : STD_LOGIC;
    SIGNAL _3_ : STD_LOGIC;
    SIGNAL _4_ : STD_LOGIC;
    SIGNAL _5_ : STD_LOGIC;
    SIGNAL _6_ : STD_LOGIC;
    SIGNAL _7_ : STD_LOGIC;
    SIGNAL _8_ : STD_LOGIC;
    SIGNAL _9_ : STD_LOGIC;

BEGIN
INV_X1_1: ENTITY WORK.INV_X1
    PORT MAP (
        A => _20_(2),
        ZN => _4_
    );
AND4_X1_1: ENTITY WORK.AND4_X1
    PORT MAP (
        A1 => _4_,
        A2 => _20_(3),
        A3 => _20_(1),
        A4 => _20_(0),
        ZN => _24_
    );
INV_X1_2: ENTITY WORK.INV_X1
    PORT MAP (
        A => _25_(0),
        ZN => _5_
    );
NAND2_X1_1: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => clkEn,
        A2 => en,
        ZN => _6_
    );
INV_X1_3: ENTITY WORK.INV_X1
    PORT MAP (
        A => rst,
        ZN => _7_
    );
OAI21_X1_1: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => _7_,
        B1 => _6_,
        B2 => _20_(0),
        ZN => _8_
    );
AOI21_X1_1: ENTITY WORK.AOI21_X1
    PORT MAP (
        A => _8_,
        B1 => _6_,
        B2 => _5_,
        ZN => _0_
    );
INV_X1_4: ENTITY WORK.INV_X1
    PORT MAP (
        A => _20_(1),
        ZN => _9_
    );
NAND3_X1_1: ENTITY WORK.NAND3_X1
    PORT MAP (
        A1 => clkEn,
        A2 => en,
        A3 => _25_(0),
        ZN => _10_
    );
NAND4_X1_1: ENTITY WORK.NAND4_X1
    PORT MAP (
        A1 => _20_(1),
        A2 => _25_(0),
        A3 => clkEn,
        A4 => en,
        ZN => _11_
    );
NAND2_X1_2: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => _11_,
        A2 => _7_,
        ZN => _12_
    );
AOI21_X1_2: ENTITY WORK.AOI21_X1
    PORT MAP (
        A => _12_,
        B1 => _10_,
        B2 => _9_,
        ZN => _1_
    );
NAND2_X1_3: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => _20_(2),
        A2 => _20_(1),
        ZN => _13_
    );
OAI21_X1_2: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => _7_,
        B1 => _10_,
        B2 => _13_,
        ZN => _14_
    );
AOI21_X1_3: ENTITY WORK.AOI21_X1
    PORT MAP (
        A => _14_,
        B1 => _11_,
        B2 => _4_,
        ZN => _2_
    );
OAI21_X1_3: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => _20_(3),
        B1 => _10_,
        B2 => _13_,
        ZN => _15_
    );
INV_X1_5: ENTITY WORK.INV_X1
    PORT MAP (
        A => _20_(3),
        ZN => _16_
    );
AND3_X1_1: ENTITY WORK.AND3_X1
    PORT MAP (
        A1 => _25_(0),
        A2 => en,
        A3 => clkEn,
        ZN => _17_
    );
AND2_X1_1: ENTITY WORK.AND2_X1
    PORT MAP (
        A1 => _20_(1),
        A2 => _20_(2),
        ZN => _18_
    );
NAND3_X1_2: ENTITY WORK.NAND3_X1
    PORT MAP (
        A1 => _17_,
        A2 => _16_,
        A3 => _18_,
        ZN => _19_
    );
AOI21_X1_4: ENTITY WORK.AOI21_X1
    PORT MAP (
        A => rst,
        B1 => _19_,
        B2 => _15_,
        ZN => _3_
    );
DFF_X1_1: ENTITY WORK.DFF_X1
    PORT MAP (
        CK => clk,
        D => _0_,
        Q => _25_(0),
        QN => _20_(0)
    );
DFF_X1_2: ENTITY WORK.DFF_X1
    PORT MAP (
        CK => clk,
        D => _1_,
        Q => _20_(1),
        QN => _21_
    );
DFF_X1_3: ENTITY WORK.DFF_X1
    PORT MAP (
        CK => clk,
        D => _2_,
        Q => _20_(2),
        QN => _22_
    );
DFF_X1_4: ENTITY WORK.DFF_X1
    PORT MAP (
        CK => clk,
        D => _3_,
        Q => _20_(3),
        QN => _23_
    );
BUF_X1_1: ENTITY WORK.BUF_X1
    PORT MAP (
        A => _24_,
        Z => co
    );
BUF_X1_2: ENTITY WORK.BUF_X1
    PORT MAP (
        A => _25_(0),
        Z => count(0)
    );
BUF_X1_3: ENTITY WORK.BUF_X1
    PORT MAP (
        A => _20_(1),
        Z => count(1)
    );
BUF_X1_4: ENTITY WORK.BUF_X1
    PORT MAP (
        A => _20_(2),
        Z => count(2)
    );
BUF_X1_5: ENTITY WORK.BUF_X1
    PORT MAP (
        A => _20_(3),
        Z => count(3)
    );

END ARCHITECTURE arch;
