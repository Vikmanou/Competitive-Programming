--[[



]]

local ParseFASTA = require("@bio/ParseFASTA")
local LCS = require("@util/LCS")

local function solve(s: string): string
	local s1: string?, s2: string?
	
	for _, v in ParseFASTA(s) do
		if not s1 then
			s1 = v[2]
			continue
		end
		
		s2 = v[2]
	end
	
	return LCS(s1, s2)
end

if ... then
	require("@rosalind")(solve)
end

return solve
