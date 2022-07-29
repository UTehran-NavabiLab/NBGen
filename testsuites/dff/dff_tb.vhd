
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY dff_tb IS
END ENTITY dff_tb;
    
ARCHITECTURE TEST OF dff_tb IS
    SIGNAL D, CLR, PRE, CE, NbarT, Si, global_reset, Q : STD_LOGIC;
    SIGNAL tmp : STD_LOGIC;
    SIGNAL C : STD_LOGIC := '0';
BEGIN
    FUT : ENTITY WORK.dff
        PORT MAP (D, C, CLR, PRE, CE, NbarT, Si, global_reset, Q);

    C <= NOT C AFTER 10 NS;

	PROCESS
	BEGIN	
		D <= '0';
        CLR <= '0';
        PRE <= '0';
        CE <= '0';
        NbarT <= '0';
        Si <= '0';
        global_reset <= '0';
		WAIT FOR 23 NS;
		D <= '1';
        CLR <= '0';
        PRE <= '0';
        CE <= '1';
        NbarT <= '0';
        Si <= '0';
        global_reset <= '0';
		WAIT FOR 23 NS;
		D <= '1';
        CLR <= '0';
        PRE <= '0';
        CE <= '1';
        NbarT <= '0';
        Si <= '0';
        global_reset <= '1';
		WAIT FOR 23 NS;
		D <= '0';
        CLR <= '0';
        PRE <= '0';
        CE <= '1';
        NbarT <= '1';
        Si <= '1';
        global_reset <= '0';
		WAIT FOR 40 NS;
		D <= '1';
        CLR <= '1';
        PRE <= '0';
        CE <= '1';
        NbarT <= '0';
        Si <= '0';
        global_reset <= '0';
		WAIT FOR 23 NS;
		D <= '1';
        CLR <= '0';
        PRE <= '0';
        CE <= '1';
        NbarT <= '0';
        Si <= '0';
        global_reset <= '0';
		WAIT FOR 23 NS;
		D <= '1';
        CLR <= '0';
        PRE <= '0';
        CE <= '0';
        NbarT <= '0';
        Si <= '0';
        global_reset <= '0';
		WAIT FOR 23 NS;
		D <= '1';
        CLR <= '0';
        PRE <= '0';
        CE <= '1';
        NbarT <= '0';
        Si <= '0';
        global_reset <= '0';
		WAIT;
	END PROCESS;

END ARCHITECTURE TEST;