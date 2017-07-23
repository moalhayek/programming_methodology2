//  HeapInterface.h
//  PM2 HW5
//  interface for ADT heap.

// reference: book page 505-506

#ifndef HeapInterface_h
#define HeapInterface_h


class HeapInterface{
public:
    // sees wheter this heap is empty.
    virtual bool isEmpty() const = 0;
    
    // gets the number of nodes in this heap.
    virtual int getNumberOfNodes() const = 0;
    
    // gets the height of ths heap.
    virtual int getHeight() const = 0;
    
    // Gets the data that is in the root (top) of this heap.
    virtual int peekTop() const = 0;
    
    // Adds a new node containing the given data to this heap.
    virtual bool add(const int& newData) = 0;
    
    // Removes the root node from this heap.
    virtual bool remove() = 0;
    
    // Removes all nodes from this heap.
    virtual void clear() = 0;
};

#endif /* HeapInterface_h */
