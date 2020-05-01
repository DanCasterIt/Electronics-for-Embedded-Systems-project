library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.numeric_std.all;

entity preamble_tb is
end preamble_tb;
architecture arch of preamble_tb is
component preamble is
	port(
		rst, clk, start : in std_logic;
		data_out : out std_logic
	);
end component;
signal rst, clk, start, data_out : std_logic;
begin
	dut : preamble port map(rst, clk, start, data_out);
	--simulation lasts 125ns
	process
	begin 
		clk <= '0';
		wait for 5ns;
		clk <= '1';
		wait for 5ns;
	end process;
	rst <= '1' after 0ns,
	'0' after 10ns;
	start <= '0' after 0ns,
	'1' after 20ns,
	'0' after 30ns;
end arch;