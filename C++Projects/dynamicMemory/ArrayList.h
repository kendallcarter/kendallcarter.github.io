#ifndef ARRAY_LIST_H_
#define ARRAY_LIST_H_

#include <iostream>
#include <string>
#include <sstream>


using namespace std;

class ArrayList{
public:
    ArrayList();

    void toString();

    void erase(int m);

    void push(int m);

    int getCapacity();

    

private:   
int size;
int capacity;
int *a;
int *temp;

};

#endif