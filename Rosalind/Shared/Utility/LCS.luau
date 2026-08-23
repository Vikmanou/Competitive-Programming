return function(s1: string, s2: string)
	local m = #s1
	local n = #s2

	-- Initialize a 2D table to store LCS lengths
	local L = {}
	for i = 0, m do
		L[i] = {}
		for j = 0, n do
			L[i][j] = 0
		end
	end

	-- Build the LCS table
	for i = 1, m do
		for j = 1, n do
			if s1:sub(i, i) == s2:sub(j, j) then
				L[i][j] = L[i-1][j-1] + 1
			else
				L[i][j] = math.max(L[i-1][j], L[i][j-1])
			end
		end
	end

	-- Reconstruct the LCS from the table
	local index = L[m][n]
	local lcsStr = {}
	local i = m
	local j = n

	while i > 0 and j > 0 do
		if s1:sub(i, i) == s2:sub(j, j) then
			table.insert(lcsStr, 1, s1:sub(i, i))
			i = i - 1
			j = j - 1
		elseif L[i-1][j] > L[i][j-1] then
			i = i - 1
		else
			j = j - 1
		end
	end

	return table.concat(lcsStr)
end