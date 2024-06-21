----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:43:23 01/22/2024 
-- Design Name: 
-- Module Name:    monitor - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use IEEE.Numeric_Std.ALL;


-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity monitor is
  port ( CLK_25MHz: in std_logic;
			DOT: in std_logic;
			DASH: in std_logic;
			SPACE: in std_logic;
			RESET: in std_logic;
			LED, LED2, LED3: inout std_logic := '0';
         VS: out std_logic;
			HS: out std_logic;
			RED: out std_logic_vector(1 downto 0);    --+++
			GREEN: out std_logic_vector(1 downto 0);  --+++
			BLUE: out std_logic_vector(1 downto 0)    --+++
  );
end monitor;

architecture Behavioral of monitor is
 -- VGA Definitions starts
  constant HDisplayArea: integer:= 640; -- horizontal display area
  constant HLimit: integer:= 800; -- maximum horizontal amount (limit)
  constant HFrontPorch: integer:= 51; -- h. front porch -p:16
  constant HBackPorch: integer:= 48;	-- h. back porch
  constant HSyncWidth: integer:= 96;	-- h. pulse width
  
  constant VDisplayArea: integer:= 480; -- vertical display area
  constant VLimit: integer:= 525; -- maximum vertical amount (limit)
  constant VFrontPorch: integer:= 35;	-- v. front porch p:10
  constant VBackPorch: integer:= 33;	-- v. back porch
  constant VSyncWidth: integer:= 2;	-- v. pulse width      
  
--  signal Clk_25MHz: std_logic := '0';  
  signal HBlank, VBlank, Blank: std_logic := '0';
    
  signal CurrentHPos: std_logic_vector(10 downto 0) := (others => '0'); -- goes to 1100100000 = 800
  signal CurrentVPos: std_logic_vector(10 downto 0) := (others => '0'); -- goes to 1000001101 = 525
  signal ScanlineX, ScanlineY: std_logic_vector(10 downto 0) := (others => '0');
  
  signal ColorOutput: std_logic_vector(5 downto 0);
  
  -- VGA Definitions end
  --- information
	--	Visible area = (1/25175000)*640 = 25.422045680238
	-- Visible area = (1/25175000)*800*480 = 15.253227408143
	--	Vertical refresh = 25.175 MHz / 800 (Whole line) = 31.46875 KHz
	
	
	
	type dataout is array (0 to 15,0 to 7) of std_logic;
