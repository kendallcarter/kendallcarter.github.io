#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include "Matrix.h"

using namespace std;

//Constructors 

Matrix::Matrix(){
    int size = std::distance(std::begin(this->myArray), std::end(this->myArray));

    for(int i=0;i<size;i++)
        for(int j=0;j<size; j++)
	      this->myArray[i][j]=rand()%100;
}

Matrix::Matrix(int a[3][3]){
    int size = std::distance(std::begin(myArray), std::end(myArray));

    for(int i=0;i<size;i++)
        for(int j=0;j<size; j++)
	      myArray[i][j]=rand()%100;
}

/**
 * toString()
 */
string Matrix::toString() const
{
    string show;

     for (size_t i = 0; i < 3; i++)
    {
        std::cout<<"{"<<myArray[i][0]<< "  ";
        for (size_t j = 0; j < 3; j++)
        {
            std::cout<<myArray[i][j]<< "  "<< "}";
        }
        std::cout<< "  "<<std::endl;
    }
    return show;
}


/**
 * Override "+" operator
 */
Matrix *Matrix::operator+(const Matrix &c) const
{
    int newOne[3][3];
    for (size_t i = 0; i < 3; i++){
        for (size_t j = 0; j < 3; j++){
            newOne[i][j]=myArray[i][j]+ c.myArray[i][j];
        }
    }
    
    return new Matrix(newOne);
        
}

/**
 * Override "-" operator
 */

Matrix *Matrix::operator-(const Matrix &c) const
{
    int newOne[3][3];
    for (size_t i = 0; i < 3; i++){
        for (size_t j = 0; j < 3; j++){
            newOne[i][j]=myArray[i][j] - c.myArray[i][j];
        }
    }
    
    return new Matrix(newOne);
}

/**
 * Override "*" operator
 */
Matrix *Matrix::operator*(const Matrix &c) const
{
    int newOne[3][3];
    int sum;
    for (size_t i = 0; i < 3; i++){
        for (size_t j = 0; j < 3; j++){
            for (size_t k = 0; k < 3; k++)
            {
                sum= sum + myArray[i][k] + c.myArray[k][j];
            }
            newOne[i][j]=sum;
            sum=0;
            
        }
    }
    
    return new Matrix(newOne);
}

/**
 * Override "==" operator
 */
bool Matrix::operator==(const Matrix &c) const
{
    return this->myArray == c.myArray;
}
