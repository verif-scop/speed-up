
all:
	clang matmul1.c -O3 -Wno-everything -o matmul1.out
	./matmul1.out 
	clang matmul2.c -O3 -Wno-everything -o matmul2.out
	./matmul2.out 
	diff -u 1.output 2.output
