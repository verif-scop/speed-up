all:
	cd matmul && make
	cd covcol && make
	cd gemver && make

clean:
	cd matmul && make clean
	cd covcol && make clean
	cd gemver && make clean
