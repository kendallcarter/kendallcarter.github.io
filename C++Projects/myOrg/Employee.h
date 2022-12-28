#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include "Bonus.h"
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

class Employee: public Employee{
public:
    Employee(){
    
    };
    Employee(int l, double s){
        //this.level = level;
        //this.salary = salary;  
        level = l;
        salary = s;  
    };

    string name;
//public abstract double pay();    
virtual double pay()=0;   
    
protected:
    int level = 0;
    double salary = 0;


    


};

#endif

