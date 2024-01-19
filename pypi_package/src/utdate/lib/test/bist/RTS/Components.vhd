--******************************************************************************
--	Filename:		Components.vhd
--	Project:		SAYAC Testing 
--  Version:		0.1
--	History:
--	Date:			18 Nov 2023
--	Last Author: 	Nooshin Nosrati
--  Copyright (C) 2022 University of Tehran
--  This source file may be used and distributed without
--  restriction provided that this copyright statement is not
--  removed from the file and that any derivative work contains
--  the original copyright notice and the associated disclaimer.
--
--******************************************************************************
--	File content description:
--	Comparator, MUX, and Tri-state for LBIST
--******************************************************************************

--///////////////////////////////// Comparator /////////////////////////////////
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
	
ENTITY Comparator IS
	GENERIC (
		n   : INTEGER := 80;
		m   : INTEGER := 90);
	PORT (
		in1, in2  : IN STD_LOGIC_VECTOR (n+m-1 DOWNTO 0);
		e : OUT STD_LOGIC);
END ENTITY Comparator;

ARCHITECTURE behaviour OF Comparator IS
BEGIN
	PROCESS(in1, in2)
	BEGIN
	  	e <= '0';
		IF (in1 = in2) THEN
			e <= '1';
		END IF;
	END PROCESS;
END ARCHITECTURE behaviour;

--///////////////////////////////// MUX /////////////////////////////////
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY MUX IS
	GENERIC (
		n : INTEGER := 8);
	PORT (
		in1, in2 : IN STD_LOGIC_VECTOR (n-1 DOWNTO 0);
		sel      : IN STD_LOGIC;
		out1     : OUT STD_LOGIC_VECTOR (n-1 DOWNTO 0));
END ENTITY MUX;

ARCHITECTURE behaviour OF MUX IS
BEGIN
	out1 <= in1 WHEN sel = '0' ELSE in2;
END ARCHITECTURE behaviour;

--///////////////////////////////// Tri_state /////////////////////////////////
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY Tri_state IS
	PORT (
		in1  : IN STD_LOGIC;
		sel  : IN STD_LOGIC;
		out1 : OUT STD_LOGIC);
END ENTITY Tri_state;

ARCHITECTURE behaviour OF Tri_state IS
BEGIN
	out1 <= in1 WHEN sel = '1' ELSE 'Z';
END ARCHITECTURE behaviour;