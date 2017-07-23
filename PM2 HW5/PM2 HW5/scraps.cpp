//  ArrayMaxHeap.h
//  PM2 HW5
//  interface for array based implementation of a max heap.

// reference: book page 512-513

#ifndef ArrayMaxHeap_h
#define ArrayMaxHeap_h

#include "HeapInterface.h"
#include <stdexcept>

template<class ItemType>
class ArrayMaxHeap : public HeapInterface<ItemType>{
private:
    static const int ROOT_INDEX = 0;        // Helps with readability
    static const int DEFAULT_CAPACITY = 100; // Small capacity to test for a full heap -- necessary?
    ItemType* items;                        // array of heap items
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
    ArrayMaxHeap(const ItemType someArray[], const int arraySize);
    virtual ~ArrayMaxHeap();
    
    bool isEmpty() const;
    int getNumberOfNodes() const;
    int getHeight() const;
    ItemType peekTop() const;
    bool add(const ItemType& newData);
    bool remove();
    void clear();
};

#endif /* ArrayMaxHeap_h */

/////////////////////////////////////////////////////////////////////////////////////////////
//  ArrayMaxHeap.cpp
//  PM2 HW5
//  implementation for array based implementation of a max heap.

// reference: book
#include "ArrayMaxHeap.h"


// default constructor allows for a maximum capacity of 100
template<class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap() : itemCount(0), maxItems(DEFAULT_CAPACITY){
    items = new ItemType[maxItems];
}

template<class ItemType>
int ArrayMaxHeap<ItemType>::getLeftChildIndex(const int nodeIndex) const{
    return (2*nodeIndex) + 1;
}

template<class ItemType>
int ArrayMaxHeap<ItemType>::getRightChildIndex(const int nodeIndex) const{
    return (2*nodeIndex) + 2;
}

template<class ItemType>
int ArrayMaxHeap<ItemType>::getParentIndex(int nodeIndex) const{
    return (nodeIndex-1)/2;
}

template<class ItemType>
bool ArrayMaxHeap<ItemType>::isLeaf(int nodeIndex) const{
    
    // first check to make sure the node index is within the nodes of the heap
    if (nodeIndex < itemCount){
        // all leaves are located at indices greater than (number of items - 1)/2
        return (nodeIndex > ((itemCount-1)/2));
    }
    else{
        // node is out of range, can't be a leaf
        return false;
    }
    
    //    if (nodeIndex > (itemCount-1/2)){
    //        return true;
    //    }
    //    else{
    //        return false;
    //    }
}

template<class ItemType>
void ArrayMaxHeap<ItemType>::heapRebuild(int subTreeRootIndex){
    if (!isLeaf(subTreeRootIndex)){
        // if not a leaf, must have a left child because heap is complete
        // assume left child is larger child
        int largerChildIndex = 2*subTreeRootIndex + 1;
        
        // it has a right child if its right child index is less than or equal to last index.
        if (getRightChildIndex(subTreeRootIndex) < itemCount){
            // if it has a right child, check which child is larger
            int rightChildIndex = largerChildIndex + 1;
            if (items[rightChildIndex] > items[largerChildIndex]){
                largerChildIndex = rightChildIndex;
            }
        }
        
        // if larger child is larger than the root, swap child and root
        // then repeat process with subtree where larger child was
        if (items[subTreeRootIndex] < items[largerChildIndex]){
            swap(items[subTreeRootIndex],items[largerChildIndex]);
            heapRebuild(largerChildIndex);
        }
    }
    // Else root is a leaf, do nothing
}

template<class ItemType>
void ArrayMaxHeap<ItemType>::heapCreate(){
    // start at first node not a leaf
    // this node is a semi heap
    for (int index = (itemCount-1)/2; index >= 0; index--){
        heapRebuild(index);
    }
    // after each iteration of loop, the index goes from semiheap to heap
}

template<class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap(const ItemType someArray[], const int arraySize) : itemCount(arraySize), maxItems(2*arraySize){
    
    // Allocate the array for the heap, give space for new nodes to be added
    items = new ItemType[2*arraySize];
    
    // copy given values into the array
    for (int i = 0; i<itemCount; i++){
        items[i] = someArray[i];
    }
    
    // reorganize the array into a heap
    heapCreate();
    
}

template<class ItemType>
ItemType ArrayMaxHeap<ItemType>::peekTop() const{
    if (isEmpty()){
        throw std::invalid_argument("Attempting to peek at an empty tree");
    }
    else{
        return items[0];
    }
}

template<class ItemType>
bool ArrayMaxHeap<ItemType>::remove(){
    // Copy the item from the last node into the root
    items[0] = items[itemCount - 1];
    // Remove the last node
    itemCount--;
    // Transform the semiheap back into a heap
    heapRebuild(0, items, itemCount);
}

template<class ItemType>
int ArrayMaxHeap<ItemType>::getHeight() const{
    return ceil(log2(itemCount+1));
}


template<class ItemType>
int ArrayMaxHeap<ItemType>::getNumberOfNodes() const{
    return itemCount;
}

template<class ItemType>
bool ArrayMaxHeap<ItemType>::add(const ItemType &newData){
    // Insert newData into the bottom of the tree
    items[itemCount] = newData;
    
    // Trickle new item up to the appropriate spot in the tree
    int newDataIndex = itemCount;
    
    bool inPlace = false;
    
    int parentIndex;
    while ( (newDataIndex >= 0) and !inPlace)
    {
        parentIndex = (newDataIndex - 1) / 2;
        if (items[newDataIndex] < items[parentIndex]){
            inPlace = true;
        }
        else{
            swap(items[newDataIndex], items[parentIndex]);
            newDataIndex = parentIndex;
        }
    }
    itemCount++;
}

template<class ItemType>
void ArrayMaxHeap<ItemType>::clear(){
    // to clear, just set item count to 0
    itemCount = 0;
}

template<class ItemType>
ArrayMaxHeap<ItemType>::~ArrayMaxHeap(){
    delete items [maxItems];
}

////////////////////////////////////////////////////////////////////////////////////////////////
//  HeapInterface.h
//  PM2 HW5
//  interface for ADT heap.

// reference: book page 505-506

#ifndef HeapInterface_h
#define HeapInterface_h

template<class ItemType>
class HeapInterface{
public:
    // sees wheter this heap is empty.
    virtual bool isEmpty() const = 0;
    
    // gets the number of nodes in this heap.
    virtual int getNumberOfNodes() const = 0;
    
    // gets the height of ths heap.
    virtual int getHeight() const = 0;
    
    // Gets the data that is in the root (top) of this heap.
    virtual ItemType peekTop() const = 0;
    
    // Adds a new node containing the given data to this heap.
    virtual bool add(const ItemType& newData) = 0;
    
    // Removes the root node from this heap.
    virtual bool remove() = 0;
    
    // Removes all nodes from this heap.
    virtual void clear() = 0;
};

#endif /* HeapInterface_h */
