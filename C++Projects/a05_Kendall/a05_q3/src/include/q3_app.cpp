#include "SplayTree.h"
#include "flags.h"
#include "SplayTree.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <iterator>
#include <map>
using namespace std;

// Testing program
int main()
{
    cout << "\nAssignment 05, Question 03 Kendall Carter: " << endl;
    
    // Add your code
    list< pair< int, string > > studentInfo;
    map<string, int> studentInfo2;
    SplayTree<string> t;
    int theValue;

    //Opening the file 
    string line;
    

    ifstream myfile ("enroll2.txt");
    if(myfile.is_open()){
        while (std::getline (myfile,line))
        {
            t.insert(line);

        }  
    }
    cout<<"The built splay tree: ";

    t.printTree();

    ifstream myfile2 ("query2.txt");

    if(myfile2.is_open()){
        while (std::getline (myfile2,line))
        {
            
            if(t.search(line)==true){
                //Inster into pair list
                theValue = t.remove(line);
                studentInfo.push_back( make_pair(theValue ,line) );
            }else{
                //insert into pair list with value zero
                studentInfo.push_back( make_pair(0 ,line) );
            }
        }  
    }


    int pairCount2=0;

    cout<< endl << "The queried students sorted by number of courses taken in descending order: " << endl;

    studentInfo.sort();

        for (auto it = studentInfo.cbegin(); it != studentInfo.cend(); it++) {
        cout << "(" << it->first <<","<< it->second <<") ";

        if (pairCount2 == 5){
            cout<< endl;
            pairCount2=0;
        }

        pairCount2++;
        }

    
    
    cout<<"The updated splay tree: ";

    t.printTree();

    myfile.close();
    myfile2.close();

   

    return 0;

}
