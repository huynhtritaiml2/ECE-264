GCC=gcc -std=c99 -Wall -Werror --pedantic -Wshadow -Wunreachable-code -g

PATH_ARGS=
MAZE_ARGS=

VAL_ARGS = --tool=memcheck --leak-check=full --show-reachable=yes
VALGRIND = valgrind $(VAL_ARGS)

all: pa07

pa07: pa07.o maze.o path.o
	$(GCC) pa07.o maze.o path.o -o pa07

maze.o: maze.c maze.h
	$(GCC) $(MAZE_ARGS) -c maze.c -o maze.o

path.o: path.c path.h
	$(GCC) $(PATH_ARGS) -c path.c -o path.o

pa07.o: pa07.c maze.h path.h
	$(GCC) $(PATH_ARGS) -c pa07.c -o pa07.o

gen: MazeGen/gen.c MazeGen/gen.h
	$(GCC) MazeGen/gen.c -o gen

test: pa07
	./pa07 inputs/maze1 inputs/path1
	./pa07 inputs/maze1 inputs/path1-bad1
	./pa07 inputs/maze1 inputs/path1-bad2

gen-test: pa07 gen
	./gen
	./pa07 maze path_good1
	./pa07 maze path_good2
	./pa07 maze path_bad1
	./pa07 maze path_bad2

clean:
	rm -f *.o
	rm -f pa07
	rm -f path_*
	rm -f gen
	rm -f maze

memory: pa07
	$(VALGRIND) pa07 inputs/maze1 inputs/path1
