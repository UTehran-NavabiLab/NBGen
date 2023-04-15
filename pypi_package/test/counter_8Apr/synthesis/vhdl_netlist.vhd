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

BEGIN
notg_1: ENTITY WORK.notg
    PORT MAP (
        A => S31(0),
        Y => S4
    );
notg_2: ENTITY WORK.notg
    PORT MAP (
        A => S31(3),
        Y => S5
    );
notg_3: ENTITY WORK.notg
    PORT MAP (
        A => S31(2),
        Y => S6
    );
notg_4: ENTITY WORK.notg
    PORT MAP (
        A => S31(1),
        Y => S7
    );
notg_5: ENTITY WORK.notg
    PORT MAP (
        A => S33,
        Y => S8
    );
nand_n_1: ENTITY WORK.nand_n
    PORT MAP (
        A(0) => S31(3),
        A(1) => S4,
        Y => S9
    );
nand_n_2: ENTITY WORK.nand_n
    PORT MAP (
        A(0) => S31(1),
        A(1) => S6,
        Y => S10
    );
nor_n_1: ENTITY WORK.nor_n
    PORT MAP (
        A(0) => S10,
        A(1) => S9,
        Y => S30
    );
nand_n_3: ENTITY WORK.nand_n
    PORT MAP (
        A(0) => S32,
        A(1) => S29,
        Y => S11
    );
nor_n_2: ENTITY WORK.nor_n
    PORT MAP (
        A(0) => S11,
        A(1) => S4,
        Y => S12
    );
notg_6: ENTITY WORK.notg
    PORT MAP (
        A => S12,
        Y => S13
    );
nand_n_4: ENTITY WORK.nand_n
    PORT MAP (
        A(0) => S11,
        A(1) => S4,
        Y => S14
    );
nand_n_5: ENTITY WORK.nand_n
    PORT MAP (
        A(0) => S14,
        A(1) => S8,
        Y => S15
    );
nor_n_3: ENTITY WORK.nor_n
    PORT MAP (
        A(0) => S15,
        A(1) => S12,
        Y => S0
    );
nor_n_4: ENTITY WORK.nor_n
    PORT MAP (
        A(0) => S13,
        A(1) => S7,
        Y => S16
    );
nand_n_6: ENTITY WORK.nand_n
    PORT MAP (
        A(0) => S12,
        A(1) => S31(1),
        Y => S17
    );
nor_n_5: ENTITY WORK.nor_n
    PORT MAP (
        A(0) => S12,
        A(1) => S31(1),
        Y => S18
    );
nor_n_6: ENTITY WORK.nor_n
    PORT MAP (
        A(0) => S18,
        A(1) => S33,
        Y => S19
    );
nand_n_7: ENTITY WORK.nand_n
    PORT MAP (
        A(0) => S19,
        A(1) => S17,
        Y => S20
    );
notg_7: ENTITY WORK.notg
    PORT MAP (
        A => S20,
        Y => S1
    );
nand_n_8: ENTITY WORK.nand_n
    PORT MAP (
        A(0) => S16,
        A(1) => S31(2),
        Y => S21
    );
nor_n_7: ENTITY WORK.nor_n
    PORT MAP (
        A(0) => S16,
        A(1) => S31(2),
        Y => S22
    );
nor_n_8: ENTITY WORK.nor_n
    PORT MAP (
        A(0) => S22,
        A(1) => S33,
        Y => S23
    );
nand_n_9: ENTITY WORK.nand_n
    PORT MAP (
        A(0) => S23,
        A(1) => S21,
        Y => S24
    );
notg_8: ENTITY WORK.notg
    PORT MAP (
        A => S24,
        Y => S2
    );
nor_n_9: ENTITY WORK.nor_n
    PORT MAP (
        A(0) => S21,
        A(1) => S5,
        Y => S25
    );
nand_n_10: ENTITY WORK.nand_n
    PORT MAP (
        A(0) => S21,
        A(1) => S5,
        Y => S26
    );
nand_n_11: ENTITY WORK.nand_n
    PORT MAP (
        A(0) => S26,
        A(1) => S8,
        Y => S27
    );
nor_n_10: ENTITY WORK.nor_n
    PORT MAP (
        A(0) => S27,
        A(1) => S25,
        Y => S3
    );
dff_1: ENTITY WORK.dff
    PORT MAP (
        C => S28,
        CE => '1',
        D => S0,
        NbarT => '0',
        PRE => '0',
        Q => S31(0),
        R => '0',
        Si => S34,
        global_reset => '0'
    );
dff_2: ENTITY WORK.dff
    PORT MAP (
        C => S28,
        CE => '1',
        D => S1,
        NbarT => '0',
        PRE => '0',
        Q => S31(1),
        R => '0',
        Si => S35,
        global_reset => '0'
    );
dff_3: ENTITY WORK.dff
    PORT MAP (
        C => S28,
        CE => '1',
        D => S2,
        NbarT => '0',
        PRE => '0',
        Q => S31(2),
        R => '0',
        Si => S36,
        global_reset => '0'
    );
dff_4: ENTITY WORK.dff
    PORT MAP (
        C => S28,
        CE => '1',
        D => S3,
        NbarT => '0',
        PRE => '0',
        Q => S31(3),
        R => '0',
        Si => S37,
        global_reset => '0'
    );
bufg_1: ENTITY WORK.bufg
    PORT MAP (
        A => clk,
        Y => S28
    );
bufg_2: ENTITY WORK.bufg
    PORT MAP (
        A => clkEn,
        Y => S29
    );
bufg_3: ENTITY WORK.bufg
    PORT MAP (
        A => S30,
        Y => co
    );
bufg_4: ENTITY WORK.bufg
    PORT MAP (
        A => S31(0),
        Y => count(0)
    );
bufg_5: ENTITY WORK.bufg
    PORT MAP (
        A => S31(1),
        Y => count(1)
    );
bufg_6: ENTITY WORK.bufg
    PORT MAP (
        A => S31(2),
        Y => count(2)
    );
bufg_7: ENTITY WORK.bufg
    PORT MAP (
        A => S31(3),
        Y => count(3)
    );
bufg_8: ENTITY WORK.bufg
    PORT MAP (
        A => en,
        Y => S32
    );
bufg_9: ENTITY WORK.bufg
    PORT MAP (
        A => rst,
        Y => S33
    );

END ARCHITECTURE arch;
