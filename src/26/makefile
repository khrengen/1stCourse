CC = gcc
FLAGS = -g -std=c99 -w -pipe -O3

all: lab26



lab26: queue.o sort.o
	$(CC) $(FLAGS) main.c queue.o sort.o -o lab26

queue.o: queue.h queue.c
	$(CC) $(FLAGS) -c queue.c

sort.o: queue.h sort.h sort.c
	$(CC) $(FLAGS) -c sort.c

clean:
	rm -f *.o