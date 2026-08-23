--[[



]]

local ParseFASTA = require(game:GetService'ReplicatedStorage'.BioUtility.ParseFASTA)
local LCS = require(game:GetService'ReplicatedStorage'.Utility.LCS)

return function(s: string): string
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