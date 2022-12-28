#ifndef EXECUTIVE_H_
#define EXECUTIVE_H_
#include "Employee.h"
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

class Executive: public Employee{
public:
    Executive(string name, int level, double salary){

    };
    
    //abstract
    double Bonus();
	double Pay();


};

#endif