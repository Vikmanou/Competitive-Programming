# Rosalind — Luau Solutions

Solutions to [Rosalind](https://rosalind.info) bioinformatics problems, written in **Luau** and run from the terminal with [**Lute**](https://lute.luau.org).

Part of the [Competitive-Programming](https://github.com/Vikmanou/Competitive-Programming) repository.

Every solution is a pure function of `(input: string) -> string`. The runner reads `Input.txt`, calls the solver, prints the result, and writes it to `Output.txt`.

---

## Running it

### 1. Install Lute

Grab a [release binary](https://github.com/luau-lang/lute/releases) and put it on your `PATH`, add it with a toolchain manager (`rokit add luau-lang/lute`), or build from source:

```sh
git clone https://github.com/luau-lang/lute
cd lute && ./tools/bootstrap.sh --install
```

### 2. Run a problem

```sh
cd Rosalind
lute run DNA
```

```
20 12 17 21
Time: 2.067 ms
```

The problem code is the directory name. `lute run` accepts a directory containing an `init.luau`, so `lute run DNA` runs `DNA/init.luau`. The runner takes `Input.txt` from the directory it was launched with.

### 3. Add a problem

Make a directory named after the problem code, holding `init.luau` and your dataset:

```sh
mkdir XXXX
touch XXXX/Input.txt
```

```lua
-- XXXX/init.luau
local function solve(s: string): string

end

if ... then
	require("@rosalind")(solve)
end

return solve
```

Then `lute run XXXX`. `Output.txt` is created on the first run.

### 4. Editor support (optional)

```sh
lute setup --with-luaurc
```

Generates type definitions for `@std` and `@lute` and registers them as aliases in `.luaurc`, so the language server resolves the runtime libraries.

---

## Layout

```
Rosalind/
├── .luaurc              # require aliases: @rosalind, @bio, @util, @problems
├── DNA/                 # one directory per Rosalind problem
│   ├── init.luau        # the solver: (input) -> output
│   ├── Input.txt        # dataset
│   └── Output.txt       # written on every run
├── lib/
│   ├── init.luau        # the runner module (@rosalind)
│   ├── BioUtility/      # domain helpers: FASTA parsing, codon tables, masses
│   └── Utility/         # generic algorithms (LCS, URL encoding, ...)
└── archive/             # earlier C++ and APL solutions, kept for reference
```

---

## Anatomy of a solution

Every solver is a module returning a single pure function.

```lua
-- DNA/init.luau
local function solve(s: string): string
    local Occurences = { A = 0, C = 0, G = 0, T = 0 }

    for c in s:gmatch'.' do
        Occurences[c] += 1
    end

    return `{Occurences.A} {Occurences.C} {Occurences.G} {Occurences.T}`
end

if ... then
    require("@rosalind")(solve)
end

return solve
```

Lute passes the command-line arguments as varargs to the script it runs and nothing to a required module, so `if ... then` is true only when the file was launched directly. `lute run DNA` solves, `require("@problems/DNA")` just hands back the function.

Because solvers are pure functions, they compose. `SPLC` (RNA Splicing) removes the introns, then reuses two earlier problems rather than reimplementing them:

```lua
local RNA = require("@problems/RNA")
local PROT = require("@problems/PROT")

return PROT(RNA(dna))
```

---

## API

`@rosalind` is one function, and that is the whole runner:

```lua
require("@rosalind")(solve)
```

It reads `Input.txt` from the directory Lute was launched with (CRLF becomes LF, trailing whitespace is stripped), calls `solve` with it, writes the result to `Output.txt`, and prints the result and the elapsed time. Asserts if the input is missing or empty.

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

- **Datasets.** Rosalind issues a different dataset per user, so most `Input.txt` files are empty by design.
- **`GBK` needs network access.** It queries NCBI through `@std/net`.
- **`archive/`** holds the original C++ and APL solutions to eight of these problems, from before the project was ported to Luau. Kept for comparison, not maintained.

## License

See the [LICENSE](../LICENSE) in the parent repository.
