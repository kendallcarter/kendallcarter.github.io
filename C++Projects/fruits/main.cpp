#include "RedGrapes.h"
#include "GalaApples.h"
#include "OrganicGalaApples.h"

using std::cout;
using std::endl;
using namespace std;



int main(){
 
    Fruit *f;
	f  = new GalaApples;
	f->descTaste();
    delete f;

	f = new RedGrapes();
	f->descTaste();
    f->descColor();
	delete f;

	f = new OrganicGalaApples();
	f->descTaste();
    f->descColor();
	delete f;


    
return 0;
};