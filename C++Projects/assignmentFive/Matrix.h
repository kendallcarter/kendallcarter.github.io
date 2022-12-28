#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>
#include <string>
#include <sstream>


using namespace std;

class Matrix{
public:
    Matrix();
    Matrix(int a[3][3]);
    
    string toString() const;
    Matrix *operator +(const Matrix &c) const;
    Matrix *operator -(const Matrix &c) const;
    Matrix *operator *(const Matrix &c) const;
    bool operator==(const Matrix &c) const;
    

private:
    

protected:
    int myArray[3][3];
    int row;
    int column;

};

#endif