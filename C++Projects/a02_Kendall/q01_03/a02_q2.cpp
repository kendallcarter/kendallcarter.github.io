#include <iostream>
#include <stack>
#include <random>

using namespace std;
stack<int> *myStack = new stack<int>();

//Removes the second element in a stack
int removeSecond(stack<int> *stk){
    int val; 
    val = stk->top(); 

    stk->pop();

    int removed = 0;
    removed+=stk->top();

    stk->pop();

    stk->push(val);


    myStack->swap(*stk);
    return removed;
}


int main()
{

    
    c
    
    for (int i = 1; i <= 8; i++) {
    myStack->push(intDistro(defEngine));
    }

    stack<int> copyList = *myStack;

    cout << "\n--------------------------------------------" << endl;
    cout << "IT 279 Assignment 02: Q02 Kendall Carter" << endl;
    cout << "The random numbers being pushed onto the stack: ";
    for(int i =0; i<myStack->size(); i++){
        cout << copyList.top() << " ";
        copyList.pop();
    }
    
    //Removes the second element from the stack
    cout << "\nThe removed element: " << removeSecond(myStack);
    copyList = *myStack;

    //Prints the updated stack
    cout << "\nThe updated stack: " ;
    for(int i =0; i<myStack->size(); i++){
        cout << copyList.top() << " ";
        copyList.pop();
    }

    copyList = *myStack;
    int sum;
    
    //Adds together the odd elements of the list
    for(int i =0; i<myStack->size(); i++){
            sum+=copyList.top() - i;
    }

    cout << "\nThe sum of the stack elements is: " << sum;

    cout << "\n--------------------------------------------" << endl;

    return 0;
}