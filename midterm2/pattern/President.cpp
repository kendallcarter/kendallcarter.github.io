#include "Faculty.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>     /* srand, rand */

using namespace std;
	Faculty::Faculty(){
		
	}

	//Override
	Faculty::public work() {
		std::cout<<"I am proud of my students and university. ";
	}

	//Override
	Faculty::void nextWorker(Worker *worker) {
		w = worker;
	}
