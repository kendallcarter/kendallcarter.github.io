#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <iterator>
#include <fstream>
#include <sstream> 

#include "BinarySearchTree.cpp"
#include "SeparateChain.cpp"
#include "Student.cpp"

using namespace std;

int main()
{

    BinarySearchTree<int> t;

    Student<string> theStudent;

    HashTable<int> theTable(7);

    cout << "Assignment 06 Kendall Carter:" << endl;
    
    // Add your code here:
   
    //Opening the file 
    string line;
    
    ifstream myfile ("enroll_test.txt");

    // word variable to store word
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
    cout<<"The built splay tree: "<<endl;

    theTable.displayHash();

    //Opening the file 
    string line2;
    
    ifstream myfile2 ("search_test1.txt");

    // word variable to store word
    string word2;


    cout << "Students whose records were searched:" << endl;

    lineCount = 0;
    if(myfile2.is_open()){
        while (std::getline (myfile,line))
        {
            int key = 0;
            string studentInfo;
            stringstream iss(line);

            while (iss >> word){
                    
                if(lineCount==0){
                    key = atoi(word.c_str());
                    theTable.printNodeInfo(key);
                }

                lineCount++;

                if(lineCount==5) 
                    lineCount=0;
                
                
               
            }
               
        }  
    }

    
    
    //Opening the file 
    string line3;
    
    ifstream myfile3 ("search_test2.txt");

    // word variable to store word
    string word3;


    cout << "Students whose records were searched:" << endl;

    lineCount = 0;
    if(myfile3.is_open()){
        while (std::getline (myfile,line))
        {
            int key = 0;
            string studentInfo;
            stringstream iss(line);

            while (iss >> word){
                    
                if(lineCount==0){
                    key = atoi(word.c_str());
                    theTable.printNodeInfo(key);
                }

                lineCount++;

                if(lineCount==5) 
                    lineCount=0;
                
                
               
            }
               
        }  
    }

    //Opening the file 
    string line4;
    
    ifstream myfile4 ("update_test.txt");

    // word variable to store word
    string word4;


    cout << "Students whose records were searched:" << endl;

    lineCount = 0;
    if(myfile4.is_open()){
        while (std::getline (myfile,line))
        {
            int key = 0;
            string studentInfo;
            stringstream iss(line);

            while (iss >> word){
                    
                if(lineCount==0){
                    key = atoi(word.c_str());
                    if(theTable.printNodeInfo(key)){
                        //theTable.update(key,theStudent);
                    }
                        
                }

                lineCount++;

                if(lineCount==5) 
                    lineCount=0;
                
                
               
            }
               
        }  
    }

    cout << "Students whose records have been updated:" << endl;
    //Print


    //Opening the file 
    string line5;
    
    ifstream myfile5 ("update_test.txt");

    // word variable to store word
    string word5;

    cout << "Students whose records were deleted:" << endl;

    lineCount = 0;
    if(myfile5.is_open()){
        while (std::getline (myfile,line))
        {
            int key = 0;
            string studentInfo;
            stringstream iss(line);

            while (iss >> word){
                    
                if(lineCount==0){
                    key = atoi(word.c_str());
                    if(theTable.printNodeInfo(key)){
                        //theTable.remove(key);
                    }
                    else   
                        cout<< key << " was not found" << endl;  
                }

                lineCount++;

                if(lineCount==5) 
                    lineCount=0;
                
                
               
            }
               
        }  
    }

    cout << "Updated hash table (in each bucket the BST is displayed in inorder traversal):" << endl;
    theTable.displayHash();

    //Emptying the Tree
    theTable.makeEmpty();

    cout << "Updated hash table after empty operation:" << endl;
    theTable.displayHash();

    return 0;


}