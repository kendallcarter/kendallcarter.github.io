#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <random>

using namespace std;

int removeSmallest(list<int> *ls){
  //sort(ls.begin(), ls.end(), greater<int>());
  //ls.pop_back();
  //return ls;
  return 0;
}

int main(){

    //Generates the 10 random numbers from 0 to 100
    //const int a[] = { 45,25,35,10,20,30,20,10};
    //list<int> myList (*a);

    std::list<int>myList;
    myList.push_front(6);
    myList.push_front(3);

   // myList.push_back(45,25,35,10,20,30,20,10);

    //removeSmallest(myList);

    //prints the original list
    cout << "The Original List: " << endl;
    for (auto it = myList.begin(); it != myList.end(); it++) {
    cout <<  *it << endl;
    }
    cout << endl;

    for (int i=0; i < myList.size(); i++) {
    cout <<  myList[i] << endl;
    }
    cout << endl;

    //Prints the smallest value
    cout << "The smallest value is:  " << endl;

    //Removes the smallest element
    //removeSmallest(myList);

    //prints the list
      cout << "List after removing the smallest element: " << endl;
      for (int i=0; i < myList.size(); i++) {
      cout <<  myList[i] << endl;
    }

    return 0;
};