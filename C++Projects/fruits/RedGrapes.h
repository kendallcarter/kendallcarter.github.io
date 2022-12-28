#ifndef RED_GRAPES_H_
#define RED_GRAPES_H_
#include "Fruit.h"
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

class RedGrapes: public Fruit{
public:
    RedGrapes();

    //abstract
    void descTaste();
	void descColor();


};

#endif