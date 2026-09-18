local fs = require("@std/fs")
local path = require("@std/path")
local process = require("@std/process")
local time = require("@std/time")

export type Solution = (input: string) -> string

local function directory(): string
	local entry = path.format(path.resolve(process.args[1] or "."))

	if path.extname(entry) == ".luau" then
		return path.dirname(entry)
	end

	return entry
end

return function(solve: Solution): ()
	local started = time.now()

	local problem = directory()
	local inputFile = path.format(path.join(problem, "Input.txt"))

	assert(fs.exists(inputFile), `Missing input at {inputFile}`)

	local input = (fs.readFileToString(inputFile):gsub("\r\n", "\n"):gsub("%s+$", ""))

	assert(#input > 0, `Empty input at {inputFile}`)

	local output = (tostring(solve(input)):gsub("\r\n", "\n"):gsub("%s+$", ""))

	fs.writeStringToFile(path.format(path.join(problem, "Output.txt")), output .. "\n")

	print(output)
	print(string.format("Time: %.3f ms", started:elapsed() * 1000))
end