--	type dataout is array (0 to 15) of std_logic_vector(0 to 7);
type RAM_ARRAY is array (0 to 607,0 to 7) of std_logic;
-- initial values in the RAM
signal RAM: RAM_ARRAY :=(
				"00000000",
				"00000000",
				"00010000",
				"00111000",
				"01101100",
				"11000110",
				"11000110",
				"11111110",
				"11000110",
				"11000110",
				"11000110",
				"11000110",
				"00000000",
				"00000000",
				"00000000",
				"00000000", --- A ---
				"00000000",
				"00000000",
				"11111000",
				"11001100",
				"11000110",
				"11001100",
				"11111100",
				"11000110",
				"11000110",
				"11000110",
				"11001100",
				"11111000",
				"00000000",
				"00000000",
				"00000000",
				"00000000", --- B ---
				"00000000",
				"00000000",
				"01111100",
				"11001110",
				"11000110",
				"11000000",
				"11000000",
				"11000000",
				"11000000",
				"11000110",
				"11001110",
				"01111100",
				"00000000",
				"00000000",
				"00000000",
				"00000000", --- C ---
				"00000000",
				"00000000",
				"11111000",
				"11001100",
				"11000110",
				"11000110",
				"11000110",
				"11000110",
				"11000110",
				"11000110",
				"11001100",
				"11111000",
				"00000000",
				"00000000",
				"00000000",
				"00000000", --- D ---
				"00000000",
				"00000000",
				"11111110",
				"11000010",
				"11000000",
				"11000100",
				"11111100",
				"11000100",
				"11000000",
				"11000000",
				"11000010",
				"11111110",
				"00000000",
				"00000000",
				"00000000",
				"00000000", --- E ---
				"00000000",
				"00000000",
				"11111110",
				"11000010",
				"11000000",
				"11000100",
				"11111100",
				"11000100",
				"11000000",
				"11000000",
				"11000000",
				"11100000",
				"00000000",
				"00000000",
				"00000000",
				"00000000", --- F ---
				"00000000",
				"00000000",
				"11111110",
				"11000110",
				"11000010",
				"11000000",
				"11000000",
				"11001110",
				"11000110",
				"11000110",
				"11000110",
				"11111110",
				"00000000",
				"00000000",
				"00000000",
				"00000000", --- G ---
				"00000000",
				"00000000",
				"11000110",
				"11000110",
				"11000110",
				"11000110",
				"11111110",
				"11111110",
				"11000110",
				"11000110",
				"11000110",
				"11000110",
				"00000000",
				"00000000",
				"00000000",
				"00000000", --- H ---
				"00000000",
				"00000000",
				"00111100",
				"00011000",
				"00011000",
				"00011000",
				"00011000",
				"00011000",
				"00011000",
				"00011000",
				"00011000",
				"00111100",
				"00000000",
				"00000000",
				"00000000",
				"00000000", --- I ---
				"00000000",
				"00000000",
				"00011110",
				"00001100",
				"00001100",
				"00001100",
				"00001100",
				"00001100",
				"00001100",
				"11001100",
				"11001100",
				"01111000",
				"00000000",
				"00000000",
				"00000000",
				"00000000", --- J ---
				"00000000",
				"00000000",
				"11000110",
				"11001100",
				"11011000",
				"11110000",
				"11100000",
				"11110000",
				"11011000",
				"11001100",
				"11000110",
				"11000010",
				"00000000",
				"00000000",
				"00000000",
				"00000000", --- K ---
				"00000000",
				"00000000",
				"11000000",
				"11000000",
				"11000000",
				"11000000",
				"11000000",
				"11000000",
				"11000000",
				"11000000",
				"11000110",
				"11111110",
				"00000000",
				"00000000",
				"00000000",
				"00000000", --- L ---
				"00000000",
				"00000000",
				"11101110",
				"10101010",
				"10101010",
				"10101010",
				"10111010",
				"10010010",
				"10000010",
				"10000010",
				"10000010",
				"10000010",
				"00000000",
				"00000000",
				"00000000",
				"00000000", --- M ---
				"00000000",
				"00000000",
				"11100010",
				"10100010",
				"10100010",
				"10100010",
				"10010010",
				"10010010",
				"10010010",
				"10001010",
				"10001010",
				"10001110",
				"00000000",
				"00000000",
				"00000000",
				"00000000", --- N ---
				"00000000",
				"00000000",
				"00111000",
				"01101100",
				"11000110",
				"11000110",
				"11000110",
				"11000110",
				"11000110",
				"11000110",
				"01101100",
				"00111000",
				"00000000",
				"00000000",
				"00000000",
				"00000000", --- O ---
				"00000000",
				"00000000",
				"11111000",
				"11001100",
				"11000110",
				"11000110",
				"11001110",
				"11111000",
				"11000000",
				"11000000",
				"11000000",
				"11100000",
				"00000000",
				"00000000",
				"00000000",
				"00000000", --- P ---
				"00000000",
				"00000000",
				"00111000",
				"01101100",
				"11000110",
				"11000110",
				"11000110",
				"11000110",
				"11000110",
				"11010110",
				"01101100",
				"00111010",
				"00000000",
				"00000000",
				"00000000",
				"00000000", --- Q ---
				"00000000",
				"00000000",
				"11111000",
				"11001100",
				"11000110",
				"11000110",
				"11001110",
				"11111000",
				"11110000",
				"11011000",
				"11001100",
				"11000110",
				"00000000",
				"00000000",
				"00000000",
				"00000000", --- R ---
				"00000000",
				"00000000",
				"01111110",
				"11000000",
				"11000000",
				"01100000",
				"00110000",
				"00011000",
				"00001100",
				"00000110",
				"00001100",
				"11111000",
				"00000000",
				"00000000",
				"00000000",
				"00000000", --- S ---
				"00000000",
				"00000000",
				"11111110",
				"10010010",
				"00010000",
				"00010000",
				"00010000",
				"00010000",
				"00010000",
				"00010000",
				"00010000",
				"00111000",
				"00000000",
				"00000000",
				"00000000",
				"00000000", --- T ---
				"00000000",
				"00000000",
				"11000110",
				"11000110",
				"11000110",
				"11000110",
				"11000110",
				"11000110",
				"11000110",
				"11000110",
				"01101100",
				"00111000",
				"00000000",
				"00000000",
				"00000000",
				"00000000", --- U ---
				"00000000",
				"00000000",
				"11000110",
				"11000110",
				"11000110",
				"01101100",
				"01101100",
				"01101100",
				"00111000",
				"00111000",
				"00010000",
				"00010000",
				"00000000",
				"00000000",
				"00000000",
				"00000000", --- V ---
				"00000000",
				"00000000",
				"10000010",
				"10000010",
				"10000010",
				"10000010",
				"10111010",
				"10101010",
				"10101010",
				"10101010",
				"10101010",
				"11101110",
				"00000000",
				"00000000",
				"00000000",
				"00000000", --- W ---
				"00000000",
				"00000000",
				"11000110",
				"11000110",
				"01101100",
				"01101100",
				"00111000",
				"01111100",
				"01101100",
				"01101100",
				"11000110",
				"11000110",
				"00000000",
				"00000000",
				"00000000",
				"00000000", --- X ---
				"00000000",
				"00000000",
				"11000110",
				"11000110",
				"11000110",
				"01101100",
				"00111000",
				"00010000",
				"00010000",
				"00010000",
				"00010000",
				"00010000",
				"00000000",
				"00000000",
				"00000000",
				"00000000", --- Y ---
				"00000000",
				"00000000",
				"11111110",
				"11111110",
				"00000110",
				"00001100",
				"00011000",
				"00110000",
				"01100000",
				"11000000",
				"11111110",
				"11111110",
				"00000000",
				"00000000",
				"00000000",
				"00000000", --- Z ---
				"00000000",
				"00000000",
				"01111100",
				"11000110",
				"11000110",
				"11000110",
				"11000110",
				"11000110",
				"11000110",
				"11000110",
				"11000110",
				"01111100",
				"00000000",
				"00000000",
				"00000000",
				"00000000", --- ZERO ---
				"00000000",
				"00000000",
				"00111000",
				"01011000",
				"00011000",
				"00011000",
				"00011000",
				"00011000",
				"00011000",
				"00011000",
				"00111100",
				"00111100",
				"00000000",
				"00000000",
				"00000000",
				"00000000", --- ONE ---
				"00000000",
				"00000000",
				"11111100",
				"11000110",
				"11000110",
				"00001100",
				"00011000",
				"00110000",
				"11000000",
				"11000000",
				"11111110",
				"11111110",
				"00000000",
				"00000000",
				"00000000",
				"00000000", --- TWO ---
				"00000000",
				"00000000",
				"01111100",
				"11000110",
				"01000110",
				"00000110",
				"00000100",
				"00111100",
				"00000100",
				"01000110",
				"11000110",
				"01111100",
				"00000000",
				"00000000",
				"00000000",
				"00000000", --- THREE ---
				"00000000",
				"00000000",
				"11000110",
				"11000110",
				"11000110",
				"11000110",
				"11111110",
				"11111110",
				"00000110",
				"00000110",
				"00000110",
				"00000110",
				"00000000",
				"00000000",
				"00000000",
				"00000000", --- FOUR ---
				"00000000",
				"00000000",
				"11111110",
				"11111110",
				"11000000",
				"11000000",
				"01110000",
				"00011000",
				"00001100",
				"00000110",
				"11001100",
				"11111000",
				"00000000",
				"00000000",
				"00000000",
				"00000000", --- FIVE ---
				"00000000",
				"00000000",
				"00000110",
				"00001100",
				"00011000",
				"00110000",
				"01100000",
				"11111100",
				"11000110",
				"11000110",
				"01100110",
				"00111100",
				"00000000",
				"00000000",
				"00000000",
				"00000000", --- SIX ---
				"00000000",
				"00000000",
				"11111110",
				"11111100",
				"00001100",
				"00011000",
				"00011000",
				"00110000",
				"00110000",
				"01100000",
				"01100000",
				"11000000",
				"00000000",
				"00000000",
				"00000000",
				"00000000", --- SEVEN ---
				"00000000",
				"00000000",
				"00111000",
				"01101100",
				"11000110",
				"01101100",
				"00111000",
				"01101100",
				"11000110",
				"11000110",
				"01101100",
				"00111000",
				"00000000",
				"00000000",
				"00000000",
				"00000000", --- EIGHT ---
				"00000000",
				"00000000",
				"00111100",
				"01100110",
				"11000110",
				"11000110",
				"01100110",
				"00111110",
				"00000110",
				"00000110",
				"00001100",
				"11111000",
				"00000000",
				"00000000",
				"00000000",
				"00000000", --- NINE ---
				"00000000",
				"00000000",
				"00000000",
				"00000000",
				"00000000",
				"00000000",
				"00000000",
				"00000000",
				"00000000",
				"00000000",
				"00011000",
				"00011000",
				"00000000",
				"00000000",
				"00000000",
				"00000000", --- DOT ---
				"00000000",
				"00000000",
				"00000000",
				"00000000",
				"00000000",
				"00000000",
				"00000000",
				"00000000",
				"00000000",
				"00000000",
				"00000000",
				"00000000",
				"00000000",
				"00000000",
				"00000000",
				"00000000" --- SPACE ---

);

	type line is array (0 to 15,0 to 639) of std_logic;
	signal line1 : line := (others => (others=>'0'));
