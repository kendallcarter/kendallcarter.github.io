// #include<iostream>
// #include <cmath>
// using namespace std;

// class BankAccount {
// 	private:
// 		double checkingAmt, savingAmt;
// 		double checkingRate = 3.3, savingRate = 4.3, time = 30;
// 	public:
// 		BankAccount(double c, double s){
// 			checkingAmt = c;
// 			savingAmt = s;
// 		}
// 		double getInterestOnChecking() {
// 			return (checkingAmt*(1+(checkingRate/100)*time)-checkingAmt);
// 		}
// 		double getInterestOnSaving() {
// 			return (savingAmt*pow(1+(savingRate/100),time) - savingAmt);;
// 		}
// };

// int main () {
// 	BankAccount* b = new BankAccount(1000,2000);
// 	cout<<"Interest on checking - "<<b->getInterestOnChecking()<<endl;
// 	cout<<"Interest on saving - "<<b->getInterestOnSaving()<<endl;
// 	delete b;

// 	return 0;
// }

// BankAccount<int>* b = new BankAccount(1000,2000);
// 	cout<<"Interest on checking - "<<b->getInterestOnChecking()<<endl;
// 	cout<<"Interest on saving - "<<b->getInterestOnSaving()<<endl;
// 	delete b;

// BankAccount<int, int> b BankAccount(1000,2000);
// 	cout<<"Interest on checking - "<<b.getInterestOnChecking()<<endl;
// 	cout<<"Interest on saving - "<<b.getInterestOnSaving()<<endl;
	//delete b;