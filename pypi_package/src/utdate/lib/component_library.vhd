LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
	
ENTITY nor_n IS
	PORT (
		A : IN STD_LOGIC_VECTOR (1 DOWNTO 0);
		Y   : OUT STD_LOGIC);
END ENTITY nor_n;

ARCHITECTURE behaviour OF nor_n IS
BEGIN
	Y <= A(0) NOR A(1);
END ARCHITECTURE behaviour;
------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY nand_n IS
	PORT (
		A : IN STD_LOGIC_VECTOR (1 DOWNTO 0);
		Y   : OUT STD_LOGIC);
END ENTITY nand_n;

ARCHITECTURE behaviour OF nand_n IS
BEGIN
	Y <= A(0) NAND A(1);
END ARCHITECTURE behaviour;
------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY notg IS
	PORT (
		A : IN STD_LOGIC;
		Y   : OUT STD_LOGIC);
END ENTITY notg;

ARCHITECTURE behaviour OF notg IS
BEGIN
	Y <= NOT A;
END ARCHITECTURE behaviour;
------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY pin IS
	PORT (
		I : IN STD_LOGIC;
		O   : OUT STD_LOGIC);
END ENTITY pin;

ARCHITECTURE behaviour OF pin IS
BEGIN
	O <= I;
END ARCHITECTURE behaviour;
------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY pout IS
	PORT (
		I : IN STD_LOGIC;
		O   : OUT STD_LOGIC);
END ENTITY pout;

ARCHITECTURE behaviour OF pout IS
BEGIN
	O <= I;
END ARCHITECTURE behaviour;
------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY dff IS
	PORT (
		D, C, R, PRE, CE, NbarT, Si, global_reset : IN STD_LOGIC;
		Q : OUT STD_LOGIC);
END ENTITY dff;

ARCHITECTURE behaviour OF dff IS
	SIGNAL tmp : STD_LOGIC;
BEGIN
	PROCESS (C, PRE, R, global_reset)
	BEGIN
		IF (R = '1' OR global_reset = '1') THEN
			tmp <= '0';
		ELSIF (PRE = '1' AND PRE'EVENT) THEN
			tmp <= '1';
		ELSIF (C = '1' AND C'EVENT) THEN
			IF NbarT = '1' THEN
				tmp <= Si;
			ELSIF CE = '1' THEN
				tmp <= D;
			END IF;
		END IF;
	END PROCESS;
	
	PROCESS (tmp)
	BEGIN
		IF (tmp = '1' AND tmp'EVENT) THEN
			Q <= tmp;
		ELSIF (tmp = '0' AND tmp'EVENT) THEN
			Q <= tmp;
		END IF;
	END PROCESS;
	
END ARCHITECTURE behaviour;