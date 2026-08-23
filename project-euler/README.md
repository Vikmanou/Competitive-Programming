# Project Euler Solutions

https://projecteuler.net/problem=\d

## Layout

```
include/pe/     shared header-only library (namespace pe)
solutions/NNNN/ one directory per solved problem
unsolved/NNNN/  work in progress
```

Problem directories are always four digits.

## Setup

Needs MSYS2. `C:\msys64\ucrt64\bin` and `C:\msys64\usr\bin` must be on PATH.

```
winget install MSYS2.MSYS2
pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-gdb make mingw-w64-ucrt-x86_64-clang-tools-extra
```

## Running

Run from this directory. Pick the problem with `p=`.

```
cd project-euler
make run p=0035
```

| command | what it does |
| --- | --- |
| `make run p=0035` | compile with `-O2`, run, print the answer |
| `make debug p=0035` | compile unoptimized with checks turned on, run |
| `make list` | list every problem directory |
| `make clean` | delete `build/` |

Works for `unsolved/` too — `make run p=0810` finds it without being told
which folder.

The binary runs with its own problem directory as the working directory, so
solutions that read `input.txt` find it.

## Debugging

`make debug` builds with `-D_GLIBCXX_DEBUG` (bounds-checks vector and string
indexing, validates iterators) and `-fsanitize=undefined -fsanitize-trap=undefined`
(signed overflow, bad shifts, null deref).

Undefined behaviour aborts with an illegal-instruction crash and no message,
because MinGW ships no sanitizer runtime. To find the line, run the binary
under gdb:

```
gdb build/0035.exe
run
bt
```

