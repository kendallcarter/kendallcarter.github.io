//Kendall Carter IT 279
#include <iostream>
#include <string>
#include <sstream>
#include <random>
#include <list>

using namespace std;

//Returns a union of the two lists 
list<int> listUnion(const list<int> &L1, const list<int> &L2){
  list<int> newList;
  newList= L1;
  list<int> newList2;
  newList2= L2;
  
  newList.merge(newList2);
  sort(newList.begin(), newList.end(), greater<int>());
  return newList;
}

int main(){

    //Generates the 10 random numbers from 1 to 100 for the first list and sorts them
    list<int> randoms;
    default_random_engine defEngine;
    uniform_int_distribution<int> intDistro(1,100);
    for (int i = 1; i <= 10; i++) {
    randoms.push_back(intDistro(defEngine));
    }

    sort(randoms.begin(), randoms.end(), greater<int>());

    //prints the list
    cout << "The first list: " << endl;
    for (list<int>::iterator itr = randoms.begin(); itr != randoms.end(); itr++) {
    cout <<  *itr << endl;
    }
    cout << endl;

    //Generates the 10 random numbers from 1 to 100 for the second list and sorts them
    list<int> randoms2;
    default_random_engine defEngine;
    uniform_int_distribution<int> intDistro(1,100);
    for (int i = 1; i <= 10; i++) {
    randoms2.push_back(intDistro(defEngine));
    }

    sort(randoms2.begin(), randoms2.end(), greater<int>());

    //prints the list
    cout << "The second list: " << endl;
    for (list<int>::iterator itr = randoms2.begin(); itr != randoms2.end(); itr++) {
    cout <<  *itr << endl;
    }
    cout << endl;

    //Creates a union of the lists
    //list<int> result = listUnion(const list<int> &L1, const list<int> &L2);
    list<int> result = listUnion(randoms, randoms2);

    //prints the list
      cout << "The resulting union list: " << endl;
      for (list<int>::iterator itr = result.begin(); itr != result.end(); itr++) {
    cout <<  *itr << endl;
    }
    cout << endl;
    return 0;
};