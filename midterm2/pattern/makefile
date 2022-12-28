CC=g++
CFLAGS= -c 
COUT=-o
all: FederalBank LocalBank StateBank PersonalLoan main
	$(CC) main.o FederalBank.o LocalBank.o StateBank.o PersonalLoan.o $(COUT) out
FederalBank: 
	$(CC) $(CFLAGS) FederalBank.cpp
LocalBank: 
	$(CC) $(CFLAGS) LocalBank.cpp	
StateBank: 
	$(CC) $(CFLAGS) StateBank.cpp
PersonalLoan: 
	$(CC) $(CFLAGS) PersonalLoan.cpp
main: 
	$(CC) $(CFLAGS) main.cpp
clean:
	rm *.o out
