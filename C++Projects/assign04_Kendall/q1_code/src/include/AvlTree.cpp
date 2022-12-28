#include "AvlTree.h"
#include "dsexceptions.h"
#include <algorithm>
#include <iostream>
#include <ctime>
#include <random>
using namespace std;

// AvlTree class
//
// CONSTRUCTION: zero parameter
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x (unimplemented)
// bool contains( x )     --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in pre-order
// ******************ERRORS********************************
// Throws UnderflowException as warranted
template <typename Comparable>
AvlTree<Comparable>::AvlTree() : root{nullptr} {}

template <typename Comparable>
AvlTree<Comparable>::AvlTree(const AvlTree &rhs) : root{nullptr}
{
    root = clone(rhs.root);
}
template <typename Comparable>
AvlTree<Comparable>::AvlTree(AvlTree &&rhs) : root{rhs.root}
{
    rhs.root = nullptr;
}
template <typename Comparable>
AvlTree<Comparable>::~AvlTree()
{
    makeEmpty();
}

/**
 * Find the smallest item in the tree.
 * Throw UnderflowException if empty.
 */
template <typename Comparable>
const Comparable &AvlTree<Comparable>::findMin() const
{
    if (isEmpty())
        throw UnderflowException{};
    return findMin(root)->element;
}

/**
 * Find the largest item in the tree.
 * Throw UnderflowException if empty.
 */
template <typename Comparable>
const Comparable &AvlTree<Comparable>::findMax() const
{
    if (isEmpty())
        throw UnderflowException{};
    return findMax(root)->element;
}
/**
 * Test if the tree is logically empty.
 * Return true if empty, false otherwise.
 */
template <typename Comparable>
bool AvlTree<Comparable>::isEmpty() const
{
    return root == nullptr;
}
/**
 * Make the tree logically empty.
 */
template <typename Comparable>
void AvlTree<Comparable>::makeEmpty()
{
    makeEmpty(root);
}
/**
 * Internal method to find the smallest item in a subtree t.
 * Return node containing the smallest item.
 */
template <typename Comparable>
typename AvlTree<Comparable>::AvlNode *AvlTree<Comparable>::findMin(AvlNode *t) const
{
    if (t == nullptr)
        return nullptr;
    if (t->left == nullptr)
        return t;
    return findMin(t->left);
}

/**
 * Internal method to find the largest item in a subtree t.
 * Return node containing the largest item.
 */
template <typename Comparable>
typename AvlTree<Comparable>::AvlNode *AvlTree<Comparable>::findMax(AvlNode *t) const
{
    if (t != nullptr)
        while (t->right != nullptr)
            t = t->right;
    return t;
}
/**
 * Internal method to make subtree empty.
 */
template <typename Comparable>
void AvlTree<Comparable>::makeEmpty(AvlNode *&t)
{
    if (t != nullptr)
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = nullptr;
}
/**
 * Internal method to clone subtree.
 */
template <typename Comparable>
typename AvlTree<Comparable>::AvlNode *AvlTree<Comparable>::clone(AvlNode *t) const
{
    if (t == nullptr)
        return nullptr;
    else
        return new AvlNode{t->element, clone(t->left), clone(t->right), t->height};
}
// Avl manipulations
/**
 * Return the height of node t or -1 if nullptr.
 */
template <typename Comparable>
int AvlTree<Comparable>::height(AvlNode *t) const
{
    return t == nullptr ? -1 : t->height;
}
template <typename Comparable>
int AvlTree<Comparable>::max(int lhs, int rhs) const
{
    return lhs > rhs ? lhs : rhs;
}
/**
 * Returns true if x is found in the tree.
 */
template <typename Comparable>
bool AvlTree<Comparable>::contains(const Comparable &x) const
{
    return contains(x, root);
}
/**
 * Internal method to test if an item is in a subtree.
 * x is item to search for.
 * t is the node that roots the tree.
 */
template <typename Comparable>
bool AvlTree<Comparable>::contains(const Comparable &x, AvlNode *t) const
{
    if (t == nullptr)
        return false;
    else if (x < t->element)
        return contains(x, t->left);
    else if (t->element < x)
        return contains(x, t->right);
    else
        return true; // Match
}

