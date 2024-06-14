---- convergence adding plate

LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.NUMERIC_STD.all;

ENTITY Convergence_Accumulator_Plate IS 
  GENERIC(
      n : INTEGER := 4
        );
  PORT ( clk, rst, run : IN STD_LOGIC ;
        reg_out : OUT STD_LOGIC;
	    din : IN STD_LOGIC_VECTOR(32*n-1 DOWNTO 0);
        dout: OUT STD_LOGIC_VECTOR (31 DOWNTO 0)
       );
END Convergence_Accumulator_Plate;	  


ARCHITECTURE behavioral_CAP OF Convergence_Accumulator_Plate IS 

	COMPONENT  mux_cascading IS 
    PORT (
			sel : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
			din : IN STD_LOGIC_VECTOR (511 DOWNTO 0);
			dout : OUT STD_LOGIC_VECTOR(31 DOWNTO 0)
			);
	END COMPONENT;


	COMPONENT CAP_controller IS 
	  PORT ( 
		  clk, rst, run : IN STD_LOGIC;
		  count : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
		  sel : OUT STD_LOGIC_VECTOR (3 DOWNTO 0);
		  in_reg, add_reg, out_reg : OUT STD_LOGIC 
		  );       
	END COMPONENT;


	COMPONENT add IS 
	  PORT (
			clk , in_reg , add_reg , reg_out : IN STD_LOGIC;
			din : IN STD_LOGIC_VECTOR (31 DOWNTO 0);
			dout : OUT STD_LOGIC_VECTOR(31 DOWNTO 0)
			);
	END COMPONENT;

SIGNAL doutm: STD_LOGIC_VECTOR(31 DOWNTO 0);
SIGNAL add_reg,in_reg, out_reg: STD_LOGIC;
SIGNAL sel : STD_LOGIC_VECTOR(3 DOWNTO 0);

SIGNAL data_in_max : STD_LOGIC_VECTOR (32*16-1 DOWNTO 0);

BEGIN 
	 PROCESS ( din)
	 BEGIN  
		IF( n < 16) then
			data_in_max(32*n-1 DOWNTO 0)  <= din;
			data_in_max(511 DOWNTO 32*n)  <= (OTHERS => '0');
		ELSe
			data_in_max <= din;
		END IF;
	END PROCESS;

	  C_add : add
		   PORT MAP(clk ,in_reg,add_reg ,out_reg ,
			doutm,
			dout
			);
	  mux : mux_cascading 
		  PORT MAP(
				sel ,
				data_in_max,
				doutm
				);      
	  c_add_ctrl : CAP_controller 
		   PORT MAP( 
		   clk, rst, run ,
		  	STD_LOGIC_VECTOR(to_UNSIGNED(n , 4)),
		  	sel,
		  	in_reg,add_reg, out_reg );

     reg_out <= out_reg;
END behavioral_CAP;
------------------------------------------------------------------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.NUMERIC_STD.all;

ENTITY CAP_controller IS 
PORT ( 
  clk, rst, run : IN STD_LOGIC;
  count : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
  sel : OUT STD_LOGIC_VECTOR (3 DOWNTO 0);
  in_reg, add_reg, out_reg : OUT STD_LOGIC );       
END CAP_controller;	  

ARCHITECTURE contr OF CAP_controller IS 
	
  COMPONENT counter IS 
	  GENERIC ( n : INTEGER := 8 );
	  PORT (clk ,rst , en : IN STD_LOGIC;
			c : OUT STD_LOGIC_VECTOR(n DOWNTO 0) 
			 );
	END COMPONENT;
	COMPONENT reg IS 
PORT (clk , en : IN STD_LOGIC;
      din : IN STD_LOGIC_VECTOR(31 DOWNTO 0);
	    dout : OUT STD_LOGIC_VECTOR(31 DOWNTO 0));
END COMPONENT;
  TYPE cascade_state IS  (idel , init, add, end_reg);
  SIGNAL ns , ps : cascade_state;
  SIGNAL i_count : STD_LOGIC;
  SIGNAL i , c  : STD_LOGIC_VECTOR(3 DOWNTO 0);
