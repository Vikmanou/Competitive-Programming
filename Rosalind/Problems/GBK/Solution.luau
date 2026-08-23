--[[



]]

local HttpService = game:GetService('HttpService')

local BASE_URL = 'https://www.ncbi.nlm.nih.gov/nuccore/?term='

local function createDateField(startDate: string, endDate: string): string
	return HttpService:UrlEncode(`"{startDate}"[Publication Date] : "{endDate}"[Publication Date]`)
end

return function(s: string): string
	local genus, startDate, endDate = table.unpack(s:split('\n'))
	
	local searchUrl = `{BASE_URL}({createDateField(startDate, endDate)})+AND+{genus}%5BOrganism%5D`
	
	local res = HttpService:GetAsync(searchUrl, nil)
	
	if res:find'Items: %d+ to' then
		return res:match'Items: %d+ to %d+ of (%d+)'
	else
		return res:match'Items: (%d+)'
	end
end