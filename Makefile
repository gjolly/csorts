CC=gcc
CFLAG=-Wall -pedantic -g
OBJ_FILES=sorting.o main.o utils.o
HEADER_FILES=sorting.h utils.h

all: sort

sort: ${OBJ_FILES} ${HEADER_FILES}
	${CC} ${CFLAG} -o $@ $^

%.o: %.c ${HEADER_FILES}
	${CC} ${CFLAG} -c $<

clean:
	rm -f *.o sort
