#ifndef STATE_BANK_H_
#define STATE_BANK_H_
#include <StateBank.h>
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

class LocalBank: public StateBank{
public:
    LocalBank(){

    };

    
private:
    double intrestRate;

};

#endif