/////////////////////////////////////////////////////////////////////////////////////////////
// Methods for assignment 03: Q1
/**
 * Print the tree contents in pre-order.
 */
template <typename Comparable>
void AvlTree<Comparable>::printTree() const
{
    // Add your code here
    if (isEmpty())
        cout << "Empty tree" << endl;
    else
        printTree(root);
}
/**
 * Internal method to print a subtree rooted at t in pre-order.
 */
template <typename Comparable>
void AvlTree<Comparable>::printTree(AvlNode *t) const
{
    // Add your code here
    if (t != nullptr)
    {
        cout << t->element << "  ";
        printTree(t->left);
        printTree(t->right);
    }
}
/**
 * Insert x into the tree; duplicates are ignored.
 */
template <typename Comparable>
void AvlTree<Comparable>::insert(const Comparable &x)
{
    // Add your code here
    insert(x, root);
}
/**
 * Internal method to insert into a subtree.
 * x is the item to insert.
 * t is the node that roots the subtree.
 * Set the new root of the subtree.
 */
template <typename Comparable>
void AvlTree<Comparable>::insert(const Comparable &x, AvlNode *&t)
{
    // Add your code here
    if (t == nullptr)
        t = new AvlNode{x, nullptr, nullptr};
    else if (x < t->element)
        insert(x, t->left);
    else if (t->element < x)
        insert(x, t->right);
   
   balance(t);
}

/**
 * Remove x from the tree. Nothing is done if x is not found.
 */
template <typename Comparable>
void AvlTree<Comparable>::remove(const Comparable &x)
{
    // Add your code here
    if (isEmpty())
    {
        cout << "\nCannot find the node" << endl;
        throw UnderflowException{};
    }
    return remove(x,root);
}
/**
 * Internal method to remove from a subtree.
 * x is the item to remove.
 * t is the node that roots the subtree.
 * Set the new root of the subtree.
 */
template <typename Comparable>
void AvlTree<Comparable>::remove(const Comparable &x, AvlNode *&t)
{
    // Add your code here
    if(t==nullptr){
    
        return;
    }
    if(x < t->element)
        remove(x,t->left);
    else if (t->element < x)
        remove(x, t->right);
    else if(t->left != nullptr && t->right != nullptr){
        t->element = findMin(t->right)->element;
        remove(t->element, t->right);

    } else{
        AvlNode *old = t;
        t =(t->left!=nullptr) ? t->left : t->right;
        delete old;
    }

    
    balance(t);
}

/**
 * Rotate binary tree node with left child.
 * For AVL trees, this is a single rotation for case 1.
 * Update heights, then set new root.
 */
template <typename Comparable>
void AvlTree<Comparable>::rotateWithLeftChild(AvlNode *&k2)
{
    // Add your code here
    AvlNode *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
    k1->height = max( height( k1->left ), k2->height ) + 1;
    k2=k1;

    //right rotate
}
/**
 * Rotate binary tree node with right child.
 * For AVL trees, this is a single rotation for case 4.
 * Update heights, then set new root.
 */
template <typename Comparable>
void AvlTree<Comparable>::rotateWithRightChild(AvlNode *&k1)
{
    // Add your code here
    AvlNode *k2 = k1->right;
    k1->right = k2->left;
    k2->left= k1;
    k1->height = max( height( k1->right ), height( k1->left ) ) + 1;
    k2->height = max( height( k2->right ), k2->height ) + 1;
    k1=k2;

}
/**
 * Double rotate binary tree node: first left child.
 * with its right child; then node k3 with new left child.
 * For AVL trees, this is a double rotation for case 2.
 * Update heights, then set new root.
 */
template <typename Comparable>
void AvlTree<Comparable>::doubleWithLeftChild(AvlNode *&k3)
{
    // Add your code here
    rotateWithRightChild( k3->left );
    rotateWithLeftChild( k3 );

}
/**
 * Double rotate binary tree node: first right child.
 * with its left child; then node k1 with new right child.
 * For AVL trees, this is a double rotation for case 3.
 * Update heights, then set new root.
 */
