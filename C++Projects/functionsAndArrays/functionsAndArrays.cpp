//Kendall Carter 
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <iterator>

void functionTwo(double a[],int size);
void functionThree(double a[],int size);
void functionFour(double a[],int size);
void functionFive(double a[],int size);
double dArray[15];


void functionTwo(double a[],int size){
    for(int i= 0; i< (size) ; i++){
        std::cout <<a[i];
    }
    std::cout <<std::endl;
}
void functionThree(double a[],int size){
	for(int i=0;i<size;i++)
	      a[i]=rand()%20;
    for(int j=0;j<size; j++){
        std::cout <<a[j]<< " ";
    }
    std::cout <<std::endl;
}

void functionFour(double a[],int size){
	double total=0;
    double mean=0;
    for(int i= 0; i<size; i++){
        total+=a[i];
    }
    mean=total/size;
    std::cout << mean<<std::endl;
}

void functionFive(double a[],int size){
	double max=a[0];
    double min=a[0];
    for(int i= 0; i<size; i++){
        if(a[i]>max){
            max=a[i];
        }
        else
        {
            
        }

        if(a[i]<min){
            min=a[i];
        }
        else
        {
            
        }
    }
    std::cout << max <<" "<< min <<std::endl;
}

int main(){
    

    //Question 2
    functionTwo(dArray,15);

    //Question 3
    srand (time(NULL));
    functionThree(dArray,15);

    //Question 4
    functionFour(dArray,15);

    //Quetsion 5
    functionFive(dArray,15);
   
    return 0;
}