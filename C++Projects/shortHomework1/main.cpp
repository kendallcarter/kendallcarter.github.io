#include "Complex.cpp"

    int main()
    {

        Complex c1(3, 4);
        Complex c2(1, 2);
        Complex c3(1, 2);

        Complex *cAdd = c1 + c2;
        cout << "Adding " << c1.toString() << " and " << c2.toString() << " results in : " << (*cAdd).toString() << endl;

        Complex *cSub = c1 - c2;
        cout << "Subtracting " << c1.toString() << " and " << c2.toString() << " results in : " << (*cSub).toString() << endl;

        Complex *cMul = c1 * c2;
        cout << "Multiplying " << c1.toString() << " and " << c2.toString() << " results in : " << (*cMul).toString() << endl;

        if (c2 == c3)
            cout << "The complex numbers " << c2.toString() << " and " << c3.toString() << " are equal." << endl;

        return 0;
    }
