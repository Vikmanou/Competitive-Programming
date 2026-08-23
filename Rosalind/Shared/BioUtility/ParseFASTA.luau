return function(s: string)
	local dataset = {}

	local currentSet: string?
	for _, line in s:split'\n' do
		if line:find'^>' then
			currentSet = line:sub(2)
			table.insert(dataset, {currentSet, ''})
			continue
		end

		dataset[#dataset][2] ..= line
	end

	return dataset
end