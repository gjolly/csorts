CC=gcc
CFLAG=-Wall -pedantic -g
OBJ_FILES=sorting.o main.o utils.o

all: sort

sort: ${OBJ_FILES} 
	${CC} ${CFLAG} -o $@ $^

%.o: %.c
	${CC} ${CFLAG} -c $<

clean:
	rm -f *.o sort
