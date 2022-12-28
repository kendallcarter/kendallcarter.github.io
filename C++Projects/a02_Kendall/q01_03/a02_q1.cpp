#include <iostream>
#include <vector>
#include <random>

using namespace std;


int main()
{
    vector<int> *lst = new vector<int>();
    
    //Generates the 12 random integers and pushes them onto the vector 
    default_random_engine defEngine;
    uniform_int_distribution<int> intDistro(1,100);
    for (int i = 1; i <= 12; i++) {
    lst->push_back(intDistro(defEngine));
    }

    //Copies the vector
    vector<int> copyList = *lst;
    
    cout << "\n--------------------------------------------" << endl;
    cout << "IT 279 Assignment 02: Q01 Kendall Carter" << endl;
    cout << "\n The original vector: ";

    //Prints the original vector
    for(int i =0; i<copyList.size(); i++){
        cout <<  copyList[i] << " ";
    }

    //Reverses the List
    for(int i =0; i<6; i++){
        copyList.push_back(lst->back());
        lst->pop_back() ;
    }
    for(int i =0; i<6; i++){
        lst->push_back(copyList.back()) ;
        copyList.pop_back();
    }
    

    copyList = *lst;


    cout << "\n The reversed vector from index 6 to the end: ";

    for(int i =0; i<copyList.size(); i++){
        cout <<  copyList[i] << " ";
    }

    copyList = *lst;

    int oddSum;
    //Adds together the odd elements of the list
    for(int i =0; i<copyList.size(); i++){
        if (copyList[i]%2 != 0)
        {
            oddSum+=copyList[i];
        }
        
    }

    cout << "\n The sum of the odd vector elements: " << oddSum;

    //Deletes elements 6 through 8
    lst->erase(lst->begin()+5,lst->begin()+9);


    copyList = *lst;
    
    cout << "\n The vector after deleting elements with index 6 to 8: ";

    for(int i =0; i<copyList.size(); i++){
        cout <<  copyList[i] << " ";
    }
    cout << "\n--------------------------------------------" << endl;
    return 0;
}