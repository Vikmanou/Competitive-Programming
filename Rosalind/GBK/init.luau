--[[



]]

local net = require("@std/net")
local UrlEncode = require("@util/UrlEncode")

local ESEARCH_URL = 'https://eutils.ncbi.nlm.nih.gov/entrez/eutils/esearch.fcgi?db=nuccore&rettype=count&term='

local function solve(s: string): string
	local genus, startDate, endDate = table.unpack(s:split('\n'))

	local term = `("{startDate}"[Publication Date] : "{endDate}"[Publication Date]) AND {genus}[Organism]`

	local response = net.request(ESEARCH_URL .. UrlEncode(term))
	assert(response.ok, `NCBI request failed with status {response.status}`)

	return assert(response.body:match'<Count>(%d+)</Count>', `NCBI returned no count:\n{response.body}`)
end

if ... then
	require("@rosalind")(solve)
end

return solve