--	signal line2 : line := (others => (others=>'0'));
	signal line1_update: std_logic := '0';
	signal xpointer : integer range 0 to 640 := 0;
	
	signal CLK_25Hz : std_logic := '0';
	signal counter : integer := 0;
	signal DOT_LOCK,DOT_CLICKED : std_logic := '0';
	signal DASH_LOCK,DASH_CLICKED : std_logic := '0';
	signal SPACE_LOCK,SPACE_CLICKED : std_logic := '0';
	
--	signal letter: std_logic_vector(0 to 6) := "0000000";
--	type letter_type is array (0 to 7,0 to 3) of bit;
	type letter_type is array (0 to 7) of std_logic_vector(0 to 1);
	signal letter : letter_type := (others => "00");

	signal letter_counter: integer range 0 to 6 := 0; 
	

   -- Clock period definitions
 --  constant RAM_CLOCK_period : time := 10 ns;
	
	procedure  writing(signal line1 : out line;
							signal ram : in RAM_ARRAY;
							signal letter : out letter_type;
							signal letter_counter : inout integer;
							signal xpointer : inout integer;
							constant	pattern : in integer) is
			variable f : integer range 0 to 640:= 0;
	begin
		
		for ii in 0 to 15 loop
			for jj in 0 to 639 loop
				if(jj >= xpointer and  jj < xpointer + 8 ) then
						
						line1(ii,jj) <= ram((pattern * 16) + (ii MOD 16) , jj MOD 8);

				end if;
			end loop;
		end loop;
		xpointer <= xpointer + 8;
		letter <= (others => "00");
		letter_counter <= 0;
	end procedure;  
