--[[



]]

local Rosalind = require(game:GetService'ServerScriptService'.Rosalind)
local ParseFASTA = require(game:GetService'ReplicatedStorage'.BioUtility.ParseFASTA)

return function(s: string): string
	local dna: string?
	
	for _, v in ParseFASTA(s) do
		if not dna then
			dna = v[2]
			continue
		end
		
		dna = dna:gsub(v[2], '')
	end

	local mRNA = Rosalind.Run('RNA', dna)
	return Rosalind.Run('PROT', mRNA)
end