template <typename Comparable>
void AvlTree<Comparable>::doubleWithRightChild(AvlNode *&k1)
{
    // Add your code here

    rotateWithLeftChild( k1->right );
    rotateWithRightChild( k1 );

}
// Assume t is balanced or within one of being balanced
template <typename Comparable>
void AvlTree<Comparable>::balance(AvlNode *&t)
{
    // Add your code here
    if( t == nullptr )
        return;
        
    if( height( t->left ) - height( t->right ) > 1 )
        if( height( t->left->left ) >= height( t->left->right ) ){
            //cout<<"left left case: rightRotate (" << t->element <<") " <<endl;
            rotateWithLeftChild( t );
        }
        else{
            //cout<<"left right case: leftRotate (" << t->left->element <<"), rightRotate (" << t->element << ")"<<endl;
            rotateWithRightChild(t->left);
            rotateWithLeftChild(t);
        }
    else{
        if( height( t->right ) - height( t->left ) > 1 ) {
            if( height( t->right->right ) >= height( t->right->left ) ){
                //cout<<"right right case: leftRotate (" << t->element <<") " <<endl;
                rotateWithRightChild( t ); 
            }
            else{
                //cout<<"right left case: rightRotate (" << t->right->element <<"), leftRotate (" << t->element << ")" <<endl;
                rotateWithLeftChild(t->right);
                rotateWithRightChild(t);
            }
        }
    }

    t->height = max( height( t->left ), height( t->right ) ) + 1;
}

/////////////////////////////////////////////////////////////////////////////////////////////
// Methods for assignment 03: Q2
// Write the functions to perform the double rotation without the inefficiency of doing
// two single rotations: you cannot use rotateWithLeftChild and rotateWithRightChild
// in the implementation
template <typename Comparable>
typename AvlTree<Comparable>::AvlNode *AvlTree<Comparable>::doubleRotateWithLeftChild(AvlNode *k3)
{

    AvlNode *k2 = k3->left->right;
    k3->left->right = k2->left;
    k2->left= k3->left;
    k3->left->height = max( height( k3->left->right ), height( k3->left->left ) ) + 1;
    k2->height = max( height( k2->right ), k2->height ) + 1;
    k3->left=k2;

    AvlNode *k1 = k3->left;
    k3->left = k1->right;
    k1->right = k3;
    k3->height = max( height( k3->left ), height( k3->right ) ) + 1;
    k1->height = max( height( k1->left ), k3->height ) + 1;
    k3=k1;

    return k3;
}
// Write the functions to perform the double rotation without the inefficiency of doing
// two single rotations: you cannot use rotateWithLeftChild and rotateWithRightChild
// in the implementation
template <typename Comparable>
typename AvlTree<Comparable>::AvlNode *AvlTree<Comparable>::doubleRotateWithRightChild(AvlNode *k3)
{
    

    AvlNode *k2 = k3->left->right;
    k3->left->right = k2->left;
    k2->left= k3->left;
    k3->left->height = max( height( k3->left->right ), height( k3->left->left ) ) + 1;
    k2->height = max( height( k2->right ), k2->height ) + 1;
    k3->left=k2;

    AvlNode *k1 = k3->left;
    k3->left = k1->right;
    k1->right = k3;
    k3->height = max( height( k3->left ), height( k3->right ) ) + 1;
    k1->height = max( height( k1->left ), k3->height ) + 1;
    k3=k1;

    return k3;
}

