// CPP program to implement double hashing
#include "DoubleHash.h"
#include <iostream>
using namespace std;

// Hash table size
#define TABLE_SIZE 13

// Used in second hash function.
#define PRIME 7

template <typename Comparable>
class DoubleHash
{
    // Pointer to an array containing buckets
    Comparable *hashTable;
    int curr_size;
};

template <typename Comparable>
DoubleHash<Comparable>::DoubleHash(int size)
{
    hashTable = new int[TABLE_SIZE];
    curr_size = 0;

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i] = -1;
    }
}

// function to check if hash table is full
template <typename Comparable>
bool DoubleHash<Comparable>::isFull()
{
    // if hash size reaches maximum size
    return (curr_size == TABLE_SIZE);
}

// function to calculate first hash
template <typename Comparable>
int DoubleHash<Comparable>::hash1(Comparable key)
{
    return (key % TABLE_SIZE);
}

// function to calculate second hash
template <typename Comparable>
int DoubleHash<Comparable>::hash2(Comparable key)
{
    return (PRIME - (key % PRIME));
}

// function to insert key into hash table
template <typename Comparable>
void DoubleHash<Comparable>::insertHash(Student<string> &val)
{
    // if hash table is full
    if (isFull())
        return;

    // get index from first hash
    int index = hash1(key);

    // if collision occurs
    if (hashTable[index] != -1)
    {
        // get index2 from second hash
        int index2 = hash2(key);
        int i = 1;
        while (1)
        {
            // get newIndex
            int newIndex = (index + i * index2) % TABLE_SIZE;

            // if no collision occurs, store the key
            if (hashTable[newIndex] == -1)
            {
                hashTable[newIndex] = key;
                break;
            }
            i++;
        }
    }  
    else{
    hashTable[index] = key;
    curr_size++;
    }
}

// function to search key in hash table
template <typename Comparable>
template <typename HashedObj>
bool DoubleHash<Comparable>::search(HashedObj key, HashedObj &bucketId, Student<string> &val)
{
    int index1 = hash1(key);
    int index2 = hash2(key);
    int i = 0;

    while (hashTable[(index1 + i * index2) % TABLE_SIZE] != key)
    {
        if (hashTable[(index1 + i * index2) % TABLE_SIZE] == -1)
        {
            cout << key << " does not exist" << endl;
            return false;
        }
        i++;
    }
    return true;
}

// function to search key in hash table
template <typename Comparable>
template <typename HashedObj>
bool DoubleHash<Comparable>::search(HashedObj bucketId, Student<string> &val)
{
    int index1 = hash1(key);
    int index2 = hash2(key);
    int i = 0;

    while (hashTable[(index1 + i * index2) % TABLE_SIZE] != key)
    {
        if (hashTable[(index1 + i * index2) % TABLE_SIZE] == -1)
        {
            cout << key << " does not exist" << endl;
            return false;
        }
        i++;
    }
    cout << key << " found" << endl;
    return true;
}

// function to display the hash table
template <typename Comparable>
void DoubleHash<Comparable>::displayHash()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hashTable[i] != -1)
            cout << i << " --> " << hashTable[i] << endl;
        else
            cout << i << endl;
    }
}

// function to update the student information who id is key
// If update is successful, return ture, otherwise, return false
template <typename Comparable>
bool DoubleHash<Comparable>::update(Student<string> &val)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hashTable[i] != -1)
            cout << i << " --> " << hashTable[i] << endl;
        else
            cout << i << endl;
    }
}

// If the two students are in the same department, return true
// Otherwise, return false
template <typename Comparable>
bool DoubleHash<Comparable>::isSameDept(Student<string> std1, Student<string> std2)
{
   


}


// Get the student stored at bucketId in the hash table
template <typename Comparable>
template <typename HashedObj>
Student<string> DoubleHash<Comparable>::getStudent(HashedObj bucketId)
{
   


}

