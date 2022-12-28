#ifndef STUDENT_H_
#define STUDENT_H_
#include <iostream>
#include <string>
#include <sstream>
#include "Worker.h"


using namespace std;

class Student: public Worker{
public:
    Student(){

    };

    void work();
	void nextStudent(Student *w);

    



};

#endif