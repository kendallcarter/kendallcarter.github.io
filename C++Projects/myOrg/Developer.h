#ifndef DEVELOPERS_H_
#define DEVELOPERS_H_
#include "Employee.h"
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

class Developer: public Employee{
public:
    Developer(string name, int level, double salary){
        Employee.level=level;

    };
    
    //abstract
    double Bonus();
	double Pay();


};

#endif