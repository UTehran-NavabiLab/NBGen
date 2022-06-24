
--******************************************************************************
--	File content description:
--	The Register File (TRF) of the SAYAC core                                 
--******************************************************************************
------------------------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;
	
ENTITY IFF IS
	PORT (
		clk, rst, enFlag, setFlags : IN STD_LOGIC;
		selFlag  : IN STD_LOGIC;
		inFlag   : IN STD_LOGIC;
		outFlag  : OUT STD_LOGIC
	);
END ENTITY IFF;

ARCHITECTURE behaviour OF IFF IS
	SIGNAL outFlag_FF, inFlag_FF : STD_LOGIC;
BEGIN
	inFlag_FF <= outFlag_FF WHEN (selFlag OR setFlags) = '0' ELSE inFlag;
	
	PROCESS (clk, rst)
	BEGIN
		IF rst = '1' THEN
			outFlag_FF <= '0';
		ELSIF clk = '1' AND clk'EVENT THEN
			IF enFlag = '1' THEN
				outFlag_FF <= inFlag_FF;
			END IF;
		END IF;
	END PROCESS;
	
	outFlag <= outFlag_FF;
END ARCHITECTURE behaviour;
------------------------------------------------------------------------------------------------

LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;
	
ENTITY TRF IS
	PORT (
		clk, rst, writeTRF : IN STD_LOGIC;
		setFlags, enFlag   : IN STD_LOGIC;
		rs1, rs2, rd       : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
		selFlag, inFlag    : IN STD_LOGIC_VECTOR(7 DOWNTO 0);
		outFlag            : OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
		write_data         : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
		p1, p2             : OUT STD_LOGIC_VECTOR(15 DOWNTO 0)
	);
END ENTITY TRF;

ARCHITECTURE behaviour OF TRF IS
	TYPE reg_file_mem IS ARRAY (0 TO 15) OF STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL memTRF 	   : reg_file_mem;
	SIGNAL outFlag_reg : STD_LOGIC_VECTOR(7 DOWNTO 0);
BEGIN
	PROCESS (clk, rst)
	BEGIN
		IF rst = '1' THEN
			FOR I IN 0 TO 15 LOOP
				memTRF(I) <= STD_LOGIC_VECTOR(TO_UNSIGNED(I, 16));
			END LOOP;
		ELSIF clk = '0' AND clk'EVENT  THEN
			IF writeTRF = '1' AND rd /= "0000" THEN
				memTRF(TO_INTEGER(UNSIGNED(rd))) <= write_data;
			END IF;
		END IF;
	END PROCESS;
	
	p1 <= memTRF(TO_INTEGER(UNSIGNED(rs1))) WHEN rs1 /= "1111" ELSE
		((15 DOWNTO 8 => '0') & outFlag_reg);
	p2 <= memTRF(TO_INTEGER(UNSIGNED(rs2))) WHEN rs2 /= "1111" ELSE 
		((15 DOWNTO 8 => '0') & outFlag_reg);
	
	-- Flags = R15(7 DOWNTO 0)
	FlagsFF : FOR I IN 0 TO 7 GENERATE
				FF_bitI : ENTITY WORK.IFF
					PORT MAP (clk, rst, enFlag, setFlags, 
							 selFlag(I), inFlag(I), outFlag_reg(I));
	END GENERATE;
	
	outFlag <= outFlag_reg;
END ARCHITECTURE behaviour;
--******************************************************************************
--	Filename:		SAYAC_DPB.vhd
--	Project:		SAYAC : Simple Architecture Yet Ample Circuitry
--  Version:		0.990
--	History:
--	Date:			18 June 2021
--	Last Author: 	HANIEH
--  Copyright (C) 2021 University of Tehran
--  This source file may be used and distributed without
--  restriction provided that this copyright statement is not
--  removed from the file and that any derivative work contains
--  the original copyright notice and the associated disclaimer.
--

--******************************************************************************
--	File content description:
--	DataPath Blocks (DPB) of the SAYAC core                                 
--******************************************************************************

LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;
	
ENTITY COMP IS
	PORT (
		inCOMP  : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
		onebartwo : IN STD_LOGIC;
		outCOMP : OUT STD_LOGIC_VECTOR(15 DOWNTO 0)
	);
END ENTITY COMP;

ARCHITECTURE behaviour OF COMP IS
	SIGNAL carry  : STD_LOGIC_VECTOR(16 DOWNTO 1);
BEGIN
	-- Half Adder
	outCOMP(0) <= (NOT inCOMP(0)) XOR onebartwo;
	carry(1) <= (NOT inCOMP(0)) AND onebartwo;
	
	rest : FOR I IN 1 TO 15 GENERATE
			outCOMP(I) <= (NOT inCOMP(I)) XOR carry(I);
			carry(I+1) <= (NOT inCOMP(I)) AND carry(I);
	END GENERATE;
END ARCHITECTURE behaviour;
------------------------------------------------------------------------------------------------

LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;
	
ENTITY IMM IS
	PORT (
		in1, in2 : IN STD_LOGIC_VECTOR(7 DOWNTO 0);
		SE5bits, SE6bits, USE8bits, SE8bits, p1lowbits : IN STD_LOGIC;
		outIMM   : OUT STD_LOGIC_VECTOR(15 DOWNTO 0)		
	);
END ENTITY IMM;

ARCHITECTURE behaviour OF IMM IS
BEGIN
	outIMM <= (15 DOWNTO 5 => in1(4)) & in1(4 DOWNTO 0) WHEN SE5bits = '1' ELSE
			  (15 DOWNTO 6 => in1(5)) & in1(5 DOWNTO 0) WHEN SE6bits = '1' ELSE
			  (15 DOWNTO 8 => '0') & in1 WHEN USE8bits = '1' ELSE
			  (15 DOWNTO 8 => in1(7)) & in1 WHEN SE8bits = '1' ELSE
			  in1 & in2 WHEN p1lowbits = '1' ELSE 
			  (OTHERS => '0');
END ARCHITECTURE behaviour;
------------------------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;
	
ENTITY LLU IS
	PORT (
		in1, in2 : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
		logicAND, onesComp, twosComp : IN STD_LOGIC;
		outLLU  : OUT STD_LOGIC_VECTOR(15 DOWNTO 0)		
	);
END ENTITY LLU;

ARCHITECTURE behaviour OF LLU IS
	SIGNAL onebartwo : STD_LOGIC;
	SIGNAL outCOMP : STD_LOGIC_VECTOR(15 DOWNTO 0);
BEGIN
	onebartwo <= '0' WHEN onesComp = '1' ELSE
				 '1' WHEN twosComp = '1' ELSE '0';
				 
	COMPlementer : ENTITY WORK.COMP PORT MAP 
					(in1, onebartwo, outCOMP);
	
	outLLU <= (in1 AND in2) WHEN logicAND = '1' ELSE
			  outCOMP WHEN onesComp = '1' OR twosComp = '1' ELSE
--			  (NOT in1) WHEN onesComp = '1' ELSE
--			  STD_LOGIC_VECTOR(TO_UNSIGNED(TO_INTEGER(UNSIGNED(NOT in1)) + 1, 16))
--			  WHEN twosComp = '1' ELSE
			  (OTHERS => '0');
END ARCHITECTURE behaviour;
------------------------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;
	
ENTITY ASU IS
	PORT (
		in1, in2 : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
		arithADD, arithSUB : IN STD_LOGIC;
		outASU   : OUT STD_LOGIC_VECTOR(15 DOWNTO 0)		
	);
END ENTITY ASU;

ARCHITECTURE behaviour OF ASU IS
	-- SIGNAL cin : STD_LOGIC;
	-- SIGNAL input2 : STD_LOGIC_VECTOR(15 DOWNTO 0);
BEGIN
	-- cin <= '0' WHEN arithADD = '1' ELSE
		   -- '1' WHEN arithSUB = '1' ELSE '0';
	-- input2 <= in2 WHEN arithADD = '1' ELSE
			  -- (NOT in2) WHEN arithSUB = '1' ELSE 
			  -- (OTHERS => '0');
	
	-- ADD1 : ENTITY WORK.CLA PORT MAP 
			-- (in1, input2, cin, outASU);
	
	outASU <= STD_LOGIC_VECTOR(TO_UNSIGNED(TO_INTEGER(UNSIGNED(in1)) + 
			  TO_INTEGER(UNSIGNED(in2)), 16)) WHEN arithADD = '1' ELSE
			  STD_LOGIC_VECTOR(TO_UNSIGNED(TO_INTEGER(UNSIGNED(in1)) - 
			  TO_INTEGER(UNSIGNED(in2)), 16)) WHEN arithSUB = '1' ELSE 
			  (OTHERS => '0');
END ARCHITECTURE behaviour;
------------------------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;
	
ENTITY SHU IS
	PORT (
		in1     : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
		in2     : IN STD_LOGIC_VECTOR(4 DOWNTO 0);
		logicSH, arithSH : IN STD_LOGIC;
		outSHU : OUT STD_LOGIC_VECTOR(15 DOWNTO 0)		
	);
END ENTITY SHU;

ARCHITECTURE behavior OF SHU IS	
	SIGNAL	cases			:	STD_LOGIC_VECTOR(2 DOWNTO 0);
	SIGNAL	outSHU_reg		:	STD_LOGIC_VECTOR(16 DOWNTO 0);
	SIGNAL	right_SHU_reg	:	STD_LOGIC_VECTOR(16 DOWNTO 0);
	SIGNAL	left_SHU_reg	:	STD_LOGIC_VECTOR(16 DOWNTO 0);
	SIGNAL	ser				:	STD_LOGIC;
	ALIAS	shift_num		:	STD_LOGIC_VECTOR(3	DOWNTO	0)	IS	in2(3 DOWNTO 0);
