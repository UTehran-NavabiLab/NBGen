LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY register IS
    PORT (
        clk : IN STD_LOGIC;
        rst : IN STD_LOGIC;
        A : IN STD_LOGIC_VECTOR (3 DOWNTO 0);
        B : IN STD_LOGIC_VECTOR (3 DOWNTO 0);
        C : IN STD_LOGIC_VECTOR (3 DOWNTO 0);
        Q1 : OUT STD_LOGIC_VECTOR (3 DOWNTO 0);
        Q2 : OUT STD_LOGIC_VECTOR (3 DOWNTO 0);
        Q3 : OUT STD_LOGIC_VECTOR (3 DOWNTO 0));
END ENTITY register;

ARCHITECTURE arch OF register IS
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
    SIGNAL CK : STD_LOGIC;
    SIGNAL R : STD_LOGIC;
    SIGNAL cnt_0 : STD_LOGIC;
    SIGNAL cnt_1 : STD_LOGIC;
    SIGNAL cnt_2 : STD_LOGIC;
    SIGNAL cnt_3 : STD_LOGIC;

BEGIN
notg_1: ENTITY WORK.notg
    PORT MAP (
        A => cnt_0,
        Y => S11
    );
notg_2: ENTITY WORK.notg
    PORT MAP (
        A => CK,
        Y => S0
    );
notg_3: ENTITY WORK.notg
    PORT MAP (
        A => cnt_1,
        Y => S1
    );
notg_4: ENTITY WORK.notg
    PORT MAP (
        A => cnt_2,
        Y => S2
    );
notg_5: ENTITY WORK.notg
    PORT MAP (
        A => cnt_3,
        Y => S3
    );
nor_n_1: ENTITY WORK.nor_n
    PORT MAP (
        A(0) => S1,
        A(1) => S11,
        Y => S4
    );
nand_n_1: ENTITY WORK.nand_n
    PORT MAP (
        A(0) => cnt_1,
        A(1) => cnt_0,
        Y => S5
    );
nor_n_2: ENTITY WORK.nor_n
    PORT MAP (
        A(0) => cnt_1,
        A(1) => cnt_0,
        Y => S6
    );
nor_n_3: ENTITY WORK.nor_n
    PORT MAP (
        A(0) => S6,
        A(1) => S4,
        Y => S12
    );
nor_n_4: ENTITY WORK.nor_n
    PORT MAP (
        A(0) => S5,
        A(1) => S2,
        Y => S7
    );
nand_n_2: ENTITY WORK.nand_n
    PORT MAP (
        A(0) => S4,
        A(1) => cnt_2,
        Y => S8
    );
nor_n_5: ENTITY WORK.nor_n
    PORT MAP (
        A(0) => S4,
        A(1) => cnt_2,
        Y => S9
    );
nor_n_6: ENTITY WORK.nor_n
    PORT MAP (
        A(0) => S9,
        A(1) => S7,
        Y => S13
    );
nor_n_7: ENTITY WORK.nor_n
    PORT MAP (
        A(0) => S8,
        A(1) => S3,
        Y => R
    );
nor_n_8: ENTITY WORK.nor_n
    PORT MAP (
        A(0) => S7,
        A(1) => cnt_3,
        Y => S10
    );
nor_n_9: ENTITY WORK.nor_n
    PORT MAP (
        A(0) => S10,
        A(1) => R,
        Y => S14
    );
dff_1: ENTITY WORK.dff
    PORT MAP (
        C => CK,
        CE => '1',
        D => S17(0),
        NbarT => '0',
        PRE => '0',
        Q => S20(0),
        R => R,
        Si => S25,
        global_reset => '0'
    );
dff_2: ENTITY WORK.dff
    PORT MAP (
        C => CK,
        CE => '1',
        D => S17(1),
        NbarT => '0',
        PRE => '0',
        Q => S20(1),
        R => R,
        Si => S29,
        global_reset => '0'
    );
dff_3: ENTITY WORK.dff
    PORT MAP (
        C => CK,
        CE => '1',
        D => S17(2),
        NbarT => '0',
        PRE => '0',
        Q => S20(2),
        R => R,
        Si => S30,
        global_reset => '0'
    );
dff_4: ENTITY WORK.dff
    PORT MAP (
        C => CK,
        CE => '1',
        D => S17(3),
        NbarT => '0',
        PRE => '0',
        Q => S20(3),
        R => R,
        Si => S24,
        global_reset => '0'
    );
dff_5: ENTITY WORK.dff
    PORT MAP (
        C => S21,
        CE => '1',
        D => S16(0),
        NbarT => '0',
        PRE => '0',
        Q => S19(0),
        R => R,
        Si => S26,
        global_reset => '0'
    );
dff_6: ENTITY WORK.dff
    PORT MAP (
        C => S21,
        CE => '1',
        D => S16(1),
        NbarT => '0',
        PRE => '0',
        Q => S19(1),
        R => R,
        Si => S31,
        global_reset => '0'
    );
dff_7: ENTITY WORK.dff
    PORT MAP (
        C => S21,
        CE => '1',
        D => S16(2),
        NbarT => '0',
        PRE => '0',
        Q => S19(2),
        R => R,
        Si => S32,
        global_reset => '0'
    );
dff_8: ENTITY WORK.dff
    PORT MAP (
        C => S21,
        CE => '1',
        D => S16(3),
        NbarT => '0',
        PRE => '0',
        Q => S19(3),
        R => R,
        Si => S33,
        global_reset => '0'
    );
