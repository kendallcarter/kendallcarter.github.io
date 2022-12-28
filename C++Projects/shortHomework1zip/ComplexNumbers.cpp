#include <iostream>
#include <string>
#include <sstream>

using namespace std; 
class ComplexNumber
{
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
    ComplexNumber(int real, int imaginary)
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

    ComplexNumber *operator+(const ComplexNumber &c) const
    {
        return new ComplexNumber(
            this->real + c.getReal(),
            this->imaginary + c.getImaginary());
    }

    ComplexNumber *operator-(const ComplexNumber &c) const
    {
        return new ComplexNumber(
            this->real - c.getReal(),
            this->imaginary - c.getImaginary());
    }

    ComplexNumber *operator*(const ComplexNumber &c) const
    {

        int real1 = this->real;
        int real2 = c.getReal();
        int imaginary1 = this->imaginary;
        int imaginary2 = c.getImaginary();

        return new ComplexNumber(
            real1 * real2 - imaginary1 * imaginary2,
            real1 * imaginary2 + real2 * imaginary1);
    }

    bool operator==(const ComplexNumber &c) const
    {
        return this->real == c.real && this->imaginary == c.imaginary;
    }
};

int main()
{

    ComplexNumber c1(3, 4);
    ComplexNumber c2(1, 2);
    ComplexNumber c3(1, 2);

    ComplexNumber *cAdd = c1 + c2;
    cout << "Adding " << c1.toString() << " and " << c2.toString() << " results in : " << (*cAdd).toString() << endl;

    ComplexNumber *cSub = c1 - c2;
    cout << "Subtracting " << c1.toString() << " and " << c2.toString() << " results in : " << (*cSub).toString() << endl;

    ComplexNumber *cMul = c1 * c2;
    cout << "Multiplying " << c1.toString() << " and " << c2.toString() << " results in : " << (*cMul).toString() << endl;

    if (c2 == c3)
        cout << "The complex numbers " << c2.toString() << " and " << c3.toString() << " are equal." << endl;

    return 0;
}