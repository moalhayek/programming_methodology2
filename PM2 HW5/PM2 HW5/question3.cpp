// Mhammed Alhayek Homework 5: Question 3 - heapSort


// reference: book page 520
#include <iostream>
#include <fstream>
#include "ArrayMaxHeap.h"

using namespace std;


/** rebuilds a heap from the root down
 @pre subTreeRootIndex is the index of the root of a tree, whose children are both heaps, arr is the full tree, n is its size
 @post arr is arranged into a heap
 @param subTreeRootIndex the root of a subtree whose children are heaps
 @param n the size of arr
 @param arr the tree to be transformed into a heap
 */
void heapRebuild(int subTreeRootIndex, int arr[], int n, long int &runTimeCounter);

/** checks if a node is a leaf
 @pre arr is a heap
 @post returns true if the node at nodeIndex is a leaf
 @param nodeIndex the node to be checked
 @param n the size of arr
 @param arr the heap
 */
bool isLeaf(int nodeIndex, int arr[], int n);

/** Sorts the items in arr into ascending order
 @pre none
 @post the array arr[] is sorted in ascending order.
 @param arr the given array
 @param n the size of arr
 @param runTimeCounter the counter that keeps track of how many moves are made
 */
void heapSort(int arr[], int n, long int &runTimeCounter);

int main(){
    // read in the file
    cout << "Enter the file name to read data from: ";
    string file;
    cin >> file;
    ifstream inFile(file);
    
    // if the file can't be read, cout an error
    if (!inFile){
        cerr << "File could not be opened" << endl;
        exit(1);
    }
    
    // use test to pull in ints to it from the file
    int test;
    // increment the counter everytime an int is pulled in.
    int count = 0;
    while (inFile >> test){
        count++;
    }
    
    // declare an array with the size being that of the counter
    int *myArrayHS = new int[count];       // this array will test heapSort
    
    // move the cursor back to the beginning of the inFile
    inFile.clear();
    inFile.seekg(0, ios::beg);
    
    // add each element from the file to the array
    for(int i = 0; i < count; i++){
        inFile >> myArrayHS[i];
    }
    
    long int counterHS = 0;          // counter for HS
    
    heapSort(myArrayHS,count, counterHS);
    
    cout << "The runtime for heapSort is: " << counterHS << endl;
    
    
    cout << "\nUsing the sorted outputs as inputs and calculating new run times: " << endl;
    counterHS = 0;          // counter for MS

    
    heapSort(myArrayHS,count, counterHS);
    
    cout << "The runtime for heapSort with a sorted input is: " << counterHS << endl;
    
    return 0;
}

void heapSort(int arr[], int n, long int &runTimeCounter){
    // Build initial heap
    
    // start at first node not a leaf (index = n-1/2)
    // this node is a semi heap
    for (int index = n / 2 - 1; index >= 0; index--){
        heapRebuild(index, arr, n, runTimeCounter);
    }
    // after each iteration of loop, the index goes from semiheap to heap

    
    // Assertion: anArray[0] is the largest item in heap anArray[0..n-1]
    // Move the largest item in the Heap region —the root arr[0] — to the beginning
    // of the Sorted region by swapping items and then adjusting the size of the regions
    swap(arr[0],arr[n - 1]);
    runTimeCounter+=3;  // increment the counter 3 times for swap operation
    int heapSize = n - 1; // Decrease the size of the Heap region, expand the Sorted region
    
    runTimeCounter++;       // increment counter for comparison in while loop statement
    while (heapSize > 1)
    {
        runTimeCounter++;       // increment counter for comparison in while loop statement
        // Make the Heap region a heap again
        heapRebuild(0, arr, heapSize, runTimeCounter);
        
        // Move the largest item in the Heap region — the root arr[0] — to the beginning
        // of the Sorted region by swapping items and then adjusting the size of the regions
        swap(arr[0], arr[heapSize - 1]);
        runTimeCounter+=3;  // increment the counter 3 times for swap operation
        heapSize--; // Decrease the size of the Heap region, expand the Sorted region
        
    }
    
}

void heapRebuild(int subTreeRootIndex, int arr[], int n, long int &runTimeCounter){
    runTimeCounter++;       // increment counter for comparison in if statement
    if (!isLeaf(subTreeRootIndex, arr, n)){
        // if not a leaf, must have a left child because heap is complete
        // assume left child is larger child
        int largerChildIndex = 2*subTreeRootIndex + 1;
        int rightChildIndex = largerChildIndex + 1;
        
        // it has a right child if its right child index is less than or equal to last index.
        runTimeCounter++;       // increment counter for comparison in if statement
        if (rightChildIndex < (n-1)){
            // if it has a right child, check which child is larger
            runTimeCounter++;       // increment counter for comparison in if statement
            if (arr[rightChildIndex] > arr[largerChildIndex]){
                largerChildIndex = rightChildIndex;
            }
        }
        
        // if larger child is larger than the root, swap child and root
        // then repeat process with subtree where larger child was
        runTimeCounter++;       // increment counter for comparison in if statement
        if (arr[subTreeRootIndex] < arr[largerChildIndex]){
            swap(arr[subTreeRootIndex],arr[largerChildIndex]);
            runTimeCounter+=3;  // increment the counter 3 times for swap operation
            heapRebuild(largerChildIndex, arr, n, runTimeCounter);
        }
    }
    // Else root is a leaf, do nothing
}

bool isLeaf(int nodeIndex, int arr[], int n){
    int size = n;
    // first check to make sure the node index is within the nodes of the heap
    if (nodeIndex < size){
        // all leaves are located at indices greater than (number of items - 2)/2
        return (nodeIndex > ((size-2)/2));
    }
    else{
        // node is out of range, can't be a leaf
        return false;
    }
}
