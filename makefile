CC = gcc
F = -Wall -g

all: isort txtfind
isort: isort.o
	$(CC) -o isort isort.o
isort.o: isort.c
	$(CC) $(F) -c isort.c
txtfind: txtfind.o
	$(CC) -o txtfind txtfind.o
txtfind.o: txtfind.c
	$(CC) $(F) -c txtfind.c

.PHONY: all clean
clean:
	rm -f *.o *.a isort txtfind
