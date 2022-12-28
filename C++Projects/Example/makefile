CC=g++
CFLAGS= -c -std=c++11
COUT=-o
all: ComplexNumber.o main.o
	$(CC) main.o ComplexNumber.o $(COUT) out
main.o: main.cpp
	$(CC) $(CFLAGS)  main.cpp
ComplexNumber.o: ComplexNumber.cpp
	$(CC) $(CFLAGS) ComplexNumber.cpp
clean:
	rm *.o out
