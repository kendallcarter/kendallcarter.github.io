#include "Employee.h"
#include "Developer.h"
#include "Executive.h"

using std::cout;
using std::endl;
using namespace std;



int main(){

    Employee *p;
        p = new Developer("Rishi", 2, 900000);
		std::cout<<(p->name + " gets paid - $" + p->pay());
		p = new Developer("Kanth", 4, 1000000);
		std::cout<<(p->name + " gets paid - $" + p->pay());
        delete p;

		Employee *exe = new Executive("Rishi VP", 4, 1000000);
		std::cout<<(exe->name + " gets paid - $" + exe->pay());
		exe = new Executive("Kanth CEO", 6, 9000000);
		std::cout<<(exe->name + " gets paid - $" + exe->pay());
        delete exe;
    
return 0;
};