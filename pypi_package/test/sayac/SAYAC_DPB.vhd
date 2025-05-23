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
	
ENTITY Flags IS
	PORT (
		clk, rst : IN STD_LOGIC;
		setFlags, enFlag : IN STD_LOGIC;
		selFlag, inFlag : IN STD_LOGIC_VECTOR(7 DOWNTO 0);
		outFlag  : OUT STD_LOGIC_VECTOR(7 DOWNTO 0)
	);
END ENTITY Flags;

ARCHITECTURE behaviour OF Flags IS
BEGIN
	FlagsFF : FOR I IN 0 TO 7 GENERATE
		FF_bitI : ENTITY WORK.IFF
		PORT MAP (clk, rst, enFlag, setFlags, 
				  selFlag(I), inFlag(I), outFlag(I));
	END GENERATE;

END ARCHITECTURE behaviour;
------------------------------------------------------------------------------------------------

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
-- LIBRARY IEEE;
-- USE IEEE.std_logic_1164.ALL;
-- ENTITY test_IMM IS
-- END ENTITY test_IMM;
-- ARCHITECTURE test OF test_IMM IS
-- 	SIGNAL in1, in2 : STD_LOGIC_VECTOR(7 DOWNTO 0);
-- 	SIGNAL SE5bits, SE6bits, USE8bits, SE8bits, p1lowbits : STD_LOGIC;
-- 	SIGNAL outIMM   : STD_LOGIC_VECTOR(15 DOWNTO 0);
-- BEGIN
-- 	SE5bits <= '0', '1' AFTER 1 NS, '0' AFTER 2 NS;
-- 	SE6bits <= '0', '1' AFTER 2 NS, '0' AFTER 3 NS;
-- 	USE8bits <= '0', '1' AFTER 3 NS, '0' AFTER 4 NS;
-- 	SE8bits <= '0', '1' AFTER 4 NS, '0' AFTER 5 NS;
-- 	p1lowbits <= '0', '1' AFTER 5 NS, '0' AFTER 6 NS;
-- 	in1 <= X"30", X"0A" AFTER 8 NS, X"E2" AFTER 12 NS;
-- 	in2 <= X"F7", X"1C" AFTER 7 NS, X"6B" AFTER 10 NS;
	
-- 	ImmediateUnit : ENTITY WORK.IMM PORT MAP 
-- 						(in1, in2, SE5bits, SE6bits, USE8bits, 
-- 						SE8bits, p1lowbits, outIMM);
-- END ARCHITECTURE test;
-- ------------------------------------------------------------------------------------------------
-- LIBRARY IEEE;
-- USE IEEE.std_logic_1164.ALL;
-- ENTITY test_LLU IS
-- END ENTITY test_LLU;
-- ARCHITECTURE test OF test_LLU IS
-- 	SIGNAL in1, in2 : STD_LOGIC_VECTOR(15 DOWNTO 0);
-- 	SIGNAL logicAND, onesComp, twosComp : STD_LOGIC;
-- 	SIGNAL outLLU   : STD_LOGIC_VECTOR(15 DOWNTO 0);
-- BEGIN
-- 	logicAND <= '0', '1' AFTER 1 NS, '0' AFTER 2 NS;
-- 	onesComp <= '0', '1' AFTER 3 NS, '0' AFTER 4 NS;
-- 	twosComp <= '0', '1' AFTER 5 NS, '0' AFTER 6 NS;
-- 	in1 <= X"2019", X"0A01" AFTER 2 NS, X"F204" AFTER 5 NS;
-- 	in2 <= X"2042", X"0A35" AFTER 3 NS, X"F275" AFTER 4 NS;
	
-- 	LogicLogicUnit : ENTITY WORK.LLU PORT MAP 
-- 						(in1, in2, logicAND, onesComp, twosComp, outLLU);
-- END ARCHITECTURE test;
-- ------------------------------------------------------------------------------------------------
-- LIBRARY IEEE;
-- USE IEEE.std_logic_1164.ALL;
-- ENTITY test_ASU IS
-- END ENTITY test_ASU;
-- ARCHITECTURE test OF test_ASU IS
-- 	SIGNAL in1, in2 : STD_LOGIC_VECTOR(15 DOWNTO 0);
-- 	SIGNAL arithADD, arithSUB : STD_LOGIC;
-- 	SIGNAL outASU   : STD_LOGIC_VECTOR(15 DOWNTO 0);
-- BEGIN
-- 	arithADD <= '1', '0' AFTER 2 NS;
-- 	arithSUB <= '0', '1' AFTER 3 NS, '0' AFTER 6 NS;
-- 	in1 <= X"2019", X"8A01" AFTER 1 NS, X"0A01" AFTER 2 NS, X"F204" AFTER 5 NS;
-- 	in2 <= X"2042", X"0A35" AFTER 3 NS, X"F275" AFTER 4 NS;
	
-- 	AddSubUnit : ENTITY WORK.ASU PORT MAP 
-- 					(in1, in2, arithADD, arithSUB, outASU);
-- END ARCHITECTURE test;
-- ------------------------------------------------------------------------------------------------
-- LIBRARY IEEE;
-- USE IEEE.std_logic_1164.ALL;
-- ENTITY test_SHU IS
-- END ENTITY test_SHU;
-- ARCHITECTURE test OF test_SHU IS
-- 	SIGNAL in1    : STD_LOGIC_VECTOR(15 DOWNTO 0);
-- 	SIGNAL in2    : STD_LOGIC_VECTOR(4 DOWNTO 0);
-- 	SIGNAL logicSH, arithSH : STD_LOGIC;
-- 	SIGNAL outSHU : STD_LOGIC_VECTOR(15 DOWNTO 0);
-- BEGIN
-- 	logicSH <= '1', '0' AFTER 1 NS, '1' AFTER 5 NS;
-- 	arithSH <= '0', '1' AFTER 2 NS, '0' AFTER 4 NS;
-- 	in1 <= X"2E18", X"8AB1" AFTER 4 NS, X"2AB1" AFTER 7 NS;
-- 	in2 <= "00100", "10110" AFTER 3 NS, "10111" AFTER 6 NS;
	
