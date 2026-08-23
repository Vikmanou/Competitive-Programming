--[[

The 20 commonly occurring amino acids are abbreviated by using 20 letters from the English alphabet (all letters except for B, J, O, U, X, and Z). Protein strings are constructed from these 20 symbols. Henceforth, the term genetic string will incorporate protein strings along with DNA strings and RNA strings.

The RNA codon table dictates the details regarding the encoding of specific codons into the amino acid alphabet.

Given: An RNA string s corresponding to a strand of mRNA (of length at most 10 kbp).

Return: The protein string encoded by s.

Sample Dataset
AUGGCCAUGGCGCCCAGAACUGAGAUCAAUAGUACCCGUAUUAACGGGUGA

Sample Output
MAMAPRTEINSTRING

]]

local RNACodons = require(game:GetService'ReplicatedStorage'.BioUtility.RNACodons)

return function(s: string): string
	local res = ''
	
	for i = 1, #s, 3 do
		local portion = s:sub(i, i+2)
		
		local codon = RNACodons[portion]
		
		if codon == 'Stop' then break end
		
		res = res .. codon
	end
	
	return res
end