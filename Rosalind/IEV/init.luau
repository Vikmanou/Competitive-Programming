--[[



]]

local probabilities = {1, 1, 1, .75, .5, 0}

local function solve(s: string): string
	local res = 0
	
	local pos = 0
	for n in s:gmatch'(%d+)' do
		pos += 1
		res += probabilities[pos] * 2 * tonumber(n)
	end
	
	return res
end

if ... then
	require("@rosalind")(solve)
end

return solve
