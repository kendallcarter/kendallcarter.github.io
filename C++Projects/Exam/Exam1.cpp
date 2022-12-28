#include <iostream>
#include <math.h>
#include "pi.cpp"

using namespace std;
/**
 * Complete the following incomplete C++ program. 
 */
void coneVolume(double v, double h, double r);

int main()
{
    double volume = 0.0; // This variable should contain the volume of the cone.
    double radius;
    double height;
    // Write the logic to accept user input for Cone radius and height
    // std::cout<< "Enter the volume of the cone: " <<std::endl;
    // std::cin>> volume;
    std::cout<< "Enter the radius of the cone: "<<std::endl;
    std::cin>> radius;
    std::cout<< "Enter the height of the cone: "<<std::endl;
    std::cin>> height;
    //call the coneVolume method.
    coneVolume(volume, radius, height);
    // The volume variable must contain the volume of the cone.
    cout << "Volume of cone: " << volume << endl;
}
// DONT move this method
void coneVolume(double v, double h, double r)
{
    // Use the value of PI defined in pi.cpp
    v = PI * r * r * h / 3;
}
