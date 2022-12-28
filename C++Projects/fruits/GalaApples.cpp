#include "GalaApples.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
	GalaApples::GalaApples(){

	}

	//Override
	void GalaApples::descTaste() {
		std::cout<<"Gala apples tastes sweet and are crisp"<<std::endl;
	}

	//Override
	void GalaApples::descColor() {
		std::cout<<"Gala apples reddish yellow"<<std::endl;
	}
