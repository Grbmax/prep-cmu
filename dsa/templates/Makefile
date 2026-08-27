# Usage from the dsa/ directory:
#   make run  FILE=steps/03-arrays/two_sum.cpp     build + run with sanitizers
#   make new  FILE=steps/03-arrays/two_sum.cpp     create a new file from the template
#   make fast FILE=...                             optimized build, no sanitizer
#
# Sanitizers are ON by default and that is deliberate: address + undefined catch
# the exact bug classes on your active drill list (value-vs-index, off-by-one,
# uninitialized reads) at the moment they happen instead of silently.

CXX      := clang++
STD      := -std=c++17
WARN     := -Wall -Wextra -Wshadow -Wconversion
# -Itemplates makes <bits/stdc++.h> resolve to the shim (Apple clang has no real one)
INC      := -Itemplates
SAN      := -g -fsanitize=address,undefined -fno-omit-frame-pointer
BIN      := .build

export ASAN_OPTIONS := detect_stack_use_after_return=1

.PHONY: run fast new clean

run:
	@mkdir -p $(BIN)
	$(CXX) $(STD) $(WARN) $(INC) $(SAN) $(FILE) -o $(BIN)/a.out
	@echo "--- run ---"
	@$(BIN)/a.out

fast:
	@mkdir -p $(BIN)
	$(CXX) $(STD) $(WARN) $(INC) -O2 $(FILE) -o $(BIN)/a.out
	@$(BIN)/a.out

new:
	@if [ -e "$(FILE)" ]; then echo "refusing: $(FILE) already exists"; exit 1; fi
	@mkdir -p $(dir $(FILE))
	@cp templates/solution.cpp "$(FILE)"
	@echo "created $(FILE)"

clean:
	@rm -rf $(BIN)
