// Mhammed Alhayek Homework 5: Question 2 - part d: Combining two heaps of arbitrary size

#include <iostream>
#include "ArrayMaxHeap.h"

using namespace std;

/** Merges two heaps into one heap
 @pre heap1 and heap2 are both max heaps
 @post a new heap is returned whose elements are those of heap1 and heap2
 @param heap1 the first heap of size n
 @param n the size of heap1
 @param heap2 the second heap of size m
 @param m the size of heap 2
 */
ArrayMaxHeap heapCombine(ArrayMaxHeap heap1, int n, ArrayMaxHeap heap2, int m);

// The main tests the above algorithm
int main(){
    int arr1[10] = {9, 12, 6, 5, 18, 3, 1, 7, 38, 10};
    int arr2[20] = {4, 11, 8, 13, 22, 15, 36, 14, 19, 31, 17, 27, 32, 16, 20, 0, 35, 28, 23, 39};
    
    // creating two heaps of arbitrary sizes m and n
    cout << "Creating two heaps" << endl;
    ArrayMaxHeap myHeap1 = ArrayMaxHeap(arr1, 10);
    ArrayMaxHeap myHeap2 = ArrayMaxHeap(arr2, 20);
    
    

    // use heapCombine to create the combined heap
    cout << "Using heapCombine() to combine the two heaps" << endl;
    ArrayMaxHeap myHeap3 = heapCombine(myHeap1, 10, myHeap2, 20);
    cout << "Peaking the top of heap3: ";
    cout << myHeap3.peekTop() << endl;
    cout << "Removing an element from the top of heap3 and peaking the top again: ";
    myHeap3.remove();
    cout << myHeap3.peekTop() << endl;
    // myHeap3 contains all the data from myHeap1 and myHeap2, and is still a heap
    
    // myHeap1 and myHeap2 are unchanged
    cout << "Peaking the top of heap1: ";
    cout << myHeap1.peekTop() << endl;
    cout << "Peaking the top of heap2: ";
    cout << myHeap2.peekTop() << endl;
    
    cout << "Combined heap contains elements from both heap1 and heap2, which are left unchanged." << endl;
    
    return 0;
}


// heap 1 size n
// heap 2 size 1
ArrayMaxHeap heapCombine(ArrayMaxHeap heap1, int n, ArrayMaxHeap heap2, int m){
    int temp[n+m];
    int *arr1 = heap1.getArr();
    int *arr2 = heap2.getArr();
    for (int i =0; i < n; i++){
        temp[i] = arr1[i];
    }
    
    for (int i = 0; i<m; i++){
        temp[n+i] = arr2[i];
    }
    
    ArrayMaxHeap combinedHeap(temp,(n+m));
    return combinedHeap;
}
