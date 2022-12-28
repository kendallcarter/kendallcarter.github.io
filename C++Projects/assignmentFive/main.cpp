#include "Matrix.h"
using std::cout;
using std::endl;

int main(){

    int a[3][3];

    Matrix c1(a);
    Matrix c2(a);
    Matrix c3(a);
    
	Matrix* cAdd = c1 + c2;
	cout<<"Adding "<<c1.toString()<<" and "<<c2.toString()<<" results in : "<<(*cAdd).toString()<<endl;

	Matrix* cSub = c1-c2;
	cout<<"Subtracting "<<c1.toString()<<" and "<<c2.toString()<<" results in : "<<(*cSub).toString()<<endl;

	Matrix* cMul = c1*c2;
	cout<<"Multiplying "<<c1.toString()<<" and "<<c2.toString()<<" results in : "<<(*cMul).toString()<<endl;

	if(c2 == c3)
		cout<<"The Matrices "<<c2.toString()<<" and "<<c3.toString()<<" are equal."<<endl;

	delete cAdd;
	delete cSub;
	delete cMul;
    
    return 0;
};