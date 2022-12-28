#include "Student.h"

template <typename Comparable>
Student<Comparable>::Student()
{
    // Add your code
    
}

template <typename Comparable>
Comparable Student<Comparable>::getFirstName()
{
    // Add your code: you can delete or modify the following code line
    return fname;
}

template <typename Comparable>
Comparable Student<Comparable>::getLastName()
{
    
    return lname;
}

template <typename Comparable>
Comparable Student<Comparable>::getDepartment()
{
    
    return department;
}

template <typename Comparable>
Comparable Student<Comparable>::getGPA()
{
    
    return gpa;
}

template <typename Comparable>
int Student<Comparable>::getId()
{
    
    return id;
}

template <typename Comparable>
int Student<Comparable>::getBucketId()
{
    
    return bucketId;
}


template <typename Comparable>
void Student<Comparable>::setFirstName(Comparable name)
{
    
    fname= name;
}

template <typename Comparable>
void Student<Comparable>::setLastName(Comparable name)
{
    
    lname= name;

}
template <typename Comparable>
void Student<Comparable>::setDepartment(Comparable dept)
{
    
    department=dept;
}

template <typename Comparable>
void Student<Comparable>::setGPA(Comparable gpa2)
{
    
    gpa=gpa2;
}
template <typename Comparable>
void Student<Comparable>::setId(int id)
{
    id=id;
}


template <typename Comparable>
void Student<Comparable>::setBucketId(int id)
{
    
    bucketId=id;
}