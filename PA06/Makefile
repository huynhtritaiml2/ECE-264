GCC_ARGS = -std=c99 -Wall -Wshadow --pedantic -Werror
COV_FLAGS = -fprofile-arcs -ftest-coverage
PROF_FLAG = -pg

GCC = gcc $(GCC_ARGS) # $(COV_FLAGS) $(PROF_FLAG)

DEL = /bin/rm -f

VAL_ARGS = --tool=memcheck --leak-check=full
VALGRIND = valgrind $(VAL_ARGS)

TEST_ARGS = -DTEST_READ -DTEST_WRITE -DTEST_SORTID -DTEST_SORTFIRSTNAME -DTEST_SORTLASTNAME
M_SORT_ARGS =

all: pa06

student.o: student.c student.h constant.h msort.h
	$(GCC) $(TEST_ARGS) -c student.c -o student.o

msort.o: msort.c msort.h
	$(GCC) $(M_SORT_ARGS) -c msort.c -o msort.o

pa06.o: pa06.c student.h constant.h
	$(GCC) -c pa06.c -o pa06.o

pa06: student.o pa06.o msort.o
	$(GCC) student.o pa06.o msort.o -o pa06

test: pa06

	echo 'Being Testing . . .'
	echo 'Generate Output . . .'
	echo 'Test 1 ---'
	./pa06 inputs/testinput1 id1 first1 last1
	echo 'Test 2 ---'
	./pa06 inputs/testinput2 id2 first2 last2
	echo 'Test 3 ---'
	./pa06 inputs/testinput3 id3 first3 last3
	echo 'Output Generated!'
	echo 'Determine Difference . . .'
	echo 'Output 1 ---'
	diff id1 expected/id1
	diff first1 expected/first1
	diff last1 expected/last1
	echo 'Output 2 ---'
	diff id2 expected/id2
	diff first2 expected/first2
	diff last2 expected/last2
	echo 'Output 3 ---'
	diff id3 expected/id3
	diff first3 expected/first3
	diff last3 expected/last3
	echo 'Testing Done!'

memory: pa06
	$(VALGRIND) pa06 inputs/testinput3 id3 first3 last3

clean:
	$(DEL) *.o
	$(DEL) pa06
	$(DEL) *gcda *.gcno gmon.out *.gcov
	$(DEL) first*
	$(DEL) last*
	$(DEL) id*
