#ifndef GALA_APPLES_H_
#define GALA_APPLES_H_
#include "Fruit.h"
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

class GalaApples: public Fruit{
public:
    GalaApples();
    
    //abstract
    void descTaste();
	void descColor();


};

#endif

