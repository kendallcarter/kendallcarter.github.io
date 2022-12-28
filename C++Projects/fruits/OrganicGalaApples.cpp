#include "OrganicGalaApples.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
	OrganicGalaApples::OrganicGalaApples(){
		
	}

	//Override
	void OrganicGalaApples::descTaste() {
		std::cout<<"Organic Gala apples are sweet"<<std::endl;
	}

	//Override
	void OrganicGalaApples::descColor() {
		std::cout<<"Organic Gala apples are reddish brown"<<std::endl;
	}
