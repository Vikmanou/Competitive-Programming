--[[



]]

return function(s: string): string
	local dna1, dna2 = s:match'(%w+)\n(%w+)'
	
	if #dna2 > #dna1 then
		local temp = dna1
		dna1 = dna2
		dna2 = temp
	end
	
	local hammDist = 0
	
	for i = 1, #dna1 do
		if not (dna1:sub(i, i) == dna2:sub(i, i)) then
			hammDist += 1
		end
	end
	
	return hammDist
end