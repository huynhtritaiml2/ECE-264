GCC=gcc -std=c99 --pedantic -Wall -Wvla -Werror -Wshadow -Wunreachable-code -g

all: pa13

bmp.o: bmp.h bmp.c
	$(GCC) -c bmp.c

filter.o: filter.c filter.h
	$(GCC) -c filter.c

validate.o: validate.c bmp.h
	$(GCC) -c validate.c

pa13: bmp.o validate.o filter.o
	$(GCC) bmp.o validate.o filter.o -o pa13

clean:
	rm -rf *.o
	rm -rf pa13
