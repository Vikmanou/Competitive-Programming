--[[



]]

local ParseFASTA = require(game:GetService'ReplicatedStorage'.BioUtility.ParseFASTA)

return function(s: string): string
	local dataset = ParseFASTA(s)
	local s1 = dataset[1][2]
	local s2 = dataset[2][2]

	local temp = table.create(#s1 + 1)
	for i = 1, #s1 + 1 do
		temp[i] = table.create(#s2 + 1, 0)
		temp[i][1] = i - 1
	end
	for j = 1, #s2 + 1 do
		temp[1][j] = j - 1
	end

	for i = 1, #s1 do
		local prev = temp[i]
		local curr = temp[i + 1]

		for j = 1, #s2 do
			if string.byte(s1, i) == string.byte(s2, j) then
				curr[j + 1] = prev[j]
			else
				curr[j + 1] = 1 + math.min(prev[j], prev[j + 1], curr[j])
			end
		end
	end

	return temp[#s1 + 1][#s2 + 1]
end