// Assume t is balanced or within one of being balanced
// You must use the developed doubleRotateWithLeftChild and doubleRotateWithRightChild for double rotation
// You can use rotateWithLeftChild and rotateWithRightChild for single rotation
template <typename Comparable>
void AvlTree<Comparable>::balanceImproved(AvlNode *&t)
{
    if( t == nullptr )
        return;
        
    if( height( t->left ) - height( t->right ) > 1 )
        if( height( t->left->left ) >= height( t->left->right ) ){
            //cout<<"left left case: rightRotate (" << t->element <<") " <<endl;
            rotateWithLeftChild(t); //rightRotate( t );
        }
        else{
            //cout<<"left right case: leftRotate (" << t->left->element <<"), rightRotate (" << t->element << ")"<<endl;
            doubleWithLeftChild(t);
        }
    else{
        if( height( t->right ) - height( t->left ) > 1 ) {
            if( height( t->right->right ) >= height( t->right->left ) ){
                //cout<<"right right case: leftRotate (" << t->element <<") " <<endl;
                rotateWithRightChild(t); 
            }
            else{
                //cout<<"right left case: rightRotate (" << t->right->element <<"), leftRotate (" << t->element << ")" <<endl;
                doubleWithRightChild(t);
            }
        }
    }

    t->height = max( height( t->left ), height( t->right ) ) + 1;

}

/**
 * Internal method to insert into a subtree.
 * x is the item to insert.
 * t is the node that roots the subtree.
 * Set the new root of the subtree.
 */

// You must use balanceImproved to balance the AVL tree
template <typename Comparable>
void AvlTree<Comparable>::insertImproved(const Comparable &x, AvlNode *&t)
{
    // Add your code here
    if (t == nullptr)
        t = new AvlNode{x, nullptr, nullptr};
    else if (x < t->element)
        insert(x, t->left);
    else if (t->element < x)
        insert(x, t->right);
   
   balanceImproved(t);
    
}
/**
 * Insert x into the tree; duplicates are ignored.
 */
// You must use insertImproved(const Comparable &x, AvlNode *&t) in this method
template <typename Comparable>
void AvlTree<Comparable>::insertImproved(const Comparable &x)
{

   insertImproved(x, root);
}

/**
 * Internal method to remove from a subtree.
 * x is the item to remove.
 * t is the node that roots the subtree.
 * Set the new root of the subtree.
 */
// You must use balanceImproved to balance the AVL tree
template <typename Comparable>
void AvlTree<Comparable>::removeImproved(const Comparable &x, AvlNode *&t)
{
    // Add your code here
    if(t==nullptr){
        return;
    }
    if(x < t->element)
        removeImproved(x,t->left);
    else if (t->element < x)
        removeImproved(x, t->right);
    else if(t->left != nullptr && t->right != nullptr){
        t->element = findMin(t->right)->element;
        removeImproved(t->element, t->right);

    } else{
        AvlNode *old = t;
        t =(t->left!=nullptr) ? t->left : t->right;
        delete old;
    }

    
    balanceImproved(t);
}
/**
 * Remove x from the tree. Nothing is done if x is not found.
 */
// You must use removeImproved(const Comparable &x, AvlNode *&t) in this method
template <typename Comparable>
void AvlTree<Comparable>::removeImproved(const Comparable &x)
{
    // Add your code here
    if (isEmpty())
    {
        cout << "\nCannot find the node" << endl;
        throw UnderflowException{};
    }
    return removeImproved(x,root);
}

/////////////////////////////////////////////////////////////////////////////////////////////
// Methods for assignment 03: Q3
// Create an Avl tree using the generated random number (integer) between lower and upper inclusive
// The number of random number generated is upper - lower
// For example if lower = 2, upper = 12, then the gernerated random numbers are in the range [2, 12],
// and 12 - 2 + 1 = 11 random numbers will be generated, which are used to build the AVL tree.
// Note: in the example, the built AVL must have 11 nodes!
// You can create any additional methods if necessary. The created methods should put headers in AvlTree.h,
// and the implementations in AvlTree.cpp, the same as all other methods  
//
// Hint: you can use srand(time(0)) and rand % num to create random number
template <typename Comparable>
void AvlTree<Comparable>::makeRandomTree(const Comparable lower, const Comparable upper)
{
    // Add your code here
    default_random_engine defEngine;
    uniform_int_distribution<int> intDistro(lower,upper);
    
    int times = upper -lower +1;
    
    while (times !=0)
    {
        insert(rand() % upper + lower-1);
        times--;
    }
    
}

// You may add more methods here for question 3.
