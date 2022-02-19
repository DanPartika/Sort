CC=gcc
CFLAGS=-c -Wall
sort: sort.o mergesort.o
	$(CC) sort.o -o sort