CC=gcc
CFLAG=-Wall -pedantic -g --std=c11

OBJ_FILES=sorting.o utils.o test.o out.o list.o heap.o tree.o
HEADER_FILES=sorting.h utils.h test.h out.h test_functions.h list.h tree.h heap.h
OBJ_TEST=$(shell find . -name '*_test.c' | sed 's/_test.c/_test.o/g')
BIN_FILE=test

SORT_ALGO=insertion

all:
	./all_tests.sh

%.o: %.c ${HEADER_FILES}
	${CC} ${CFLAG} -c $< -DSORT_ALGO=${SORT_ALGO}

test: ${OBJ_TEST} ${OBJ_FILES} ${HEADER_FILES}
	${CC} ${CFLAG} -o $@ $^

clean:
	rm -f *.tmp *.o ${BIN_FILE}
