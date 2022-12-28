#include "Worker.h"
#include "Student.h"
#include "faculty.h"
#include "President.h"

using std::cout;
using std::endl;
using namespace std;



int main(){
 
    Worker *w;
    Worker *w2;
    Worker *w3;
	w  = new Student();
    w2= new Faculty();
    w2= new President();

	w->nextWorker(w2);

    w2>nextWorker(w3);

    w->work();

	delete w;
	delete w2;
    delete w3;


return 0;
};