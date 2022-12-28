CC=g++
CFLAGS= -c 
COUT=-o
all: Developer Executive main
	$(CC) main.o Developer.o Executive.o $(COUT) out
Developer: 
	$(CC) $(CFLAGS) Developer.cpp
Executive: 
	$(CC) $(CFLAGS) Executive.cpp	
main: 
	$(CC) $(CFLAGS) main.cpp
clean:
	rm *.o out
