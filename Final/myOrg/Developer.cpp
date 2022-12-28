#include "Developer.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
	Developer::Employee(string name, int level, double salary){
		
	}
    //Override
	double Bonus::Bonus() {
		if (level <= 2)
            return .2 * salary;
        else if (level > 2 && level <= 4)
            return .3 * salary;
        return 0;
	}

	//Override
	double Employee::Pay() {
		return salary + bonus();
	}
