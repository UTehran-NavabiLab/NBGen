--******************************************************************************
--	Filename:		SRSG.vhd
--	Project:		SAYAC Testing 
--  Version:		0.90
--	History:
--	Date:			20 June 2022
--	Last Author: 	Delaram Mohammadzadeh
--  Copyright (C) 2022 University of Tehran
--  This source file may be used and distributed without
--  restriction provided that this copyright statement is not
--  removed from the file and that any derivative work contains
--  the original copyright notice and the associated disclaimer.
--
--******************************************************************************
--	File content description:
--	SRSG (Pseudo Random Sequence Generator)                             
--******************************************************************************

LIBRARY ieee;     
use IEEE.std_logic_1164.all;
	
ENTITY SRSG IS
    GENERIC (seed, poly: STD_LOGIC_VECTOR);
	PORT (
		clk, rst, en : IN STD_LOGIC;
		Sout : OUT STD_LOGIC
	);
END ENTITY SRSG;

ARCHITECTURE behaviour OF SRSG IS
SIGNAL data : STD_LOGIC_VECTOR (seed'LENGTH-1 DOWNTO 0);
BEGIN  
	PROCESS (clk) BEGIN
        IF (clk='1' AND clk'EVENT) THEN
            IF (rst ='1') THEN 
                data <= seed;
            ELSE
                IF en = '1' THEN
                    data(seed'LENGTH-1) <= data(0);
                    FOR i IN 0 TO seed'LENGTH-2 LOOP
                        data(i) <= (data(0) AND poly(i)) XOR data(i + 1);
                    END LOOP;
                END IF;
            END IF;
        END IF;
	END PROCESS;
    Sout <= data(0);
END ARCHITECTURE behaviour;
------------------------------------------------------------------------------------------------