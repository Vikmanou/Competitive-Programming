# Rosalind — Luau Solutions

Solutions to [Rosalind](https://rosalind.info) bioinformatics problems, written in **Luau** and runnable inside **Roblox Studio**.

Part of the [Competitive-Programming](https://github.com/Vikmanou/Competitive-Programming) repository, alongside `Kattis`, `project-euler`, and `code-golf`. Each subdirectory there is a self-contained set of solutions; this one is the Rosalind track.

Every solution here is a pure function of `(input: string) -> string`, kept in plain files on disk and synced into the Roblox instance tree by [Argon](https://argon.wiki).

# TODO
Ensure project can be ran directly through terminal and not necessarily Roblox Studio. Essentially an implementation for Lute or Lune.

---

## Why Luau

Rosalind expects Python. Luau is the deliberate constraint: no NumPy, no Biopython, no `itertools` — every parser, codon table, and dynamic-programming routine is written from scratch. Comparable to solving Advent of Code in a language with no standard library to lean on.

The tradeoff is honest: Luau gives fast iteration and a genuinely good VM, but no package ecosystem for bioinformatics. That's the point.

---

## Layout

```
Rosalind/
├── Rosalind.project.json    # Argon project — maps disk paths to the instance tree
├── Problems/                # one directory per Rosalind problem
│   └── DNA/
│       ├── Solution.luau    # the solver: (input) -> output
│       ├── Notes.luau       # scratch notes / theory
│       └── Input.txt        # dataset, becomes a StringValue named "Input"
├── Server/
│   └── Rosalind/
│       ├── init.luau        # the runner module (Solve / Run / SetupProblem)
│       └── ProblemTemplate/ # scaffold cloned by Rosalind.SetupProblem
├── Shared/
│   ├── BioUtility/          # domain helpers: FASTA parsing, codon tables, masses
│   └── Utility/             # generic algorithms (LCS, ...)
└── archive/                 # earlier C++ and APL solutions, kept for reference
```

---

## Anatomy of a solution

Every solver is a module returning a single pure function. No I/O, no globals, no side effects — trivially testable and reusable.

```lua
-- Problems/DNA/Solution.luau
return function(s: string): string
    local Occurences = { A = 0, C = 0, G = 0, T = 0 }

    for c in s:gmatch'.' do
        Occurences[c] += 1
    end

    return `{Occurences.A} {Occurences.C} {Occurences.G} {Occurences.T}`
end
```

Because solvers are pure functions, they compose. `SPLC` (RNA Splicing) removes the introns, then reuses two earlier problems rather than reimplementing them:

```lua
local mRNA = Rosalind.Run('RNA', dna)
return Rosalind.Run('PROT', mRNA)
```

---

## Running it

### 1. Install the Argon CLI

Pick one:

```sh
cargo install argon-rbx           # Rust toolchain
rokit add argon-rbx/argon --global
aftman add argon-rbx/argon --global
```

Or install the [VS Code extension](https://marketplace.visualstudio.com/items?itemName=Dervex.argon), or grab a [standalone binary](https://github.com/argon-rbx/argon/releases).

### 2. Install the Studio plugin

```sh
argon plugin install
```

Or search "Argon" in the Studio Toolbox.

### 3. Serve this directory

```sh
cd Rosalind
argon serve Rosalind.project.json
```

The project file has a non-default name, so pass it explicitly.

### 4. Connect from Studio

Open any place, open the **Argon** plugin widget, hit **Connect**. The tree appears under `ServerScriptService` and `ReplicatedStorage`.

### 5. Configure the plugin — required

Argon's defaults sync **scripts only**. Without these changes the `Input` datasets never round-trip, and you'll get silent no-ops rather than errors:

| Setting | Default | Set to | Why |
| --- | --- | --- | --- |
| **Only Code Mode** | `true` | **off** | Filters out any instance that isn't a script or a script's ancestor. `StringValue` inputs are dropped. |
| **Two-Way Sync** | `false` | **on** | Required for Studio → filesystem sync at all. |
| **Syncback Properties** | `false` | **on** | `StringValue.Value` is a property; without this, edits to a dataset never reach disk. |
| **Initial Sync Priority** | `Server` | leave as `Server` | Filesystem wins on connect. Setting it to `Client` lets Studio overwrite your working tree. |

### 6. Solve

In the Studio command bar:

```lua
local Rosalind = require(game:GetService('ServerScriptService').Rosalind)

print(Rosalind.Solve('DNA'))
```

---

## API

```lua
Rosalind.Solve(problem: string): string
```
Reads `Problems[problem].Input`, runs the solver, writes the result to an `Output` `StringValue`, and returns it. Asserts if no `Input` exists. Outside of a running game the solver module is re-required each call, so edits take effect immediately without a restart.

```lua
Rosalind.Run(problem: string, input: string): string
```
Runs a solver against a string passed directly. Used for ad-hoc testing and for composing solutions (see `SPLC` above).

```lua
Rosalind.SetupProblem(problem: string)
```
Clones `ProblemTemplate` into `Problems` under the given name — scaffolds `Solution.luau` and `Notes.luau`. Asserts if the problem already exists.

### Adding a problem

1. `Rosalind.SetupProblem('XXXX')` in the command bar, or just `mkdir Problems/XXXX` and copy the template files.
2. Paste the problem statement into the `--[[ ]]` block at the top of `Solution.luau`.
3. Drop your dataset into `Problems/XXXX/Input.txt`.
4. Implement the returned function.
5. `print(Rosalind.Solve('XXXX'))`.

---

## Problem index

24 solved. Rosalind's [Stronghold](https://rosalind.info/problems/list-view/) unless noted.

| Code | Problem |
| --- | --- |
| [DNA](https://rosalind.info/problems/dna/) | Counting DNA Nucleotides |
| [RNA](https://rosalind.info/problems/rna/) | Transcribing DNA into RNA |
| [REVC](https://rosalind.info/problems/revc/) | Complementing a Strand of DNA |
| [FIB](https://rosalind.info/problems/fib/) | Rabbits and Recurrence Relations |
| [GC](https://rosalind.info/problems/gc/) | Computing GC Content |
| [HAMM](https://rosalind.info/problems/hamm/) | Counting Point Mutations |
| [IPRB](https://rosalind.info/problems/iprb/) | Mendel's First Law |
| [PROT](https://rosalind.info/problems/prot/) | Translating RNA into Protein |
| [SUBS](https://rosalind.info/problems/subs/) | Finding a Motif in DNA |
| [CONS](https://rosalind.info/problems/cons/) | Consensus and Profile |
| [IEV](https://rosalind.info/problems/iev/) | Calculating Expected Offspring |
| [LCSM](https://rosalind.info/problems/lcsm/) | Finding a Shared Motif |
| [PERM](https://rosalind.info/problems/perm/) | Enumerating Gene Orders |
| [PRTM](https://rosalind.info/problems/prtm/) | Calculating Protein Mass |
| [REVP](https://rosalind.info/problems/revp/) | Locating Restriction Sites |
| [MRNA](https://rosalind.info/problems/mrna/) | Inferring mRNA from Protein |
| [LEXF](https://rosalind.info/problems/lexf/) | Enumerating k-mers Lexicographically |
| [SPLC](https://rosalind.info/problems/splc/) | RNA Splicing |
| [LCSQ](https://rosalind.info/problems/lcsq/) | Finding a Shared Spliced Motif |
| [SSEQ](https://rosalind.info/problems/sseq/) | Finding a Spliced Motif |
| [TRAN](https://rosalind.info/problems/tran/) | Transitions and Transversions |
| [INI](https://rosalind.info/problems/ini/) | Introduction to the Bioinformatics Armory *(Armory)* |
| [GBK](https://rosalind.info/problems/gbk/) | GenBank Introduction *(Armory)* |
| [BA1G](https://rosalind.info/problems/ba1g/) | Compute the Hamming Distance Between Two Strings *(Textbook Track)* |

---

## Notes

- **Datasets.** Rosalind issues a different dataset per user, so most `Input.txt` files are absent by design — supply your own. Eight are committed from earlier work as worked examples.
- **`GBK` needs network access.** It queries NCBI over `HttpService:GetAsync`. Enable **Game Settings → Security → Allow HTTP Requests** in Studio, or it will throw.
- **`archive/`** holds the original C++ and APL solutions to eight of these problems, from before the project was ported to Luau. Kept for comparison, not maintained.

## License

See the [LICENSE](../LICENSE) in the parent repository.
