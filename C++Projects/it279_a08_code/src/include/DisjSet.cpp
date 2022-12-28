#include <DisjSet.h>
#include <iostream>
using namespace std;

// Constructor to create and
// initialize sets of n items
template <typename Comparable>
class DisjSet
{
    rank = new int[n];
    parent = new int[n];
    this->n = n;
    makeSet();
};


// Creates n single item sets
template <typename Comparable>
void DisjSet<Comparable>::makeSet(Comparable i)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
}

// Finds the representative of the set
// that i is an element of
template <typename Comparable>
Comparable find(Comparable x)
{
    // If i is the parent of itself
    if (parent[x] == x)
    {
        // Then i is the representative of
        // this set
        return x;
    }
    else
    {
        // Else if i is not the parent of
        // itself, then i is not the
        // representative of its set. So we
        // recursively call find on its parent
        return find(parent[x]);
    }
}

// Unites the set that includes i
// and the set that includes j
template <typename Comparable>
bool Union(Comparable x, Comparable y)
{
    // Find the representatives
    // (or the root nodes) for the set
    // that includes i
    int xrep = find(x);

    // And do the same for the set
    // that includes j
    int yrep = find(y);

    // Make the parent of i’s representative
    // be j’s  representative effectively
    // moving all of i’s set into j’s set
    parent[xrep] = yrep;
}
