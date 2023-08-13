
all:
	clang gemver1.c -O3 -Wno-everything -o gemver1.out
	./gemver1.out 2> 1.output
	clang gemver2.c -O3 -Wno-everything -o gemver2.out
	./gemver2.out 2> 2.output
	diff -u 1.output 2.output

clean:
	rm -f *.out .output *.output *.scop *.pluto.c *.pluto.cloog .outfilename .regtile .srcfilename

