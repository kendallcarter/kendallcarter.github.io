#include <iostream>
#include <string>
#include <sstream>
#include "Complex.h"

using namespace std;

class Complex{
private:
    string to_string(int value) const
    {
        std::ostringstream os;

        os << value;

        return os.str();

    }

protected:
    int real;
    int imaginary;

public:
    Complex(int real, int imaginary)
    {
        this->setReal(real);
        this->setImaginary(imaginary);
    }
    int getReal() const
    {
        return real;
    }
    int getImaginary() const
    {
        return imaginary;
    }
    void setReal(int real)
    {
        this->real = real;
    }

    void setImaginary(int imaginary)
    {
        this->imaginary = imaginary;
    }

    string toString() const
    {
        return to_string(real) + "+ i" + to_string(imaginary);
    }

    Complex *operator+(const Complex &c) const
    {
        return new Complex(
            this->real + c.getReal(),
            this->imaginary + c.getImaginary());
    }

    Complex *operator-(const Complex &c) const
    {
        return new Complex(
            this->real - c.getReal(),
            this->imaginary - c.getImaginary());
    }

    Complex *operator*(const Complex &c) const
    {

        int real1 = this->real;
        int real2 = c.getReal();
        int imaginary1 = this->imaginary;
        int imaginary2 = c.getImaginary();

        return new Complex(
            real1 * real2 - imaginary1 * imaginary2,
            real1 * imaginary2 + real2 * imaginary1);
    }

    bool operator==(const Complex &c) const
    {
        return this->real == c.real && this->imaginary == c.imaginary;
    }





};