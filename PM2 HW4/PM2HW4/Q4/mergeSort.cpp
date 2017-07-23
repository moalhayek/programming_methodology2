// Mhammed Alhayek Homework 4: Question 4 - Merge Sort
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// referenced the book for sorting algorithms and pseudocode
// referenced: http://penguin.ewu.edu/cscd300/Topic/AdvSorting/MergeSorts/InPlace.html for in place merge sort


/** Merges two sorted arrays arr[first...mid] and arr[mid+1... last] into one sorted array. Uses an extra temporary array.
    @pre the two sub arrays are sorted. first<=mid<=last
    @post the array arr[] is sorted.
    @param arr the given array
    @param first the index of the first element in arr
    @param mid the index of the middle elment in arr
    @param last the index the last element in arr
    @param runTimeCounter the counter that keeps track of how many moves are made
 */
void merge(int arr[], int first, int mid, int last, long int &runTimeCounter);

/** Sorts the items in arr into ascending order
 @pre none
 @post the array arr[] is sorted in ascending order.
 @param arr the given array
 @param first the index of the first element in arr
 @param last the index the last element in arr
 @param runTimeCounter the counter that keeps track of how many moves are made
 */
void mergeSort(int arr[], int first, int last, long int &runTimeCounter);

/** Merges two sorted arrays arr[first...mid] and arr[mid+1... last] into one sorted array. Does not use any additional memory
 @pre the two sub arrays are sorted. first<=mid<=last
 @post the array arr[] is sorted.
 @param arr the given array
 @param first the index of the first element in arr
 @param mid the index of the middle elment in arr
 @param last the index the last element in arr
 @param runTimeCounter the counter that keeps track of how many moves are made
 */
void inPlaceMerge(int arr[], int first, int mid, int last, long int &runTimeCounter);

/** Sorts the items in arr into ascending order
 @pre none
 @post the array arr[] is sorted in ascending order.
 @param arr the given array
 @param first the index of the first element in arr
 @param last the index the last element in arr
 @param runTimeCounter the counter that keeps track of how many moves are made
 */
void inPlaceMergeSort(int arr[], int first, int last, long int &runTimeCounter);

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
    int *myArrayMS = new int[count];       // this array will test merge sort
    int *myArrayIPMS = new int[count];       // this array will test in place merge sort
    
    // move the cursor back to the beginning of the inFile
    inFile.clear();
    inFile.seekg(0, ios::beg);
    
    // add each element from the file to the array
    for(int i = 0; i < count; i++){
        inFile >> myArrayMS[i];
        myArrayIPMS[i] = myArrayMS[i];
    }
    
    
    long int counterMS = 0;          // counter for MS
    long int counterIPMS = 0;          // counter for In Place MS
    
    mergeSort(myArrayMS, 0, count-1, counterMS);
    inPlaceMergeSort(myArrayIPMS, 0, count-1, counterIPMS);
    
    cout << "The runtime for MergeSort is: " << counterMS << endl;
    cout << "The runtime for In Place MergeSort is: " << counterIPMS << endl;
    
//    cout << "The array sorted with MergeSort is: " << endl;
//     for (int i = 0; i < count; i++){
//     cout << i << ". " << myArrayMS[i] << endl;
//     }
    
    
    
    cout << "\nUsing the sorted outputs as inputs and calculating new run times: " << endl;
    counterMS = 0;          // counter for MS
    counterIPMS = 0;          // counter for In Place MS
    
    mergeSort(myArrayMS,0, count-1, counterMS);
    inPlaceMergeSort(myArrayIPMS,0, count-1, counterIPMS);
    
    cout << "The runtime for Mergesort is: " << counterMS << endl;
    cout << "The runtime for In Place Mergesort is: " << counterIPMS << endl;
    
    return 0;
}

