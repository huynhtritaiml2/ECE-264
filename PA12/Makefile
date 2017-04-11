GCC=gcc -std=c99 --pedantic -Wall -Wvla -Werror -Wshadow -Wunreachable-code -g

all: pa12

expressionTree.o: expressionTree.c expressionTree.h tree.h
	$(GCC) -c expressionTree.c

scanner.o: scanner.c scanner.h
	$(GCC) -c scanner.c

pa12.o: pa12.c scanner.h tree.h
	$(GCC) -c pa12.c

tree.o: tree.c tree.h
	$(GCC) -c tree.c

pa12: expressionTree.o scanner.o pa12.o tree.o 
	$(GCC) expressionTree.o scanner.o pa12.o tree.o -o pa12

clean:
	rm -rf *.o
	rm -rf pa12