BEGIN	
	cases	<=	(in2(4) & logicSH & arithSH);
	ser		<=	in1(15)	WHEN	arithSH = '1' ELSE '0';	

	-- outSHU_reg(15 DOWNTO	in2)		<= in1((15 - in2) DOWNTO 0);
	-- outSHU_reg((in2 - 1) DOWNTO 0)	<= (OTHERS => '0');
	
	PROCESS	(	in1, shift_num, ser	)
	BEGIN
		CASE	shift_num	IS
			WHEN	"0000"	=>
				right_SHU_reg(15 DOWNTO 0)	<=	in1(15 DOWNTO 0);
				right_SHU_reg(16)			<=	ser;
				
				left_SHU_reg(16) 			<=	'0';
				left_SHU_reg(15 DOWNTO 0)	<=	in1(15 DOWNTO 0);
			WHEN	"0001"	=>
				right_SHU_reg(14 DOWNTO 0)	<=	in1(15 DOWNTO 1);
				right_SHU_reg(16 DOWNTO 15)	<=	(OTHERS => ser);
				
				left_SHU_reg(16) 			<=	'0';
				left_SHU_reg(15 DOWNTO 1)	<=	in1(14 DOWNTO 0);
				left_SHU_reg(0)				<=	'0';
			WHEN	"0010"	=>
				right_SHU_reg(13 DOWNTO 0)	<=	in1(15 DOWNTO 2);
				right_SHU_reg(16 DOWNTO 14)	<=	(OTHERS => ser);
				
				left_SHU_reg(16) 			<=	'0';
				left_SHU_reg(15 DOWNTO 2)	<=	in1(13 DOWNTO 0);
				left_SHU_reg(1  DOWNTO 0)	<=	(OTHERS => '0');
			WHEN	"0011"	=>
				right_SHU_reg(12 DOWNTO 0)	<=	in1(15 DOWNTO 3);
				right_SHU_reg(16 DOWNTO 13)	<=	(OTHERS => ser);
				
				left_SHU_reg(16) 			<=	'0';
				left_SHU_reg(15 DOWNTO 3)	<=	in1(12 DOWNTO 0);
				left_SHU_reg(2  DOWNTO 0)	<=	(OTHERS => '0');
			WHEN	"0100"	=>
				right_SHU_reg(11 DOWNTO 0)	<=	in1(15 DOWNTO 4);
				right_SHU_reg(16 DOWNTO 12)	<=	(OTHERS => ser);
				
				left_SHU_reg(16) 			<=	'0';
				left_SHU_reg(15 DOWNTO 4)	<=	in1(11 DOWNTO 0);
				left_SHU_reg(3  DOWNTO 0)	<=	(OTHERS => '0');
			WHEN	"0101"	=>
				right_SHU_reg(10 DOWNTO 0)	<=	in1(15 DOWNTO 5);
				right_SHU_reg(16 DOWNTO 11)	<=	(OTHERS => ser);
				
				left_SHU_reg(16) 			<=	'0';
				left_SHU_reg(15 DOWNTO 5)	<=	in1(10 DOWNTO 0);
				left_SHU_reg(4  DOWNTO 0)	<=	(OTHERS => '0');
			WHEN	"0110"	=>
				right_SHU_reg(9	DOWNTO 0)	<=	in1(15 DOWNTO 6);
				right_SHU_reg(16 DOWNTO 10)	<=	(OTHERS => ser);
				
				left_SHU_reg(16) 			<=	'0';
				left_SHU_reg(15 DOWNTO 6)	<=	in1(9 DOWNTO 0);
				left_SHU_reg(5  DOWNTO 0)	<=	(OTHERS => '0');
			WHEN	"0111"	=>
				right_SHU_reg(8	DOWNTO 0)	<=	in1(15 DOWNTO 7);
				right_SHU_reg(16 DOWNTO 9)	<=	(OTHERS => ser);
				
				left_SHU_reg(16) 			<=	'0';
				left_SHU_reg(15 DOWNTO 7)	<=	in1(8 DOWNTO 0);
				left_SHU_reg(6  DOWNTO 0)	<=	(OTHERS => '0');
			WHEN	"1000"	=>
				right_SHU_reg(7	DOWNTO 0)	<=	in1(15 DOWNTO 8);
				right_SHU_reg(16 DOWNTO 8)	<=	(OTHERS => ser);
				
				left_SHU_reg(16) 			<=	'0';
				left_SHU_reg(15 DOWNTO 8)	<=	in1(7 DOWNTO 0);
				left_SHU_reg(7  DOWNTO 0)	<=	(OTHERS => '0');
			WHEN	"1001"	=>
				right_SHU_reg(6	DOWNTO 0)	<=	in1(15 DOWNTO 9);
				right_SHU_reg(16 DOWNTO 7)	<=	(OTHERS => ser);
				
				left_SHU_reg(16) 			<=	'0';
				left_SHU_reg(15 DOWNTO 9)	<=	in1(6 DOWNTO 0);
				left_SHU_reg(8  DOWNTO 0)	<=	(OTHERS => '0');
			WHEN	"1010"	=>
				right_SHU_reg(5	DOWNTO 0)	<=	in1(15 DOWNTO 10);
				right_SHU_reg(16 DOWNTO 6)	<=	(OTHERS => ser);
				
				left_SHU_reg(16) 			<=	'0';
				left_SHU_reg(15 DOWNTO 10)	<=	in1(5 DOWNTO 0);
				left_SHU_reg(9  DOWNTO 0)	<=	(OTHERS => '0');
			WHEN	"1011"	=>
				right_SHU_reg(4	DOWNTO 0)	<=	in1(15 DOWNTO 11);
				right_SHU_reg(16 DOWNTO 5)	<=	(OTHERS => ser);
				
				left_SHU_reg(16) 			<=	'0';
				left_SHU_reg(15 DOWNTO 11)	<=	in1(4 DOWNTO 0);
				left_SHU_reg(10  DOWNTO 0)	<=	(OTHERS => '0');
			WHEN	"1100"	=>
				right_SHU_reg(3	DOWNTO 0)	<=	in1(15 DOWNTO 12);
				right_SHU_reg(16 DOWNTO 4)	<=	(OTHERS => ser);
				
				left_SHU_reg(16) 			<=	'0';
				left_SHU_reg(15 DOWNTO 12)	<=	in1(3 DOWNTO 0);
				left_SHU_reg(11  DOWNTO 0)	<=	(OTHERS => '0');
			WHEN	"1101"	=>
				right_SHU_reg(2	DOWNTO 0)	<=	in1(15 DOWNTO 13);
				right_SHU_reg(16 DOWNTO 3)	<=	(OTHERS => ser);
				
				left_SHU_reg(16) 			<=	'0';
				left_SHU_reg(15 DOWNTO 13)	<=	in1(2 DOWNTO 0);
				left_SHU_reg(12  DOWNTO 0)	<=	(OTHERS => '0');
			WHEN	"1110"	=>
				right_SHU_reg(1	DOWNTO 0)	<=	in1(15 DOWNTO 14);
				right_SHU_reg(16 DOWNTO 2)	<=	(OTHERS => ser);
				
				left_SHU_reg(16) 			<=	'0';
				left_SHU_reg(15 DOWNTO 14)	<=	in1(1 DOWNTO 0);
				left_SHU_reg(13  DOWNTO 0)	<=	(OTHERS => '0');
			WHEN	"1111"	=>
				right_SHU_reg(0)			<=	in1(15);
				right_SHU_reg(16 DOWNTO 1)	<=	(OTHERS => ser);
				
				left_SHU_reg(16) 			<=	'0';
				left_SHU_reg(15)			<=	in1(0);
				left_SHU_reg(14  DOWNTO 0)	<=	(OTHERS => '0');
			WHEN	OTHERS	=>
			
		END CASE;
	END PROCESS;
	
--	PROCESS (in2, logicSH, arithSH, cases, in1)
	PROCESS (right_SHU_reg, cases, left_SHU_reg)
	BEGIN		
		CASE cases IS
			WHEN "001" =>						-- arithmetic right shift
				outSHU_reg	<=	right_SHU_reg;
			WHEN "010" =>						-- logical right shift
				outSHU_reg	<=	right_SHU_reg;
			WHEN "101" =>						-- arithmetic left shift
				outSHU_reg	<=	left_SHU_reg;
			WHEN "110" =>						-- logic left shift
				outSHU_reg	<=	left_SHU_reg;
			WHEN OTHERS =>
				outSHU_reg <=  (OTHERS => '0');
		END CASE;
	END PROCESS;
	
	outSHU <= outSHU_reg(15 DOWNTO 0);
END ARCHITECTURE behavior;
------------------------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;
	
ENTITY MDU IS
	PORT (
		clk, rst, startMDU, arithMUL, arithDIV, ldMDU1, ldMDU2 : IN STD_LOGIC;
		in1, in2          : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
		outMDU1, outMDU2  : OUT STD_LOGIC_VECTOR(15 DOWNTO 0);
		readyMDU          : OUT STD_LOGIC
	);
END ENTITY MDU;

ARCHITECTURE behaviour OF MDU IS
	SIGNAL outMDU_reg, outMULT : STD_LOGIC_VECTOR(31 DOWNTO 0);
	SIGNAL busyMULT : STD_LOGIC;
BEGIN
	-- MUT : ENTITY WORK.Radix4 
		-- PORT MAP (clk, rst, startMDU, '0', in1, in2, busyMULT, outMULT);
	
	-- outMDU_reg <= STD_LOGIC_VECTOR(TO_UNSIGNED(TO_INTEGER(UNSIGNED(in1)) *
				  -- TO_INTEGER(UNSIGNED(in2)), 32)) WHEN startMDU = '1' AND arithMUL = '1' ELSE
				  -- STD_LOGIC_VECTOR(TO_UNSIGNED(TO_INTEGER(UNSIGNED(in1)) /
				  -- TO_INTEGER(UNSIGNED(in2)), 32)) WHEN startMDU = '1' AND arithDIV = '1';
	
	-- outMDU_reg <= outMULT WHEN arithMUL = '1' ELSE
	outMDU_reg <= STD_LOGIC_VECTOR(TO_UNSIGNED(TO_INTEGER(UNSIGNED(in1)) *
				  TO_INTEGER(UNSIGNED(in2)), 32)) WHEN arithMUL = '1' ELSE
				  (STD_LOGIC_VECTOR(TO_UNSIGNED(TO_INTEGER(UNSIGNED(in1)) REM
			TO_INTEGER(UNSIGNED(in2)), 16)) & STD_LOGIC_VECTOR(TO_UNSIGNED(TO_INTEGER(UNSIGNED(in1)) /
			TO_INTEGER(UNSIGNED(in2)), 16))) WHEN startMDU = '1' AND arithDIV = '1' ELSE 
			(OTHERS => '0');
	
