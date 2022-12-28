#ifndef ORGANIC_GALA_APPLES_H_
#define ORGANIC_GALA_APPLES_H_
#include "GalaApples.h"
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

class OrganicGalaApples: public GalaApples{
public:
    OrganicGalaApples();
    
    
    //abstract
    void descTaste();
	void descColor();



};

#endif