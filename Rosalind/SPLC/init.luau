--[[



]]

local RNA = require("@problems/RNA")
local PROT = require("@problems/PROT")
local ParseFASTA = require("@bio/ParseFASTA")

local function solve(s: string): string
	local dna: string?
	
	for _, v in ParseFASTA(s) do
		if not dna then
			dna = v[2]
			continue
		end
		
		dna = dna:gsub(v[2], '')
	end

	return PROT(RNA(dna))
end

if ... then
	require("@rosalind")(solve)
end

return solve
