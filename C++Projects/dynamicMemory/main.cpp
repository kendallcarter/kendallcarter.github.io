#include "ArrayList.h"

using std::cout;
using std::endl;
using namespace std;



int main(){
ArrayList *list= new ArrayList();

list->push(7);
list->push(12);
std::cout<<"Capacity: "<<list->getCapacity()<<"\n";
list->push(15);
list->push(33);
std::cout<<"Capacity: "<<list->getCapacity()<<"\n";

list->toString();

list->erase(12);
list->erase(33);
list->erase(15);
list->toString();
std::cout<<"Capacity: "<<list->getCapacity()<<"\n";


list->push(18);
list->push(22);

std::cout<<"Capacity: "<<list->getCapacity()<<"\n";
list->toString();
    
delete list;

return 0;
}