--	readyMDU <= NOT busyMULT;
	-- readyMDU <= (arithMUL AND (NOT busyMULT)) OR arithDIV;
	readyMDU <= arithMUL OR arithDIV;
	
	PROCESS (clk, rst)
	BEGIN
		IF rst = '1' THEN
			outMDU1 <= (OTHERS => '0');
		ELSIF clk = '1' AND clk'EVENT THEN
			IF ldMDU1 = '1' THEN
				outMDU1 <= outMDU_reg(15 DOWNTO 0);
			END IF;
		END IF;
	END PROCESS;
	
	PROCESS (clk, rst)
	BEGIN
		IF rst = '1' THEN
			outMDU2 <= (OTHERS => '0');
		ELSIF clk = '1' AND clk'EVENT THEN
			IF ldMDU2 = '1' THEN
				outMDU2 <= outMDU_reg(31 DOWNTO 16);
			END IF;
		END IF;
	END PROCESS;
END ARCHITECTURE behaviour;
------------------------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;
	
ENTITY CMP IS
	PORT (
		in1, in2 : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
		eq, gt   : OUT STD_LOGIC	
	);
END ENTITY CMP;

ARCHITECTURE behaviour OF CMP IS
BEGIN
	-- eq <= '1' WHEN TO_INTEGER(UNSIGNED(in2)) = TO_INTEGER(UNSIGNED(in1)) ELSE '0';
	-- gt <= '1' WHEN TO_INTEGER(UNSIGNED(in2)) > TO_INTEGER(UNSIGNED(in1)) ELSE '0';	
	
	PROCESS (in1, in2)
	BEGIN
		IF TO_INTEGER(UNSIGNED(in2)) = TO_INTEGER(UNSIGNED(in1)) THEN
			eq <= '1';		gt <= '0';
		ELSIF TO_INTEGER(UNSIGNED(in2)) > TO_INTEGER(UNSIGNED(in1)) THEN
			gt <= '1';		eq <= '0';
		ELSE
			gt <= '0';		eq <= '0';
		END IF;
	END PROCESS;
END ARCHITECTURE behaviour;
------------------------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;
	
ENTITY ADD IS
	GENERIC ( 
		n : INTEGER := 16
	);
	PORT (
		in1, in2 : IN STD_LOGIC_VECTOR(n-1 DOWNTO 0);
		outADD   : OUT STD_LOGIC_VECTOR(n-1 DOWNTO 0)
	);
END ENTITY ADD;

ARCHITECTURE behaviour OF ADD IS
BEGIN
	outADD <= STD_LOGIC_VECTOR(TO_UNSIGNED(TO_INTEGER(UNSIGNED(in1)) +
			  TO_INTEGER(UNSIGNED(in2)), n));
			  
	-- ADD1 : ENTITY WORK.CLA PORT MAP 
			-- (in1, in2, '0', outADD);
END ARCHITECTURE behaviour;
------------------------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;
	
ENTITY MUX2ofnbits IS
	GENERIC (
		n : INTEGER := 16	-- number of input bits
	);
	PORT (
		in1, in2   : IN STD_LOGIC_VECTOR(n-1 DOWNTO 0);
		sel1, sel2 : IN STD_LOGIC;
		outMUX     : OUT STD_LOGIC_VECTOR(n-1 DOWNTO 0)
	);
END ENTITY MUX2ofnbits;

ARCHITECTURE behaviour OF MUX2ofnbits IS
BEGIN
	outMUX <= in1 WHEN sel1 = '1' ELSE
			  in2 WHEN sel2 = '1' ELSE 
			  (OTHERS => '0');
END ARCHITECTURE behaviour;
------------------------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;
	
ENTITY MUX8of16bits IS
	PORT (
		in1, in2, in3, in4 : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
		in5, in6, in7, in8 : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
		sel1, sel2, sel3, sel4, sel5, sel6, sel7, sel8 : IN STD_LOGIC;
		outMUX             : OUT STD_LOGIC_VECTOR(15 DOWNTO 0)
	);
END ENTITY MUX8of16bits;

ARCHITECTURE behaviour OF MUX8of16bits IS
BEGIN
	outMUX <= in1 WHEN sel1 = '1' ELSE
			  in2 WHEN sel2 = '1' ELSE 
			  in3 WHEN sel3 = '1' ELSE 
			  in4 WHEN sel4 = '1' ELSE 
			  in5 WHEN sel5 = '1' ELSE 
			  in6 WHEN sel6 = '1' ELSE 
			  in7 WHEN sel7 = '1' ELSE 
			  in8 WHEN sel8 = '1' ELSE 
			  (OTHERS => '0');
END ARCHITECTURE behaviour;
------------------------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;
	
ENTITY MUX3of16bits IS
	PORT (
		in1, in2, in3    : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
		sel1, sel2, sel3 : IN STD_LOGIC;
		outMUX           : OUT STD_LOGIC_VECTOR(15 DOWNTO 0)
	);
END ENTITY MUX3of16bits;

ARCHITECTURE behaviour OF MUX3of16bits IS
BEGIN
	outMUX <= in1 WHEN sel1 = '1' ELSE
			  in2 WHEN sel2 = '1' ELSE 
			  in3 WHEN sel3 = '1' ELSE 
			  (OTHERS => '0');
END ARCHITECTURE behaviour;
------------------------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;
	
ENTITY INC IS
	GENERIC (
		n : INTEGER := 16	-- number of input bits
	);
	PORT (
		inINC  : IN STD_LOGIC_VECTOR(n-1 DOWNTO 0);
		outINC : OUT STD_LOGIC_VECTOR(n-1 DOWNTO 0)
	);
END ENTITY INC;

ARCHITECTURE behaviour OF INC IS
	SIGNAL carry  : STD_LOGIC_VECTOR(n DOWNTO 1);
BEGIN
	-- Half Adder
	outINC(0) <= inINC(0) XOR '1';
	carry(1) <= inINC(0) AND '1';
	
	rest : FOR I IN 1 TO n-1 GENERATE
			outINC(I) <= inINC(I) XOR carry(I);
			carry(I+1) <= inINC(I) AND carry(I);
	END GENERATE;
END ARCHITECTURE behaviour;
------------------------------------------------------------------------------------------------

LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;
	
ENTITY REG IS
	PORT (
		clk, rst, ld : IN STD_LOGIC;
		inREG        : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
		outREG       : OUT STD_LOGIC_VECTOR(15 DOWNTO 0)
	);
END ENTITY REG;

ARCHITECTURE behaviour OF REG IS
BEGIN
	PROCESS (clk, rst)
	BEGIN
		IF rst = '1' THEN
			outREG <= (OTHERS => '0');
		ELSIF clk = '1' AND clk'EVENT THEN
			IF ld = '1' THEN
				outREG <= inREG;
			END IF;
		END IF;
	END PROCESS;
END ARCHITECTURE behaviour;
------------------------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
ENTITY test_IMM IS
END ENTITY test_IMM;
ARCHITECTURE test OF test_IMM IS
	SIGNAL in1, in2 : STD_LOGIC_VECTOR(7 DOWNTO 0);
	SIGNAL SE5bits, SE6bits, USE8bits, SE8bits, p1lowbits : STD_LOGIC;
	SIGNAL outIMM   : STD_LOGIC_VECTOR(15 DOWNTO 0);
BEGIN
	SE5bits <= '0', '1' AFTER 1 NS, '0' AFTER 2 NS;
	SE6bits <= '0', '1' AFTER 2 NS, '0' AFTER 3 NS;
	USE8bits <= '0', '1' AFTER 3 NS, '0' AFTER 4 NS;
	SE8bits <= '0', '1' AFTER 4 NS, '0' AFTER 5 NS;
	p1lowbits <= '0', '1' AFTER 5 NS, '0' AFTER 6 NS;
	in1 <= X"30", X"0A" AFTER 8 NS, X"E2" AFTER 12 NS;
	in2 <= X"F7", X"1C" AFTER 7 NS, X"6B" AFTER 10 NS;
	
	ImmediateUnit : ENTITY WORK.IMM PORT MAP 
						(in1, in2, SE5bits, SE6bits, USE8bits, 
						SE8bits, p1lowbits, outIMM);
END ARCHITECTURE test;
------------------------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
ENTITY test_LLU IS
END ENTITY test_LLU;
ARCHITECTURE test OF test_LLU IS
	SIGNAL in1, in2 : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL logicAND, onesComp, twosComp : STD_LOGIC;
	SIGNAL outLLU   : STD_LOGIC_VECTOR(15 DOWNTO 0);
BEGIN
	logicAND <= '0', '1' AFTER 1 NS, '0' AFTER 2 NS;
	onesComp <= '0', '1' AFTER 3 NS, '0' AFTER 4 NS;
	twosComp <= '0', '1' AFTER 5 NS, '0' AFTER 6 NS;
	in1 <= X"2019", X"0A01" AFTER 2 NS, X"F204" AFTER 5 NS;
	in2 <= X"2042", X"0A35" AFTER 3 NS, X"F275" AFTER 4 NS;
	
	LogicLogicUnit : ENTITY WORK.LLU PORT MAP 
						(in1, in2, logicAND, onesComp, twosComp, outLLU);
END ARCHITECTURE test;
------------------------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
ENTITY test_ASU IS
END ENTITY test_ASU;
ARCHITECTURE test OF test_ASU IS
	SIGNAL in1, in2 : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL arithADD, arithSUB : STD_LOGIC;
	SIGNAL outASU   : STD_LOGIC_VECTOR(15 DOWNTO 0);
BEGIN
	arithADD <= '1', '0' AFTER 2 NS;
	arithSUB <= '0', '1' AFTER 3 NS, '0' AFTER 6 NS;
	in1 <= X"2019", X"8A01" AFTER 1 NS, X"0A01" AFTER 2 NS, X"F204" AFTER 5 NS;
	in2 <= X"2042", X"0A35" AFTER 3 NS, X"F275" AFTER 4 NS;
	
	AddSubUnit : ENTITY WORK.ASU PORT MAP 
					(in1, in2, arithADD, arithSUB, outASU);
