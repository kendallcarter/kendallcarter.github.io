//Kendall Carter IT 279
using namespace std;
#include <iostream>
#include <string>
#include <sstream>
#include <random>
#include <stack>
#include <queue>

//Removes the second node
queue<int> removeSecond(queue<int> *que) {
int val = que->front();
que->pop();
int val2 = que->front();
cout << "The data in the removed node is: " << val2 << endl;
que->pop();
que->push(val);

return *que;
}

int main(){

    //Generates the 8 random numbers from 0 to 100
    stack<int> myStack;
    queue<int> myQueue;

    default_random_engine defEngine;
    uniform_int_distribution<int> intDistro(0,50);

    cout << "The random numbers pushed onto the queue one by one: " << endl;
    for (int i = 1; i <= 10; i++) {
    int element = intDistro(defEngine);
    cout << element << " ";
    myQueue.push(element);
    }
    cout << endl;

    //Removes the second node
    std::queue<int> *tempQueue;
    tempQueue = &myQueue;

    //Removes second element 
    myQueue = removeSecond(tempQueue);

    //Holds the results, the sum of the even values
    int result = 0;

    
    cout << "The updated queue: ";
    //Add the resutlts together 
    while(!myQueue.empty()){
        cout << myQueue.front()<< " ";
        if(myQueue.front() % 2 == 0)
            result= result + myQueue.front();
        myQueue.pop();
    }
    cout<< endl;

    cout << "The sum of the even elements is: ";
    std::cout << result << endl; 
      
    return 0;
};