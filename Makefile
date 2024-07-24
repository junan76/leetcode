project := leetcode

B ?= build
$(if "$(B)", $(shell mkdir -p "$(B)"))

srcs = $(wildcard src/*.cpp)
exes = $(srcs:%.cpp=$(B)/%)

.PHONY: all
all: $(exes)
	@:

$(B)/%: %.cpp
	mkdir -p $(dir $@)
	g++ -g $< -o $@

%_debug: $(B)/src/%
	gdb $<

%_run: $(B)/src/%
	$<

.PHONY: clean
clean:
	rm -rf $(exes)