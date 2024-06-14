		--------- matrix_multiplier_plate

		LIBRARY IEEE;
		USE IEEE.STD_LOGIC_1164.ALL;
		USE IEEE.NUMERIC_STD.All;

		ENTITY MAPn IS 
		  GENERIC( ---- config is the same as testbench of "5__Verfiying Mahboobeh's RTL with My Python version"
			  h : INTEGER := 2; --number of dimensions
			  a : INTEGER := 4; -- from last layers to the first ones
			  b : INTEGER := 6;
			  c : INTEGER := 1;
			  d : INTEGER := 1;
			  e : INTEGER := 1;
			  f : INTEGER := 1;
			  k : INTEGER := 12 ---number of MAP1's clock (n0)
				);
		  PORT (clk,  rst,  run,  pause : IN STD_LOGIC ;
				reg_out : OUT STD_LOGIC;
				din : IN STD_LOGIC_VECTOR(16*a*b*c*d*e*f -1 DOWNTO 0);
				w : IN STD_LOGIC_VECTOR(16*a*b*c*d*e*f -1 DOWNTO 0);
				dout : OUT STD_LOGIC_VECTOR (31 DOWNTO 0)
			   );
		END MAPn;	  


		ARCHITECTURE behavioral_MAPn OF MAPn IS 


		COMPONENT MAPn IS 
		  GENERIC(
			  h : INTEGER;
			  a : INTEGER;
			  b : INTEGER;
			  c : INTEGER;
			  d : INTEGER;
			  e : INTEGER;
			  f : INTEGER;
			  k : INTEGER
				);
		  PORT (clk,  rst,  run,  pause : IN STD_LOGIC ;
				reg_out : OUT STD_LOGIC;
				din : IN STD_LOGIC_VECTOR(16*b*c*d*e*f*a -1 DOWNTO 0);
				w : IN STD_LOGIC_VECTOR(16*b*c*d*e*f*a -1 DOWNTO 0);
				dout : OUT STD_LOGIC_VECTOR (31 DOWNTO 0)
			   );
		END COMPONENT;
		
		COMPONENT  Multiplier_Accumulator_Plate_1 IS 
		GENERIC(
			  n : INTEGER
				);
		PORT ( 
			  clk,  rst,  run,  pause: IN STD_LOGIC;
			  reg_out : OUT STD_LOGIC;
			  din : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
			  w : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
			  dout : OUT STD_LOGIC_VECTOR (31 DOWNTO 0)
			   );
		END COMPONENT;


		COMPONENT Convergence_Accumulator_Plate IS 
		  GENERIC(
			  n : INTEGER
				);
		  PORT ( clk,  rst,  run : IN STD_LOGIC ;
				 reg_out : OUT STD_LOGIC;
				 din : IN STD_LOGIC_VECTOR(32*n-1 DOWNTO 0);
				 dout: OUT STD_LOGIC_VECTOR (31 DOWNTO 0)
			   );
		END COMPONENT;

		SIGNAL rego : STD_LOGIC_VECTOR (a DOWNTO 1 );
		SIGNAL regocap : STD_LOGIC_VECTOR (h+1 DOWNTO 0 ) := (others => '0');
		--SIGNAL rego3 : STD_LOGIC_VECTOR (k DOWNTO 1 );
		--SIGNAL rego4 : STD_LOGIC_VECTOR (l DOWNTO 1 );


		--SIGNAL cap1_in : STD_LOGIC_VECTOR ( 16*m*k-1 DOWNTO 0);
		--SIGNAL input_2d : STD_LOGIC_VECTOR ( 16*m-1 DOWNTO 0);


		SIGNAL data_out_map : STD_LOGIC_VECTOR(32*a -1 DOWNTO 0);
		--SIGNAL data_out_map2 : STD_LOGIC_VECTOR(32*k*l -1 DOWNTO 0);
		--SIGNAL data_out_map3 : STD_LOGIC_VECTOR(32*l -1 DOWNTO 0);


		BEGIN 

			regocap(h) <= run;

			h0 : if h = 1 generate
				MAP_1s: FOR I IN 1 TO a GENERATE
					   MAP1 :  Multiplier_Accumulator_Plate_1
					   GENERIC MAP( k )
						PORT MAP (  
							 clk,  rst,  run,  pause,  rego(I),
							 din(((I*16)-1) DOWNTO ((I-1)*16)),  
							 w(((I*16)-1) DOWNTO ((I-1)*16)),  
							 data_out_map((I*32)-1 DOWNTO (I-1)*32)
							 );
					  END GENERATE MAP_1s;
				CAP_1 : Convergence_Accumulator_Plate 
					GENERIC MAP (a)
					PORT MAP( 
						clk,  rst,  rego(1),  
						regocap(0),  
						data_out_map,  
						dout
						);
			end generate h0;
			
			hb0 : if h > 1 generate
				MAP_ns_for : FOR i in 1 to a generate
					MAP_ns : MAPn 
						  GENERIC map( h-1, b, c, d, e, f, 1, k )
						  PORT map(clk,  rst,  regocap(h),  pause,
								rego(i),
								din (16*b*c*d*e*f*(i) -1 downto 16*b*c*d*e*f*(i-1)),
								w (16*b*c*d*e*f*(i) -1 downto 16*b*c*d*e*f*(i-1)),
								data_out_map((32*i)-1 downto 32*(i-1)) 
							   );
							   
				END GENERATE MAP_ns_for;
				CAP_n : Convergence_Accumulator_Plate 
					GENERIC MAP (a)
					PORT MAP( 
						clk,  rst,  rego(1),  
						regocap(h-1),  
						data_out_map,  
						dout
						);
			END GENERATE hb0;
				
				
			reg_out <= regocap(h-1);
				
		END behavioral_MAPn;


		------------ CONFIGURATION declaration


		LIBRARY IEEE;
		USE IEEE.STD_LOGIC_1164.ALL;
		USE IEEE.NUMERIC_STD.All;

		CONFIGURATION config_nd OF MAPn IS
		 	FOR behavioral_MAPn
				FOR h0
					FOR MAP_1s
						FOR MAP1 : Multiplier_Accumulator_Plate_1 
							USE ENTITY work.Multiplier_Accumulator_Plate_1 (behavioral_MAP1);
						END FOR;		
					END FOR;
					FOR CAP_1 : Convergence_Accumulator_Plate 
						USE ENTITY work.Convergence_Accumulator_Plate (behavioral_CAP);
					END FOR;
				END FOR;  --- h0
				
				FOR hb0
					FOR MAP_ns_for
						FOR MAP_ns : MAPn 
							use configuration config_nd;
						END FOR;		
					END FOR;	
					FOR CAP_n : Convergence_Accumulator_Plate 
						USE ENTITY work.Convergence_Accumulator_Plate (behavioral_CAP);
					END FOR;
				END FOR;  --- hb0
			end for;	
		END CONFIGURATION config_nd;