END ARCHITECTURE test;
------------------------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
ENTITY test_SHU IS
END ENTITY test_SHU;
ARCHITECTURE test OF test_SHU IS
	SIGNAL in1    : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL in2    : STD_LOGIC_VECTOR(4 DOWNTO 0);
	SIGNAL logicSH, arithSH : STD_LOGIC;
	SIGNAL outSHU : STD_LOGIC_VECTOR(15 DOWNTO 0);
BEGIN
	logicSH <= '1', '0' AFTER 1 NS, '1' AFTER 5 NS;
	arithSH <= '0', '1' AFTER 2 NS, '0' AFTER 4 NS;
	in1 <= X"2E18", X"8AB1" AFTER 4 NS, X"2AB1" AFTER 7 NS;
	in2 <= "00100", "10110" AFTER 3 NS, "10111" AFTER 6 NS;
	
	SHiftUnit : ENTITY WORK.SHU PORT MAP 
					(in1, in2, logicSH, arithSH, outSHU);
END ARCHITECTURE test;
------------------------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
ENTITY test_MDU IS
END ENTITY test_MDU;
ARCHITECTURE test OF test_MDU IS
	SIGNAL clk : STD_LOGIC := '0';
	SIGNAL rst, startMDU, arithMUL, arithDIV, ldMDU1, ldMDU2, readyMDU : STD_LOGIC;
	SIGNAL in1, in2         : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL outMDU1, outMDU2 : STD_LOGIC_VECTOR(15 DOWNTO 0);
BEGIN
	clk <= NOT clk AFTER 5 NS WHEN NOW <= 140 NS ELSE '0';
	rst <= '1', '0' AFTER 1 NS;
	startMDU <= '0', '1' AFTER 1 NS, '0' AFTER 13 NS, '1' AFTER 14 NS;
	arithMUL <= '0', '1' AFTER 4 NS, '0' AFTER 88 NS;
	arithDIV <= '0', '1' AFTER 102 NS;
	ldMDU1 <= '1', '0' AFTER 27 NS, '1' AFTER 84 NS, '0' AFTER 88 NS, '1' AFTER 105 NS, '0' AFTER 108 NS;
	ldMDU2 <= '0', '1' AFTER 95 NS, '0' AFTER 97 NS, '1' AFTER 115 NS, '0' AFTER 117 NS, '1' AFTER 125 NS, '0' AFTER 128 NS;
	in1 <= X"0001", X"0019" AFTER 2 NS, X"0A01" AFTER 100 NS, X"F204" AFTER 104 NS;
	in2 <= X"0001", X"0005" AFTER 3 NS, X"FFFE" AFTER 106 NS;
	
	MultDivUnit : ENTITY WORK.MDU PORT MAP 
					(clk, rst, startMDU, arithMUL, arithDIV, ldMDU1, 
					ldMDU2, in1, in2, outMDU1, outMDU2, readyMDU);
END ARCHITECTURE test;
------------------------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
ENTITY test_CMP IS
END ENTITY test_CMP;
ARCHITECTURE test OF test_CMP IS
	SIGNAL in1, in2   : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL eq, gt : STD_LOGIC;
BEGIN
	in1 <= X"0000", X"0019" AFTER 2 NS, X"FFF1" AFTER 5 NS, X"FEFE" AFTER 8 NS;
	in2 <= X"0000", X"0042" AFTER 3 NS, X"FFE2" AFTER 6 NS;
	
	ComparatorUnit : ENTITY WORK.CMP PORT MAP 
						(in1, in2, eq, gt);
END ARCHITECTURE test;
------------------------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
ENTITY test_INC IS
END ENTITY test_INC;
ARCHITECTURE test OF test_INC IS
	SIGNAL inINC  : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL outINC : STD_LOGIC_VECTOR(15 DOWNTO 0);
BEGIN
	inINC <= X"2E18", X"8AB1" AFTER 4 NS, X"2AB1" AFTER 7 NS;
	
	INCrementer : ENTITY WORK.INC PORT MAP 
					(inINC, outINC);
END ARCHITECTURE test;
------------------------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
ENTITY test_COMP IS
END ENTITY test_COMP;
ARCHITECTURE test OF test_COMP IS
	SIGNAL inCOMP  : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL onebartwo : STD_LOGIC;
	SIGNAL outCOMP : STD_LOGIC_VECTOR(15 DOWNTO 0);
BEGIN
	inCOMP <= X"2E18", X"8AB1" AFTER 4 NS, X"2AB1" AFTER 7 NS;
	onebartwo <= '0', '1' AFTER 3 NS, '0' AFTER 5 NS;
	
	COMPlementer : ENTITY WORK.COMP PORT MAP 
					(inCOMP, onebartwo, outCOMP);
END ARCHITECTURE test;
--******************************************************************************
--	Filename:		SAYAC_DPU.vhd
--	Project:		SAYAC : Simple Architecture Yet Ample Circuitry
--  Version:		0.990
--	History:
--	Date:			18 June 2021
--	Last Author: 	HANIEH
--  Copyright (C) 2021 University of Tehran
--  This source file may be used and distributed without
--  restriction provided that this copyright statement is not
--  removed from the file and that any derivative work contains
--  the original copyright notice and the associated disclaimer.
--

--******************************************************************************
--	File content description:
--	DataPath Unit (DPU) of the SAYAC core                                 
--******************************************************************************

LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;
	
ENTITY DPU IS
	PORT (
		clk, rst : IN STD_LOGIC;
		seldataBus_TRF, selPC1_TRF, selLLU_TRF, selSHU_TRF, 
		selASU_TRF, selMDU1_TRF, selMDU2_TRF, selIMM_TRF,
        selrs1_TRF, selrd_1_TRF, selrs2_TRF, selrd_2_TRF, selrd0_TRF,
		selrd1_TRF, writeTRF, selp1_PCP, selimm_PCP, 
        selp1_PC, selPCadd_PC, selPC1_PC, selPC_MEM, selADR_MEM,
        driveDataBus, SE5bits, SE6bits, USE8bits, SE8bits, p1lowbits,
        selp2_ASU, selimm_ASU, arithADD, arithSUB,
        logicAND, onesComp, twosComp,
        selp2_SHU, selshim_SHU, logicSH, arithSH,
        ldMDU1, ldMDU2, arithMUL, arithDIV, startMDU,
        ldIR, ldADR, ldPC : IN STD_LOGIC;
		readyMDU : OUT STD_LOGIC;
		opcode  : OUT  STD_LOGIC_VECTOR(7 DOWNTO 0);
		FIB	    : OUT  STD_LOGIC_VECTOR(4 DOWNTO 0);
		setFlags, enFlag : IN STD_LOGIC;
		selFlag : IN STD_LOGIC_VECTOR(7 DOWNTO 0);
		outFlag : OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
		dataBusIn : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
		addrBus, dataBusOut : OUT STD_LOGIC_VECTOR(15 DOWNTO 0)
	);
END ENTITY DPU;

ARCHITECTURE behaviour OF DPU IS
	SIGNAL inDataTRF, p1, p2  			  : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL outMDU1, outMDU2, outASU       : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL outLLU, outSHU, outPC1, outIMM : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL Instruction   				  : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL outPCP, outPC, outADR 	      : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL outMuxPCP, outMuxPC, outMuxASU : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL outMuxSHU 				      : STD_LOGIC_VECTOR(4 DOWNTO 0);
	SIGNAL outrd1, rs1, rs2, rd           : STD_LOGIC_VECTOR(3 DOWNTO 0);
	SIGNAL outMuxrs1, outMuxrs2, outMuxrd : STD_LOGIC_VECTOR(3 DOWNTO 0);
	SIGNAL inFlag						  : STD_LOGIC_VECTOR(7 DOWNTO 0);
	SIGNAL gt, eq : STD_LOGIC;
BEGIN
	rs1 <= Instruction(7 DOWNTO 4);
	rs2 <= Instruction(11 DOWNTO 8);
	rd  <= Instruction(3 DOWNTO 0);

	dataBusOut <= (OTHERS => 'Z') WHEN driveDataBus = '0' ELSE p1;
	
	-- rd1 : ENTITY WORK.ADD GENERIC MAP ( 4 )
			-- PORT MAP (rd, "0001", outrd1);
	rd1 : ENTITY WORK.INC GENERIC MAP ( 4 )
			PORT MAP (rd, outrd1);
		
	muxrd : ENTITY WORK.MUX2ofnbits GENERIC MAP ( 4 )
				PORT MAP (rd, outrd1, selrd0_TRF, selrd1_TRF, outMuxrd);
		
	muxrs1 : ENTITY WORK.MUX2ofnbits GENERIC MAP ( 4 )
				PORT MAP (rs1, rd, selrs1_TRF, selrd_1_TRF, outMuxrs1);
				  
	muxrs2 : ENTITY WORK.MUX2ofnbits GENERIC MAP ( 4 )
				PORT MAP (rs2, rd, selrs2_TRF, selrd_2_TRF, outMuxrs2);
		
	muxinDataTRF : ENTITY WORK.MUX8of16bits PORT MAP 
						(outIMM, outMDU1, outMDU2, outASU, outLLU, outSHU, 
						dataBusIn, outPC1, selIMM_TRF, selMDU1_TRF, selMDU2_TRF, 
						selASU_TRF,	selLLU_TRF, selSHU_TRF, seldataBus_TRF, 
						selPC1_TRF,	inDataTRF);
						
	TheRegisterFile : ENTITY WORK.TRF PORT MAP 
						(clk, rst, writeTRF, setFlags, enFlag, outMuxrs1, 
						outMuxrs2, outMuxrd, selFlag, inFlag, outFlag, 
						inDataTRF, p1, p2);
	
	
	opcode <= Instruction(15 DOWNTO 8);
	FIB    <= Instruction(8 DOWNTO 4);
