--******************************************************************************
--	Filename:		Top_level.vhd
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
--	Top level of testable SAYAC-MEM system for RTS LBIST testing                               
--******************************************************************************

LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE STD.TEXTIO.ALL;
USE IEEE.STD_LOGIC_TEXTIO.ALL;
USE IEEE.NUMERIC_STD.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
USE IEEE.MATH_REAL.ALL;

ENTITY Top_level IS
	GENERIC (
		-- PI_Size
        PI_Size     : INTEGER := 3;
		-- PO_Size
        PO_Size     : INTEGER := 5;
		-- Seed & Polynomial
        PRPG_Seed	: STD_LOGIC_VECTOR := "00000000";
        PRPG_Poly	: STD_LOGIC_VECTOR := "00000000";
        MISR_Seed	: STD_LOGIC_VECTOR := "00000000";
        MISR_Poly	: STD_LOGIC_VECTOR := "00000000";
        SRSG_Seed	: STD_LOGIC_VECTOR := "00000000";
        SRSG_Poly	: STD_LOGIC_VECTOR := "00000000";
        SISA_Seed	: STD_LOGIC_VECTOR := "00000000";
        SISA_Poly	: STD_LOGIC_VECTOR := "00000000";

		-- ShiftSize
        ShiftSize     : INTEGER := 4;
		-- numOfCycles
		numOfCycles : INTEGER := 10;
		-- numOfRounds
		numOfRounds : INTEGER := 10
	);
	PORT (
		clk          : IN STD_LOGIC;
		-- DUT Inputs
        rst_pin   : IN STD_LOGIC;
        en_pin   : IN STD_LOGIC;

		-- DUT Outputs
        co   : OUT STD_LOGIC;
        counter   : OUT STD_LOGIC_VECTOR (4-1 DOWNTO 0);

		-- Test Inputs
		test_reset   : IN STD_LOGIC;
		runLBIST     : IN STD_LOGIC;
		-- Test Outputs
		Ready        : OUT STD_LOGIC;
		FbarP        : OUT STD_LOGIC;
	);
END ENTITY Top_level;

ARCHITECTURE arch OF Top_level IS
	
	-- Signals of DUT
    SIGNAL rst: STD_LOGIC;
    SIGNAL en: STD_LOGIC;
    SIGNAL Si : STD_LOGIC;
    SIGNAL So : STD_LOGIC;
    SIGNAL internalRst : STD_LOGIC;
    SIGNAL PbarS : STD_LOGIC;


	-- Signals of PRPG, MISR, SRSG, and SISA
	SIGNAL PRPG_En : STD_LOGIC; 
	SIGNAL MISR_En : STD_LOGIC;
	SIGNAL SRSG_En : STD_LOGIC;
	SIGNAL SISA_En : STD_LOGIC;
	SIGNAL PRPG_Out : STD_LOGIC_VECTOR (PRPG_Seed'LENGTH-1 DOWNTO 0);
	SIGNAL MISR_In  : STD_LOGIC_VECTOR (MISR_Seed'LENGTH-1 DOWNTO 0);
	SIGNAL MISR_Out : STD_LOGIC_VECTOR (MISR_Seed'LENGTH-1 DOWNTO 0);
	SIGNAL SISA_Out : STD_LOGIC_VECTOR (SISA_Seed'LENGTH-1 DOWNTO 0);

	-- Signals of Comprator, ROM, MUX, and Tri-state
	SIGNAL MUX_In1  : STD_LOGIC_VECTOR (PI_Size-1 DOWNTO 0);
	SIGNAL MUX_Out  : STD_LOGIC_VECTOR (PI_Size-1 DOWNTO 0);
	SIGNAL Comp_In  : STD_LOGIC_VECTOR (MISR_Seed'LENGTH+SISA_Seed'LENGTH-1 DOWNTO 0);
	SIGNAL data_ROM : STD_LOGIC_VECTOR (MISR_Seed'LENGTH+SISA_Seed'LENGTH-1 DOWNTO 0);
	SIGNAL addr_ROM : STD_LOGIC_VECTOR (integer(ceil(log2(real(numOfRounds))))-1 DOWNTO 0);
	SIGNAL Comp_Out : STD_LOGIC;
	SIGNAL read_ROM : STD_LOGIC;
	SIGNAL done_Round : STD_LOGIC;

	CONSTANT Zeros: STD_LOGIC_VECTOR(MISR_Seed'LENGTH-PO_Size-1 DOWNTO 0) := (OTHERS => '0');

BEGIN	
	-- DUT Instantiation
   DUT : ENTITY WORK.counter 
           PORT MAP (
              clk 		 => clk,
              rst 		 => rst,
              en 		 => en,
              co 		 => co,
              counter 		 => counter,
              global_reset => internalRst,
              NbarT		 => PbarS,
              Si 		 => Si,
              So 		 => So
           );


	
	PRPG_1 : ENTITY WORK.LFSR GENERIC MAP (PRPG_Seed, PRPG_Poly) 
			PORT MAP (clk, internalRst, PRPG_En, PRPG_Out);
	MISR_1 : ENTITY WORK.MISR GENERIC MAP (MISR_Seed, MISR_Poly) 
			PORT MAP (clk, internalRst, MISR_En, MISR_In, MISR_Out);
	SRSG_1 : ENTITY WORK.SRSG GENERIC MAP (SRSG_Seed, SRSG_Poly) 
			PORT MAP (clk, internalRst, SRSG_En, Si);
	SISA_1 : ENTITY WORK.SISA GENERIC MAP (SISA_Seed, SISA_Poly) 
			PORT MAP (clk, internalRst, SISA_En, So, SISA_Out);
	CNTRL : ENTITY WORK.RTS_Controller GENERIC MAP (ShiftSize, numOfCycles, numOfRounds) 
			PORT MAP (clk, test_reset, runLBIST, PbarS, internalRst, PRPG_En, SRSG_En, SISA_En, MISR_En, 
			done_Round, read_ROM, Ready, addr_ROM);	
	MUX: ENTITY WORK.MUX GENERIC MAP (PI_Size)
			PORT MAP (MUX_In1, PRPG_Out(PI_Size-1 DOWNTO 0), runLBIST, MUX_Out);	
	COMP : ENTITY WORK.Comparator GENERIC MAP (MISR_Seed'LENGTH, SISA_Seed'LENGTH)
			PORT MAP (Comp_In, data_ROM, Comp_Out);
	Tri_state: ENTITY WORK.Tri_state PORT MAP (Comp_Out, done_Round, FbarP);
	Sig_ROM : ENTITY WORK.ROM_Signature GENERIC MAP (MISR_Seed'LENGTH + SISA_Seed'LENGTH, numOfRounds)
			PORT MAP (clk, test_reset, read_ROM, addr_ROM, data_ROM);
	
	Comp_In <= (MISR_Out & SISA_Out); 
	-- Assign outputs to MISR_In
    MISR_In <= (Zeros & co & counter );
	-- Assign input pins to MUX_In1
    MUX_In1 <= (rst_pin & en_pin );
	-- Assign MUX_Out to inputs
    (rst & en ) <= MUX_Out;
			
END ARCHITECTURE arch;