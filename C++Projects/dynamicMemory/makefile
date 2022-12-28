CC=g++
CFLAGS= -c 
COUT=-o
all: ArrayList main
	$(CC) main.o ArrayList.o $(COUT) out
ArrayList: 
	$(CC) $(CFLAGS) ArrayList.cpp
main: 
	$(CC) $(CFLAGS) main.cpp
clean:
	rm *.o out
