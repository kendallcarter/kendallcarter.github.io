//Kendall Carter IT 279
using namespace std;
#include <iostream>
#include <string>
#include <sstream>
#include <random>
#include <stack>

//Removes the second node
stack<int> removeSecond(stack<int> *stk) {
int val = stk->top();
stk -> pop(); 
int val2 = stk-> top();
cout << "The data in the removed node is: " << val2 << endl;
stk -> pop(); 
stk -> push(val);

return *stk;
}

int main(){
    
    //Generates the 8 random numbers from 0 to 100
    stack<int> myStack;
    default_random_engine defEngine;
    uniform_int_distribution<int> intDistro(0,100);

    //Prints and adds to stack
    cout << "The random numbers that are pushed into the stack one by one: ";
    for (int i = 1; i <= 8; i++) {
    int element = intDistro(defEngine);
    cout << element << " ";
    myStack.push(element);
    }
    cout << endl;

    //Creates another temp stack
    std::stack<int> *tempStack;
    tempStack = &myStack;

    //Removes second element 
    myStack = removeSecond(tempStack);

    //Holds the results, will add together within popping for loop
    int result = 0;

    //Add the resutlts together 
    cout << "The updated stack is: ";
    while(!myStack.empty()){
        cout << myStack.top()<< " ";
        result= result + myStack.top();
        myStack.pop();
    }
    cout << endl;

    std::cout << "The sum of these values is: " << result << endl; 
      
    return 0;
};