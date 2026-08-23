--[[

A DNA string is a reverse palindrome if it is equal to its reverse complement. For instance, GCATGC is a reverse palindrome because its reverse complement is GCATGC. See Figure 2.

Given: A DNA string of length at most 1 kbp in FASTA format.

Return: The position and length of every reverse palindrome in the string having length between 4 and 12. You may return these pairs in any order.

Sample Dataset
>Rosalind_24
TCAATGCATGCGGGTCTATATGCAT

Sample Output
4 6
5 4
6 6
7 4
17 4
18 4
20 6
21 4

]]

local Rosalind = require(game:GetService'ServerScriptService'.Rosalind)
local ParseFASTA = require(game:GetService'ReplicatedStorage'.BioUtility.ParseFASTA)

return function(s: string): string
	local res = ''
	
	for _, v in ParseFASTA(s) do
		local str = v[2]
		
		for i = 1, #str - 3 do
			for j = 4, math.min(12, #str - i + 1) do
				local substr = str:sub(i, i + j - 1)
				if Rosalind.Run('REVC', substr) == substr then
					res ..= `{i} {j}\n`
				end
			end
		end
	end
	
	return res
end