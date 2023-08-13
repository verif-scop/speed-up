
all:
	clang matmul1.c -O3 -Wno-everything -o matmul1.out
	./matmul1.out 
	clang matmul2.c -O3 -Wno-everything -o matmul2.out
	./matmul2.out 
	diff -u 1.output 2.output

clean:
	rm -f *.out .output *.output *.scop *.pluto.c *.pluto.cloog .outfilename .regtile .srcfilename
