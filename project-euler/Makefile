CXX := g++
CXXFLAGS := -std=c++20 -w -Iinclude
RELEASE := -O2
DEBUG := -g -O0 -D_GLIBCXX_DEBUG -fsanitize=undefined -fsanitize-trap=undefined

EXT := $(if $(findstring mingw,$(shell $(CXX) -dumpmachine)),.exe,)
BUILD := build

SRC := $(firstword $(wildcard solutions/$(p)/$(p).cpp unsolved/$(p)/$(p).cpp))
DIR := $(dir $(SRC))
OPT ?= $(RELEASE)

run:
	@if [ -z "$(p)" ]; then echo "usage: make run p=0044"; exit 1; fi
	@if [ -z "$(SRC)" ]; then echo "no C++ solution for p=$(p)"; exit 1; fi
	@mkdir -p $(BUILD)
	@$(CXX) $(CXXFLAGS) $(OPT) $(SRC) -o $(BUILD)/$(p)$(EXT)
	@cd $(DIR) && start=$$(date +%s%N) && ../../$(BUILD)/$(p)$(EXT) && end=$$(date +%s%N) && \
		ms=$$(( (end - start) / 1000000 )) && \
		echo && echo "Time: $${ms} ms"
	@echo

debug: OPT := $(DEBUG)
debug: run

list:
	@ls -d solutions/*/ unsolved/*/ | sed 's|.*/\([^/]*\)/|\1|'

clean:
	rm -rf $(BUILD)

.PHONY: run debug list clean
