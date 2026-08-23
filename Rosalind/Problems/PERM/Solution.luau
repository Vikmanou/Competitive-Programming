--[[

A permutation of length n is an ordering of the positive integers {1,2,…,n}. For example, π=(5,3,2,1,4) is a permutation of length 5.

Given: A positive integer n≤7.

Return: The total number of permutations of length n, followed by a list of all such permutations (in any order).

Sample Dataset
3

Sample Output
6
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1

]]


local function next_permutation(arr)
	local n = #arr
	local i = n - 1
	while i > 0 and arr[i] > arr[i + 1] do
		i = i - 1
	end
	if i == 0 then return false end
	local j = n
	while arr[j] < arr[i] do
		j = j - 1
	end
	arr[i], arr[j] = arr[j], arr[i]
	local left, right = i + 1, n
	while left < right do
		arr[left], arr[right] = arr[right], arr[left]
		left = left + 1
		right = right - 1
	end
	return true
end


return function(s: string): string
	local n = tonumber(s)
	
	local arr = {}
	local res = {}
	
	for i = 1, n do
		table.insert(arr, i)
	end
	
	table.insert(res, table.concat(arr, ' '))
	
	while next_permutation(arr) do
		table.insert(res, table.concat(arr, ' '))
	end
	
	return `{#res}\n{table.concat(res, '\n')}`
end