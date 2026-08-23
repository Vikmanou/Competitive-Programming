--[[



]]

local ParseFASTA = require(game:GetService'ReplicatedStorage'.BioUtility.ParseFASTA)

return function(s: string): string
	local dataset = {}
	
	for _, v in ParseFASTA(s) do
		table.insert(dataset, v[2])
	end
	
	local profile = {
		A = table.create(#dataset[1], 0),
		C = table.create(#dataset[1], 0),
		G = table.create(#dataset[1], 0),
		T = table.create(#dataset[1], 0)
	}
	
	for i = 1, #dataset[1] do
		for _, v in dataset do
			local char = v:sub(i, i)
			profile[char][i] += 1
		end
	end
	
	local consensus = {}
	for i = 1, #dataset[1] do
		local most = 'A'
		for _, v in {'C', 'G', 'T'} do
			if profile[v][i] > profile[most][i] then
				most = v
			end
		end
		
		table.insert(consensus, most)
	end
	
	local res = table.concat(consensus, '')
	
	for _, v in {'A', 'C', 'G', 'T'} do
		res ..= `\n{v}: {table.concat(profile[v], ' ')}`
	end
	
	return res
end