#include "BinaryHeap.h"
#include "dsexceptions.h"
using namespace std;

template <typename Comparable>
BinaryHeap<Comparable>::BinaryHeap(int capacity){
    array[capacity + 1];
    buildHeap();
}

//Retruns if the size is zero, 
template <typename Comparable>
bool BinaryHeap<Comparable>::isEmpty() const
{
    return currentSize == 0;
}

//Makes the Array Empty 
template <typename Comparable>
void BinaryHeap<Comparable>::makeEmpty()
{
    currentSize = 0;
}

// Find the student with the largest id number in the binary heap.
// Return the student information, or throw Underflow if empty.
template <typename Comparable>
const Student<string> &BinaryHeap<Comparable>::findMax() const
{
    if (isEmpty())
        throw UnderflowException{};
    return array[currentSize-1];
}


// Insert item x, allowing duplicates.
template <typename Comparable>
void BinaryHeap<Comparable>::insert(Student<string> &stu)
{
    if (currentSize == array.size() - 1)
        array.resize(array.size() * 2);

    // Percolate up
    int hole = ++currentSize;
    for (; hole > 1 && stu.getId() < array[hole / 2]; hole /= 2)
        array[hole] = std::move(array[hole / 2]);
    array[hole] = std::move(stu);
}

// Remove the student with the largest id number.
// Throws UnderflowException if empty.
template <typename Comparable>
void BinaryHeap<Comparable>::deleteMax()
{
    if (isEmpty())
        throw UnderflowException{};

    array[1] = std::move(array[currentSize--]);
    percolateDown(currentSize-1);
}

// Remove the student with the largest id and place the student information in stuWithMaxId.
// Throws Underflow if empty.
template <typename Comparable>
void BinaryHeap<Comparable>::deleteMax(Student<string> &stuWithMaxId)
{
    if (isEmpty())
        throw UnderflowException{};

    stuWithMaxId = std::move(array[currentSize]);
    array[1] = std::move(array[currentSize--]);
    percolateDown(1);
}

// Update the current student of binary heap at index position p by a new student 
// information stored in newValue.
// Throws ArrayIndexOutOfBoundsException if p is an invalid heap index.
template <typename Comparable>
void BinaryHeap<Comparable>::updateStudent(int p, Student<string> newStudent){
    if (p>currentSize){
    throw ArrayIndexOutOfBoundsException{};
    }
    array[p]=newStudent;
}

// Delete the current student from binary heap at position p,
// and place it in stu.
// Throws UnderflowException if empty.
// Throws ArrayIndexOutOfBoundsException if p is an invalid heap index.
template <typename Comparable>
void BinaryHeap<Comparable>::deleteStudent(int p, Student<string> &stu){
    if (isEmpty())
        throw UnderflowException{};

    array[p] = std::move(array[currentSize--]);
    percolateDown(p);
}

// Establish heap order property from an arbitrary
// arrangement of items. Runs in linear time.
template <typename Comparable>
void BinaryHeap<Comparable>::buildHeap()
{
    for (int i = currentSize / 2; i > 0; --i)
        percolateDown(i);
}

// Internal method to percolate down in the heap.
// hole is the index at which the percolate begins.
template <typename Comparable>
void BinaryHeap<Comparable>::percolateDown(int hole)
{
    int child;
    Comparable tmp = std::move(array[hole]);

    for (; hole * 2 <= currentSize; hole = child)
    { 
        child = hole * 2;
    }
    array[hole] = std::move(tmp);
}

template <typename Comparable>
void BinaryHeap<Comparable>::printHeap(){
    for (int i = 0; i < currentSize; i++) {
            cout<<array[i]<<endl;
        }
        cout<<endl;
}

template <typename Comparable>
vector<Student<string>> BinaryHeap<Comparable>::heapsort(){
    for (int i = (array.size() / 2) - 1; i >= 0; i--) {
        cout << "i = " << i << " ";
        cout << "h[i] = " << array[i] << " ";
        cout << "children = " << array[2 * i + 1];
        if (2 * i + 2 < array.size())
            cout << ", " << array[2 * i + 2];
        cout << endl;

        percolateDown(i);
    }
    
    for (int j = array.size() - 1; j > 0; j--)
    {
        swap(array[0], array[j]); 
        percolateDown(j);
        
    }
}

template <typename Comparable>
int BinaryHeap<Comparable>::getCurrentSize(){
return currentSize;
}