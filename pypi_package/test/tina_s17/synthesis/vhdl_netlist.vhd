LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY sequence IS
    PORT (
        clk : IN STD_LOGIC;
        rst : IN STD_LOGIC;
        x : IN STD_LOGIC;
        out : OUT STD_LOGIC);
END ENTITY sequence;

ARCHITECTURE arch OF sequence IS
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
    SIGNAL ns_0 : STD_LOGIC;
    SIGNAL ns_1 : STD_LOGIC;
    SIGNAL ps_0 : STD_LOGIC;
    SIGNAL ps_1 : STD_LOGIC;

BEGIN
notg_1: ENTITY WORK.notg
    PORT MAP (
        A => ps_1,
        Y => S3
    );
notg_2: ENTITY WORK.notg
    PORT MAP (
        A => S9,
        Y => S4
    );
nand_n_1: ENTITY WORK.nand_n
    PORT MAP (
        A(0) => ps_0,
        A(1) => ps_1,
        Y => S5
    );
notg_3: ENTITY WORK.notg
    PORT MAP (
        A => S5,
        Y => S7
    );
nor_n_1: ENTITY WORK.nor_n
    PORT MAP (
        A(0) => ps_0,
        A(1) => S3,
        Y => S0
    );
nand_n_2: ENTITY WORK.nand_n
    PORT MAP (
        A(0) => S0,
        A(1) => S9,
        Y => S1
    );
nand_n_3: ENTITY WORK.nand_n
    PORT MAP (
        A(0) => S4,
        A(1) => ps_0,
        Y => S2
    );
nand_n_4: ENTITY WORK.nand_n
    PORT MAP (
        A(0) => S2,
        A(1) => S1,
        Y => ns_1
    );
bufg_1: ENTITY WORK.bufg
    PORT MAP (
        A => S9,
        Y => ns_0
    );
dff_1: ENTITY WORK.dff
    PORT MAP (
        C => S6,
        CE => '1',
        D => ns_0,
        NbarT => '0',
        PRE => '0',
        Q => ps_0,
        R => S8,
        Si => S10,
        global_reset => '0'
    );
dff_2: ENTITY WORK.dff
    PORT MAP (
        C => S6,
        CE => '1',
        D => ns_1,
        NbarT => '0',
        PRE => '0',
        Q => ps_1,
        R => S8,
        Si => S11,
        global_reset => '0'
    );
bufg_2: ENTITY WORK.bufg
    PORT MAP (
        A => clk,
        Y => S6
    );
bufg_3: ENTITY WORK.bufg
    PORT MAP (
        A => S7,
        Y => out
    );
bufg_4: ENTITY WORK.bufg
    PORT MAP (
        A => rst,
        Y => S8
    );
bufg_5: ENTITY WORK.bufg
    PORT MAP (
        A => x,
        Y => S9
    );

END ARCHITECTURE arch;
