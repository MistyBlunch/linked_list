# declare a variable
CC=g++

CFLAGS=-c -Wall

all: 	main
			echo "Finish :D" 

main: main.o
			$(CC) main.o -o linkedList

main.o: message.o
				$(CC) $(CFLAGS) main.cpp

message.o: 
					echo "Testing Linked List uwu..." 

clean: 
			rm -rf *.o linkedList