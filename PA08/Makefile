ARGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror -Wunreachable-code

all: pa08

pa08: pa08.o solver.o
	gcc $(ARGS) maze.o pa08.o solver.o -o pa08

maze.o: maze.c maze.h
	gcc $(ARGS) -c maze.c

pa08.o: pa08.c maze.h path.h
	gcc $(ARGS) -c pa08.c

solver.o: solver.c maze.h path.h
	gcc $(ARGS) -c solver.c

clean:
	rm -f *.o
	rm pa08

test: pa08
	cat inputs/maze1
	./pa08 inputs/maze1
	cat inputs/maze2
	./pa08 inputs/maze2
	cat inputs/maze3
	./pa08 inputs/maze3
	cat inputs/maze4
	./pa08 inputs/maze4
	cat inputs/maze5
	./pa08 inputs/maze5
