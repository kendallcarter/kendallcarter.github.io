#include "AVL.h"
#include <algorithm>
#include <iostream>
using namespace std;

template <typename Comparable>
AvlTree<Comparable>::AvlTree() 
: root{nullptr}
{

}

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
 * Test if the tree is logically empty.
 * Return true if empty, false otherwise.
 */
template <typename Comparable>
bool AvlTree<Comparable>::isEmpty() const
{
    return root == nullptr;
}

/**
 * Print the tree contents in sorted order.
 */
template <typename Comparable>
void AvlTree<Comparable>::printTree() const
{
    if (isEmpty())
        cout << "Empty tree" << endl;
    else
        printTree(root);
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
 * Internal method to make subtree empty.
 */
template <typename Comparable>
void AvlTree<Comparable>::makeEmpty(AvlTree<Comparable>::AvlNode *&t)
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
 * Internal method to print a subtree rooted at t in sorted order.
 */
template <typename Comparable>
void AvlTree<Comparable>::printTree(AvlNode *t) const
{
    if (t != nullptr)
    {
        cout << t->element << "  ";
        printTree(t->left);
        printTree(t->right);
    }
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

// Get Balance factor of node N
template <typename Comparable>
int AvlTree<Comparable>::getBalance(AvlNode *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

/**
 * Find the largest item in the tree.
 * Throw UnderflowException if empty.
 */
template <typename Comparable>
typename AvlTree<Comparable>::AvlNode *AvlTree<Comparable>::findMax() const
{
    //Add you code here
    if (isEmpty())
    {
        cout << "\nCannot find the node" << endl;
        throw UnderflowException{};
    }
    return findMax(root);

}

/**
 * Internal method to find the largest item in a subtree t.
 * Return node containing the largest item.
 */
template <typename Comparable>
typename AvlTree<Comparable>::AvlNode *AvlTree<Comparable>::findMax(AvlNode *t) const
{
    //Add your code here
    if( t != nullptr )
        while( t->right != nullptr )
            t = t->right;
    return t;
}

/**
 * Find the smallest item in the tree.
 * Throw UnderflowException if empty.
 */
template <typename Comparable>
typename AvlTree<Comparable>::AvlNode *AvlTree<Comparable>::findMin() const
{
    if (isEmpty())
    {
        cout << "\nCannot find the node" << endl;
        throw UnderflowException{};
    }
    return findMin(root);
}
/**
 * Internal method to find the smallest item in a subtree t.
 * Return node containing the smallest item.
 */
template <typename Comparable>
typename AvlTree<Comparable>::AvlNode *AvlTree<Comparable>::findMin(AvlNode *t) const
{
    if (t == nullptr)
    {
        return nullptr;
    }
    if (t->left == nullptr)
        return t;

    return findMin(t->left);
}

// a)	(10 pts) Complete findMax and findMin methods (both public and private). 
// b)	(15 pts) Complete rightRotate method
// c)	(15 pts) Complete leftRotate method
// d)	(40 pts) Complete balance method, must have the function of outputting each of the four cases to handle unbalance and the node that is used as root to rotate. For example:

// left left case: rightRotate (50)
// left left case: rightRotate (20)
// left right case: leftRotate (40), rightRotate(50)

// right left case: rightRotate (50), leftRotate(45)

// e)	(10 pts) Complete insert method 
// f)	(10 pts) Complete remove method

/**
 * Internal method to print a subtree rooted at t
 */
template <typename Comparable>
void AvlTree<Comparable>::rightRotate(AvlNode *&y){
   if (y != nullptr){
        AvlNode* old = y->left;
        y->left = old->right;
        old ->right = y;
        y->height = max(height(y->left), height(y->right)) +1;
        old->height = max(height(old->left), height(old->right)) +1;
        y = old;

    }
}

/**
 * Internal method to print a subtree rooted at t 
 */
template <typename Comparable>
void AvlTree<Comparable>::leftRotate(AvlNode * & x){
    if (x != nullptr){
        AvlNode *old = x->right;
        x->right = old->left;
        old ->left = x;
        x->height = max(height(x->right), height(x->left)) +1;
        old->height = max(height(old->right), height(old->left)) +1;
        x = old;

    }
}


/**
 * Internal method to insert into a subtree.
 * x is the item to insert.
 * t is the node that roots the subtree.
 * Set the new root of the subtree.
 */

template <typename Comparable>
void AvlTree<Comparable>::insert(const Comparable &x)
{
    insert(x, root);
}

template <typename Comparable>
void AvlTree<Comparable>::insert(const Comparable &x, AvlNode *&t)
{
    if (t == nullptr)
        t = new AvlNode{x, nullptr, nullptr};
    else if (x < t->element)
        insert(x, t->left);
    else if (t->element < x)
        insert(x, t->right);
   
   balance(t);
   //right or left rotate 

    
}

/**
 * Remove x from the tree. Nothing is done if x is not found.
 */
template <typename Comparable>
void AvlTree<Comparable>::remove(const Comparable &x)
{

    //Add your code here
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

template <typename Comparable>
void AvlTree<Comparable>::balance(AvlNode *&t) {
    if( t == nullptr )
        return;
        
    if( height( t->left ) - height( t->right ) > 1 )
        if( height( t->left->left ) >= height( t->left->right ) ){
            cout<<"left left case: rightRotate (" << t->element <<") " <<endl;
            rightRotate( t );
        }
        else{
            cout<<"left right case: leftRotate (" << t->left->element <<"), rightRotate (" << t->element << ")"<<endl;
            leftRotate(t->left);
            rightRotate(t);
        }
    else{
        if( height( t->right ) - height( t->left ) > 1 ) {
            if( height( t->right->right ) >= height( t->right->left ) ){
                cout<<"right right case: leftRotate (" << t->element <<") " <<endl;
                leftRotate( t ); 
            }
            else{
                cout<<"right left case: rightRotate (" << t->right->element <<"), leftRotate (" << t->element << ")" <<endl;
                rightRotate(t->right);
                leftRotate(t);
            }
        }
    }

    t->height = max( height( t->left ), height( t->right ) ) + 1;
}
