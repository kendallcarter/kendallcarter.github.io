#include "SingleList.h"
#include <algorithm>

template <typename Object>
SingleList<Object>::SingleList()
{
    init();
}

template <typename Object>
SingleList<Object>::~SingleList() { eraseList(head); }

template <typename Object>
SingleList<Object>::SingleList(const SingleList &rhs)
{
    eraseList(head);
    init();
    *this = rhs;
}

template <typename Object>
void SingleList<Object>::init()
{
    theSize = 0;
    head = new Node;
    head->next = (Object)NULL;
}

template <typename Object>
void SingleList<Object>::eraseList(Node *h)
{
    Node *ptr = h;
    Node *nextPtr;

    while (ptr != (Object)NULL)
    {
        nextPtr = ptr->next;
        delete ptr;
        ptr = nextPtr;
    }
}

template <typename Object>
void SingleList<Object>::print()
{
    Node *ptr = head->next;
    while (ptr != (Object)NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

// Methods/functions for assignment 02: q4
template <typename Object>
bool SingleList<Object>::contains(const Object &x)
{
    // Add your code here:
    Node *ptr = head->next;
    while (ptr != (Object)NULL)
    {
        if(ptr->data == x){
            return true;
        }
        ptr = ptr->next;
    }

    return false;
}

template <typename Object>
bool SingleList<Object>::add(Object x)
{
    // Add your code here:    
    Node *ptr = head->next;
    while (ptr != (Object)NULL)
    {
        if(ptr->data == x){
            return false;
        }
        ptr = ptr->next;
    }

    Node* theNode = new Node();
    theNode->data = x;
    theNode->next = (head);
    head = theNode;

    return true;
}

template <typename Object>
bool SingleList<Object>::remove(Object x)
{
    // Add your code here:
    
    Node *ptr = head;
    Node *nextPtr;
    
    while (ptr != (Object)NULL)
    {
        if(ptr->data == x){
            nextPtr = ptr->next;
            ptr->data = nextPtr->data;
            
            return true;
        }
        ptr = ptr->next;
    }

    return false;
}

template <typename Object>
int SingleList<Object>::size()
{
    int size;
    // Add your code here:
    Node *ptr = head->next;
    while (ptr != (Object)NULL)
    {
        size++;
        ptr = ptr->next;
    }
    return size-1; // You can change this line 
}
