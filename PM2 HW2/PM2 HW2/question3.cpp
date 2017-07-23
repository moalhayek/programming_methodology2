// Mhammed Alhayek Homework 2: Question 3 (i) - kSmall

#include <iostream>
#include <fstream>

using namespace std;
int partitionFirst(int arr[], int first, int last);
int kSmallFirst(int k, int anArray[], int first, int last);
int kSmallMid(int k, int anArray[], int first, int last);
int partitionMid(int arr[], int first, int last);

int main(int argc, const char * argv[]) {
    
    // read in the file
    ifstream inFile("hw2-data.txt");
    
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
    int myArray[count];       //allowed since C++11
    int myArrayMid[count];    // make a second identical array to pass through kSmallMid
    
    // move the cursor back to the beginning of the inFile
    inFile.clear();
    inFile.seekg(0, ios::beg);
    
    // add each element from the file to the array
    for(int i = 0; i < count; i++){
        inFile >> myArray[i];
        myArrayMid[i] = myArray[i];
    }
    
    cout << "Part (i): Using the first element in the array as the pivot: " << endl;
    // Display the 42nd smallest number to the user
    cout << kSmallFirst(42,myArray,0,count-1) << endl;
    
    
    cout << "Part (ii): Using the middle element in the array as the pivot: " << endl;
    // Display the 42nd smallest number to the user
    cout << kSmallMid(42,myArrayMid,0,count-1) << endl;
    
    return 0;
}


/** Searches anArray[first] through anArray[last] for the kth smallest number in the array. Uses the first element in the array as the pivot
    @pre k > 0, 0 <= first < last, first <= last <= anArray.size() - 1, anArray is an integer array
    @post none
    @param k The number of how small of an element to search for (kth smallest element).
    @param first The low index to start searching from.
    @param last The high index to stop searching at.
    @param anArray Array to search through for the kth smallest element
    @return kth smallest element in the array

*/

int kSmallFirst(int k, int anArray[], int first, int last){
    
    // pivotIndex is recieved from the partition function
    int pivotIndex = partitionFirst(anArray,first,last);
    
    // pivot is the number at the pivot index
    int p = anArray[pivotIndex];
    
    // if (k-1) is less than the pivot index, then partition again from first to the pivotIndex
    if ( k < (pivotIndex - first + 1)){
        return kSmallFirst(k,anArray,first,pivotIndex - 1);
    // else if (k-1) == the pivot index, then it is the kth smallest number
    }else if (k == (pivotIndex - first + 1)){
        cout << "The k smallest element in the array is: " << p << endl;
        return p;
    // else (k-1) is greater than the pivot index, partition again from the pivot index to last
    }else{
        return kSmallFirst(k - (pivotIndex - first + 1), anArray, pivotIndex + 1, last);
    }
}


/** partitions an array about a pivot. The pivot is chosen to be the first element in the array
 @pre 0 <= first < last, first <= last <= arr.size() - 1, arr is an integer array
 @post arr is partitioned about a pivot index.
 @param arr The array to partition
 @param first The low index to start partitioning from.
 @param last The high index to stop partitioning at.
 @return the index of the pivot
 
 // Uses first element in the array as pivot
*/

//chapter 11 pseudocode used (page 323)
int partitionFirst(int arr[], int first, int last){

     //first choose your pivot index
     int pivotIndex = first;
     //cout << pivotIndex << endl;
     int pivot = arr[pivotIndex];
     cout << "The pivot = " << pivot << endl;
    
    // From the left, start with the first index + 1. From the right, start with the last index
    // because the first index is now the pivot, we dont need to check it
    int indexFromLeft = first + 1;
    int indexFromRight = last;

    
    // done will only be true when the indexFromLeft is > indexFromRight
    bool done = false;
    while (!done){
        //Locate first entry on left that is >= pivot
        while(arr[indexFromLeft]<pivot){
        // increment the index from the left until it reaches a value greater than or equal to the pivot
            indexFromLeft++;
        }
        while(arr[indexFromRight]>pivot){
        // decrement the index from the right until it reaches a value less than or equal to the pivot
            indexFromRight--;
        }
        if(indexFromLeft<indexFromRight){
        // as long as indexFromLeft is less than indexFromRight, swap the elements at those indices and move the iterators.
            swap(arr[indexFromLeft],arr[indexFromRight]);
            indexFromLeft++;
            indexFromRight--;
        }
        else
            // stop the while loop when index from left is greater than index from right because
            // at this point everything is in place aside from the pivot
            done = true;
    }
    
    // now when exiting the loop, indexFromRight is at an index of a value less than the pivot, so swap it with the pivot to place the pivot in the middle.
    swap(arr[pivotIndex], arr[indexFromRight]);
    pivotIndex = indexFromRight;
    
    return pivotIndex;
    
}