-- 	SHiftUnit : ENTITY WORK.SHU PORT MAP 
-- 					(in1, in2, logicSH, arithSH, outSHU);
-- END ARCHITECTURE test;
-- ------------------------------------------------------------------------------------------------
-- LIBRARY IEEE;
-- USE IEEE.std_logic_1164.ALL;
-- ENTITY test_MDU IS
-- END ENTITY test_MDU;
-- ARCHITECTURE test OF test_MDU IS
-- 	SIGNAL clk : STD_LOGIC := '0';
-- 	SIGNAL rst, startMDU, arithMUL, arithDIV, ldMDU1, ldMDU2, readyMDU : STD_LOGIC;
-- 	SIGNAL in1, in2         : STD_LOGIC_VECTOR(15 DOWNTO 0);
-- 	SIGNAL outMDU1, outMDU2 : STD_LOGIC_VECTOR(15 DOWNTO 0);
-- BEGIN
-- 	clk <= NOT clk AFTER 5 NS WHEN NOW <= 140 NS ELSE '0';
-- 	rst <= '1', '0' AFTER 1 NS;
-- 	startMDU <= '0', '1' AFTER 1 NS, '0' AFTER 13 NS, '1' AFTER 14 NS;
-- 	arithMUL <= '0', '1' AFTER 4 NS, '0' AFTER 88 NS;
-- 	arithDIV <= '0', '1' AFTER 102 NS;
-- 	ldMDU1 <= '1', '0' AFTER 27 NS, '1' AFTER 84 NS, '0' AFTER 88 NS, '1' AFTER 105 NS, '0' AFTER 108 NS;
-- 	ldMDU2 <= '0', '1' AFTER 95 NS, '0' AFTER 97 NS, '1' AFTER 115 NS, '0' AFTER 117 NS, '1' AFTER 125 NS, '0' AFTER 128 NS;
-- 	in1 <= X"0001", X"0019" AFTER 2 NS, X"0A01" AFTER 100 NS, X"F204" AFTER 104 NS;
-- 	in2 <= X"0001", X"0005" AFTER 3 NS, X"FFFE" AFTER 106 NS;
	
-- 	MultDivUnit : ENTITY WORK.MDU PORT MAP 
-- 					(clk, rst, startMDU, arithMUL, arithDIV, ldMDU1, 
-- 					ldMDU2, in1, in2, outMDU1, outMDU2, readyMDU);
-- END ARCHITECTURE test;
-- ------------------------------------------------------------------------------------------------
-- LIBRARY IEEE;
-- USE IEEE.std_logic_1164.ALL;
-- ENTITY test_CMP IS
-- END ENTITY test_CMP;
-- ARCHITECTURE test OF test_CMP IS
-- 	SIGNAL in1, in2   : STD_LOGIC_VECTOR(15 DOWNTO 0);
-- 	SIGNAL eq, gt : STD_LOGIC;
-- BEGIN
-- 	in1 <= X"0000", X"0019" AFTER 2 NS, X"FFF1" AFTER 5 NS, X"FEFE" AFTER 8 NS;
-- 	in2 <= X"0000", X"0042" AFTER 3 NS, X"FFE2" AFTER 6 NS;
	
-- 	ComparatorUnit : ENTITY WORK.CMP PORT MAP 
-- 						(in1, in2, eq, gt);
-- END ARCHITECTURE test;
-- ------------------------------------------------------------------------------------------------
-- LIBRARY IEEE;
-- USE IEEE.std_logic_1164.ALL;
-- ENTITY test_INC IS
-- END ENTITY test_INC;
-- ARCHITECTURE test OF test_INC IS
-- 	SIGNAL inINC  : STD_LOGIC_VECTOR(15 DOWNTO 0);
-- 	SIGNAL outINC : STD_LOGIC_VECTOR(15 DOWNTO 0);
-- BEGIN
-- 	inINC <= X"2E18", X"8AB1" AFTER 4 NS, X"2AB1" AFTER 7 NS;
	
-- 	INCrementer : ENTITY WORK.INC PORT MAP 
-- 					(inINC, outINC);
-- END ARCHITECTURE test;
-- ------------------------------------------------------------------------------------------------
-- LIBRARY IEEE;
-- USE IEEE.std_logic_1164.ALL;
-- ENTITY test_COMP IS
-- END ENTITY test_COMP;
-- ARCHITECTURE test OF test_COMP IS
-- 	SIGNAL inCOMP  : STD_LOGIC_VECTOR(15 DOWNTO 0);
-- 	SIGNAL onebartwo : STD_LOGIC;
-- 	SIGNAL outCOMP : STD_LOGIC_VECTOR(15 DOWNTO 0);
-- BEGIN
-- 	inCOMP <= X"2E18", X"8AB1" AFTER 4 NS, X"2AB1" AFTER 7 NS;
-- 	onebartwo <= '0', '1' AFTER 3 NS, '0' AFTER 5 NS;
	
-- 	COMPlementer : ENTITY WORK.COMP PORT MAP 
-- 					(inCOMP, onebartwo, outCOMP);
-- END ARCHITECTURE test;

