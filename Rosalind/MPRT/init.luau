local net = require("@std/net")
local ParseFASTA = require("@bio/ParseFASTA")

local FETCH_URL = 'https://rest.uniprot.org/uniprotkb/%s.fasta'
local N_GLYCOSYLATION_MOTIF_PATTERN = 'N[^P][ST][^P]'

local function solve(s: string): string
    local res = ''

    for _, c in s:split'\n' do
        local proteinName = c:match'[^_]+'

        local data = net.request(FETCH_URL:format(proteinName))
        local parsedData = ParseFASTA(data.body)
        
        local proteinData = parsedData[1][2]

        local start = proteinData:find(N_GLYCOSYLATION_MOTIF_PATTERN, 1)
        
        if start then
            res ..= (res == '' and '' or '\n') .. `{c}\n`
            res ..= start
        end

        while start do
            start = proteinData:find(N_GLYCOSYLATION_MOTIF_PATTERN, start + 1)

            if start then
                res ..= ` {start}`
            end
        end
        
    end

    return res
end

if ... then
    require("@rosalind")(solve)
end

return solve