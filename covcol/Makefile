
all:
	clang covcol1.c -O3 -Wno-everything -o covcol1.out
	./covcol1.out 2> 1.output
	clang covcol2.c -O3 -Wno-everything -o covcol2.out
	./covcol2.out 2> 2.output
	diff -u 1.output 2.output
