//Kendall Carter IT 279
using namespace std;

#include <iostream>
#include <list>
#include <random>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

//Removed the smallest node
list<int> removeSmallest(list<int> *ls){
  sort(ls->begin(), ls->end(), greater<int>());
  cout << "The smallest value is:  " << ls->back() <<  endl;
  ls->remove(ls->back());
  return *ls;
}

int main(){
    std::list<int> myList;

    myList.push_back(45);
    myList.push_back(35);
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    myList.push_back(20);
    myList.push_back(10);
   

    //prints the original list

    cout << "The Original List: " << endl;
    for (list<int>::iterator itr = myList.begin(); itr != myList.end(); itr++) {
    cout <<  *itr << endl;
    }
    cout << endl;

    std::list<int> *tempList;
    tempList = &myList;

    //Removes the smallest element

    myList= removeSmallest(tempList);

    //prints the list
      cout << "List after removing the smallest element: " << endl;
      for (list<int>::iterator itr = myList.begin(); itr != myList.end(); itr++) {
    cout <<  *itr << endl;
    }
    cout << endl;

    return 0;
};