#include <iostream>
#include <string>
#include <sstream>
#include <stab.h>


using namespace std;

class complex{
public:
    int getReal();
    int getImaginary();
    void setReal();
    void setImaginary();
    string toString() const;
    Complex operator+(const Complex& obj) const;
    Complex operator-(const Complex& obj) const;
    Complex operator*(const Complex& obj) const;
    bool operator==(const Complex &c) const;

private:
    string to_string(int value) const;

protected:
    int real;
    int imaginary;




};