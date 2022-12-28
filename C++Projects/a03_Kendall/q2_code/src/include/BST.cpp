#include "BST.h"
#include <algorithm>
#include <iostream>
#include <random>

using namespace std;

template <typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree() :root{nullptr}{
    
}

/**
 * Copy constructor
 */
template <typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree(const BinarySearchTree &rhs) : root{nullptr}
{
    root = clone(rhs.root);
}

/**
 * Move constructor
 */
template <typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree(BinarySearchTree &&rhs) : root{rhs.root}
{
    rhs.root = nullptr;
}

/**
 * Internal method to clone subtree.
 */
template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode *BinarySearchTree<Comparable>::clone(BinaryNode *t) const
{
    if (t == nullptr)
        return nullptr;
    else
        return new BinaryNode{t->element, clone(t->left), clone(t->right)};
};

/**
 * Internal method to insert into a subtree.
 * x is the item to insert.
 * t is the node that roots the subtree.
 * Set the new root of the subtree.
 */
template <typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable &x, BinaryNode *&t)
{
    if (t == nullptr)
        t = new BinaryNode{x, nullptr, nullptr};
    else if (x < t->element)
        insert(x, t->left);
    else if (t->element < x)
        insert(x, t->right);
    else
        ; // Duplicate; do nothing
}

/**
 * Remove x from the tree. Nothing is done if x is not found.
 */
template <typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable &x)
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
 * Find the smallest item in the tree.
 * Throw UnderflowException if empty.
 */
template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode *BinarySearchTree<Comparable>::findMin() const
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
typename BinarySearchTree<Comparable>::BinaryNode *BinarySearchTree<Comparable>::findMin(BinaryNode *t) const
{
    if (t == nullptr)
    {
        return nullptr;
    }
    if (t->left == nullptr)
        return t;

    return findMin(t->left);
}

/**
 * Find the largest item in the tree.
 * Throw UnderflowException if empty.
 */
template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode *BinarySearchTree<Comparable>::findMax() const
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
typename BinarySearchTree<Comparable>::BinaryNode *BinarySearchTree<Comparable>::findMax(BinaryNode *t) const
{
    //Add your code here
    if( t != nullptr )
        while( t->right != nullptr )
            t = t->right;
    return t;
}

/**
 * Insert x into the tree; duplicates are ignored.
 */
template <typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable &x)
{
    insert(x, root);
}
 
/**
 * Internal method to remove from a subtree.
 * x is the item to remove.
 * t is the node that roots the subtree.
 * Set the new root of the subtree.
 */
template <typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable &x, BinaryNode *&t)
{
    default_random_engine defEngine;
    uniform_int_distribution<int> intDistro(1,1000);
    int remainder = intDistro(defEngine)%2;

    if(t==nullptr){
    
        return;
    }

    if(x < t->element)
        remove(x,t->left);
    else if (t->element < x)
        remove(x, t->right);
    else if(t->left != nullptr && t->right != nullptr){
        if(remainder ==1){
        t->element = findMin(t->right)->element;
        cout<< "Remove the minimum node of the right subtree" <<endl;
        remove(t->element, t->right);
        }
        if(remainder ==0){
        t->element = findMax(t->left)->element;
        cout<< "Remove the maximum node of the left subtree" <<endl;
        remove(t->element, t->left);
        }
        

    } else{
        BinaryNode *old = t;
        t =(t->left!=nullptr) ? t->left : t->right;
        delete old;
    }
    return;
}

/**
 * Destructor for the tree
 */
template <typename Comparable>
BinarySearchTree<Comparable>::~BinarySearchTree()
{
    makeEmpty();
}
template <typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty()
{
    makeEmpty(root);
}
/**
 * Internal method to make subtree empty.
 */
template <typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty(BinaryNode *&t)
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
  * Print the tree contents in sorted order.
  */
template <typename Comparable>
void BinarySearchTree<Comparable>::printTree() const
{
    if (isEmpty())
        cout << "Empty tree" << endl;
    else
        printTree(root, cout);
    cout << endl;
};

/**
 * Internal method to print a subtree rooted at t in sorted order.
 */
template <typename Comparable>
void BinarySearchTree<Comparable>::printTree(BinarySearchTree<Comparable>::BinaryNode *t, ostream &out) const
{
    if (t != nullptr)
    {
        cout << t->element << " ";      
		printTree(t->left, out);

        printTree(t->right, out);
    }
}

/**
 * Test if the tree is logically empty.
 * Return true if empty, false otherwise.
 */
template <typename Comparable>
bool BinarySearchTree<Comparable>::isEmpty() const
{
    return root == nullptr;
}
/**
 * Find an item in the tree.
 * Throw UnderflowException if empty.
 */
template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode *BinarySearchTree<Comparable>::find(const Comparable &x) const
{
    //Add you code here
    if (isEmpty())
    {
        cout << "\nCannot find the node" << endl;
        throw UnderflowException{};
    }
    return find(x,root);

}

/**
 * Internal method to find an item in a tree, returns that item.
 */
template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode *BinarySearchTree<Comparable>::find(const Comparable &x, BinaryNode *t) const
{
    if (t == nullptr){
        cout << "\nCannot find the node" << endl;
        return nullptr;
    }
    else if (x < t->element)
        return find(x, t->left); 
    else if (t->element < x)
        return find(x, t->right);
    else
        return t; 
    
}

/**
 * Internal method to find the predecessor node
 * Return predecessor
 */
template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode *BinarySearchTree<Comparable>::findPredecessor(const Comparable &x) const
{
    //finde node, go to left of tree and then all the way right, right for find successor 

    BinaryNode* theNode=find(x);
     if (theNode != nullptr){
         if(theNode->left == nullptr){
        cout<< "node has no predecessor ";
        return find(x);
        }
        return findMax(theNode->left);
        }
    return findMax(theNode->left);
}

/**
 * Internal method to find the successor of a node
 * Return the successor node
 */
template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode *BinarySearchTree<Comparable>::findSuccessor(const Comparable &x) const
{
   
    BinaryNode* theNode = find(x);

    if (theNode == nullptr){
         cout << "Could not find: ";
         return find(x); 
         }
    if(theNode->right == nullptr){
        cout<< "node has no predecessor ";
        return find(x);
    }
    BinaryNode* newNode = find(x)->right;
    return findMin(newNode);;
}

/**
 * Wrapper function to find parent node
 */
template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode *BinarySearchTree<Comparable>::findParent(const Comparable &x) const
{
    //Add you code here
    if (isEmpty())
    {
        cout << "\nCannot find the node" << endl;
    }
    return findParent(x,root);

}

/**
 * Internal method to find the parent of a node 
 * Return the parent node
 */
template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode *BinarySearchTree<Comparable>::findParent(const Comparable &x, BinaryNode *t) const
{
    if(x==t->element){
        cout<<"Node is root";
        return root;
    }
    if (t->left->element == x || t->right->element == x){
        return t;
    }else if (t->element > x){
        return findParent(x,t->left);
    }else {
        return findParent(x,t->right);
    }
    
}

