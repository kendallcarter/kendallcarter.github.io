#include "Student.h"
#include "Student.cpp"
#include "DisjSet.h"
#include "DisjSet.cpp"

#include "DoubleHash.h"
#include "DoubleHash.cpp"
#include "Utilities.h"
#include <vector>
#include "MergeSort.h"
#include "QuickSort.h"
#include "ShellSort.h"

using namespace std;

void printStudent(int i, Student<string> student)
{
    string lineStr;
    if (i < 10)
        lineStr = " ----------------> ";
    else
        lineStr = " ---------------> ";

    cout << i << lineStr << to_string(student.getId()) << "   " << student.getFirstName()
            << " " << student.getLastName() << "   " << student.getDepartment() << "   "
            << student.getGPA() << endl;
}

// Test program
int main()
{
    string strline2 = "--------------------------------------------------------------------";
    cout << strline2 << endl;
    cout << "Assignment 08, Question 01 Kendall Carter:" << endl;
	
	// Add your code here

    Student<string> theStudent;
    
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
	


    return 0;
}