CC = gcc
FLAGS = -g -std=c99 -w -pipe -O3

all: generate.o print.o execute.o io.o
	$(CC) generate.o
	$(CC) execute.o
	$(CC) print.o

io.o: io.c student.h
	$(CC) $(FLAGS) -c io.c

execute.o: execute.c io.o 
	$(CC) $(FLAGS) -c execute.c 

print.o:print.c io.o 
	$(CC) $(FLAGS) -c print.c 

generate.o: generate.c io.o 
	$(CC) $(FLAGS) -c generate.c 

clean:
	rm -f *.o