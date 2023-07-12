LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY seqDetector IS
    PORT (
        clk : IN STD_LOGIC;
        rst : IN STD_LOGIC;
        serIn : IN STD_LOGIC;
        serOutValid : OUT STD_LOGIC);
END ENTITY seqDetector;

ARCHITECTURE arch OF seqDetector IS
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
    SIGNAL ps_0 : STD_LOGIC;
    SIGNAL ps_1 : STD_LOGIC;
    SIGNAL ps_2 : STD_LOGIC;

BEGIN
notg_1: ENTITY WORK.notg
    PORT MAP (
        A => S16,
        Y => S4
    );
notg_2: ENTITY WORK.notg
    PORT MAP (
        A => ps_1,
        Y => S5
    );
nand_n_1: ENTITY WORK.nand_n
    PORT MAP (
        A(0) => S17,
        A(1) => S4,
        Y => S6
    );
notg_3: ENTITY WORK.notg
    PORT MAP (
        A => S6,
        Y => S7
    );
nor_n_1: ENTITY WORK.nor_n
    PORT MAP (
        A(0) => ps_1,
        A(1) => S16,
        Y => S8
    );
notg_4: ENTITY WORK.notg
    PORT MAP (
        A => S8,
        Y => S9
    );
nor_n_2: ENTITY WORK.nor_n
    PORT MAP (
        A(0) => S9,
        A(1) => ps_0,
        Y => S10
    );
nor_n_3: ENTITY WORK.nor_n
    PORT MAP (
        A(0) => S10,
        A(1) => S7,
        Y => S3
    );
nor_n_4: ENTITY WORK.nor_n
    PORT MAP (
        A(0) => S18,
        A(1) => ps_2,
        Y => S11
    );
notg_5: ENTITY WORK.notg
    PORT MAP (
        A => S11,
        Y => S12
    );
nor_n_5: ENTITY WORK.nor_n
    PORT MAP (
        A(0) => S12,
        A(1) => ps_0,
        Y => S13
    );
nor_n_6: ENTITY WORK.nor_n
    PORT MAP (
        A(0) => S13,
        A(1) => S6,
        Y => S1
    );
nand_n_2: ENTITY WORK.nand_n
    PORT MAP (
        A(0) => S12,
        A(1) => S4,
        Y => S14
    );
nor_n_7: ENTITY WORK.nor_n
    PORT MAP (
        A(0) => S14,
        A(1) => S17,
        Y => S0
    );
nor_n_8: ENTITY WORK.nor_n
    PORT MAP (
        A(0) => S6,
        A(1) => S5,
        Y => S2
    );
dff_1: ENTITY WORK.dff
    PORT MAP (
        C => S15,
        CE => '1',
        D => S3,
        NbarT => '0',
        PRE => '0',
        Q => ps_0,
        R => '0',
        Si => S19,
        global_reset => '0'
    );
dff_2: ENTITY WORK.dff
    PORT MAP (
        C => S15,
        CE => '1',
        D => S0,
        NbarT => '0',
        PRE => '0',
        Q => ps_1,
        R => '0',
        Si => S20,
        global_reset => '0'
    );
dff_3: ENTITY WORK.dff
    PORT MAP (
        C => S15,
        CE => '1',
        D => S1,
        NbarT => '0',
        PRE => '0',
        Q => ps_2,
        R => '0',
        Si => S21,
        global_reset => '0'
    );
dff_4: ENTITY WORK.dff
    PORT MAP (
        C => S15,
        CE => '1',
        D => S2,
        NbarT => '0',
        PRE => '0',
        Q => S18,
        R => '0',
        Si => S22,
        global_reset => '0'
    );
BUFX2_1: ENTITY WORK.BUFX2
    PORT MAP (
        A => clk,
        Y => S15
    );
BUFX2_2: ENTITY WORK.BUFX2
    PORT MAP (
        A => rst,
        Y => S16
    );
BUFX2_3: ENTITY WORK.BUFX2
    PORT MAP (
        A => serIn,
        Y => S17
    );
BUFX2_4: ENTITY WORK.BUFX2
    PORT MAP (
        A => S18,
        Y => serOutValid
    );

END ARCHITECTURE arch;
