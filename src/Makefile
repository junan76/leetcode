project := leetcode

B ?= build
$(if "$(B)", $(shell mkdir -p "$(B)"))

srcs = $(wildcard *.cpp)
exes = $(srcs:%.cpp=$(B)/%)

.PHONY: all
all: $(exes)
	@:

$(B)/%: %.cpp
	g++ -g $< -o $@

%_debug: $(B)/%
	gdb $<

%_run: $(B)/%
	$<

.PHONY: clean
clean:
	rm -rf $(exes)