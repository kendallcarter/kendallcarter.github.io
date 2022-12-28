#ifndef PRESIDENT_H_
#define PRESIDENT_H_
#include <iostream>
#include <string>
#include <sstream>
#include "Faculty.h"


using namespace std;

class President: public Worker{
public:
    President(){

    };

    void work();
	void nextPresident(President *w);

    virtual ~President(){

    };



};

#endif