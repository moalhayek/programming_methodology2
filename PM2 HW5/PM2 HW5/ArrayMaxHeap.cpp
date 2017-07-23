//  ArrayMaxHeap.cpp
//  PM2 HW5
//  implementation for array based implementation of a max heap.

// reference: book
#include "ArrayMaxHeap.h"
#include <cmath>


// default constructor allows for a maximum capacity of 100

ArrayMaxHeap::ArrayMaxHeap() : itemCount(0), maxItems(100){
    items = new int[100];
}


int ArrayMaxHeap::getLeftChildIndex(const int nodeIndex) const{
    return (2*nodeIndex) + 1;
}


int ArrayMaxHeap::getRightChildIndex(const int nodeIndex) const{
    return (2*nodeIndex) + 2;
}


int ArrayMaxHeap::getParentIndex(int nodeIndex) const{
    return (nodeIndex-1)/2;
}


bool ArrayMaxHeap::isLeaf(int nodeIndex) const{
    
    // first check to make sure the node index is within the nodes of the heap
    if (nodeIndex < itemCount){
        // all leaves are located at indices greater than (number of items - 1)/2
        return (nodeIndex > ((itemCount-2)/2));
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

void ArrayMaxHeap::heapRebuild(int subTreeRootIndex){
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
            std::swap(items[subTreeRootIndex],items[largerChildIndex]);
            heapRebuild(largerChildIndex);
        }
    }
    // Else root is a leaf, do nothing
}


void ArrayMaxHeap::heapCreate(){
    // start at first node not a leaf
    // this node is a semi heap
    for (int index = itemCount/2 - 1; index >= 0; index--){
        heapRebuild(index);
    }
    // after each iteration of loop, the index goes from semiheap to heap
}


ArrayMaxHeap::ArrayMaxHeap(const int someArray[], const int arraySize) : itemCount(arraySize), maxItems(2*arraySize){
    
    // Allocate the array for the heap, give space for new nodes to be added
    items = new int[2*arraySize];
    
    // copy given values into the array
    for (int i = 0; i<itemCount; i++){
        items[i] = someArray[i];
    }
    
    // reorganize the array into a heap
    heapCreate();
    
}


int ArrayMaxHeap::peekTop() const{
    if (isEmpty()){
        throw std::invalid_argument("Attempting to peek at an empty tree");
    }
    else{
        return items[0];
    }
}


bool ArrayMaxHeap::remove(){
    if (isEmpty()){
        return false;
    }
    else{
        // Copy the item from the last node into the root
        items[0] = items[itemCount - 1];
        // Remove the last node
        itemCount--;
        // Transform the semiheap back into a heap
        heapRebuild(0);
    
        return true;
    }
}


int ArrayMaxHeap::getHeight() const{
    return ceil(log2(itemCount+1));
}
                                     


int ArrayMaxHeap::getNumberOfNodes() const{
    return itemCount;
}


bool ArrayMaxHeap::add(const int &newData){
    if (isEmpty()){
        items[itemCount] = newData;
        itemCount++;
        return true;
    }
    else if (itemCount < maxItems){
        // Insert newData into the bottom of the tree
        items[itemCount] = newData;
    
        // Trickle new item up to the appropriate spot in the tree
        int newDataIndex = itemCount;
        
        bool inPlace = false;
        
        int parentIndex;
        while ( (newDataIndex > 0) and !inPlace){
            parentIndex = (newDataIndex - 1) / 2;
            
            if (items[newDataIndex] < items[parentIndex]){
                inPlace = true;
            }
            else{
                std::swap(items[newDataIndex], items[parentIndex]);
                newDataIndex = parentIndex;
            }
        }
        itemCount++;
        
        return true;
    }
    else{
        return false;
    }
}


void ArrayMaxHeap::clear(){
    // to clear, just set item count to 0
    itemCount = 0;
}


ArrayMaxHeap::~ArrayMaxHeap(){
}

bool ArrayMaxHeap::isEmpty() const{
    return (itemCount == 0);
}

int* ArrayMaxHeap::getArr(){
    return items;
}
