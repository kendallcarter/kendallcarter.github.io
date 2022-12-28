#include <iostream>
#include <cmath>
using namespace std;

template <class T, class U, class V, class W>

class GasLaw {
	private:
		T pressure;
	    U volume;
	    V moles;
	    string name;
		
	public:
        double const R = 8.314;
		GasLaw (T t,U u, V v, W w){
			pressure=t;
	        volume=u;
	        moles=v;
	        name=w;
		}
        virtual ~GasLaw(){

        }
		virtual void displayTemp() {
			cout<<"Temp of "<<name<<" gas is: "<<((pressure*volume)/(moles*R))<<endl;
		}
		

};


int main () {
	int p= 1;
	int v= 30;
	int m= 1;
	string n= "Sodium";

	GasLaw<int,int,int,string> *s= new GasLaw(p,v,m,n);
    
    s->displayTemp();

    delete s;


	p= 3;
	v= 30;
	m= 10;
	n= "Oxygen";
    
	GasLaw<int,int,int,string> *o= new GasLaw(p,v,m,n);

	o->displayTemp();

	delete o;


	p= 10;
	v= 600;
	m= 5;
	n= "Hydrogen";
    
	GasLaw<int,int,int,string> *h= new GasLaw(p,v,m,n);
	
	h->displayTemp();

	delete h;


	return 0;
}