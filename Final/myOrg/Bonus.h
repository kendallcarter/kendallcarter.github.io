#ifndef DEVELOPERS_H_
#define DEVELOPERS_H_
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

class Developer: public Employee{
public:
    Developer(string name, int level, double salary){
        
    };
    
    //abstract
    virtual double pay()=0;


};

#endif