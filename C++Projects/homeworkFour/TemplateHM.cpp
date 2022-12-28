#include <iostream>
#include <cmath>
using namespace std;

template <class T, class U>

class BankAccount {
	private:
		T checkingAmt;
		U savingAmt;
		double checkingRate = 3.3, savingRate = 4.3, time = 30;
		
		
	public:
		BankAccount (T c,U s){
			checkingAmt = c;
			savingAmt = s;
		}
		T getInterestOnChecking() {
			return (checkingAmt*(1+(checkingRate/100)*time)-checkingAmt);
		}
		T getInterestOnSaving() {
			return (savingAmt*pow(1+(savingRate/100),time) - savingAmt);;
		}

};


int main () {
	BankAccount<int,int> b(1000,2000);
	cout<<"Interest on checking - "<<b.getInterestOnChecking()<<endl;
	cout<<"Interest on saving - "<<b.getInterestOnSaving()<<endl;
	

	return 0;
}