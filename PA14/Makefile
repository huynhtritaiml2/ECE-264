GCC=gcc -std=c99 --pedantic -Wall -Wvla -Werror -Wshadow -Wunreachable-code -g -lpthread

all: pa13

bmp.o: bmp.h bmp.c
	$(GCC) -c bmp.c

filterParallel.o: filterParallel.c filterParallel.h
	$(GCC) -c filterParallel.c

filter.o: filter.c filter.h
	$(GCC) -c filter.c

validate.o: validate.c bmp.h filter.h filterParallel.h
	$(GCC) -c validate.c

pa13: bmp.o validate.o filterParallel.o filter.o
	$(GCC) bmp.o validate.o filterParallel.o filter.o -o pa14

clean:
	rm -rf *.o
	rm -rf pa14
