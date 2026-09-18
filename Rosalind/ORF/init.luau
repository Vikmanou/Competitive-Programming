--[[

Open Reading Frames

Given: A DNA string s of length at most 1 kbp in FASTA format.

Return: Every distinct candidate protein string that can be translated from ORFs of s.
ORFs may be found on both the given strand and its reverse complement.

]]

local ParseFASTA = require("@bio/ParseFASTA")
local DNACodons = require("@bio/DNACodons")
local RNA = require("@problems/RNA")
local PROT = require("@problems/PROT")
local ReverseComplement = require("@problems/REVC")

local function findProteins(dna: string, results: { [string]: boolean })
	for i = 1, #dna - 2 do
		local codon = dna:sub(i, i + 2)

		if codon == DNACodons.Start then
			for j = i, #dna - 2, 3 do
				local c = dna:sub(j, j + 2)

				if DNACodons[c] == 'Stop' then
					local orf = dna:sub(i, j + 2)
					results[PROT(RNA(orf))] = true
					break
				end
			end
		end
	end
end

local function solve(s: string): string
	local parsedData = ParseFASTA(s)
	local dna = parsedData[1][2]

	local results: { [string]: boolean } = {}

	findProteins(dna, results)
	findProteins(ReverseComplement(dna), results)

	local res = ''
	for protein in results do
		res ..= protein .. '\n'
	end

	return res
end

if ... then
	require("@rosalind")(solve)
end

return solve