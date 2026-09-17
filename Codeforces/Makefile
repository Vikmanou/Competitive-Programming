CXX := g++
CXXFLAGS := -std=c++20 -O2 -w -Iinclude

EXT := $(if $(findstring mingw,$(shell $(CXX) -dumpmachine)),.exe,)
BUILD := build

# grab first arg after "run"
TARGET := $(word 2,$(MAKECMDGOALS))
SRC := $(wildcard solutions/$(TARGET).cpp)

run:
	@if [ -z "$(TARGET)" ]; then echo "usage: make run 4a"; exit 1; fi
	@if [ -z "$(SRC)" ]; then echo "no C++ solution for $(TARGET)"; exit 1; fi
	@mkdir -p $(BUILD)
	@$(CXX) $(CXXFLAGS) $(SRC) -o $(BUILD)/$(TARGET)$(EXT)
	@start=$$(date +%s%N) && ./$(BUILD)/$(TARGET)$(EXT) && end=$$(date +%s%N) && \
		ms=$$(( (end - start) / 1000000 )) && \
		echo && echo "Time: $${ms} ms"
	@echo

# prevent make from treating the filename as a target
%:
	@:

list:
	@ls solutions/*.cpp 2>/dev/null | sed 's|solutions/||;s|\.cpp||'

clean:
	rm -rf $(BUILD)

.PHONY: run list clean
