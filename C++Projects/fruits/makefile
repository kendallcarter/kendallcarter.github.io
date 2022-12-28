CC=g++
CFLAGS= -c 
COUT=-o
all: RedGrapes GalaApples OrganicGalaApples main
	$(CC) main.o RedGrapes.o GalaApples.o OrganicGalaApples.o $(COUT) out
RedGrapes: 
	$(CC) $(CFLAGS) RedGrapes.cpp
GalaApples: 
	$(CC) $(CFLAGS) GalaApples.cpp	
OrganicGalaApples: 
	$(CC) $(CFLAGS) OrganicGalaApples.cpp
main: 
	$(CC) $(CFLAGS) main.cpp
clean:
	rm *.o out
