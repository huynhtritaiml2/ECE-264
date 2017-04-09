GCC=gcc -std=c99 -Wall -Werror -Wshadow --pedantic -Wvla -Wunreachable-code -g
VALGRIND = valgrind --tool=memcheck --leak-check=yes 

all: pa10

pa10: list.o maze.o pa10.o solver.o

list.o: list.c list.h
	$(GCC) -c list.c -o list.o

maze.o: maze.c maze.h
	$(GCC) -c maze.c -o maze.o

pa10.o: pa10.c maze.h path.h solver.h
	$(GCC) -c pa10.c -o pa10.o

solver.o: solver.c solver.h mazehelper.h path.h list.h
	$(GCC) -c solver.c -o solver.o

clean:
	rm -f *.o
	rm -f pa10

memory: pa10
	$(VALGRIND) pa10 inputs/maze3 maze3_out
