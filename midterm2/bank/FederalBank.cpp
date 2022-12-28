#include "FederalBank.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>     /* srand, rand */

using namespace std;
	FederalBank::FederalBank(){
		
	}

	//Override
	double FederalBank::getInterestRate() {
		// generates a random number between 0 and 1
		double change = rand()%100+1;
		// For C++ using rand() defined in stdlib.h library
		// Step 1: rand() % 100+ 1 - generates a number between 1 - 100.
		// Step 2: Get the random value and then divide by 100.
        change=change/100;

		return FederalBank + change;
	}
