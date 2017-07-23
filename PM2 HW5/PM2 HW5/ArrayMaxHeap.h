//  ArrayMaxHeap.h
//  PM2 HW5
//  interface for array based implementation of a max heap.

// reference: book page 512-513

#ifndef ArrayMaxHeap_h
#define ArrayMaxHeap_h

#include "HeapInterface.h"
#include <iostream>
#include <stdexcept>

class ArrayMaxHeap : public HeapInterface{
private:
    static const int ROOT_INDEX = 0;        // Helps with readability
    static const int DEFAULT_CAPACITY = 100; // Small capacity to test for a full heap -- necessary?
    int* items;                        // array of heap items
    int itemCount;                          // current count of heap items
    int maxItems;                           // maximum capacity of the heap
    
    // Returns the array index of the left child (if it exists).
    int getLeftChildIndex(const int nodeIndex) const;
    
    // Returns the array index of the right child (if it exists).
    int getRightChildIndex(const int nodeIndex) const;
    
    // Returns the array index of the parent node.
    int getParentIndex(int nodeIndex) const;
    
    // Tests whether this node is a leaf.
    bool isLeaf(int nodeIndex) const;
    
    // Converts a semiheap to a heap.
    void heapRebuild(int subTreeRootIndex);
    
    // Creates a heap from an unordered array.
    void heapCreate();
    
public:
    ArrayMaxHeap();
    ArrayMaxHeap(const int someArray[], const int arraySize);
    virtual ~ArrayMaxHeap();
    
    bool isEmpty() const;
    int getNumberOfNodes() const;
    int getHeight() const;
    int peekTop() const;
    bool add(const int& newData);
    bool remove();
    void clear();
    
    int* getArr();
};

#endif /* ArrayMaxHeap_h */
