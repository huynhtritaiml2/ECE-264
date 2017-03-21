GCC=gcc -std=c99 -Wvla -Werror -Wunreachable-code -Wall --pedantic -Wshadow -g

all:
	$(GCC) -c answer09.c
	$(GCC) -c pa09.c
	$(GCC) -c linkedlist.c
	$(GCC) pa09.o answer09.o linkedlist.o -o pa09

clean:
	rm -f *.o
	rm -f pa09
