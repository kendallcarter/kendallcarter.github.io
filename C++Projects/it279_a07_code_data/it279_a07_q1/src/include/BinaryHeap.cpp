#include "BinaryHeap.h"
#include "dsexceptions.h"
using namespace std;

template <typename Comparable>
BinaryHeap<Comparable>::BinaryHeap(int capacity){
    array[capacity + 1];
    buildHeap();
}

template <typename Comparable>
bool BinaryHeap<Comparable>::isEmpty() const
{
    return currentSize == 0;
}

// Find the smallest item in the priority queue.
// Return the smallest item, or throw Underflow if empty.
template <typename Comparable>
const Comparable &BinaryHeap<Comparable>::findMax() const
{
    if (isEmpty())
        throw UnderflowException{};
    return array[currentSize-1];
}

// // Insert item x, allowing duplicates.
template <typename Comparable>
void BinaryHeap<Comparable>::insert(const Comparable &x)
{
    if (currentSize == array.size() - 1)
        array.resize(array.size() * 2);

    
    int hole = ++currentSize;
    for (; hole > 1 && x < array[hole / 2]; hole /= 2)
        array[hole] = std::move(array[hole / 2]);
    array[hole] = std::move(x);
}


// Remove the minimum item.
// Throws UnderflowException if empty.
template <typename Comparable>
void BinaryHeap<Comparable>::deleteMax()
{
    if (isEmpty())
        throw UnderflowException{};

    array[1] = std::move(array[currentSize--]);
    percolateDown(currentSize-1);
}

// Remove the max item and place it in maxItem.
// Throws Underflow if empty.
template <typename Comparable>
void BinaryHeap<Comparable>::deleteMax(Comparable &maxItem){
    if (isEmpty())
        throw UnderflowException{};

    maxItem = std::move(array[currentSize]);
    array[1] = std::move(array[currentSize--]);
    percolateDown(currentSize-1);
}

// Update the current value of binary heap at index position p with newValue.
// Throws ArrayIndexOutOfBoundsException if p is an invalid heap index.
template <typename Comparable>
void BinaryHeap<Comparable>::updateVal(int p, Comparable newValue){
if (p>currentSize)
{
   throw ArrayIndexOutOfBoundsException{};
}
array[p]=newValue;

}

//Deletes a specific value in the array
template <typename Comparable>
void BinaryHeap<Comparable>::deleteVal(int p, Comparable &val){
    if (isEmpty())
        throw UnderflowException{};

    array[p] = std::move(array[currentSize--]);
    percolateDown(p);
}

//Empties Array
template <typename Comparable>
void BinaryHeap<Comparable>::makeEmpty()
{
    currentSize = 0;
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
        // child: left child
        // child + 1: right child
        if (child != currentSize && array[child + 1] < array[child])
            ++child;

        if (array[child] < tmp)
            array[hole] = std::move(array[child]);
        else
            break;
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
// template <typename Comparable>
// vector<Comparable> BinaryHeap<Comparable>::heapsort(){
//     if (isEmpty())
//         throw UnderflowException{};
//     heapsort();
// }

template <typename Comparable>
vector<Comparable> BinaryHeap<Comparable>::heapsort(){
    cout << endl << "Building heap." << endl;
    for (int i = (array.size() / 2) - 1; i >= 0; i--) 
    {
        
        cout << "i = " << i << " ";
        cout << "h[i] = " << array[i] << " ";
        cout << "children = " << array[2 * i + 1];
        if (2 * i + 2 < array.size())
            cout << ", " << array[2 * i + 2];
        cout << endl;

        percolateDown(i);
    }
    

    cout << "Using deleteMax to sort heap." << endl;
    for (int j = array.size() - 1; j > 0; j--)
    {
        swap(array[0], array[j]); 
        
        percolateDown(j);
        
    }
}