--	inFlag <= (i & x & gt & eq & i_en & x_en & i_mask & x_mask);
	inFlag <= ('0' & '0' & gt & eq & '0' & '0' & '0' & '0');
	
	IR : ENTITY WORK.REG PORT MAP 
			(clk, rst, ldIR, dataBusIn, Instruction);
	
	ImmediateUnit : ENTITY WORK.IMM PORT MAP 
						(Instruction(11 DOWNTO 4), p1(7 DOWNTO 0), SE5bits, SE6bits,
						USE8bits, SE8bits, p1lowbits, outIMM);
	
	muxPCP : ENTITY WORK.MUX2ofnbits GENERIC MAP ( 16 )
				PORT MAP (p1, outIMM, selp1_PCP, selimm_PCP, outMuxPCP);
	
	PCP : ENTITY WORK.ADD GENERIC MAP ( 16 )
				PORT MAP (outMuxPCP, outPC, outPCP);
	
	muxPC : ENTITY WORK.MUX3of16bits PORT MAP 
				(p1, outPCP, outPC1, selp1_PC, selPCAdd_PC, 
				selPC1_PC, outMuxPC);
	
	PC : ENTITY WORK.REG PORT MAP 
			(clk, rst, ldPC, outMuxPC, outPC);
	
--	PC1 : ENTITY WORK.ADD GENERIC MAP ( 16 )
--			PORT MAP (outPC, X"0001", outPC1);
	PC1 : ENTITY WORK.INC GENERIC MAP ( 16 )
			PORT MAP (outPC, outPC1);
	
	ADR : ENTITY WORK.REG PORT MAP 
			(clk, rst, ldADR, outMuxPCP, outADR);
			
	muxMEM : ENTITY WORK.MUX2ofnbits GENERIC MAP ( 16 )
				PORT MAP (outADR, outPC, selADR_MEM, selPC_MEM, addrBus);
	
	
	MultDivUnit : ENTITY WORK.MDU PORT MAP 
					(clk, rst, startMDU, arithMUL, arithDIV, ldMDU1, ldMDU2, p1, p2,
					outMDU1, outMDU2, readyMDU);
	
	muxASU : ENTITY WORK.MUX2ofnbits GENERIC MAP ( 16 )
				PORT MAP (p2, outIMM, selp2_ASU, selimm_ASU, outMuxASU);
	
	ComparatorUnit : ENTITY WORK.CMP PORT MAP 
						(p1, outMuxASU, eq, gt);
	
	AddSubUnit : ENTITY WORK.ASU PORT MAP 
					(p1, outMuxASU, arithADD, arithSUB, outASU);
	
	LogicLogicUnit : ENTITY WORK.LLU PORT MAP 
						(p1, outMuxASU, logicAND, onesComp, twosComp, outLLU);
	
	
	muxSHU : ENTITY WORK.MUX2ofnbits GENERIC MAP ( 5 )
		PORT MAP (p2(4 DOWNTO 0), Instruction(8 DOWNTO 4), selp2_SHU, 
				 selshim_SHU, outMuxSHU);
	
	ShiftUnit : ENTITY WORK.SHU PORT MAP 
					(p1, outMuxSHU, logicSH, arithSH, outSHU);
END ARCHITECTURE behaviour;

--******************************************************************************
--	Filename:		SAYAC_CCU.vhd
--	Project:		SAYAC : Simple Architecture Yet Ample Circuitry
--  Version:		0.990
--	History:
--	Date:			18 June 2021
--	Last Author: 	HANIEH
--  Copyright (C) 2021 University of Tehran
--  This source file may be used and distributed without
--  restriction provided that this copyright statement is not
--  removed from the file and that any derivative work contains
--  the original copyright notice and the associated disclaimer.
--

--******************************************************************************
--	File content description:
--	Control Control Unit (CCU) of the SAYAC core                                 
--******************************************************************************

LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;
	
	
ENTITY CCU IS
	PORT (
		clk, rst, readyMEM, readyMDU : IN STD_LOGIC;
		opcode   : IN STD_LOGIC_VECTOR(7 DOWNTO 0);
		FIB      : IN STD_LOGIC_VECTOR(4 DOWNTO 0);  --FLags Intrepretation Bits
	    seldataBus_TRF, selPC1_TRF, selLLU_TRF, selSHU_TRF, 
		selASU_TRF, selMDU1_TRF, selMDU2_TRF, selIMM_TRF,
        selrs1_TRF, selrd_1_TRF, selrs2_TRF, selrd_2_TRF, selrd0_TRF, 
		selrd1_TRF, writeTRF, selp1_PCP, selimm_PCP, 
        selp1_PC, selPCadd_PC, selPC1_PC,
        selPC_MEM, selADR_MEM, driveDataBus,
        SE5bits, SE6bits, USE8bits, SE8bits, p1lowbits,
        selp2_ASU, selimm_ASU, arithADD, arithSUB,
        logicAND, onesComp, twosComp,
        selp2_SHU, selshim_SHU, logicSH, arithSH,
        ldMDU1, ldMDU2, arithMUL, arithDIV, startMDU,
        ldIR, ldADR, ldPC,
        readMEM, writeMEM, readIO, writeIO,
		setFlags, enFlag : OUT STD_LOGIC;
		outFlag  : IN STD_LOGIC_VECTOR(7 DOWNTO 0);
		selFlag  : OUT STD_LOGIC_VECTOR(7 DOWNTO 0)
	);
END ENTITY CCU;

ARCHITECTURE behaviour OF CCU IS
	CONSTANT RSV1   : STD_LOGIC_VECTOR(3 DOWNTO 0) := "0000";
	CONSTANT RSV2   : STD_LOGIC_VECTOR(3 DOWNTO 0) := "0001";
	CONSTANT INST2  : STD_LOGIC_VECTOR(3 DOWNTO 0) := "0010";
	CONSTANT LDR    : STD_LOGIC_VECTOR(1 DOWNTO 0) := "00";
	CONSTANT STR    : STD_LOGIC_VECTOR(1 DOWNTO 0) := "01";
	CONSTANT JMR    : STD_LOGIC_VECTOR(1 DOWNTO 0) := "10";
	CONSTANT JMI    : STD_LOGIC_VECTOR(1 DOWNTO 0) := "11";
	CONSTANT ANR    : STD_LOGIC_VECTOR(3 DOWNTO 0) := "0011";
	CONSTANT ANI    : STD_LOGIC_VECTOR(3 DOWNTO 0) := "0100";
	CONSTANT MSI    : STD_LOGIC_VECTOR(3 DOWNTO 0) := "0101";
	CONSTANT MHI    : STD_LOGIC_VECTOR(3 DOWNTO 0) := "0110";
	CONSTANT SLR    : STD_LOGIC_VECTOR(3 DOWNTO 0) := "0111";
	CONSTANT SAR    : STD_LOGIC_VECTOR(3 DOWNTO 0) := "1000";
	CONSTANT ADR    : STD_LOGIC_VECTOR(3 DOWNTO 0) := "1001";
	CONSTANT SUR    : STD_LOGIC_VECTOR(3 DOWNTO 0) := "1010";
	CONSTANT ADI    : STD_LOGIC_VECTOR(3 DOWNTO 0) := "1011";
	CONSTANT SUI    : STD_LOGIC_VECTOR(3 DOWNTO 0) := "1100";
	CONSTANT MUL    : STD_LOGIC_VECTOR(3 DOWNTO 0) := "1101";
	CONSTANT DIV    : STD_LOGIC_VECTOR(3 DOWNTO 0) := "1110";
	CONSTANT INST15 : STD_LOGIC_VECTOR(3 DOWNTO 0) := "1111";
	CONSTANT CMR    : STD_LOGIC_VECTOR(2 DOWNTO 0) := "000";
	CONSTANT CMI    : STD_LOGIC_VECTOR(2 DOWNTO 0) := "001";
	CONSTANT BRC    : STD_LOGIC_VECTOR(2 DOWNTO 0) := "010";
	CONSTANT BRR    : STD_LOGIC_VECTOR(2 DOWNTO 0) := "011";
	CONSTANT SHI    : STD_LOGIC_VECTOR(5 DOWNTO 0) := "111110";
	CONSTANT NTR    : STD_LOGIC_VECTOR(2 DOWNTO 0) := "110";
	CONSTANT NTD    : STD_LOGIC_VECTOR(2 DOWNTO 0) := "111";
	
	TYPE state IS (fetch, exec1, exec2, exec3);
	SIGNAL pstate, nstate : state := fetch;
	
	ALIAS opcode7downto4 : STD_LOGIC_VECTOR(3 DOWNTO 0) IS opcode(7 DOWNTO 4);
	ALIAS opcode3downto2 : STD_LOGIC_VECTOR(1 DOWNTO 0) IS opcode(3 DOWNTO 2);
	ALIAS opcode3downto1 : STD_LOGIC_VECTOR(2 DOWNTO 0) IS opcode(3 DOWNTO 1);
	
	ALIAS RFI : STD_LOGIC_VECTOR(2 DOWNTO 0) IS FIB(2 DOWNTO 0);
