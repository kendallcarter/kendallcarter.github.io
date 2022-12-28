//Kendall Carter IT 279
#include <iostream>
using namespace std;

template <typename Object>
struct Node
{
    Object data;
    Node *next;
    Node(const Object &d = Object(), Node *n = (Object)NULL) : data(d), next(n) {}
};

template <typename Object>
class singleList
{
public:
    singleList() { init(); }
    ~singleList() { eraseList(head); }
    singleList(const singleList &rhs)
    {
        eraseList(head);
        init();
        *this = rhs;
    }

    void init()
    {
        theSize = 0;
        head = new Node<Object>;
        head->next = (Object)NULL;
    }

    void eraseList(Node<Object> *h)
    {
        Node<Object> *ptr = h;
        Node<Object> *nextPtr;
        while (ptr != (Object)NULL)
        {
            nextPtr = ptr->next;
            delete ptr;
            ptr = nextPtr;
        }
    }

    int size()
    {
        Node<Object> *ptr = h;
        Node<Object> *nextPtr;
        int val;
        while (ptr != (Object)NULL)
        {
            nextPtr = ptr->next;
            val += ptr;
            ptr = nextPtr;
        }
        return val;
    }

    void print()
    {
        Node<Object> *nextPtr;
        while (ptr != (Object)NULL)
        {
            nextPtr = ptr->next;
            cout << ptr << endl;
            ptr = nextPtr;
        }
    }

    bool add(int i)
    {
        Node<Object> *ptr = h;
        Node<Object> *nextPtr;
        while (ptr != (Object)NULL)
        {
            nextPtr = ptr->next;
            delete ptr;
            ptr = nextPtr;
        }
        return true;
    }

    void remove(int i)
    {
        Node<Object> *ptr = h;
        Node<Object> *nextPtr;
        while (ptr != (Object)NULL)
        {
            nextPtr = ptr->next;
            delete ptr;
            ptr = nextPtr;
        }
    }

private:
    Node<Object> *head;
    int theSize;
};

 int main()
 {
    singleList<int> *lst = new singleList<int>();
     lst->add(10);
     lst->add(12);
     lst->add(15);
     lst->add(6);
     lst->add(3);
     lst->add(8);
     lst->add(3);
     lst->add(18);
     lst->add(5);
     lst->add(15);

     cout << "The original linked list: ";
     lst->print();

     lst->remove(6);
     lst->remove(15);
     cout << "The updated linked list: ";
     lst->print();
     cout << "The number of node in the list: " << lst->size() << endl;

     return 0;
 }