#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <functional>
#include <array>
#include <cassert>
#include <random>
#include <sstream> // std::stringstream
#include <fstream>
#include "BinaryHeap.h"
#include "BinaryHeap.cpp"
#include "flags.h"
#include "Student.h"

#include "Student.cpp"

using namespace std;

// Test program
int main()
{
    cout << "\nAssignment 07, Question 02 Kendall Carter: " << endl;
	// Add your code here:
    Student<string> theStudent;
    BinaryHeap<Student<string>> theHeap;

    //Opening the file 
    string line;
    
    ifstream myfile ("enroll_test.txt");

    string word;
    int lineCount = 0;
    
    //opens and reads file
    if(myfile.is_open()){
        while (std::getline (myfile,line))
        {
            int key = 0;
            string studentInfo;
            stringstream iss(line);

            while (iss >> word){
                
                switch (lineCount)
                {
                case 0:
                    key = atoi(word.c_str());

                    break;
                case 1:
                    theStudent.setFirstName(word);
                   
                    break;
                
                case 2:
                    theStudent.setLastName(word);
                    
                    break;
                case 3:
                    theStudent.setDepartment(word);
                    
                    break;
                case 4:
                    theStudent.setGPA(word);
                    
                    break;
                default:
                    break;
                }
                lineCount++;

                if(lineCount==5){
                    //theTable.insert(key,theStudent);
                    lineCount=0;
                }
               
            }
               
        }  
    
    }
    cout<< "The initial built binary heap: " <<endl;


    cout<< "The sorted heap in descending order: " <<endl;

    cout<< "The updated heap after finishing the described 3 operations: " <<endl;

    cout<< "The sorted heap in descendingorder after finishing the described 3 operations: " <<endl;  

    



    return 0;
}