#ifndef FEDERAL_BANK_H_
#define FEDERAL_BANK_H_
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

class FederalBank{
public:
    FederalBank(){

    };

    //abstract
    virtual double getInterestRate()=0;

    virtual ~FederalBank(){

    };
private:
    double intrestRate;


};

#endif