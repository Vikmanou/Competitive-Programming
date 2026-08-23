--[[

In DNA strings, symbols 'A' and 'T' are complements of each other, as are 'C' and 'G'.

The reverse complement of a DNA string s is the string sc formed by reversing the symbols of s, then taking the complement of each symbol (e.g., the reverse complement of "GTCA" is "TGAC").

Given: A DNA string s of length at most 1000 bp.

Return: The reverse complement s^c of s.

Sample Dataset
AAAACCCGGT

Sample Output
ACCGGGTTTT

]]


local Complements = require(game:GetService'ReplicatedStorage'.BioUtility.Complements)


return function(s: string): string
	s = string.reverse(s)
	
	local res = ''
	
	for c in s:gmatch'.' do
		res ..= Complements[c]
	end
	
	return res
end