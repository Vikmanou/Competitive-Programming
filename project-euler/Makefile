CXX := g++
CXXFLAGS := -std=c++20 -O2 -w -Iinclude

EXT := $(if $(findstring mingw,$(shell $(CXX) -dumpmachine)),.exe,)
BUILD := build

TARGET := $(word 2,$(MAKECMDGOALS))
SRC := $(wildcard solutions/$(TARGET)/$(TARGET).cpp)
DIR := $(dir $(SRC))

run:
	@if [ -z "$(TARGET)" ]; then echo "usage: make run 0044"; exit 1; fi
	@if [ -z "$(SRC)" ]; then echo "no C++ solution for $(TARGET)"; exit 1; fi
	@mkdir -p $(BUILD)
	@$(CXX) $(CXXFLAGS) $(SRC) -o $(BUILD)/$(TARGET)$(EXT)
	@cd $(DIR) && start=$$(date +%s%N) && ../../$(BUILD)/$(TARGET)$(EXT) && end=$$(date +%s%N) && \
		ms=$$(( (end - start) / 1000000 )) && \
		echo && echo "Time: $${ms} ms"
	@echo

%:
	@:

list:
	@ls -d solutions/*/ | sed 's|.*/\([^/]*\)/|\1|'

clean:
	rm -rf $(BUILD)

.PHONY: run list clean
