// Mhammed Alhayek Homework 4: Question 1 - Quick Sort
#include <iostream>
#include <fstream>

// referenced the book for sorting algorithms and pseudocode

using namespace std;

/** selects the first, middle, and last elements in an array and sorts them in ascending order
 @pre none
 @post arr[first]<=arr[mid]<=arr[last]
 @param arr the given array
 @param first the index of the first element in arr
 @param mid the index of the middle element in arr
 @param last the index the last element in arr
 @param runTimeCounter the counter that keeps track of how many moves are made
 */
void sortFirstMiddleLast(int arr[], int first, int mid, int last, long int &runTimeCounter);

/** Partitions an array so that all items before the pivot index are less than the pivot and all elements after the pivot index are 
    greater than the pivot. The pivot is chosen using the median-of-three selection method.
 @pre none
 @post arr is partitioned around a pivot index
 @return the index of the pivot
 @param arr the given array
 @param first the index of the first element in arr
 @param last the index the last element in arr
 @param runTimeCounter the counter that keeps track of how many moves are made
 */
int partition(int arr[], int first, int last, long int &runTimeCounter);

/** Sorts the items in arr into ascending order. Uses the median-of-three pivot selection method.
 @pre none
 @post the array arr[] is sorted in ascending order.
 @param arr the given array
 @param first the index of the first element in arr
 @param last the index the last element in arr
 @param runTimeCounter the counter that keeps track of how many moves are made
 */
void quickSort(int arr[], int first, int last, long int &runTimeCounter);

int main(int argc, const char * argv[]) {
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
    int *myArrayQS = new int[count];       // this array will test selection sort
    
    // move the cursor back to the beginning of the inFile
    inFile.clear();
    inFile.seekg(0, ios::beg);
    
    // add each element from the file to the array
    for(int i = 0; i < count; i++){
        inFile >> myArrayQS[i];
    }
    
    
    long int counterQS = 0;          // counter for SS
    
    
    quickSort(myArrayQS, 0, count-1, counterQS);

    cout << "The runtime for Quicksort is: " << counterQS << endl;
    
//    cout << "The array sorted with QuickSort is: " << endl;
//    for (int i = 0; i < count; i++){
//        cout << i << ". " << myArrayQS[i] << endl;
//    }
    
    
    
    cout << "\nUsing the sorted outputs as inputs and calculating new run times: " << endl;
    counterQS = 0;          // counter for QS

    quickSort(myArrayQS,0, count-1, counterQS);
    
    cout << "The runtime for Quicksort is: " << counterQS << endl;

    
    return 0;
}

// arranges the first, middle, and last entries in an array into ascending order
void sortFirstMiddleLast(int arr[], int first, int mid, int last, long int &runTimeCounter){
    runTimeCounter += 3;        // for three if statement comparisons
    if (arr[first] > arr[mid]){
        swap(arr[first],arr[mid]);
        runTimeCounter++;           // for swap
    }
    if (arr[mid] > arr[last]){
        swap(arr[mid],arr[last]);
        runTimeCounter++;           // for swap
    }
    if (arr[first] > arr[mid]){
        swap(arr[first],arr[mid]);
        runTimeCounter++;           // for swap
    }
}

int partition(int arr[], int first, int last, long int &runTimeCounter){
    // finds the middles index in the array
    int mid = first + (last - first)/2;
    // sorts the first, mid, and last element so that we choose the middle value of the 3 as the pivot
    sortFirstMiddleLast(arr, first, mid, last, runTimeCounter);
    // moves the int at the middle index to first to get it out of the way when partitioning
    runTimeCounter++;           // incrementing for swap
    swap(arr[mid], arr[first]);
    //the int at the middle index is the pivot
    int pivotIndex = first;
    int pivot = arr[pivotIndex];
    
    // From the left, start with the first index + 1. From the right, start with the last index
    // because the first index is the pivot, we dont need to check it
    int indexFromLeft = first + 1;
    int indexFromRight = last;
    
    // done will only be true when the indexFromLeft is > indexFromRight
    bool done = false;
    while (!done){
        //Locate first entry on left that is >= pivot
        while(++runTimeCounter && (arr[indexFromLeft]<pivot)){      //increment counter for comparison
            // increment the index from the left until it reaches a value greater than or equal to the pivot
            indexFromLeft++;
        }
        
        while(++runTimeCounter && (arr[indexFromRight]>pivot)){     //increment counter for comparison
            // decrement the index from the right until it reaches a value less than or equal to the pivot
            indexFromRight--;
        }
        
        runTimeCounter++;
        if(indexFromLeft<indexFromRight){
            // as long as indexFromLeft is less than indexFromRight, swap the elements at those indices and move the iterators.
            swap(arr[indexFromLeft],arr[indexFromRight]);
            indexFromLeft++;
            indexFromRight--;
            
            runTimeCounter++;        // incrementing counter 1 times for the swap
        }
        else
            // stop the while loop when index from left is greater than index from right because
            // at this point everything is in place aside from the pivot
            done = true;
    }
    
    // now when exiting the loop, indexFromRight is at an index of a value less than the pivot, so swap it with the pivot to place the pivot in its proper position and the element in the left half of the partition
    runTimeCounter++;       // incrementing for swap
    swap(arr[pivotIndex], arr[indexFromRight]);
    pivotIndex = indexFromRight;
    
    return pivotIndex;
    
}

void quickSort(int arr[], int first, int last, long int &runTimeCounter){
    runTimeCounter++;   // increment for comparison of "first<last"
    if (first < last){
        int pivotIndex = partition(arr,first,last, runTimeCounter);

        quickSort(arr, first, pivotIndex - 1, runTimeCounter);
        quickSort(arr, pivotIndex + 1, last, runTimeCounter);
    }
}












