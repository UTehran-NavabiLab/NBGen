------ ****  matrix_multiplier_plate1   ***** --------


LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.NUMERIC_STD.all; 


ENTITY Multiplier_Accumulator_Plate_1 IS 
GENERIC(
      n : INTEGER := 12
        );
PORT ( 
      clk,  rst,  run,  pause: IN STD_LOGIC;
      reg_out : OUT STD_LOGIC;
      din : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
      w : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
      dout : OUT STD_LOGIC_VECTOR (31 DOWNTO 0)
	   );
END Multiplier_Accumulator_Plate_1;	  


ARCHITECTURE behavioral_MAP1 OF Multiplier_Accumulator_Plate_1 IS 

	COMPONENT MAP_Controller IS 
	  PORT ( 
		  clk,  rst,  run,  pause : IN STD_LOGIC;
		  count : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
		  add_reg,  out_reg : OUT STD_LOGIC );  
	END COMPONENT;
	

	COMPONENT MAP_add IS 
	  PORT ( 
		  clk,  rst,  add_reg,  reg_out: IN STD_LOGIC;
		  din1 : IN STD_LOGIC_VECTOR(31 DOWNTO 0);
		  dout : OUT STD_LOGIC_VECTOR(31 DOWNTO 0));
	END COMPONENT;

SIGNAL mul_out , mul : STD_LOGIC_VECTOR(31 DOWNTO 0);
SIGNAL add_reg,  out_reg : STD_LOGIC;

BEGIN 

control : MAP_Controller 
  PORT MAP(  clk,  rst,  run,  pause,  STD_LOGIC_VECTOR(to_UNSIGNED(n,  4)),  add_reg,  out_reg );

add : MAP_add 
  PORT MAP( clk,  rst,  add_reg,  out_reg,  mul, dout );
    
mul <= STD_LOGIC_VECTOR (signed(din) * signed(w));

-- mul<= std_logic_vector( shift_right(signed(mul_out),12));

reg_out <= out_reg;

END behavioral_MAP1;	 

-----------------------------------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.NUMERIC_STD.all;

ENTITY MAP_Controller IS 
PORT ( 
  clk,  rst,  run,  pause : IN STD_LOGIC;
  count : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
  add_reg,  out_reg : OUT STD_LOGIC );       
END MAP_Controller;	  

ARCHITECTURE contr OF MAP_Controller IS 
  TYPE mini_state IS  (init,  mull,  add,  end_reg); -- add_pause,  
  SIGNAL ns,  ps : mini_state;
  SIGNAL i,  c : STD_LOGIC_VECTOR(3 DOWNTO 0);
  SIGNAL i_count : STD_LOGIC;
BEGIN 

PROCESS(clk) BEGIN 
  IF rising_edge(clk) then
    IF (rst ='1')then
      ps <= init; 
    ELSe  
      ps <= ns;  
    END IF;
  END IF;
END PROCESS;

PROCESS ( ps,  run,  pause,  i )
  BEGIN 
  CASE (ps) IS 
    WHEN init => 
      IF ( run = '1') then
        c <= count; 
		IF ( pause = '0') then 
			ns <= add;
		ELSe 
			ns <= mull;
		END IF;
      ELSe
        ns <= init;
      END IF;
    WHEN mull =>
      IF( pause ='1') then 
        ns <= mull;
      ELSe
        ns <= add;
      END IF;
    WHEN add =>
      IF( pause ='1') then 
        ns <= mull;
      ELSIF ( i =  STD_LOGIC_VECTOR(UNSIGNED(c)-1)) then
          ns <= end_reg;
        ELSe
         ns <= add;
        END IF;
    WHEN end_reg =>
      ns <= init;
    WHEN OTHERS =>
      ns <= init;
   END CASE;
END PROCESS;
 
PROCESS (ps) 
  BEGIN     
    add_reg <= '0';
    out_reg <= '0';
	i_count <= '0';
    CASE ps IS 
		WHEN add =>
		  i_count <= '1';
		  add_reg <= '1';
		WHEN end_reg =>
		  out_reg <= '1';
		WHEN OTHERS =>
		  i_count <= '0';
		  add_reg <= '0';
		  out_reg <= '0';
   END CASE;  
 END PROCESS;


	 PROCESS (clk,  run,  i_count)
	   BEGIN 
		 IF rising_edge (clk ) then 
		     IF ( run = '1') then 
				i <= "0000"; 
		     ELSIF ( i_count = '1')then
		        i <= STD_LOGIC_VECTOR(UNSIGNED(i)+1);
		     END IF;
	     END IF;
	  END PROCESS;

END contr;	 

------------------------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.NUMERIC_STD.all;

ENTITY MAP_add IS 
PORT ( 
      clk,  rst, add_reg, reg_out: IN STD_LOGIC;
      din1 : IN STD_LOGIC_VECTOR(31 DOWNTO 0);
	  dout : OUT STD_LOGIC_VECTOR(31 DOWNTO 0));
END MAP_add;	  

ARCHITECTURE behaviorall OF MAP_add IS 

SIGNAL outreg,  d_reg1,  d_reg2 : STD_LOGIC_VECTOR(31 DOWNTO 0);

BEGIN 

 PROCESS(clk)
	 BEGIN 
	   IF rising_edge(clk )then
	     IF (rst ='1') then
			d_reg2 <= (OTHERS => '0');
		 ELSIF (add_reg = '1')then
			d_reg2 <= d_reg1;
		 ELSIF (reg_out ='1') then
			outreg <= d_reg2;
			d_reg2 <= (OTHERS =>'0');
		 ELSE
			d_reg2 <= d_reg2;
			outreg <= outreg;
		 END IF; 
	   END IF;
	END PROCESS;  
	
d_reg1 <= STD_LOGIC_VECTOR(SIGNED (din1) + SIGNED (d_reg2));
dout <= outreg;
 
END behaviorall;	

