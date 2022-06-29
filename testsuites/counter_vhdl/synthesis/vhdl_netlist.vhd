LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY counter IS
    PORT (
        clk : IN STD_LOGIC;
        rst : IN STD_LOGIC;
        en : IN STD_LOGIC;
        co : OUT STD_LOGIC;
        counter : OUT STD_LOGIC_VECTOR (3 DOWNTO 0));
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
    SIGNAL new_counter_reg_0 : STD_LOGIC;
    SIGNAL new_counter_reg_1 : STD_LOGIC;
    SIGNAL new_counter_reg_2 : STD_LOGIC;
    SIGNAL new_counter_reg_3 : STD_LOGIC;

BEGIN
notg_0: ENTITY WORK.notg
    PORT MAP (
        in => new_counter_reg_0,
        out => S4
    );
notg_1: ENTITY WORK.notg
    PORT MAP (
        in => new_counter_reg_3,
        out => S5
    );
notg_2: ENTITY WORK.notg
    PORT MAP (
        in => S20,
        out => S6
    );
nand_n_3: ENTITY WORK.nand_n
    PORT MAP (
        in(0) => new_counter_reg_1,
        in(1) => new_counter_reg_0,
        out => S7
    );
nand_n_4: ENTITY WORK.nand_n
    PORT MAP (
        in(0) => new_counter_reg_2,
        in(1) => new_counter_reg_3,
        out => S8
    );
nor_n_5: ENTITY WORK.nor_n
    PORT MAP (
        in(0) => S8,
        in(1) => S7,
        out => S19
    );
nor_n_6: ENTITY WORK.nor_n
    PORT MAP (
        in(0) => S6,
        in(1) => S4,
        out => S9
    );
nor_n_7: ENTITY WORK.nor_n
    PORT MAP (
        in(0) => S20,
        in(1) => new_counter_reg_0,
        out => S10
    );
nor_n_8: ENTITY WORK.nor_n
    PORT MAP (
        in(0) => S10,
        in(1) => S9,
        out => S0
    );
nor_n_9: ENTITY WORK.nor_n
    PORT MAP (
        in(0) => S7,
        in(1) => S6,
        out => S11
    );
nor_n_10: ENTITY WORK.nor_n
    PORT MAP (
        in(0) => S9,
        in(1) => new_counter_reg_1,
        out => S12
    );
nor_n_11: ENTITY WORK.nor_n
    PORT MAP (
        in(0) => S12,
        in(1) => S11,
        out => S1
    );
nand_n_12: ENTITY WORK.nand_n
    PORT MAP (
        in(0) => S11,
        in(1) => new_counter_reg_2,
        out => S13
    );
notg_13: ENTITY WORK.notg
    PORT MAP (
        in => S13,
        out => S14
    );
nor_n_14: ENTITY WORK.nor_n
    PORT MAP (
        in(0) => S11,
        in(1) => new_counter_reg_2,
        out => S15
    );
nor_n_15: ENTITY WORK.nor_n
    PORT MAP (
        in(0) => S15,
        in(1) => S14,
        out => S2
    );
nor_n_16: ENTITY WORK.nor_n
    PORT MAP (
        in(0) => S14,
        in(1) => new_counter_reg_3,
        out => S16
    );
nor_n_17: ENTITY WORK.nor_n
    PORT MAP (
        in(0) => S13,
        in(1) => S5,
        out => S17
    );
nor_n_18: ENTITY WORK.nor_n
    PORT MAP (
        in(0) => S17,
        in(1) => S16,
        out => S3
    );
dff_19: ENTITY WORK.dff
    PORT MAP (
        C => S18,
        CE => '1',
        CLR => S21,
        D => S0,
        NbarT => '0',
        PRE => '0',
        Q => new_counter_reg_0,
        Si => S22,
        global_reset => '0'
    );
dff_20: ENTITY WORK.dff
    PORT MAP (
        C => S18,
        CE => '1',
        CLR => S21,
        D => S1,
        NbarT => '0',
        PRE => '0',
        Q => new_counter_reg_1,
        Si => S23,
        global_reset => '0'
    );
dff_21: ENTITY WORK.dff
    PORT MAP (
        C => S18,
        CE => '1',
        CLR => S21,
        D => S2,
        NbarT => '0',
        PRE => '0',
        Q => new_counter_reg_2,
        Si => S24,
        global_reset => '0'
    );
dff_22: ENTITY WORK.dff
    PORT MAP (
        C => S18,
        CE => '1',
        CLR => S21,
        D => S3,
        NbarT => '0',
        PRE => '0',
        Q => new_counter_reg_3,
        Si => S25,
        global_reset => '0'
    );
pin_23: ENTITY WORK.pin
    PORT MAP (
        in => clk,
        out => S18
    );
pout_24: ENTITY WORK.pout
    PORT MAP (
        in => S19,
        out => co
    );
pout_25: ENTITY WORK.pout
    PORT MAP (
        in => new_counter_reg_0,
        out => counter(0)
    );
pout_26: ENTITY WORK.pout
    PORT MAP (
        in => new_counter_reg_1,
        out => counter(1)
    );
pout_27: ENTITY WORK.pout
    PORT MAP (
        in => new_counter_reg_2,
        out => counter(2)
    );
pout_28: ENTITY WORK.pout
    PORT MAP (
        in => new_counter_reg_3,
        out => counter(3)
    );
pin_29: ENTITY WORK.pin
    PORT MAP (
        in => en,
        out => S20
    );
pin_30: ENTITY WORK.pin
    PORT MAP (
        in => rst,
        out => S21
    );

END ARCHITECTURE arch;
