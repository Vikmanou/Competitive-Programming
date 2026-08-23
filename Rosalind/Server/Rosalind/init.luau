local RunService = game:GetService('RunService')

local Rosalind = {
	Solutions = {}
}


function Rosalind.Solve(problem: string): string
	local problemFolder: Folder = script.Problems[problem]
	
	assert(problemFolder:FindFirstChild'Input' ~= nil, `Problem '{problem}' requires an input`)
	
	if not (RunService:IsRunning() or RunService:IsRunMode()) then
		Rosalind.Solutions[problem] = nil
	end
	
	if not Rosalind.Solutions[problem] then
		Rosalind.Solutions[problem] = require(script.Problems[problem].Solution)
	end
	
	local solution = Rosalind.Solutions[problem](problemFolder.Input.Value)
	
	local Output: StringValue = problemFolder:FindFirstChild'Output'
	if not Output then
		Output = Instance.new('StringValue')
		Output.Name = 'Output'
	end
	Output.Value = solution
	
	return solution
end


function Rosalind.Run(problem: string, input: string)
	local problemFolder: Folder = script.Problems[problem]

	if not (RunService:IsRunning() or RunService:IsRunMode()) then
		Rosalind.Solutions[problem] = nil
	end

	if not Rosalind.Solutions[problem] then
		Rosalind.Solutions[problem] = require(script.Problems[problem].Solution)
	end

	return Rosalind.Solutions[problem](input)
end


function Rosalind.SetupProblem(problem: string)
	assert(not script.Problems:FindFirstChild(problem), `Problem folder '{problem}' already exists`)
	
	local problemFolder = script.ProblemTemplate:Clone()
	
	problemFolder.Name = problem
	problemFolder.Parent = script.Problems
end


return Rosalind