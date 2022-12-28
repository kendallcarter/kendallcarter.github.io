#include "Student.h"

template <typename Comparable>
Student<Comparable>::Student()
{
    // Add your code
    
}

template <typename Comparable>
string Student<Comparable>::getFirstName()
{
    // Add your code: you can delete or modify the following code line
    return fname;
}

template <typename Comparable>
string Student<Comparable>::getLastName()
{
    // Add your code: you can delete or modify the following code line
    return lname;
}

template <typename Comparable>
string Student<Comparable>::getDepartment()
{
    // Add your code: you can delete or modify the following code line
    return department;
}

template <typename Comparable>
string Student<Comparable>::getGPA()
{
    // Add your code: you can delete or modify the following code line
    return gpa;
}

template <typename Comparable>
void Student<Comparable>::setFirstName(Comparable name)
{
    // Add your code
    fname= name;
}

template <typename Comparable>
void Student<Comparable>::setLastName(Comparable name)
{
    // Add your code
    lname= name;

}
template <typename Comparable>
void Student<Comparable>::setDepartment(Comparable dept)
{
    // Add your code
    department=dept;
}

template <typename Comparable>
void Student<Comparable>::setGPA(Comparable gpa2)
{
    // Add your code
    gpa=gpa2;
}