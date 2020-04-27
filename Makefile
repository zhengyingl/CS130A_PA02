CXX=g++
BINARIES=prog2.out

prog2.out: prog2.o heap.o
	${CXX} $^ -o $@

clean:
	rm *.o ${BINARIES}