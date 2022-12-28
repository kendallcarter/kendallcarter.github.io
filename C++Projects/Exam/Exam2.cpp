#include <stdlib.h>
#include <time.h>
using namespace std;
/**
 * Write a C++ program that declares two arrays of size 10
 * Use the provided method to randomly assign values to the array
 * Write a method - To display the elements of the array.
 * Write a method - To Swap the array elements. For example, if a = {1,2} & b = {3,4}, after swapping the elements, a = {3,4} and b={1,2} 
 */
const int SIZE = 10;
void fillArray(int a[], int b[]);
void displayElements();

void fillArray(int a[], int b[])
{
    for (int i = 0; i < SIZE; i++)
    {
        a[i] = b[i] = rand() % 50 + 1;
    }
}

void displayElements(int a[], int size){
    using namespace std;
    
    for(int j=0;j<size; j++){
        std::cout <<a[j]<< " ";
    }
    std::cout <<std::endl;
}

int main()
{
    srand(time(NULL));
}