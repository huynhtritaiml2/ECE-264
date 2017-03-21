
CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
COVFLAGS = -fprofile-arcs -ftest-coverage
PROFFLAG = -pg
GCC = gcc $(CFLAGS) # $(COVFLAGS) $(PROFFLAG)

DIR_INPUT = testdir/
DIR_OUTPUT = output_

FUNC_OBJ = func1.o func2.o func3.o func4.o func5.o

all: pa04

pa04.o: pa04.c pa04.h
	$(GCC) -c pa04.c

answer04.o: answer04.c pa04.h
	$(GCC) -DTEST_INTEGRATE -DRUN_INTEGRATE -c answer04.c

func1.o:
func2.o:
func3.o:
func4.o:
func5.o: 
	$(GCC) -c $*.c

pa04: pa04.o answer04.o $(FUNC_OBJ)
	$(GCC) pa04.o answer04.o $(FUNC_OBJ) -o pa04 -lm

testall: pa04
	echo "testing beings . . ."
	echo "test 1"
	./pa04 $(DIR_INPUT)test1 $(DIR_OUTPUT)test1
	echo "test 2"
	./pa04 $(DIR_INPUT)test2 $(DIR_OUTPUT)test2
	echo "test 3"
	./pa04 $(DIR_INPUT)test3 $(DIR_OUTPUT)test3
	echo "test 4"
	./pa04 $(DIR_INPUT)test4 $(DIR_OUTPUT)test4
	echo "test 5"
	./pa04 $(DIR_INPUT)test5 $(DIR_OUTPUT)test5
	echo "testing finished"

printOutput:
	echo "print output"
	echo "test1-------------------------"
	cat $(DIR_OUTPUT)test1
	echo "test2-------------------------"
	cat $(DIR_OUTPUT)test2
	echo "test3-------------------------"
	cat $(DIR_OUTPUT)test3
	echo "test4-------------------------"
	cat $(DIR_OUTPUT)test4
	echo "test5-------------------------"
	cat $(DIR_OUTPUT)test5
	echo "done printing output"

clean:
	/bin/rm -f input*
	/bin/rm -f *.o
	/bin/rm -f testgen 
	/bin/rm -f *.gcda *.gcno gmon.out *gcov
	/bin/rm -f pa04 pa04.prof
	/bin/rm -f output*
