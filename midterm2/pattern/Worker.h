#ifndef WORKER_H_
#define WORKER_H_
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

class Worker{
public:
    Worker(){

    };

    virtual void work()=0;
	void nextWorker(Worker *w);

    virtual ~Worker(){

    };



};

#endif