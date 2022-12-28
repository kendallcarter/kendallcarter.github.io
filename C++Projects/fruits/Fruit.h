#ifndef FRUIT_H_
#define FRUIT_H_

#include <iostream>
#include <string>
#include <sstream>


using namespace std;

class Fruit{
public:
    Fruit(){

    }
    virtual ~Fruit(){

    }
    
    //abstract
    virtual void descTaste()=0;
	virtual void descColor()=0;

    


};

#endif