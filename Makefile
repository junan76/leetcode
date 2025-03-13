p ?= add_two_numbers
args =

a.out: src/$p.cpp
	g++ -g src/$p.cpp -o a.out

run: a.out
	./a.out $(args)

debug: a.out
	gdb --args a.out $(args)

clean:
	rm -f a.out