#include "Faculty.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>     /* srand, rand */

using namespace std;
	Faculty::Faculty(){
		
	}

	//Override
	Faculty::void work() {
		System.out.println("My Work is to teach and help students to reach their goals. "
				+ "Als, I evaluate the student's projects and assignments.");
		w.work();
	}

	//Override
	Faculty::void nextWorker(Worker *worker) {
		w = worker;
	}
