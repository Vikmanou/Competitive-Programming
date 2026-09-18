--[[



]]

local net = require("@std/net")
local UrlEncode = require("@util/UrlEncode")

local BASE_URL = 'https://www.ncbi.nlm.nih.gov/nuccore/?term='

local function createDateField(startDate: string, endDate: string): string
	return UrlEncode(`"{startDate}"[Publication Date] : "{endDate}"[Publication Date]`)
end

local function solve(s: string): string
	local genus, startDate, endDate = table.unpack(s:split('\n'))
	
	local searchUrl = `{BASE_URL}({createDateField(startDate, endDate)})+AND+{genus}%5BOrganism%5D`
	
	local response = net.request(searchUrl)
	assert(response.ok, `NCBI request failed with status {response.status}`)

	local res = response.body
	
	if res:find'Items: %d+ to' then
		return res:match'Items: %d+ to %d+ of (%d+)'
	else
		return res:match'Items: (%d+)'
	end
end

if ... then
	require("@rosalind")(solve)
end

return solve
