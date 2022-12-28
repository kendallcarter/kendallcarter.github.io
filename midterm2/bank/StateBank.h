#ifndef STATE_BANK_H_
#define STATE_BANK_H_
#include <FederalBank.h>
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

class StateBank: public FederalBank{
public:
    StateBank(){

    };
    virtual double getInterestRate()=0;

private:
    double intrestRate;   


};

#endif