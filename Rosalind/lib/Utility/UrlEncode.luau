return function(s: string): string
	return (s:gsub("[^%w%-%.~_]", function(c: string): string
		return string.format("%%%02X", string.byte(c))
	end))
end
