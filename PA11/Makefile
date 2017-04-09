GCC = gcc -std=c99 -Wall -Werror -Wvla -Wshadow --pedantic -Wunreachable-code -g
VALGRIND = valgrind --tool=memcheck --leak-check=yes 

all: pa11

pa11: pa11.o stack.o calc.o
	$(GCC) pa11.o stack.o calc.o -o pa11

pa11.o: pa11.c stack.h
	$(GCC) -c pa11.c

stack.o: stack.c stack.h
	$(GCC) -c stack.c

calc.o: calc.c calc.h
	$(GCC) -c calc.c

memory:
	$(VALGRIND) pa11 inputs/test2

clean:
	rm -f *.o
	rm -f *~
	rm -f pa11
