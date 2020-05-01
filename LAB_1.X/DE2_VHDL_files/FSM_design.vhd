library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.numeric_std.all;

entity preamble is
	port(
		rst, clk, start : in std_logic;
		data_out : out std_logic
	);
end preamble;
architecture beh of preamble is
type states is (idle, patterna, patternb);
signal curstat, nxtstat : states;
signal cnt, nxtcnt : integer;
begin
	process(rst, clk)
	begin
		if(clk'event and clk = '1') then
			if(rst = '1') then
				curstat <= idle;
				cnt <= 0;
			else
				curstat <= nxtstat;
				cnt <= nxtcnt;
			end if;
		end if;
	end process;
	process(curstat, cnt, start)
	begin
		nxtcnt <= cnt;
		case curstat is
		when idle =>
			if(start = '1') then
				nxtstat <= patterna;
			else
				nxtstat <= idle;
			end if;
			data_out <= '0';
			nxtcnt <= 0;
		when patterna =>
			nxtstat <= patternb;
			data_out <= '1';
		when patternb =>
			if(cnt >= 3) then
				nxtstat <= idle;
			else
				nxtstat <= patterna;
				nxtcnt <= cnt + 1;
			end if;
			data_out <= '0';
		end case;
	end process;
end beh;