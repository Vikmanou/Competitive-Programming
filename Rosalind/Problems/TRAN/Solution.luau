--[[



]]

local ParseFASTA = require(game:GetService'ReplicatedStorage'.BioUtility.ParseFASTA)
local TransitionTransversion = require(game:GetService'ReplicatedStorage'.BioUtility.TransitionTransversion)

return function(s: string): string
	local dnas = ParseFASTA(s)
	local s1, s2 = dnas[1][2], dnas[2][2]
	
	local transitions = 0
	local transversions = 0
	
	for i = 1, #s1 do
		local c1 = s1:sub(i, i)
		local c2 = s2:sub(i, i)
		
		local t = TransitionTransversion[c1 .. c2]
		if t == 'Transition' then
			transitions += 1
		elseif t == 'Transversion' then
			transversions += 1
		end
	end
	
	return transitions/transversions
end