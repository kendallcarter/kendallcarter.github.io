#include "FederalBank.h"
#include "StateBank.h"
#include "LocalBank.h"
#include "PersonalLoan.h"

using std::cout;
using std::endl;
using namespace std;



int main(){
 
    FederalBank *f;
	f  = new StateBank();
	f->getInterestRate();
    delete f;


    PersonalLoan *p;

    
    
return 0;
};