BEGIN	
	-- Issuing control signals
	PROCESS (pstate, readyMEM, readyMDU, opcode, FIB, outFlag)
	BEGIN
		seldataBus_TRF <= '0';	selPC1_TRF <= '0';		selLLU_TRF <= '0'; 
		selSHU_TRF <= '0';	    selASU_TRF <= '0';		selMDU1_TRF <= '0'; 
		selMDU2_TRF <= '0';	    selIMM_TRF <= '0';		selrs1_TRF <= '0';	    
		selrd_1_TRF <= '0';		selrd0_TRF <= '0';		selrd1_TRF <= '0';	    
		writeTRF <= '0';		selp1_PCP <= '0';		selimm_PCP <= '0';	
		selp1_PC <= '0';		selPCadd_PC <= '0';		selPC1_PC <= '0';       
		selPC_MEM <= '0';		selADR_MEM <= '0';	    SE5bits <= '0';			
		SE6bits <= '0';			USE8bits <= '0';		SE8bits <= '0';			
		p1lowbits <= '0';		selp2_ASU <= '0';		selimm_ASU <= '0';		
		arithADD <= '0';		arithSUB <= '0';        logicAND <= '0';		
		onesComp <= '0';		twosComp <= '0';        selp2_SHU <= '0';		
		selshim_SHU <= '0';		logicSH <= '0';			arithSH <= '0';
		ldMDU1 <= '0';			ldMDU2 <= '0';			arithMUL <= '0';
		arithDIV <= '0';		startMDU <= '0';        ldIR <= '0';
		ldADR <= '0';			ldPC <= '0';	        readMEM <= '0';
		writeMEM <= '0';		readIO <= '0';			writeIO <= '0';		
		selrd_2_TRF <= '0';		selrs2_TRF <= '0';		driveDataBus <= '0';
		setFlags <= '0';		enFlag <= '0';
		selFlag <= (OTHERS => '0');			
		
		CASE (pstate) IS
			WHEN fetch =>
				selPC_MEM <= '1';	ldIR <= '1';
			WHEN exec1 =>
				CASE (opcode7downto4) IS
					WHEN RSV1 => 
						ldPC <= '1';		selPC1_PC <= '1';  			
					WHEN RSV2 => 
						ldPC <= '1';		selPC1_PC <= '1'; 	
					WHEN INST2 =>
						CASE (opcode3downto2) IS
							WHEN LDR =>
								selrs1_TRF <= '1';		selp1_PCP <= '1';	ldADR <= '1';
							WHEN STR =>
								selrd_1_TRF <= '1';		selp1_PCP <= '1';	ldADR <= '1';	
							WHEN JMR => 
								selrs1_TRF <= '1';		selp1_PCP <= '1';	selPCadd_PC <= '1';	
								ldPC <= '1';			
								IF opcode(1) = '1' THEN
									selrd0_TRF <= '1';		selPC1_TRF <= '1';		
									writeTRF <= '1';
								END IF;
							WHEN JMI =>
								SE6bits <= '1';			selimm_PCP <= '1';	selPCadd_PC <= '1';
								ldPC <= '1';			selrd0_TRF <= '1';	selPC1_TRF <= '1';	
								writeTRF <= '1';					
							WHEN OTHERS =>
								selrs1_TRF <= '0';		ldADR <= '0';		selp1_PCP <= '0';
								ldPC <= '0';			selPCadd_PC <= '0';	selrd0_TRF <= '0';	
								selPC1_TRF <= '0';		SE6bits <= '0';		selimm_PCP <= '0';	
								writeTRF <= '0';		selrd_1_TRF <= '0';		
						END CASE;
					WHEN ANR =>
						selrs1_TRF <= '1';		selrs2_TRF <= '1';		selp2_ASU <= '1';	
						logicAND <= '1';		selrd0_TRF <= '1';		selLLU_TRF <= '1';	
						writeTRF <= '1';		selPC1_PC <= '1';		ldPC <= '1';	
					WHEN ANI =>
						selrd_1_TRF <= '1';		USE8bits <= '1';		selimm_ASU <= '1';	
						logicAND <= '1';		selrd0_TRF <= '1';		selLLU_TRF <= '1';	
						writeTRF <= '1';		selPC1_PC <= '1';		ldPC <= '1';
					WHEN MSI =>
						SE8bits <= '1';			selrd0_TRF <= '1';		selIMM_TRF <= '1';
						writeTRF <= '1';		selPC1_PC <= '1';		ldPC <= '1';
					WHEN MHI =>
						selrd_1_TRF <= '1';		p1lowbits <= '1';		selrd0_TRF <= '1';
						selIMM_TRF <= '1';		writeTRF <= '1';		selPC1_PC <= '1';
						ldPC <= '1';			
					WHEN SLR =>
						selrs1_TRF <= '1';		selrs2_TRF <= '1';		selp2_SHU <= '1';
						logicSH <= '1';			selrd0_TRF <= '1';		selSHU_TRF <= '1';	
						writeTRF <= '1';		selPC1_PC <= '1';		ldPC <= '1';	
					WHEN SAR =>
						selrs1_TRF <= '1';		selrs2_TRF <= '1';		selp2_SHU <= '1';
						arithSH <= '1';			selrd0_TRF <= '1';		selSHU_TRF <= '1';	
						writeTRF <= '1';		selPC1_PC <= '1';		ldPC <= '1';	
					WHEN ADR =>
						selrs1_TRF <= '1';		selrs2_TRF <= '1';		selp2_ASU <= '1';
						arithADD <= '1';		selrd0_TRF <= '1';		selASU_TRF <= '1';	
						writeTRF <= '1';		selPC1_PC <= '1';		ldPC <= '1';	
					WHEN SUR =>
						selrs1_TRF <= '1';		selrs2_TRF <= '1';		selp2_ASU <= '1';
						arithSUB <= '1';		selrd0_TRF <= '1';		selASU_TRF <= '1';	
						writeTRF <= '1';		selPC1_PC <= '1';		ldPC <= '1';
					WHEN ADI =>
						selrd_1_TRF <= '1';		SE8bits <= '1';			selimm_ASU <= '1';
						arithADD <= '1';		selrd0_TRF <= '1';		selASU_TRF <= '1';	
						writeTRF <= '1';		selPC1_PC <= '1';		ldPC <= '1';
					WHEN SUI =>
						selrd_1_TRF <= '1';		SE8bits <= '1';			selimm_ASU <= '1';
						arithSUB <= '1';		selrd0_TRF <= '1';		selASU_TRF <= '1';	
						writeTRF <= '1';		selPC1_PC <= '1';		ldPC <= '1';
					WHEN MUL =>
						selrs1_TRF <= '1';		selrs2_TRF <= '1';		arithMUL <= '1';
						IF readyMDU = '1' THEN 
							startMDU <= '1';	ldMDU1 <= '1';
						END IF;
					WHEN DIV =>
						selrs1_TRF <= '1';		selrs2_TRF <= '1';		arithDIV <= '1';
						IF readyMDU = '1' THEN 
							startMDU <= '1';	ldMDU1 <= '1';
						END IF;
					WHEN INST15 =>
						CASE (opcode3downto1) IS
							WHEN CMR =>
								selrs1_TRF <= '1';		selrd_2_TRF <= '1';		selp2_ASU <= '1';		
								selPC1_PC <= '1';		ldPC <= '1';			enFlag <= '1';
								selFlag <= "00110000";
							WHEN CMI =>
								selrd_1_TRF <= '1';		SE5bits <= '1';			selimm_ASU <= '1';	
								selPC1_PC <= '1';		ldPC <= '1';			enFlag <= '1';
								selFlag <= "00110000";
							WHEN BRC =>
								CASE (RFI) IS
									WHEN "000" =>
										ldPC <= '1';
										IF outFlag(4) = '1' THEN						--eq
											selrd_1_TRF <= '1';		selp1_PC <= '1';
										ELSE
											selPC1_PC <= '1';		
										END IF;
									WHEN "001" =>
										ldPC <= '1';
										IF outFlag(5) = '0' AND outFlag(4) = '0' THEN	--lt
											selrd_1_TRF <= '1';		selp1_PC <= '1';	
										ELSE
											selPC1_PC <= '1';
										END IF;
									WHEN "010" =>
										ldPC <= '1';
										IF outFlag(5) = '1' THEN						--gt
											selrd_1_TRF <= '1';		selp1_PC <= '1';	
										ELSE
											selPC1_PC <= '1';
										END IF;
									WHEN "011" =>
										ldPC <= '1';
										IF outFlag(5) = '1' OR outFlag(4) = '1' THEN	--gt/eq
											selrd_1_TRF <= '1';		selp1_PC <= '1';	
										ELSE
											selPC1_PC <= '1';
										END IF;
									WHEN "100" =>
										ldPC <= '1';
										IF outFlag(5) = '0' OR outFlag(4) = '1' THEN	--lt/eq
											selrd_1_TRF <= '1';		selp1_PC <= '1';
										ELSE
											selPC1_PC <= '1';		
										END IF;
									WHEN "101" =>
										ldPC <= '1';
										IF outFlag(4) = '0' THEN						--neq
											selrd_1_TRF <= '1';		selp1_PC <= '1';	
										ELSE
											selPC1_PC <= '1';
										END IF;
									WHEN OTHERS =>
										selrd_1_TRF <= '0';		selp1_PC <= '0';	ldPC <= '0';
										selPC1_PC <= '0';
								END CASE;
							WHEN BRR =>
								CASE (RFI) IS
									WHEN "000" =>
										ldPC <= '1';
										IF outFlag(4) = '1' THEN						--eq
											selrd_1_TRF <= '1';		selp1_PCP <= '1';		selPCadd_PC <= '1';	
										ELSE
											selPC1_PC <= '1';
										END IF;
									WHEN "001" =>
										ldPC <= '1';
										IF outFlag(5) = '0' AND outFlag(4) = '0' THEN	--lt
											selrd_1_TRF <= '1';		selp1_PCP <= '1';		selPCadd_PC <= '1';	
										ELSE
											selPC1_PC <= '1';											
										END IF;
									WHEN "010" =>
										ldPC <= '1';
										IF outFlag(5) = '1' THEN						--gt
											selrd_1_TRF <= '1';		selp1_PCP <= '1';		selPCadd_PC <= '1';	
										ELSE
											selPC1_PC <= '1';		
										END IF;
									WHEN "011" =>
										ldPC <= '1';
										IF outFlag(5) = '1' OR outFlag(4) = '1' THEN	--gt/eq
											selrd_1_TRF <= '1';		selp1_PCP <= '1';		selPCadd_PC <= '1';	
										ELSE
											selPC1_PC <= '1';
										END IF;
									WHEN "100" =>
										ldPC <= '1';
										IF outFlag(5) = '0' OR outFlag(4) = '1' THEN	--lt/eq
											selrd_1_TRF <= '1';		selp1_PCP <= '1';		selPCadd_PC <= '1';	
										ELSE
											selPC1_PC <= '1';
										END IF;
									WHEN "101" =>
										ldPC <= '1';
										IF outFlag(4) = '0' THEN						--neq
											selrd_1_TRF <= '1';		selp1_PC <= '1';		selPCadd_PC <= '1';
										ELSE
											selPC1_PC <= '1';	
										END IF;
									WHEN OTHERS =>
										selrd_1_TRF <= '0';		selp1_PCP <= '0';		selPCadd_PC <= '0';	
										ldPC <= '0';
								END CASE;
							WHEN NTR =>
								selrs1_TRF <= '1';		selrd0_TRF <= '1';		selLLU_TRF <= '1';	
								writeTRF <= '1';		selPC1_PC <= '1';		ldPC <= '1';
								IF opcode(0) = '0' THEN
									onesComp <= '1';
								ELSE
									twosComp <= '1';
								END IF;
							WHEN NTD =>
								selrd_1_TRF <= '1';		selrd0_TRF <= '1'; 		selLLU_TRF <= '1';	
								writeTRF <= '1';		selPC1_PC <= '1';		ldPC <= '1';
								IF opcode(0) = '0' THEN
									onesComp <= '1';
								ELSE
									twosComp <= '1';
								END IF;
							WHEN OTHERS =>
								selrs1_TRF <= '0';		selp2_ASU <= '0';		SE5bits <= '0';	
								selimm_ASU <= '0';		selrd_1_TRF <= '0';		selp1_PC <= '0';	
								writeTRF <= '0';		selPCadd_PC <= '0';		selLLU_TRF <= '0';	
								selrd0_TRF <= '0';		onesComp <= '0';		twosComp <= '0';	
								ldPC <= '0';			selrs2_TRF <= '0';		enFlag <= '0';
								selFlag <= (OTHERS => '0');
						END CASE;
					WHEN OTHERS =>
							selp1_PCP <= '0';		selimm_PCP <= '0';	selp1_PC <= '0';
							selPCadd_PC <= '0';		selPC1_PC <= '0';	seldataBus_TRF <= '0';	
							selPC1_TRF <= '0';		selLLU_TRF <= '0';	selSHU_TRF <= '0';
							selASU_TRF <= '0';		selMDU1_TRF <= '0';	selMDU2_TRF <= '0';	
							selIMM_TRF <= '0';		selp2_SHU <= '0';	selshim_SHU <= '0';	
							selp2_ASU <= '0';		selimm_ASU <= '0';	selrs1_TRF <= '0';	
							selrd_1_TRF <= '0';		selrd0_TRF <= '0';	selrd1_TRF <= '0';	
							selPC_MEM <= '0';		selADR_MEM <= '0';	SE5bits <= '0';	
							SE6bits <= '0';			USE8bits <= '0';	SE8bits <= '0';	
							readMEM <= '0';			writeMEM <= '0';	readIO <= '0';	
							writeIO <= '0';			logicAND <= '0'; 	ldIR <= '0';	
							writeTRF <= '0';		ldADR <= '0';		ldPC <= '0';	
							ldMDU1 <= '0';			ldMDU2 <= '0';		onesComp <= '0';	
							twosComp <= '0';		arithADD <= '0';	arithSUB <= '0';	
							arithMUL <= '0';		arithDIV <= '0'; 	logicSH <= '0';	
							arithSH <= '0';			startMDU <= '0';	selrd_2_TRF <= '0';	
							selrs2_TRF <= '0';
				END CASE;
				-- SHI
				IF opcode(7 DOWNTO 2) = SHI THEN
					selrd_1_TRF <= '1';		selshim_SHU <= '1';		selrd0_TRF <= '1';
					selSHU_TRF <= '1';		writeTRF <= '1';		selPC1_PC <= '1';	
					ldPC <= '1';
					IF opcode(1) = '0' THEN
						logicSH <= '1';
					ELSE
						arithSH <= '1';
					END IF;
				END IF;
			WHEN exec2 =>
				CASE (opcode7downto4) IS
					WHEN INST2 =>
						CASE (opcode3downto2) IS
							WHEN LDR =>
								selADR_MEM <= '1';	seldataBus_TRF <= '1';	selPC1_PC <= '1';	
								selrd0_TRF <= '1';
								IF opcode(1) = '1' THEN		--I/O
									readIO <= '1';	ldPC <= '1';	writeTRF <= '1';
								ELSE						--MEM
									readMEM <= '1';
									IF readyMEM = '1' THEN
										ldPC <= '1';	writeTRF <= '1';
									END IF;
								END IF;
							WHEN STR =>
								selADR_MEM <= '1';	selrs1_TRF <= '1';		driveDataBus <= '1';
								selPC1_PC <= '1';
								IF opcode(1) = '1' THEN
									writeIO <= '1';		ldPC <= '1';
								ELSE
									writeMEM <= '1';
									IF readyMEM = '1' THEN
										ldPC <= '1';
									END IF;
								END IF;
							WHEN OTHERS => 
								selADR_MEM <= '0';	selrd0_TRF <= '0';	readIO <= '0';	
								writeTRF <= '0';	readMEM <= '0';		writeIO <= '0';	
								writeMEM<= '0';
						END CASE;
					WHEN MUL | DIV => 
						selrd0_TRF <= '1';		selMDU1_TRF <= '1';		writeTRF <= '1';
						ldMDU2 <= '1';
					WHEN OTHERS =>
						selADR_MEM <= '0';		selrd0_TRF <= '0';		readIO <= '0';	
						writeTRF <= '0';		readMEM <= '0';			writeIO <= '0';	
						writeMEM<= '0';			arithMUL <= '0';		selMDU1_TRF <= '0';	
						ldMDU1 <= '0';			arithDIV <= '0';		driveDataBus <= '0';
				END CASE;
			WHEN exec3 =>
				CASE (opcode7downto4) IS
					WHEN MUL | DIV => 
						selrd1_TRF <= '1';		selMDU2_TRF <= '1';		writeTRF <= '1';
						selPC1_PC <= '1';		ldPC <= '1';
					WHEN OTHERS => 
						writeTRF <= '0';		selMDU2_TRF <= '0';		selrd1_TRF <= '0';	
						selPC1_PC <= '0';		ldPC <= '0';
				END CASE;
		END CASE;
	END PROCESS;
	
	-- Issuing next state
	PROCESS (pstate, readyMEM, readyMDU, opcode)
	BEGIN
		CASE (pstate) IS
			WHEN fetch =>
				nstate <= exec1;
			WHEN exec1 =>
				CASE (opcode7downto4) IS
					WHEN RSV1 => 
						nstate <= fetch;
					WHEN RSV2 => 
						nstate <= fetch;
					WHEN INST2 =>
						CASE (opcode3downto2) IS
							WHEN LDR | STR => 
								nstate <= exec2;
							WHEN JMR | JMI => 
								nstate <= fetch;	
							WHEN OTHERS =>
								nstate <= fetch;
						END CASE;
					WHEN ANR | ANI | MSI | MHI | SLR | SAR | ADR | SUR | ADI | SUI => 
						nstate <= fetch;
					WHEN MUL | DIV => 
						IF readyMDU = '1' THEN 
							nstate <= exec2;
						ELSE
							nstate <= exec1;
						END IF;
					WHEN INST15 =>
						CASE (opcode3downto1) IS
							WHEN CMR | CMI | BRC | BRR | NTR | NTD => 
								nstate <= fetch;
							WHEN OTHERS =>
								nstate <= fetch;
						END CASE;
					WHEN OTHERS =>
							nstate <= fetch;
				END CASE;
				-- SHI
				IF opcode(7 DOWNTO 2) = SHI THEN
					nstate <= fetch;
				END IF;
			WHEN exec2 =>
				CASE (opcode7downto4) IS
					WHEN INST2 =>
						CASE (opcode3downto2) IS
							WHEN LDR | STR =>	
								IF opcode(1) = '1' THEN		--I/O
									nstate <= fetch;
								ELSE						--MEM
									IF readyMEM = '1' THEN
										nstate <= fetch;
									ELSE
										nstate <= exec2;
									END IF;
								END IF;
							WHEN OTHERS => 
								nstate <= fetch;
						END CASE;
					WHEN MUL | DIV => 
						nstate <= exec3;	
					WHEN OTHERS =>
						nstate <= fetch;
				END CASE;
			WHEN exec3 =>
				CASE (opcode7downto4) IS
					WHEN MUL | DIV => 
						nstate <= fetch;
					WHEN OTHERS => 
						nstate <= fetch;
				END CASE;
		END CASE;
	END PROCESS;
	
	PROCESS (clk, rst)
	BEGIN
		IF rst = '1' THEN
			pstate <= fetch;
		ELSIF clk = '1' AND clk'EVENT THEN
			pstate <= nstate;
		END IF;
	END PROCESS;