begin
  --Generate25MHz: process (CLK_50MHz)
  --begin
    --if rising_edge(CLK_50MHz) then
	   --Clk_25MHz <= not Clk_25MHz;
	 --end if;
  --end process Generate25MHz;
  
  Generate25Hz: process (CLK_25MHz)
  begin
		
	 if rising_edge(CLK_25MHz) then 
		counter <= counter + 1;
		if counter = 900000 then
			counter <= 0;
		end if;
		 if counter < 1 then
			CLK_25Hz <= '1';
		 else 
			CLK_25Hz <= '0';
		 end if;
	end if;
  end process Generate25Hz;
    		
  VGAPosition: process (CLK_25MHz)
  begin
    if rising_edge(CLK_25MHz) then
	   if CurrentHPos < HLimit-1 then
		  CurrentHPos <= CurrentHPos + 1;
		else
		  if CurrentVPos < VLimit-1 then
		    CurrentVPos <= CurrentVPos + 1;
		  else
		    CurrentVPos <= (others => '0'); -- reset Vertical Position
		  end if;
		  CurrentHPos <= (others => '0'); -- reset Horizontal Position
		end if;
	 end if;
  end process VGAPosition;
	--  840000/800/2
  -- Timing definition for HSync, VSync and Blank (http://tinyvga.com/vga-timing/640x480@60Hz)
     HS <= '0' when CurrentHPos < HSyncWidth else	-- 800			x < 96 = 0
	        '1';
	  
	  VS <= '0' when CurrentVPos < VSyncWidth else		-- 525		x < 2 = 0
	        '1';
	  
	  HBlank <= '0' when (CurrentHPos >= HSyncWidth + HFrontPorch) and (CurrentHPos < HSyncWidth + HFrontPorch + HDisplayArea) else
	           '1';
				  
	  VBlank <= '0' when (CurrentVPos >= VSyncWidth + VFrontPorch) and (CurrentVPos < VSyncWidth + VFrontPorch + VDisplayArea) else
	           '1';				  
	  
	  Blank <= '1' when HBlank = '1' or VBlank = '1' else
	           '0';
	  
	  ScanlineX <= CurrentHPos - HSyncWidth - HFrontPorch when Blank = '0' else
	               (others => '0');
	  ScanlineY <= CurrentVPos - VSyncWidth - VFrontPorch when Blank = '0' else
	               (others => '0');	
						
						
     RED <= ColorOutput(5 downto 4) when Blank = '0' else
            "00";	  
     GREEN <= ColorOutput(3 downto 2) when Blank = '0' else
            "00";				
     BLUE <= ColorOutput(1 downto 0) when Blank = '0' else
            "00";		
	DOTChecker: process (CLK_25Hz)
	  begin
			if CLK_25Hz'event and CLK_25Hz = '1' then 
				dot_clicked <= '0';
				if not DOT = '1' then
					if(DOT_LOCK = '0') then
						DOT_LOCK <= '1';
						dot_clicked <= '1';

					end if;
				else 
					DOT_LOCK <= '0';
				end if;
			end if;
	  end process DOTChecker;
	  
	  DASHChecker: process (CLK_25Hz)
	  begin
			if CLK_25Hz'event and CLK_25Hz = '1' then 
				dash_clicked <= '0';
				if not DASH = '1' then
					if(DASH_LOCK = '0') then
						DASH_LOCK <= '1';
						dash_clicked <= '1';
						
					end if;
				else 
					DASH_LOCK <= '0';
				end if;
			end if;
	  end process DASHChecker;

	  SPACEChecker: process (CLK_25Hz)
	  begin
			if CLK_25Hz'event and CLK_25Hz = '1' then 
				SPACE_clicked <= '0';
				if not SPACE = '1' then
					if(SPACE_LOCK = '0') then
						SPACE_LOCK <= '1';
						SPACE_clicked <= '1';
						
					end if;
				else 
					SPACE_LOCK <= '0';
				end if;
			end if;
	  end process SPACEChecker;

	
	write_letter: process (CLK_25Hz)
	begin
		
		if CLK_25Hz'event and CLK_25Hz = '1' then 
			if(not RESET = '1') then
				xpointer <= 0;
				letter <= (others => "00");
				letter_counter <= 0;
				for ii in 0 to 15 loop
					for jj in 0 to 639 loop
						line1(ii,jj) <= '0';
					end loop;
				end loop;
				LED <= '0';
				LED2 <= '0';
				LED3 <= '0';
			else
				if dot_clicked = '1' then
					letter(letter_counter) <= "01";
					letter_counter <= letter_counter + 1;
					LED <= not LED;
				elsif dash_clicked = '1' then
					letter(letter_counter) <= "10";
					letter_counter <= letter_counter + 1;
					LED2 <= not LED2;
				elsif space_clicked = '1' then 
					letter(letter_counter) <= "11";
					letter_counter <= letter_counter + 1;
					LED3 <= not LED3;
				else
					letter(letter_counter) <= "00";
				end if;
					if letter(0) = "01" and letter(1) = "10" and letter(2) = "11" then 
						writing(line1, ram, letter, letter_counter, xpointer, 0); --A--
					elsif letter(0) = "10" and letter(1) = "01" and letter(2) = "01" and letter(3) = "01" and letter(4) = "11" then 
						writing(line1, ram, letter, letter_counter, xpointer, 1); --B--
					elsif letter(0) = "10" and letter(1) = "01" and letter(2) = "10" and letter(3) = "01" and letter(4) = "11" then 
						writing(line1, ram, letter, letter_counter, xpointer, 2); --C--
					elsif letter(0) = "10" and letter(1) = "01" and letter(2) = "01" and letter(3) = "11" then 
						writing(line1, ram, letter, letter_counter, xpointer, 3); --D--
--					elsif letter(0) = "01" and letter(1) = "11" then 
--						writing(line1, ram, letter, letter_counter, xpointer, 4);
--					elsif letter(0) = "01" and letter(1) = "01" and letter(2) = "10" and letter(3) = "01" and letter(4) = "11" then 
--						writing(line1, ram, letter, letter_counter, xpointer, 5);
--					elsif letter(0) = "10" and letter(1) = "10" and letter(2) = "01" and letter(3) = "11"  then 
--						writing(line1, ram, letter, letter_counter, xpointer, 6);
--					elsif letter(0) = "01" and letter(1) = "01" and letter(2) = "01" and letter(3) = "01" and letter(4) = "11" then 
--						writing(line1, ram, letter, letter_counter, xpointer, 7);
--					elsif letter(0) = "01" and letter(1) = "01" and letter(2) = "11" then 
--						writing(line1, ram, letter, letter_counter, xpointer, 8);
--					elsif letter(0) = "01" and letter(1) = "10" and letter(2) = "10" and letter(3) = "10" and letter(4) = "11" then 
--						writing(line1, ram, letter, letter_counter, xpointer, 9);
--					elsif letter(0) = "10" and letter(1) = "01" and letter(2) = "10" and letter(3) = "11" then 
--						writing(line1, ram, letter, letter_counter, xpointer, 10);
--					elsif letter(0) = "01" and letter(1) = "10" and letter(2) = "01" and letter(3) = "01" and letter(4) = "11" then 
--						writing(line1, ram, letter, letter_counter, xpointer, 11);
--					elsif letter(0) = "10" and letter(1) = "10" and letter(2) = "11" then 
--						writing(line1, ram, letter, letter_counter, xpointer, 12);
--					elsif letter(0) = "10" and letter(1) = "01" and letter(2) = "11" then 
--						writing(line1, ram, letter, letter_counter, xpointer, 13);
--					elsif letter(0) = "10" and letter(1) = "10" and letter(2) = "10" and letter(3) = "11" then 
--						writing(line1, ram, letter, letter_counter, xpointer, 14);
--					elsif letter(0) = "01" and letter(1) = "10" and letter(2) = "10" and letter(3) = "01" and letter(4) = "11" then 
--						writing(line1, ram, letter, letter_counter, xpointer, 15);
--					elsif letter(0) = "10" and letter(1) = "10" and letter(2) = "01" and letter(3) = "10" and letter(4) = "11" then 
--						writing(line1, ram, letter, letter_counter, xpointer, 16);
--					elsif letter(0) = "01" and letter(1) = "10" and letter(2) = "01" and letter(3) = "11" then 
--						writing(line1, ram, letter, letter_counter, xpointer, 17);
--					elsif letter(0) = "01" and letter(1) = "01" and letter(2) = "01" and letter(3) = "11" then 
--						writing(line1, ram, letter, letter_counter, xpointer, 18);
--					elsif letter(0) = "10" and letter(1) = "11" then 
--						writing(line1, ram, letter, letter_counter, xpointer, 19);
--					elsif letter(0) = "01" and letter(1) = "01" and letter(2) = "01" and letter(3) = "11" then 
--						writing(line1, ram, letter, letter_counter, xpointer, 20);
--					elsif letter(0) = "01" and letter(1) = "01" and letter(2) = "01" and letter(3) = "10" and letter(4) = "11" then 
--						writing(line1, ram, letter, letter_counter, xpointer, 21);
--					elsif letter(0) = "01" and letter(1) = "10" and letter(2) = "10" and letter(3) = "11" then 
--						writing(line1, ram, letter, letter_counter, xpointer, 22);
--					elsif letter(0) = "10" and letter(1) = "01" and letter(2) = "01" and letter(3) = "10" and letter(4) = "11" then 
--						writing(line1, ram, letter, letter_counter, xpointer, 23);
--					elsif letter(0) = "10" and letter(1) = "01" and letter(2) = "10" and letter(3) = "10" and letter(4) = "11" then 
--						writing(line1, ram, letter, letter_counter, xpointer, 24);
--					elsif letter(0) = "10" and letter(1) = "10" and letter(2) = "01" and letter(3) = "01" and letter(4) = "11" then 
--						writing(line1, ram, letter, letter_counter, xpointer, 25);
--					elsif letter(0) = "10" and letter(1) = "10" and letter(2) = "10" and letter(3) = "10" and letter(4) = "10" and letter(5) = "11" then 
--						writing(line1, ram, letter, letter_counter, xpointer, 26);
--					elsif letter(0) = "01" and letter(1) = "10" and letter(2) = "10" and letter(3) = "10" and letter(4) = "10" and letter(5) = "11"  then 
--						writing(line1, ram, letter, letter_counter, xpointer, 27);
--					elsif letter(0) = "01" and letter(1) = "01" and letter(2) = "10" and letter(3) = "10" and letter(4) = "10" and letter(5) = "11" then 
--						writing(line1, ram, letter, letter_counter, xpointer, 28);
--					elsif letter(0) = "01" and letter(1) = "01" and letter(2) = "01" and letter(3) = "10" and letter(4) = "10" and letter(5) = "11" then 
--						writing(line1, ram, letter, letter_counter, xpointer, 29);
--					elsif letter(0) = "01" and letter(1) = "01" and letter(2) = "01" and letter(3) = "01" and letter(4) = "10" and letter(5) = "11" then 
--						writing(line1, ram, letter, letter_counter, xpointer, 30);
--					elsif letter(0) = "01" and letter(1) = "01" and letter(2) = "01" and letter(3) = "01" and letter(4) = "01" and letter(5) = "11" then 
--						writing(line1, ram, letter, letter_counter, xpointer, 31);
--					elsif letter(0) = "10" and letter(1) = "01" and letter(2) = "01" and letter(3) = "01" and letter(4) = "01" and letter(5) = "11" then 
--						writing(line1, ram, letter, letter_counter, xpointer, 32);
--					elsif letter(0) = "10" and letter(1) = "10" and letter(2) = "01" and letter(3) = "01" and letter(4) = "01" and letter(5) = "11" then 
--						writing(line1, ram, letter, letter_counter, xpointer, 33);
--					elsif letter(0) = "10" and letter(1) = "10" and letter(2) = "10" and letter(3) = "01" and letter(4) = "01" and letter(5) = "11" then 
--						writing(line1, ram, letter, letter_counter, xpointer, 34);
--					elsif letter(0) = "10" and letter(1) = "10" and letter(2) = "10" and letter(3) = "10" and letter(4) = "01" and letter(5) = "11" then 
--						writing(line1, ram, letter, letter_counter, xpointer, 35);
					elsif letter(0) = "01" and letter(1) = "10" and letter(2) = "01" and letter(3) = "10" and letter(4) = "01" and letter(5) = "10" and letter(6) = "11" then 
						writing(line1, ram, letter, letter_counter, xpointer, 36);
					elsif letter(0) = "11" and letter(1) = "11" then 
						writing(line1, ram, letter, letter_counter, xpointer, 37);
					end if;
					

			end if;
	
		end if;
	end process write_letter;



	ColorOutput <= "110000" when ScanlineY < 16 and 
					(line1(to_integer(unsigned(ScanlineY)),to_integer(unsigned(ScanlineX))) = '1') else "000000";
 	  

end Behavioral;

