# declare a variable
CC=g++

CFLAGS=-c -Wall

all: linkedList

linkedList: main.o
						$(CC) main.o -o linkedList

main.o: main.cpp
				$(CC) $(CFLAGS) main.cpp

clean: 
				rm -rf *.o linkedList