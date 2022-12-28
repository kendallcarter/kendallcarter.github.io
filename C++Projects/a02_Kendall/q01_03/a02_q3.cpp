#include <iostream>
#include <queue>
#include <random>


using namespace std;

queue<int> *myQue = new queue<int>();

//Removes the second element in the queue
int removeSecond(queue<int> *que){
    int val; 
    val = que->front(); 

    que->pop();

    int removed = 0;
    removed+=que->front();

    que->pop();

    que->push(val);
    
    myQue->swap(*que);
    return removed;
}
int main()
{
    //queue<int> *que = new queue<int>();

    //Generates 10 random numbers
    default_random_engine defEngine;
    uniform_int_distribution<int> intDistro(1,50);

    for (int i = 1; i <= 10; i++) {
    myQue->push(intDistro(defEngine));
    }


    queue<int> copyQueue = *myQue;
    
    cout << "\n--------------------------------------------" << endl;
    cout << "IT 279 Assignment 02: Q03 Kendall Carter" << endl;
    cout << "The random numbers being pushed into the queue: ";
    while(!copyQueue.empty()){
        cout<< copyQueue.front()<< " ";
        copyQueue.pop();
    }

    //Removes the second element from the stack
    cout << "\nThe removed element: " << removeSecond(myQue);
    copyQueue = *myQue;

    //Prints the updated stack
    cout << "\nThe updated stack: ";
    while(!copyQueue.empty()){
        cout<< copyQueue.front()<< " ";
        copyQueue.pop();
    }

    copyQueue = *myQue;
    int addSum;

    //Adds together the even elements of the list
    while(!copyQueue.empty()){
        if(copyQueue.front()%2 == 0){
            addSum+= copyQueue.front();
        }

        copyQueue.pop();
    }

    cout << "\nThe sum of the even elements: " << addSum;
    
    cout << "\n--------------------------------------------" << endl;
    return 0;
}