BEGIN 

  c <= STD_LOGIC_VECTOR(UNSIGNED(count)-2) ;
	PROCESS(clk) BEGIN 
	  IF rising_edge(clk) then
		IF (rst ='1')then
		  ps <= idel; 
		ELSE  
		  ps <= ns;  
		END IF;
	  END IF;
	END PROCESS;
	
	PROCESS(ps ,rst, run , i,c) BEGIN 
	  CASE (ps) IS 
		WHEN idel => 
		  IF ( rst = '0') then
			   ns <= init;
		  ELSe
			   ns <= idel;
		  END IF;
		WHEN init =>
		  IF ( run = '1') then
			   ns <= add; 
		  ELSe
			   ns <= init;
		  END IF;
		WHEN add =>
		  IF ( UNSIGNED(i) > UNSIGNED(c) ) then
			   ns <= end_reg;
		  ELSe
			   ns <= add;
		  END IF;
		WHEN end_reg =>
		   ns <= init;
		WHEN OTHERS =>
		  ns <= idel;
	   END CASE;
	END PROCESS;
	 
	PROCESS (ps ) 
	  BEGIN 
		  i_count <= '0';
		  add_reg <= '0';
		  out_reg <= '0';
		  in_reg <= '0';
		CASE ps IS 
		WHEN init =>
		WHEN idel => 
		   in_reg <='1';
		WHEN add =>
		   add_reg <= '1';
		   i_count <= '1';
		WHEN end_reg =>
		   out_reg <= '1';
		WHEN OTHERS =>
		   i_count <= '0';
		   add_reg <= '0';
		   out_reg <= '0';
		   in_reg <= '0';
	   END CASE;  
	  END PROCESS;

count_i : counter 
  GENERIC MAP ( 3 )
  PORT MAP (clk ,run , i_count , i );

	

	sel <= i;

END contr;


------------------------------------------------------------------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.NUMERIC_STD.all; 

ENTITY mux_cascading IS 
  PORT (
        sel : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
        din : IN STD_LOGIC_VECTOR (511 DOWNTO 0);
        dout : OUT STD_LOGIC_VECTOR(31 DOWNTO 0)
        );
END mux_cascading;

architecture behavioral OF mux_cascading IS  
BEGIN  
	 
	 PROCESS(sel , din)
		 BEGIN 
		  CASE (sel)  IS  
			WHEN "0000" => dout <= din(31 DOWNTO 0) ;
			WHEN "0001" => dout <= din(63 DOWNTO 32) ;
			WHEN "0010" => dout <= din(95 DOWNTO 64) ;
			WHEN "0011" => dout <= din(127 DOWNTO 96) ;
			WHEN "0100" => dout <= din(159 DOWNTO 128) ;
			WHEN "0101" => dout <= din(191 DOWNTO 160) ;
			WHEN "0110" => dout <= din(223 DOWNTO 192) ;
			WHEN "0111" => dout <= din(255 DOWNTO 224) ;
		    WHEN "1000" => dout <= din(287 DOWNTO 256) ;
		    WHEN "1001" => dout <= din(319 DOWNTO 288) ;
		    WHEN "1010" => dout <= din(351 DOWNTO 320) ;
		    WHEN "1011" => dout <= din(383 DOWNTO 352) ;
		    WHEN "1100" => dout <= din(415 DOWNTO 384) ;
		    WHEN "1101" => dout <= din(447 DOWNTO 416) ;
		    WHEN "1110" => dout <= din(479 DOWNTO 448) ;
		    WHEN "1111" => dout <= din(511 DOWNTO 480) ;
			WHEN OTHERS => dout <= (OTHERS =>'0'); 
		  END CASE;
		  
	 END PROCESS;  

END behavioral;	 

------------------------------------------------------------------------------------------------------------------------------------------

LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.NUMERIC_STD.all; 

ENTITY add IS 
  PORT (clk , in_reg , add_reg , reg_out : IN STD_LOGIC;
        din : IN STD_LOGIC_VECTOR (31 DOWNTO 0);
        dout : OUT STD_LOGIC_VECTOR(31 DOWNTO 0)
        );
END add;

architecture behavioral OF add IS  

SIGNAL  val1, outm1, d_reg1 :STD_LOGIC_VECTOR(31 DOWNTO 0);


BEGIN  
	 PROCESS(clk)
		 BEGIN 
		   IF rising_edge(clk )then
			  IF(add_reg = '1')then
				   d_reg1 <= val1;
			  ELSIF ( in_reg ='1') then 
				  d_reg1 <= (OTHERS=>'0');
			  ELSIF (reg_out ='1') then
				   d_reg1 <= (OTHERS=>'0');
			  END IF;

			  IF (reg_out ='1') then
				   outm1 <= d_reg1;
			  END IF;
		 END IF;
	END PROCESS;  

	val1 <= STD_LOGIC_VECTOR (SIGNED(din) + SIGNED(d_reg1));

	dout <= outm1 ;   


END behavioral;	 

------------------------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.NUMERIC_STD.all;


ENTITY counter IS 
  GENERIC ( n : INTEGER := 8 );
  PORT (clk ,rst , en : IN STD_LOGIC;
        c : OUT STD_LOGIC_VECTOR(n DOWNTO 0) 
         );
END counter;

architecture behavioral1 OF counter IS  
SIGNAL counter_signal : STD_LOGIC_VECTOR( n DOWNTO 0);
BEGIN  
 
 process(clk)
 BEGIN 
	if (rising_edge (clk)) then
		if (rst ='1') then
			counter_signal <= (others =>'0');
		elsif (en = '1') then 
			counter_signal <= STD_LOGIC_VECTOR(unsigned(counter_signal)+1); 
		END if;
	END if;
END process;  

c <= counter_signal;

END behavioral1;