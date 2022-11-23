LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY counter IS
    PORT (
        clk : IN STD_LOGIC;
        rst : IN STD_LOGIC;
        en : IN STD_LOGIC;
		global_reset : IN STD_LOGIC;
		NbarT : IN STD_LOGIC;
		Si : IN STD_LOGIC;
		So : OUT STD_LOGIC;
        co : OUT STD_LOGIC;
        counter : OUT STD_LOGIC_VECTOR (0 TO 3));
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
	
	SIGNAL global_reset_sig : STD_LOGIC;
    SIGNAL NbarT_sig : STD_LOGIC;
    SIGNAL Si_sig : STD_LOGIC;
    SIGNAL So_sig : STD_LOGIC;

BEGIN
notg_0: ENTITY WORK.notg
    PORT MAP (
        in1 => new_counter_reg_0,
        out1 => S4
    );
notg_1: ENTITY WORK.notg
    PORT MAP (
        in1 => new_counter_reg_3,
        out1 => S5
    );
notg_2: ENTITY WORK.notg
    PORT MAP (
        in1 => S20,
        out1 => S6
    );
nand_n_3: ENTITY WORK.nand_n
    PORT MAP (
        in1(0) => new_counter_reg_1,
        in1(1) => new_counter_reg_0,
        out1 => S7
    );
nand_n_4: ENTITY WORK.nand_n
    PORT MAP (
        in1(0) => new_counter_reg_2,
        in1(1) => new_counter_reg_3,
        out1 => S8
    );
nor_n_5: ENTITY WORK.nor_n
    PORT MAP (
        in1(0) => S8,
        in1(1) => S7,
        out1 => S19
    );
nor_n_6: ENTITY WORK.nor_n
    PORT MAP (
        in1(0) => S6,
        in1(1) => S4,
        out1 => S9
    );
nor_n_7: ENTITY WORK.nor_n
    PORT MAP (
        in1(0) => S20,
        in1(1) => new_counter_reg_0,
        out1 => S10
    );
nor_n_8: ENTITY WORK.nor_n
    PORT MAP (
        in1(0) => S10,
        in1(1) => S9,
        out1 => S0
    );
nor_n_9: ENTITY WORK.nor_n
    PORT MAP (
        in1(0) => S7,
        in1(1) => S6,
        out1 => S11
    );
nor_n_10: ENTITY WORK.nor_n
    PORT MAP (
        in1(0) => S9,
        in1(1) => new_counter_reg_1,
        out1 => S12
    );
nor_n_11: ENTITY WORK.nor_n
    PORT MAP (
        in1(0) => S12,
        in1(1) => S11,
        out1 => S1
    );
nand_n_12: ENTITY WORK.nand_n
    PORT MAP (
        in1(0) => S11,
        in1(1) => new_counter_reg_2,
        out1 => S13
    );
notg_13: ENTITY WORK.notg
    PORT MAP (
        in1 => S13,
        out1 => S14
    );
nor_n_14: ENTITY WORK.nor_n
    PORT MAP (
        in1(0) => S11,
        in1(1) => new_counter_reg_2,
        out1 => S15
    );
nor_n_15: ENTITY WORK.nor_n
    PORT MAP (
        in1(0) => S15,
        in1(1) => S14,
        out1 => S2
    );
nor_n_16: ENTITY WORK.nor_n
    PORT MAP (
        in1(0) => S14,
        in1(1) => new_counter_reg_3,
        out1 => S16
    );
nor_n_17: ENTITY WORK.nor_n
    PORT MAP (
        in1(0) => S13,
        in1(1) => S5,
        out1 => S17
    );
nor_n_18: ENTITY WORK.nor_n
    PORT MAP (
        in1(0) => S17,
        in1(1) => S16,
        out1 => S3
    );
dff_19: ENTITY WORK.dff
    PORT MAP (
        C => S18,
        CE => '1',
        CLR => S21,
        D => S0,
        NbarT => NbarT_sig,
        PRE => '0',
        Q => new_counter_reg_0,
        Si => Si_sig,
        global_reset => global_reset_sig
    );
dff_20: ENTITY WORK.dff
    PORT MAP (
        C => S18,
        CE => '1',
        CLR => S21,
        D => S1,
        NbarT => NbarT_sig,
        PRE => '0',
        Q => new_counter_reg_1,
        Si => new_counter_reg_0,
        global_reset => global_reset_sig
    );
dff_21: ENTITY WORK.dff
    PORT MAP (
        C => S18,
        CE => '1',
        CLR => S21,
        D => S2,
        NbarT => NbarT_sig,
        PRE => '0',
        Q => new_counter_reg_2,
        Si => new_counter_reg_1,
        global_reset => global_reset_sig
    );
dff_22: ENTITY WORK.dff
    PORT MAP (
        C => S18,
        CE => '1',
        CLR => S21,
        D => S3,
        NbarT => NbarT_sig,
        PRE => '0',
        Q => new_counter_reg_3,
        Si => new_counter_reg_2,
        global_reset => global_reset_sig
    );
	
	So_sig <= new_counter_reg_3;
	
pin_23: ENTITY WORK.pin
    PORT MAP (
        in1 => clk,
        out1 => S18
    );
pout_24: ENTITY WORK.pout
    PORT MAP (
        in1 => S19,
        out1 => co
    );
pout_25: ENTITY WORK.pout
    PORT MAP (
        in1 => new_counter_reg_0,
        out1 => counter(0)
    );
pout_26: ENTITY WORK.pout
    PORT MAP (
        in1 => new_counter_reg_1,
        out1 => counter(1)
    );
pout_27: ENTITY WORK.pout
    PORT MAP (
        in1 => new_counter_reg_2,
        out1 => counter(2)
    );
pout_28: ENTITY WORK.pout
    PORT MAP (
        in1 => new_counter_reg_3,
        out1 => counter(3)
    );
pin_29: ENTITY WORK.pin
    PORT MAP (
        in1 => en,
        out1 => S20
    );
pin_30: ENTITY WORK.pin
    PORT MAP (
        in1 => rst,
        out1 => S21
    );
pin_31: ENTITY WORK.pin
    PORT MAP (
        in1 => global_reset,
        out1 => global_reset_sig
    );
pin_32: ENTITY WORK.pin
    PORT MAP (
        in1 => NbarT,
        out1 => NbarT_sig
    );
pin_33: ENTITY WORK.pin
    PORT MAP (
        in1 => Si,
        out1 => Si_sig
    );
pout_34: ENTITY WORK.pout
    PORT MAP (
        in1 => So_sig,
        out1 => So
    );
	
END ARCHITECTURE arch;
