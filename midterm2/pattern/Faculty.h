#ifndef FACULTY_H_
#define FACULTY_H_
#include <iostream>
#include <string>
#include <sstream>
#include "Worker.h"


using namespace std;

class Faculty: public Worker{
public:
    Faculty(){

    };

    void work();
	void nextFaculty(Faculty *w);

    virtual ~Faculty(){

    };



};

#endif