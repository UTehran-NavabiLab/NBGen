
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY dff IS
PORT (
    D, C, CLR, PRE, CE, NbarT, Si, global_reset : IN STD_LOGIC;
    Q : OUT STD_LOGIC);
END ENTITY dff;

ARCHITECTURE behaviour OF dff IS
SIGNAL tmp : STD_LOGIC;
BEGIN
    PROCESS (C, PRE, CLR, global_reset)
    BEGIN
        IF (C = '1' AND C'EVENT AND PRE = '0' AND CLR = '0' AND global_reset = '0') THEN 
            IF NbarT = '1' THEN 
                tmp <= Si;
            END IF;
            IF (CE = '1' AND NbarT = '0') THEN 
                    tmp <= D;
            END IF;
        END IF;
        
        IF (CLR = '1' OR global_reset = '1') THEN 
            tmp <= '0';
        END IF;

        
        IF (PRE = '1' AND CLR = '0' AND global_reset = '0') THEN 
            tmp <= '1';
        END IF;
        
    END PROCESS;

PROCESS (tmp)
BEGIN
    IF (tmp = '1' AND tmp'EVENT) THEN
        Q <= tmp;
    END IF;
    IF (tmp = '0') THEN
        Q <= tmp;
    END IF;
END PROCESS;

END ARCHITECTURE behaviour;