dff_9: ENTITY WORK.dff
    PORT MAP (
        C => S21,
        CE => '1',
        D => S11,
        NbarT => '0',
        PRE => '0',
        Q => cnt_0,
        R => S22,
        Si => S27,
        global_reset => '0'
    );
dff_10: ENTITY WORK.dff
    PORT MAP (
        C => S21,
        CE => '1',
        D => S12,
        NbarT => '0',
        PRE => '0',
        Q => cnt_1,
        R => S22,
        Si => S34,
        global_reset => '0'
    );
dff_11: ENTITY WORK.dff
    PORT MAP (
        C => S21,
        CE => '1',
        D => S13,
        NbarT => '0',
        PRE => '0',
        Q => cnt_2,
        R => S22,
        Si => S35,
        global_reset => '0'
    );
dff_12: ENTITY WORK.dff
    PORT MAP (
        C => S21,
        CE => '1',
        D => S14,
        NbarT => '0',
        PRE => '0',
        Q => cnt_3,
        R => S22,
        Si => S36,
        global_reset => '0'
    );
dff_13: ENTITY WORK.dff
    PORT MAP (
        C => CK,
        CE => '1',
        D => S15(0),
        NbarT => '0',
        PRE => '0',
        Q => S18(0),
        R => S22,
        Si => S28,
        global_reset => '0'
    );
dff_14: ENTITY WORK.dff
    PORT MAP (
        C => CK,
        CE => '1',
        D => S15(1),
        NbarT => '0',
        PRE => '0',
        Q => S18(1),
        R => S22,
        Si => S37,
        global_reset => '0'
    );
dff_15: ENTITY WORK.dff
    PORT MAP (
        C => CK,
        CE => '1',
        D => S15(2),
        NbarT => '0',
        PRE => '0',
        Q => S18(2),
        R => S22,
        Si => S38,
        global_reset => '0'
    );
dff_16: ENTITY WORK.dff
    PORT MAP (
        C => CK,
        CE => '1',
        D => S15(3),
        NbarT => '0',
        PRE => '0',
        Q => S18(3),
        R => S22,
        Si => S39,
        global_reset => '0'
    );
dff_17: ENTITY WORK.dff
    PORT MAP (
        C => S21,
        CE => '1',
        D => S0,
        NbarT => '0',
        PRE => '0',
        Q => CK,
        R => S22,
        Si => S23,
        global_reset => '0'
    );
bufg_1: ENTITY WORK.bufg
    PORT MAP (
        A => A(0),
        Y => S15(0)
    );
bufg_2: ENTITY WORK.bufg
    PORT MAP (
        A => A(1),
        Y => S15(1)
    );
bufg_3: ENTITY WORK.bufg
    PORT MAP (
        A => A(2),
        Y => S15(2)
    );
bufg_4: ENTITY WORK.bufg
    PORT MAP (
        A => A(3),
        Y => S15(3)
    );
bufg_5: ENTITY WORK.bufg
    PORT MAP (
        A => B(0),
        Y => S16(0)
    );
bufg_6: ENTITY WORK.bufg
    PORT MAP (
        A => B(1),
        Y => S16(1)
    );
bufg_7: ENTITY WORK.bufg
    PORT MAP (
        A => B(2),
        Y => S16(2)
    );
bufg_8: ENTITY WORK.bufg
    PORT MAP (
        A => B(3),
        Y => S16(3)
    );
bufg_9: ENTITY WORK.bufg
    PORT MAP (
        A => C(0),
        Y => S17(0)
    );
bufg_10: ENTITY WORK.bufg
    PORT MAP (
        A => C(1),
        Y => S17(1)
    );
bufg_11: ENTITY WORK.bufg
    PORT MAP (
        A => C(2),
        Y => S17(2)
    );
bufg_12: ENTITY WORK.bufg
    PORT MAP (
        A => C(3),
        Y => S17(3)
    );
bufg_13: ENTITY WORK.bufg
    PORT MAP (
        A => S18(0),
        Y => Q1(0)
    );
bufg_14: ENTITY WORK.bufg
    PORT MAP (
        A => S18(1),
        Y => Q1(1)
    );
bufg_15: ENTITY WORK.bufg
    PORT MAP (
        A => S18(2),
        Y => Q1(2)
    );
bufg_16: ENTITY WORK.bufg
    PORT MAP (
        A => S18(3),
        Y => Q1(3)
    );
bufg_17: ENTITY WORK.bufg
    PORT MAP (
        A => S19(0),
        Y => Q2(0)
    );
bufg_18: ENTITY WORK.bufg
    PORT MAP (
        A => S19(1),
        Y => Q2(1)
    );
bufg_19: ENTITY WORK.bufg
    PORT MAP (
        A => S19(2),
        Y => Q2(2)
    );
bufg_20: ENTITY WORK.bufg
    PORT MAP (
        A => S19(3),
        Y => Q2(3)
    );
bufg_21: ENTITY WORK.bufg
    PORT MAP (
        A => S20(0),
        Y => Q3(0)
    );
bufg_22: ENTITY WORK.bufg
    PORT MAP (
        A => S20(1),
        Y => Q3(1)
    );
bufg_23: ENTITY WORK.bufg
    PORT MAP (
        A => S20(2),
        Y => Q3(2)
    );
bufg_24: ENTITY WORK.bufg
    PORT MAP (
        A => S20(3),
        Y => Q3(3)
    );
bufg_25: ENTITY WORK.bufg
    PORT MAP (
        A => clk,
        Y => S21
    );
bufg_26: ENTITY WORK.bufg
    PORT MAP (
        A => rst,
        Y => S22
    );

END ARCHITECTURE arch;
