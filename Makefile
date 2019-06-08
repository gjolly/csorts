CC=gcc
CFLAG=-Wall -pedentic
LIBS=./libs

all: %.o
	${CC} ${CFLAG} -o $@ $^

%.o: ${LIBS}/%.c
	${CC} ${CFLAG} -c $@ $<

clean:
	rm *.o
