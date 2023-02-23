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
    SIGNAL S40 : STD_LOGIC;

BEGIN
notg_1: ENTITY WORK.notg
    PORT MAP (
        in1 => S31,
        out1 => S4
    );
notg_2: ENTITY WORK.notg
    PORT MAP (
        in1 => S34,
        out1 => S5
    );
notg_3: ENTITY WORK.notg
    PORT MAP (
        in1 => S33,
        out1 => S6
    );
notg_4: ENTITY WORK.notg
    PORT MAP (
        in1 => S32,
        out1 => S7
    );
notg_5: ENTITY WORK.notg
    PORT MAP (
        in1 => S36,
        out1 => S8
    );
nand_n_1: ENTITY WORK.nand_n
    PORT MAP (
        in1(0) => S34,
        in1(1) => S4,
        out1 => S9
    );
nand_n_2: ENTITY WORK.nand_n
    PORT MAP (
        in1(0) => S32,
        in1(1) => S6,
        out1 => S10
    );
nor_n_1: ENTITY WORK.nor_n
    PORT MAP (
        in1(0) => S10,
        in1(1) => S9,
        out1 => S30
    );
nand_n_3: ENTITY WORK.nand_n
    PORT MAP (
        in1(0) => S35,
        in1(1) => S29,
        out1 => S11
    );
nor_n_2: ENTITY WORK.nor_n
    PORT MAP (
        in1(0) => S11,
        in1(1) => S4,
        out1 => S12
    );
notg_6: ENTITY WORK.notg
    PORT MAP (
        in1 => S12,
        out1 => S13
    );
nand_n_4: ENTITY WORK.nand_n
    PORT MAP (
        in1(0) => S11,
        in1(1) => S4,
        out1 => S14
    );
nand_n_5: ENTITY WORK.nand_n
    PORT MAP (
        in1(0) => S14,
        in1(1) => S8,
        out1 => S15
    );
nor_n_3: ENTITY WORK.nor_n
    PORT MAP (
        in1(0) => S15,
        in1(1) => S12,
        out1 => S0
    );
nor_n_4: ENTITY WORK.nor_n
    PORT MAP (
        in1(0) => S13,
        in1(1) => S7,
        out1 => S16
    );
nand_n_6: ENTITY WORK.nand_n
    PORT MAP (
        in1(0) => S12,
        in1(1) => S32,
        out1 => S17
    );
nor_n_5: ENTITY WORK.nor_n
    PORT MAP (
        in1(0) => S12,
        in1(1) => S32,
        out1 => S18
    );
nor_n_6: ENTITY WORK.nor_n
    PORT MAP (
        in1(0) => S18,
        in1(1) => S36,
        out1 => S19
    );
nand_n_7: ENTITY WORK.nand_n
    PORT MAP (
        in1(0) => S19,
        in1(1) => S17,
        out1 => S20
    );
notg_7: ENTITY WORK.notg
    PORT MAP (
        in1 => S20,
        out1 => S1
    );
nand_n_8: ENTITY WORK.nand_n
    PORT MAP (
        in1(0) => S16,
        in1(1) => S33,
        out1 => S21
    );
nor_n_7: ENTITY WORK.nor_n
    PORT MAP (
        in1(0) => S16,
        in1(1) => S33,
        out1 => S22
    );
nor_n_8: ENTITY WORK.nor_n
    PORT MAP (
        in1(0) => S22,
        in1(1) => S36,
        out1 => S23
    );
nand_n_9: ENTITY WORK.nand_n
    PORT MAP (
        in1(0) => S23,
        in1(1) => S21,
        out1 => S24
    );
notg_8: ENTITY WORK.notg
    PORT MAP (
        in1 => S24,
        out1 => S2
    );
nor_n_9: ENTITY WORK.nor_n
    PORT MAP (
        in1(0) => S21,
        in1(1) => S5,
        out1 => S25
    );
nand_n_10: ENTITY WORK.nand_n
    PORT MAP (
        in1(0) => S21,
        in1(1) => S5,
        out1 => S26
    );
nand_n_11: ENTITY WORK.nand_n
    PORT MAP (
        in1(0) => S26,
        in1(1) => S8,
        out1 => S27
    );
nor_n_10: ENTITY WORK.nor_n
    PORT MAP (
        in1(0) => S27,
        in1(1) => S25,
        out1 => S3
    );
dff_1: ENTITY WORK.dff
    PORT MAP (
        C => S28,
        CE => '1',
        CLR => '0',
        D => S0,
        NbarT => '0',
        PRE => '0',
        Q => S31,
        Si => S37,
        global_reset => '0'
    );
dff_2: ENTITY WORK.dff
    PORT MAP (
        C => S28,
        CE => '1',
        CLR => '0',
        D => S1,
        NbarT => '0',
        PRE => '0',
        Q => S32,
        Si => S38,
        global_reset => '0'
    );
dff_3: ENTITY WORK.dff
    PORT MAP (
        C => S28,
        CE => '1',
        CLR => '0',
        D => S2,
        NbarT => '0',
        PRE => '0',
        Q => S33,
        Si => S39,
        global_reset => '0'
    );
dff_4: ENTITY WORK.dff
    PORT MAP (
        C => S28,
        CE => '1',
        CLR => '0',
        D => S3,
        NbarT => '0',
        PRE => '0',
        Q => S34,
        Si => S40,
        global_reset => '0'
    );
bufg_1: ENTITY WORK.bufg
    PORT MAP (
        in1 => clk,
        out1 => S28
    );
bufg_2: ENTITY WORK.bufg
    PORT MAP (
        in1 => clkEn,
        out1 => S29
    );
bufg_3: ENTITY WORK.bufg
    PORT MAP (
        in1 => S30,
        out1 => co
    );
bufg_4: ENTITY WORK.bufg
    PORT MAP (
        in1 => S31,
        out1 => count(0)
    );
bufg_5: ENTITY WORK.bufg
    PORT MAP (
        in1 => S32,
        out1 => count(1)
    );
bufg_6: ENTITY WORK.bufg
    PORT MAP (
        in1 => S33,
        out1 => count(2)
    );
bufg_7: ENTITY WORK.bufg
    PORT MAP (
        in1 => S34,
        out1 => count(3)
    );
bufg_8: ENTITY WORK.bufg
    PORT MAP (
        in1 => en,
        out1 => S35
    );
bufg_9: ENTITY WORK.bufg
    PORT MAP (
        in1 => rst,
        out1 => S36
    );

END ARCHITECTURE arch;
