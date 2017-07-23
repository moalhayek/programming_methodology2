// Mhammed Alhayek Homework 2: Question 3 (ii) - kSmall

#include <iostream>
#include <fstream>

using namespace std;
int partition(int arr[], int first, int last);
int kSmall(int k, int anArray[], int first, int last);

int main(int argc, const char * argv[]) {
    ifstream inFile("hw2-data.txt");
    if (!inFile){
        cerr << "File could not be opened" << endl;
        exit(1);
    }
    
    int test;
    int count = 0;
    while (inFile >> test){
        count++;
    }
    //    cout << count << endl;
    int myArray[count];       //allowed since C++11
    
    inFile.clear();
    inFile.seekg(0, ios::beg);
    
    for(int i = 0; i < count; i++){
        inFile >> myArray[i];
    }
    
    
    cout << kSmall(42,myArray,0,count-1) << endl;

    return 0;
}

int kSmall(int k, int anArray[], int first, int last){
    int p = anArray[first];
    // partition the values of array about p
    int pivotIndex = partition(anArray, first, last);
    
    if (k < (pivotIndex - first + 1)){
        return kSmall(k,anArray,first,pivotIndex - 1);
    }else if (k == pivotIndex - first + 1){
        return p;
    }else{
        return kSmall(k - (pivotIndex - first + 1), anArray, pivotIndex + 1, last);
    }
}

//chapter 11 pseudocode used (page 323)
int partition(int arr[], int first, int last){
    
    int mid = first + (last - first)/2;
    swap(arr[mid], arr[first]);
    int pivotIndex = first;
    //    cout << pivotIndex << endl;
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
