#include "ArrayList.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
	ArrayList::ArrayList(){
        size=1;
        capacity=1;
        a=new int[capacity];

        for (int i=0; i<size; i++){
            a[i]=0;
        }
	}

	//Methods
    void ArrayList::push(int m){

        if(size>=capacity){
            
            int newCapacity=capacity*2;
            temp=new int[newCapacity];
            for (int i=0;i<newCapacity;i++){
                temp[i]=a[i];
            }
            a=temp;
            
            capacity=newCapacity;
            
        }
        temp[size]=m;
        size++;
        
        //delete temp;
    } 

    void ArrayList::erase(int m){
        int index=0;
        for(int i=0; i<size;i++){
            if(a[i]==m){
                index=i;
            }
        }
       
        
            //Check for 50% size 
            int halfCapacity=capacity/2;
            if(halfCapacity>size){
                temp=new int[halfCapacity];
                for (int i=0;i<halfCapacity;i++){
                temp[i]=a[i];
                }
                a=temp;
                capacity=halfCapacity;
            }

            size--;
            for (int i= index;i<size;i++){
                a[i]=a[i+1];
            }
            
        
        //delete temp;
    }

    void ArrayList::toString(){
        
        for (int i=1;i<size;i++){
             std::cout<<a[i]<< " ";
            }
            std::cout<<"\n";
    }

    int ArrayList::getCapacity(){
        return capacity;
    }