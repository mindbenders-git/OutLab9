CC=g++

CFLAGS=-c -Wall

hello: main.o factorial.o hello.o
	$(CC) main.o factorial.o hello.o -o hello

main.o: main.cpp functions.h
	$(CC) $(CFLAGS) main.cpp
	
factorial.o: factorial.cpp functions.h
	$(CC) $(CFLAGS) factorial.cpp
	
hello.o: hello.cpp functions.h
	$(CC) $(CFLAGS) hello.cpp