void merge(int arr[], int first, int mid, int last, long int &runTimeCounter){
    // since both halves are sorted, if the last element in the first half is less than
    // the first element in the second half, the whole array is sorted.
    runTimeCounter++;
    if (arr[mid] <= arr[mid+1]){
        return;
    }
    
    int size1 = mid - first + 1;
    int size2 = last - mid;
    //creating two sub arrays for right and left halves
    vector<int> L(size1);
    vector<int> R(size2);

    int first2 = mid+1;             // beginning of second subbarry
    
    // increment the counter for copying the elements into the subarrays
    for (int i = 0; i<size1; i++){
        L[i] = arr[first + i];
        runTimeCounter++;
    }
    
    for (int i = 0; i< size2; i++){
        R[i] = arr[first2 + i];
        runTimeCounter++;
    }
    
    // while both subarrays are not empty, copy the
    // smaller item into the array
    int index = first;             // first index in array to add to
    int i = 0;                     // iterator for left subarray
    int j = 0;                     // iterator for right subarray
    
    runTimeCounter += 2;           // incrementing for when not entering the while loop
    while ((i < size1) && (j < size2)){
        runTimeCounter += 2;       // for two comparisons in while loop
        runTimeCounter += 1;       // for comparison in if statement
        if (L[i] <= R[j]){
            arr[index++] = L[i++];      // increment iterator after taking element
            runTimeCounter++;        // incrememnt counter for copy
        }
        else{
            arr[index++] = R[j++];      // increment iterator after taking element
            runTimeCounter++;        // incrememnt counter for copy
        }
    }
    
    // above while loop could have ended if one of the two subarrays is finished but the other is not
    // therefore, we must finish off both subarrays
    
    while (i < size1){
        arr[index++] = L[i++];
        runTimeCounter++;               // increment counter for copy
    }
    
    while (j < size2){
        arr[index++] = R[j++];
        runTimeCounter++;               // increment counter for copy
    }
    
    
}

void mergeSort(int arr[], int first, int last, long int &runTimeCounter){
    runTimeCounter++;       //increment counter for comparison
    if (first < last){
        //divide the array in two and sort both halves
        
        int mid = first + (last - first)/2;             // index of midpoint
        
        // sort left half
        mergeSort(arr,first,mid, runTimeCounter);
        // sort right half
        mergeSort(arr, mid+1, last, runTimeCounter);
        
        // merge both sorted halves
        
        merge(arr,first,mid,last, runTimeCounter);
        
    }
}


void inPlaceMerge(int arr[], int first, int mid, int last, long int &runTimeCounter){
    int first2 = mid+1;             // beginning of second subbarry
    
    // since both halves are sorted, if the last element in the first half is less than
    // the first element in the second half, the whole array is sorted.
    
    runTimeCounter++;
    if (arr[mid] <= arr[mid+1]){
        return;
    }
    
    runTimeCounter += 2;        // for the two comparisons made when the while loop doesn't enter the loop
    while ((first <= mid) && (first2 <= last)){
        runTimeCounter += 2;        // for the two comparisons made in the while loop condition
        
        // if the element in the left half is less than element in the right half, go to next element
        runTimeCounter++;       // for comparison in if statement
        if (arr[first] <= arr[first2]){
            first++;
        }
        else{
            // element on right is smaller, need to move it before the left element and shift
            // all other elements
            int temp = arr[first2];
            
            for (int i = first2; i>first; i--){
                runTimeCounter++;           // for each shift
                arr[i] = arr[i-1];
            }
            arr[first] = temp;
            // increment both iterators
            first++;
            first2++;
            // must increment mid as well because all elements were shifted
            mid++;
        }
    }
    
    // anything left is in place
    
}

void inPlaceMergeSort(int arr[], int first, int last, long int &runTimeCounter){
    runTimeCounter++;       //increment counter for comparison
    if (first < last){
        //divide the array in two and sort both halves
        
        int mid = first + (last - first)/2;             // index of midpoint
        
        // sort left half
        mergeSort(arr,first,mid, runTimeCounter);
        // sort right half
        mergeSort(arr, mid+1, last, runTimeCounter);
        
        // merge both sorted halves
        
        inPlaceMerge(arr,first,mid,last, runTimeCounter);
        
    }
}