END ARCHITECTURE behaviour;
------------------------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
ENTITY test_CCU IS
END ENTITY test_CCU;
ARCHITECTURE test OF test_CCU IS
	SIGNAL clk : STD_LOGIC := '0';
	SIGNAL rst, readyMEM, readyMDU : STD_LOGIC;
	SIGNAL seldataBus_TRF, selPC1_TRF, selLLU_TRF, selSHU_TRF : STD_LOGIC; 
	SIGNAL selASU_TRF, selMDU1_TRF, selMDU2_TRF, selIMM_TRF : STD_LOGIC;
    SIGNAL selrs1_TRF, selrd_1_TRF, selrs2_TRF, selrd_2_TRF, selrd0_TRF, 
		   selrd1_TRF, writeTRF : STD_LOGIC;
	SIGNAL selp1_PCP, selimm_PCP : STD_LOGIC;
    SIGNAL selp1_PC, selPCadd_PC, selPC1_PC : STD_LOGIC;
    SIGNAL selPC_MEM, selADR_MEM, driveDataBus : STD_LOGIC;
    SIGNAL SE5bits, SE6bits, USE8bits, SE8bits, p1lowbits : STD_LOGIC;
    SIGNAL selp2_ASU, selimm_ASU, arithADD, arithSUB : STD_LOGIC;
    SIGNAL logicAND, onesComp, twosComp : STD_LOGIC;
    SIGNAL selp2_SHU, selshim_SHU, logicSH, arithSH : STD_LOGIC;
    SIGNAL ldMDU1, ldMDU2, arithMUL, arithDIV, startMDU : STD_LOGIC;
    SIGNAL ldIR, ldADR, ldPC : STD_LOGIC;
    SIGNAL readMEM, writeMEM, readIO, writeIO : STD_LOGIC;
	SIGNAL opcode  : STD_LOGIC_VECTOR(7 DOWNTO 0);
	SIGNAL FIB     : STD_LOGIC_VECTOR(4 DOWNTO 0);  --FLags Intrepretation Bits
	SIGNAL setFlags, enFlag : STD_LOGIC;
	SIGNAL outFlag : STD_LOGIC_VECTOR(7 DOWNTO 0);
	SIGNAL selFlag : STD_LOGIC_VECTOR(7 DOWNTO 0);
