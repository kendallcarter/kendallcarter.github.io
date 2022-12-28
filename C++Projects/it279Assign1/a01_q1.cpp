//Kendall Carter IT 279
#include <iostream>
#include <string>
#include <sstream>
#include <random>

using std::cout;
using std::endl;
using namespace std;

int main(){

    //Generates the 10 random numbers from 0 to 100
    vector<int> randoms;
    default_random_engine defEngine;
    uniform_int_distribution<int> intDistro(0,100);
    for (int i = 1; i <= 10; i++) {
    randoms.push_back(intDistro(defEngine));
    }

    //prints the list
    cout << "Originally created list: " << endl;
    for (int i=0; i < randoms.size(); i++) {
    cout <<  randoms[i] << endl;
    }
    cout << endl;

    //Sorts the list 
    sort(randoms.begin(), randoms.end(), greater<int>());

    //prints the list
      cout << "Sorted list: " << endl;
      for (int i=0; i < randoms.size(); i++) {
      cout <<  randoms[i] << endl;
    }
    return 0;
};