////////////////////////// Part 2 ////////////////////////////////

/** partitions an array about a pivot. The pivot is chosen to be the middle element in the array
 @pre 0 <= first < last, first <= last <= arr.size() - 1, arr is an integer array
 @post arr is partitioned about a pivot index.
 @param arr The array to partition
 @param first The low index to start partitioning from.
 @param last The high index to stop partitioning at.
 @return the index of the pivot
 
 // Uses middle element in the array as pivot
 */

int partitionMid(int arr[], int first, int last){
    // finds the middles index in the array
    int mid = first + (last - first)/2;
    //moves the int at the middle index to first to get it out of the way when partitioning
    swap(arr[mid], arr[first]);
    //the int at the middle index is the pivot
    int pivotIndex = first;
    int pivot = arr[pivotIndex];
    
    cout << "The pivot = " << pivot << endl;
    
    
    // From the left, start with the first index + 1. From the right, start with the last index
    // because the first index is now the pivot, we dont need to check it
    int indexFromLeft = first + 1;
    int indexFromRight = last;
    
    
    // done will only be true when the indexFromLeft is > indexFromRight
    bool done = false;
    while (!done){
        //Locate first entry on left that is >= pivot
        while(arr[indexFromLeft]<pivot){
            // increment the index from the left until it reaches a value greater than or equal to the pivot
            indexFromLeft++;
        }
        while(arr[indexFromRight]>pivot){
            // decrement the index from the right until it reaches a value less than or equal to the pivot
            indexFromRight--;
        }
        if(indexFromLeft<indexFromRight){
            // as long as indexFromLeft is less than indexFromRight, swap the elements at those indices and move the iterators.
            swap(arr[indexFromLeft],arr[indexFromRight]);
            indexFromLeft++;
            indexFromRight--;
        }
        else
            // stop the while loop when index from left is greater than index from right because
            // at this point everything is in place aside from the pivot
            done = true;
    }
    
    // now when exiting the loop, indexFromRight is at an index of a value less than the pivot, so swap it with the pivot to place the pivot in the middle.
    swap(arr[pivotIndex], arr[indexFromRight]);
    pivotIndex = indexFromRight;
    
    return pivotIndex;
    
    
}

/** Searches anArray[first] through anArray[last] for the kth smallest number in the array, using the middle element in the array as the pivot
 @pre k > 0, 0 <= first < last, first <= last <= anArray.size() - 1, anArray is an integer array
 @post none
 @param k The number of how small of an element to search for (kth smallest element).
 @param first The low index to start searching from.
 @param last The high index to stop searching at.
 @param anArray Array to search through for the kth smallest element
 @return kth smallest element in the array
 
 */

int kSmallMid(int k, int anArray[], int first, int last){
    
    // pivotIndex is recieved from the partition function
    int pivotIndex = partitionMid(anArray,first,last);
    
    // pivot is the number at the pivot index
    int p = anArray[pivotIndex];
    
    // if (k-1) is less than the pivot index, then partition again from first to the pivotIndex
    if ( k < (pivotIndex - first + 1)){
        return kSmallMid(k,anArray,first,pivotIndex - 1);
        // else if (k-1) == the pivot index, then it is the kth smallest number
    }else if (k == (pivotIndex - first + 1)){
        cout << "The k smallest element in the array is: " << p << endl;
        return p;
        // else (k-1) is greater than the pivot index, partition again from the pivot index to last
    }else{
        return kSmallMid(k - (pivotIndex - first + 1), anArray, pivotIndex + 1, last);
    }
}