BEGIN	
	clk <= NOT clk AFTER 1 NS WHEN NOW <= 380 NS ELSE '0';
	rst <= '1', '0' AFTER 1 NS;
	readyMEM <= '0', '1' AFTER 4 NS, '0' AFTER 16 NS;
	readyMDU <= '0', '1' AFTER 50 NS;
	FIB <= "00000", "00011" AFTER 50 NS;
	outFlag <= X"00", X"F1" AFTER 50 NS;
	-- opcode <= X"00", X"01" AFTER 1 NS, X"20" AFTER 2 NS, X"22" AFTER 6 NS, 
			  -- X"26" AFTER 14 NS, X"2A" AFTER 22 NS, X"30" AFTER 26 NS, 
			  -- X"50" AFTER 30 NS, X"70" AFTER 34 NS, X"90" AFTER 38 NS, 
			  -- X"B0" AFTER 42 NS, X"D0" AFTER 46 NS, X"E0" AFTER 54 NS, 
			  -- X"F2" AFTER 60 NS, X"F6" AFTER 64 NS, X"FA" AFTER 68 NS,
			  -- X"FD" AFTER 72 NS, X"FF" AFTER 76 NS;
	opcode <= X"00", X"01" AFTER 1 NS, X"24" AFTER 4 NS, X"28" AFTER 12 NS,
			  X"2C" AFTER 18 NS, X"40" AFTER 22 NS, X"60" AFTER 26 NS, 
			  X"80" AFTER 30 NS, X"A0" AFTER 34 NS, X"C0" AFTER 38 NS, 
			  X"F0" AFTER 42 NS, X"F4" AFTER 46 NS, X"F8" AFTER 50 NS, 
			  X"FC" AFTER 54 NS, X"FE" AFTER 58 NS;

	Controller : ENTITY WORK.CCU PORT MAP 
					(clk, rst, readyMEM, readyMDU, opcode, FIB,
					seldataBus_TRF, selPC1_TRF, selLLU_TRF, selSHU_TRF, 
					selASU_TRF, selMDU1_TRF, selMDU2_TRF, selIMM_TRF,
					selrs1_TRF, selrd_1_TRF, selrs2_TRF, selrd_2_TRF, selrd0_TRF, 
					selrd1_TRF, writeTRF, selp1_PCP, selimm_PCP, 
					selp1_PC, selPCadd_PC, selPC1_PC,
					selPC_MEM, selADR_MEM, driveDataBus,
					SE5bits, SE6bits, USE8bits, SE8bits, p1lowbits,
					selp2_ASU, selimm_ASU, arithADD, arithSUB,
					logicAND, onesComp, twosComp,
					selp2_SHU, selshim_SHU, logicSH, arithSH,
					ldMDU1, ldMDU2, arithMUL, arithDIV, startMDU,
					ldIR, ldADR, ldPC,
					readMEM, writeMEM, readIO, writeIO,
					setFlags, enFlag, outFlag, selFlag);
END ARCHITECTURE test;

--******************************************************************************
--	Filename:		SAYAC_register_file.vhd
--	Project:		SAYAC : Simple Architecture Yet Ample Circuitry
--  Version:		0.990
--	History:
--	Date:			27 April 2021
--	Last Author: 	HANIEH
--  Copyright (C) 2021 University of Tehran
--  This source file may be used and distributed without
--  restriction provided that this copyright statement is not
--  removed from the file and that any derivative work contains
--  the original copyright notice and the associated disclaimer.
--

--******************************************************************************
--	File content description:
--	SAYAC_TOP level circuit (SAYAC_TOP) of the SAYAC core                                 
--******************************************************************************

LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;
	
ENTITY SAYAC_TOP IS
	PORT (
		clk, rst, readyMEM : IN STD_LOGIC;
		dataBusIn : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
		readMEM, writeMEM, readIO, writeIO : OUT STD_LOGIC;
		dataBusOut, addrBus : OUT STD_LOGIC_VECTOR(15 DOWNTO 0)
	);
END ENTITY SAYAC_TOP;

ARCHITECTURE behaviour OF SAYAC_TOP IS
	SIGNAL opcode : STD_LOGIC_VECTOR(7 DOWNTO 0);
    SIGNAL seldataBus_TRF, selPC1_TRF, selLLU_TRF, selSHU_TRF, 
		   selASU_TRF, selMDU1_TRF, selMDU2_TRF, selIMM_TRF : STD_LOGIC;
    SIGNAL selrs1_TRF, selrd_1_TRF, selrs2_TRF, selrd_2_TRF : STD_LOGIC;
	SIGNAL selrd0_TRF, selrd1_TRF, writeTRF : STD_LOGIC;
	SIGNAL selp1_PCP, selimm_PCP : STD_LOGIC;
    SIGNAL selPC_MEM, selp1_PC, selPCadd_PC, selPC1_PC : STD_LOGIC;
    SIGNAL selADR_MEM, driveDataBus : STD_LOGIC;
    SIGNAL SE5bits, SE6bits, USE8bits, SE8bits, p1lowbits : STD_LOGIC;
    SIGNAL selp2_ASU, selimm_ASU, arithADD, arithSUB : STD_LOGIC;
    SIGNAL logicAND, onesComp, twosComp : STD_LOGIC;
    SIGNAL selp2_SHU, selshim_SHU, logicSH, arithSH : STD_LOGIC;
    SIGNAL ldMDU1, ldMDU2, arithMUL, arithDIV, startMDU : STD_LOGIC;
    SIGNAL ldIR, ldADR, ldPC : STD_LOGIC;
	SIGNAL readyMDU : STD_LOGIC;
	SIGNAL FIB     : STD_LOGIC_VECTOR(4 DOWNTO 0);  --FLags Intrepretation Bits
	SIGNAL setFlags, enFlag : STD_LOGIC;
	SIGNAL outFlag : STD_LOGIC_VECTOR(7 DOWNTO 0);
	SIGNAL selFlag : STD_LOGIC_VECTOR(7 DOWNTO 0);
BEGIN
	DataPath : ENTITY WORK.DPU PORT MAP 
					(clk => clk, rst => rst,
					seldataBus_TRF => seldataBus_TRF, selPC1_TRF => selPC1_TRF,  
					selLLU_TRF => selLLU_TRF, selSHU_TRF => selSHU_TRF, 
					selASU_TRF => selASU_TRF, selMDU1_TRF => selMDU1_TRF,  
					selMDU2_TRF => selMDU2_TRF, selIMM_TRF => selIMM_TRF, 
					selrs1_TRF => selrs1_TRF, selrd_1_TRF => selrd_1_TRF,  
					selrs2_TRF => selrs2_TRF, selrd_2_TRF => selrd_2_TRF, 
					selrd0_TRF => selrd0_TRF, selrd1_TRF => selrd1_TRF,  writeTRF => writeTRF,
					selp1_PCP => selp1_PCP, selimm_PCP => selimm_PCP, selp1_PC => selp1_PC, 
					selPCadd_PC => selPCadd_PC, selPC1_PC => selPC1_PC,  
					selPC_MEM => selPC_MEM, selADR_MEM => selADR_MEM,  
					driveDataBus => driveDataBus, SE5bits => SE5bits, SE6bits => SE6bits, 
					USE8bits => USE8bits, SE8bits => SE8bits, p1lowbits => p1lowbits,  
					selp2_ASU => selp2_ASU, selimm_ASU => selimm_ASU, arithADD => arithADD, 
					arithSUB => arithSUB, logicAND => logicAND, onesComp => onesComp,  
					twosComp => twosComp, selp2_SHU => selp2_SHU, selshim_SHU => selshim_SHU,  
					logicSH => logicSH, arithSH => arithSH, ldMDU1 => ldMDU1, ldMDU2 => ldMDU2, 
					arithMUL => arithMUL, arithDIV => arithDIV, startMDU => startMDU,  
					ldIR => ldIR, ldADR => ldADR, ldPC => ldPC, 
					readyMDU => readyMDU, opcode => opcode, FIB => FIB, setFlags => setFlags, 
					enFlag => enFlag, selFlag => selFlag, outFlag => outFlag, 
					dataBusIn => dataBusIn, addrBus => addrBus, dataBusOut => dataBusOut);
	Controller : ENTITY WORK.CCU PORT MAP 
					(clk => clk, rst => rst, readyMEM => readyMEM, readyMDU => readyMDU, 
					opcode => opcode, FIB => FIB, seldataBus_TRF => seldataBus_TRF,  
					selPC1_TRF => selPC1_TRF, selLLU_TRF => selLLU_TRF,  
					selSHU_TRF => selSHU_TRF, selASU_TRF => selASU_TRF,  
					selMDU1_TRF => selMDU1_TRF, selMDU2_TRF => selMDU2_TRF,  
					selIMM_TRF => selIMM_TRF, selrs1_TRF => selrs1_TRF,  
					selrd_1_TRF => selrd_1_TRF, selrs2_TRF => selrs2_TRF,  
					selrd_2_TRF => selrd_2_TRF, selrd0_TRF => selrd0_TRF,  
					selrd1_TRF => selrd1_TRF, writeTRF => writeTRF, selp1_PCP => selp1_PCP, 
					selimm_PCP => selimm_PCP, selp1_PC => selp1_PC,  
					selPCadd_PC => selPCadd_PC, selPC1_PC => selPC1_PC,  
					selPC_MEM => selPC_MEM, selADR_MEM => selADR_MEM,  
					driveDataBus => driveDataBus, SE5bits => SE5bits, SE6bits => SE6bits, 
					USE8bits => USE8bits, SE8bits => SE8bits, p1lowbits => p1lowbits, 
					selp2_ASU => selp2_ASU, selimm_ASU => selimm_ASU, arithADD => arithADD, 
					arithSUB => arithSUB, logicAND => logicAND, onesComp => onesComp,  
					twosComp => twosComp, selp2_SHU => selp2_SHU, selshim_SHU => selshim_SHU,  
					logicSH => logicSH, arithSH => arithSH, ldMDU1 => ldMDU1, ldMDU2 => ldMDU2,  
					arithMUL => arithMUL, arithDIV => arithDIV, startMDU => startMDU, 
					ldIR => ldIR, ldADR => ldADR, ldPC => ldPC, readMEM => readMEM,  
					writeMEM => writeMEM, readIO => readIO, writeIO => writeIO, 
					setFlags => setFlags, enFlag => enFlag, 
					outFlag => outFlag, selFlag => selFlag);
END ARCHITECTURE behaviour;
------------------------------------------------------------------------------------------------