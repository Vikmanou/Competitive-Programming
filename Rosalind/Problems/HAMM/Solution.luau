--[[

Given two strings s and t of equal length, the Hamming distance between s and t, denoted dH(s,t), is the number of corresponding symbols that differ in s and t. See Figure 2.

Given: Two DNA strings s and t of equal length (not exceeding 1 kbp).

Return: The Hamming distance dH(s,t).

Sample Dataset
GAGCCTACTAACGGGAT
CATCGTAATGACGGCCT

Sample Output
7

]]

return function(s: string): string
	local s1 = s:match'^%w+'
	local s2 = s:match'%w+$'
	
	local diff = 0
	
	for i = 1, #s1 do
		if s1:sub(i, i) ~= s2:sub(i, i) then
			diff += 1
		end
	end
	
	return diff
end