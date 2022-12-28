 complex: main.o Complex.o
	g++ -std=c++11 -c Complex.o main.o -o out

Complex.o: Complex.cpp
	g++ -std=c++11 -c Complex.cpp


main.o: main.cpp
	g++ -std=c++11 -c main.cpp


clean:
	rm *.o out
