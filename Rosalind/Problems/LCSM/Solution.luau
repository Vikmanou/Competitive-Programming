--[[

Problem
A common substring of a collection of strings is a substring of every member of the collection. We say that a common substring is a longest common substring if there does not exist a longer common substring. For example, "CG" is a common substring of "ACGTACGT" and "AACCGTATA", but it is not as long as possible; in this case, "CGTA" is a longest common substring of "ACGTACGT" and "AACCGTATA".

Note that the longest common substring is not necessarily unique; for a simple example, "AA" and "CC" are both longest common substrings of "AACC" and "CCAA".

Given: A collection of k (k≤100) DNA strings of length at most 1 kbp each in FASTA format.

Return: A longest common substring of the collection. (If multiple solutions exist, you may return any single solution.)

Sample Dataset
>Rosalind_1
GATTACA
>Rosalind_2
TAGACCA
>Rosalind_3
ATACA

Sample Output
AC

]]

local ParseFASTA = require(game:GetService'ReplicatedStorage'.BioUtility.ParseFASTA)


local function isCommonSubstring(subString, strings)
	for i = 2, #strings do
		if not strings[i]:find(subString, 1, true) then
			return false
		end
	end
	
	return true
end


return function(s: string): string
	local collection = {}
	
	for _, v in ParseFASTA(s) do
		table.insert(collection, v[2])
	end
	
	table.sort(collection, function(a: string, b: string)return #a < #b end)
	
	local baseString = collection[1]
	for i = #baseString, 1, -1 do
		for j = 1, #baseString - i + 1 do
			local subString = baseString:sub(j, j + i - 1)
			if isCommonSubstring(subString, collection) then
				return subString
			end
		end
	end
	
	return ''
end