CXX := g++
CXXFLAGS := -std=c++20 -O2 -w -Iinclude

EXT := $(if $(findstring mingw,$(shell $(CXX) -dumpmachine)),.exe,)
BUILD := build

SRC := $(firstword $(wildcard solutions/$(p)/$(p).cpp unsolved/$(p)/$(p).cpp))
DIR := $(dir $(SRC))

run:
	@if [ -z "$(p)" ]; then echo "usage: make run p=0044"; exit 1; fi
	@if [ -z "$(SRC)" ]; then echo "no C++ solution for p=$(p)"; exit 1; fi
	@mkdir -p $(BUILD)
	@$(CXX) $(CXXFLAGS) $(SRC) -o $(BUILD)/$(p)$(EXT)
	@cd $(DIR) && start=$$(date +%s%N) && ../../$(BUILD)/$(p)$(EXT) && end=$$(date +%s%N) && \
		ms=$$(( (end - start) / 1000000 )) && \
		echo && echo "Time: $${ms} ms"
	@echo

list:
	@ls -d solutions/*/ unsolved/*/ | sed 's|.*/\([^/]*\)/|\1|'

clean:
	rm -rf $(BUILD)

.PHONY: run list clean
