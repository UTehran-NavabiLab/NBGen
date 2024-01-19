--******************************************************************************
--	Filename:		VirtualTester_BIST.vhd
--	Project:		SAYAC Testing 
--  Version:		0.90
--	History:
--	Date:			20 June 2022
--	Last Author: 	Nooshin Nosrati
--  Copyright (C) 2022 University of Tehran
--  This source file may be used and distributed without
--  restriction provided that this copyright statement is not
--  removed from the file and that any derivative work contains
--  the original copyright notice and the associated disclaimer.
--
--******************************************************************************
--	File content description:
--	Testbench as a virtual tester for RTS LBIST testing                                 
--******************************************************************************

LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE STD.TEXTIO.ALL;
USE IEEE.STD_LOGIC_TEXTIO.ALL;
USE IEEE.NUMERIC_STD.ALL;
USE IEEE.STD_LOGIC_ARITH.ALL; 
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
USE IEEE.MATH_REAL.ALL;

ENTITY VirtualTester IS
END ENTITY VirtualTester;
--- First config 000 1110100011 1001 1010

ARCHITECTURE test OF VirtualTester IS
	CONSTANT PI_Size     : INTEGER := 2; 
	CONSTANT PO_Size     : INTEGER := 5;	 	
	CONSTANT PRPG_Seed   : STD_LOGIC_VECTOR := "011";    
	CONSTANT PRPG_Poly   : STD_LOGIC_VECTOR := "000"; 	--"101";	--101  --"000";    --"000";     -- "110"
	CONSTANT MISR_Seed	 : STD_LOGIC_VECTOR := "0000011011";    
	CONSTANT MISR_Poly	 : STD_LOGIC_VECTOR := "1100010111";	--"1011100000";   --0000011101  --"1100010111";    --"1110100011"; -- "0110011101"
	CONSTANT SRSG_Seed	 : STD_LOGIC_VECTOR := "1000";    
	CONSTANT SRSG_Poly	 : STD_LOGIC_VECTOR := "1001";	--"1011"; --1101	--"1001";    --"1001"; --"0100"
	CONSTANT SISA_Seed	 : STD_LOGIC_VECTOR := "0100";   
	CONSTANT SISA_Poly	 : STD_LOGIC_VECTOR := "0101";	--0011	--"0101";    --"1010";
	CONSTANT ShiftSize   : INTEGER := 4;
	CONSTANT numOfCycles : INTEGER := 13; --10;
	CONSTANT numOfRounds : INTEGER := 7;  --3;   
	CONSTANT clkPeriod   : time    := 10 ns;
	
	SIGNAL clk        : STD_LOGIC := '0';
	SIGNAL rst        : STD_LOGIC := '0';
	SIGNAL en         : STD_LOGIC := '0';
	SIGNAL test_reset : STD_LOGIC := '0';
	SIGNAL runLBIST   : STD_LOGIC := '0';
	SIGNAL Ready      : STD_LOGIC := '0';
	SIGNAL FbarP      : STD_LOGIC := '0';
	SIGNAL co         : STD_LOGIC := '0';
	SIGNAL counter    : STD_LOGIC_VECTOR (3 DOWNTO 0) := "0000";
		
	SIGNAL faultInjection : STD_LOGIC := '0';
	SIGNAL stopSimulation : BOOLEAN   := false;

BEGIN
	FUT : ENTITY WORK.Top_level 
			GENERIC MAP (PI_Size, PO_Size, PRPG_Seed, PRPG_Poly, MISR_Seed, MISR_Poly,
			SRSG_Seed, SRSG_Poly, SISA_Seed, SISA_Poly, ShiftSize, numOfCycles, numOfRounds)
			PORT MAP (clk, rst, en, test_reset, runLBIST, Ready, FbarP, co, counter); 

	clk <= NOT clk AFTER clkPeriod/2;
	
	FI:PROCESS 

		VARIABLE detected : STD_LOGIC := '0';
		VARIABLE numOfDetected : INTEGER := 0;
		VARIABLE numOfFaults : INTEGER := 0;
	    FILE faultFile, reportFile : TEXT; 
        VARIABLE fstatusR, fstatusW : FILE_OPEN_STATUS;
	    VARIABLE lbufR, lbufW : LINE;
		variable str : string(1 TO 100);
		variable strSize : INTEGER;
		VARIABLE wireName : STRING(1 TO 100);
		VARIABLE stuckAtVal : STD_LOGIC;
		VARIABLE coverage : REAL;
	BEGIN
		runLBIST <= '1';
		
		FILE_OPEN (fstatusW, reportFile, "reportFile.txt", write_mode);
		FILE_OPEN (fstatusR, faultFile, "fault_list__counter.flt", read_mode);
		numOfFaults := 0;
		numOfDetected := 0;
		WHILE (NOT ENDFILE (faultFile)) LOOP
			-- WAIT UNTIL (Ready = '1' AND Ready'EVENT);
			WAIT UNTIL clk = '0';
			READLINE (faultFile, lbufR);
			assert lbufR'length < str'length;  
			str := (others => ' '); 
			strSize := lbufR'length;
			read(lbufR, str(1 to strSize));
			wireName := (others => ' ');
			wireName(1 TO strSize-2) := str(1 to strSize-2);
			stuckAtVal := STD_LOGIC'value(str(strSize to strSize));
			faultInjection <= '1';
			numOfFaults := numOfFaults + 1;
		
			test_reset <= '1'; 
			WAIT UNTIL clk = '1';
			test_reset <= '0';
			
			detected := '0';
			FOR i IN 1 TO 2*numOfRounds LOOP
				WAIT UNTIL FbarP'EVENT;
				WAIT FOR 1 NS;
				IF (FbarP = '0' AND detected = '0') THEN 
					numOfDetected := numOfDetected + 1;
					detected := '1';
				END IF;
			END LOOP;
			
			faultInjection <= '0';
			WAIT FOR 0 NS;
		END LOOP;
		FILE_CLOSE(faultFile);
		
		coverage := (REAL(numOfDetected) / REAL(numOfFaults));
		REPORT "numOfDetected: " &INTEGER'IMAGE(numOfDetected); 
		REPORT "numOfFaults: " &INTEGER'IMAGE(numOfFaults); 
		REPORT "coverage: " &REAL'IMAGE(coverage);
		WRITE (lbufW, string'(": Coverage = "));
		WRITE (lbufW, coverage);
		WRITE (lbufW, string'(": --- numOfDetected = "));
		WRITE (lbufW, numOfDetected);
		WRITE (lbufW, string'(", numOfFaults = "));
		WRITE (lbufW, numOfFaults);
		WRITELINE (reportFile, lbufW);
		FILE_CLOSE (reportFile);

		stopSimulation <= true;
		WAIT;	

	END PROCESS;
END ARCHITECTURE test;