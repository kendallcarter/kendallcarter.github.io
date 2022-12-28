#include "Student.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>     /* srand, rand */

using namespace std;
	Student::Student(){
		
	}

	//Override
	Student::public work() {
		std::cout<<"My Work is to get projects and assignment done on time ";
		w.work();
	}

	//Override
	Student::void nextWorker(Worker *worker) {
		w = worker;
	}
