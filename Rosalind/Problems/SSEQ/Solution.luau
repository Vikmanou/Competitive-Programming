--[[



]]

local ParseFASTA = require(game:GetService'ReplicatedStorage'.BioUtility.ParseFASTA)

return function(s: string): string
	local mainDNA: string?, subSeq: string?
	
	for _, v in ParseFASTA(s) do
		if not mainDNA then
			mainDNA = v[2]
			continue
		end
		
		subSeq = v[2]
	end
	
	local res = {}
	
	local subStringPos = 1
	local dnaPos = 1
	for c in mainDNA:gmatch'.' do
		local compChar = subSeq:sub(subStringPos, subStringPos)
		
		if c == compChar then
			subStringPos += 1
			table.insert(res, dnaPos)
		end
		
		dnaPos += 1
	end
	
	return table.concat(res, ' ')
end