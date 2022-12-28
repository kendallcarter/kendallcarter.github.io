#include "Executive.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
	Developer::Employee(string name, int level, double salary){
		
	}
    //Override
	double Bonus::Bonus() {
		if (level <= 3)
            return .1 * salary;
        else if (level > 3 && level <= 5)
            return .25 * salary;
        return 0;
	}

	//Override
	double Employee::pay() {
		return salary + bonus();
	}
