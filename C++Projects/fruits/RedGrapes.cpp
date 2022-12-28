#include "RedGrapes.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
	RedGrapes::RedGrapes(){
		
	}
    //Override
	void RedGrapes::descTaste() {
		std::cout<<"Red Grappes tastes sweet and sour"<<std::endl;
	}

	//Override
	void RedGrapes::descColor() {
		std::cout<<"Red Grappes are red"<<std::endl;
	}
