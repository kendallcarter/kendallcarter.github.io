CC=g++
CFLAGS= -c -std=c++11
COUT=-o
all: Matrix.o main.o
	$(CC) main.o Matrix.o $(COUT) out
main.o: main.cpp
	$(CC) $(CFLAGS)  main.cpp
Matrix.o: Matrix.cpp
	$(CC) $(CFLAGS) Matrix.cpp
clean:
	rm *.o out
