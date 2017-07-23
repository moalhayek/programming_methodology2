// Mhammed Alhayek Homework 3: Question 1 - Sorting Algorithms

#include <iostream>
#include <fstream>

// referenced the book for sorting algorithms

using namespace std;

/** Sorts the items in an array into ascending order
    @pre None.
    @post arr is sorted into ascending order, size is unchanged, 
            runTimeCounter is roughly the number of moves made
 */
void selectionSort(int arr[], int size, long int &runTimeCounter);

/** Sorts the items in an array into ascending order
    @pre None.
    @post arr is sorted into ascending order, size is unchanged,
    runTimeCounter is roughly the number of moves made
 */
void insertionSort(int arr[], int size, long int &runTimeCounter);

/** Sorts the items in an array into ascending order
    @pre None.
    @post arr is sorted into ascending order, size is unchanged,
    runTimeCounter is roughly the number of moves made
 */
void bubbleSort(int arr[], int size, long int &runTimeCounter);

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
    int *myArraySS = new int[count];       // this array will test selection sort
    int *myArrayIS = new int[count];       // this array will test insertion sort
    int *myArrayBS = new int[count];       // this array will test bubble sort
    
    // move the cursor back to the beginning of the inFile
    inFile.clear();
    inFile.seekg(0, ios::beg);
    
    // add each element from the file to the array
    for(int i = 0; i < count; i++){
        inFile >> myArraySS[i];
        myArrayIS[i] = myArraySS[i];
        myArrayBS[i] = myArraySS[i];
    }

    long int counterSS = 0;          // counter for SS
    long int counterIS = 0;          // counter for IS
    long int counterBS = 0;          // counter for BS
    
    
    selectionSort(myArraySS, count, counterSS);
    insertionSort(myArrayIS, count, counterIS);
    bubbleSort(myArrayBS, count, counterBS);
    cout << "The runtime for Selection Sort is: " << counterSS << endl;
    cout << "The runtime for Insertion Sort is: " << counterIS << endl;
    cout << "The runtime for Bubble Sort is: " << counterBS << endl;
    
    cout << "\nUsing the sorted outputs as inputs and calculating new run times: " << endl;
    counterSS = 0;          // counter for SS
    counterIS = 0;          // counter for IS
    counterBS = 0;          // counter for BS
    
    selectionSort(myArraySS, count, counterSS);
    insertionSort(myArrayIS, count, counterIS);
    bubbleSort(myArrayBS, count, counterBS);
    cout << "The runtime for Selection Sort is: " << counterSS << endl;
    cout << "The runtime for Insertion Sort is: " << counterIS << endl;
    cout << "The runtime for Bubble Sort is: " << counterBS << endl;
    
    /*
    cout << "The array sorted with Selection Sort:" << endl;
    for (int i = 0; i < count; i++){
        cout << myArraySS[i] << endl;
    }
    
    cout << "The array sorted with Insertion Sort:" << endl;
    for (int i = 0; i < count; i++){
        cout << myArrayIS[i] << endl;
    }
    
    cout << "The array sorted with Bubble Sort:" << endl;
    for (int i = 0; i < count; i++){
        cout << myArrayBS[i] << endl;
    }
    */
    return 0;
}

void selectionSort(int arr[], int size, long int &runTimeCounter){
    
    // last = index of the last item in the subarray of items yet
    // to be sorted;
    // largest = index of the largest item found
    int largest = 0;    // index of largest item found
    for (int last = size - 1; last>0; last--){
        // finding the largest item in the sub array from the beginning to the last unsorted item
        largest = 0;
        for (int i = 1; i <= last; i++){
            runTimeCounter++;
            if (arr[i]>arr[largest]){
                largest = i;
            }
        }
        // move the largest item to the last position
        runTimeCounter++;
        swap(arr[largest], arr[last]);
    }
}

void insertionSort(int arr[], int size, long int &runTimeCounter){
    
    // unsorted = first index of the unsorted region,
    // item at arr[0] is considered sorted initially
    for (int unsorted = 1; unsorted < size; unsorted++){
        // nextToSort, the next item to sort is the first item outside the sorted region
        int nextToSort = arr[unsorted];
        // loc is going to be where the unsorted item should be inserted
        int loc = unsorted;
        // decrement location until you find an item less than the unsorted item
        // increment the counter in the while loop each time you do a comparison
        while ((loc>0) && ++runTimeCounter && (arr[loc-1]>nextToSort)){
            runTimeCounter++;   // increment the counter each time you do a shift
            // shift all items to the right while searching for position to place unsorted item
            arr[loc] = arr[loc-1];
            loc--;
        }
        
        // place the unsorted item in its proper location
        arr[loc] = nextToSort;
        }
}

void bubbleSort(int arr[], int size, long int &runTimeCounter){
    // when there aren't any swaps, the array is sorted
    bool sorted = false;
    // for as many elements as there are in the array, if it is not sorted, begin bubbling
    for (int i = 1; (i < size) & !sorted; i++){
        sorted = true;
        for (int j = 0; j < size - i; j++){
            runTimeCounter++;       // increment the counter for each time you do a comparison
            // swap consecutive elements if the first is larger than the second
            if (arr[j] > arr[j+1]){
                runTimeCounter++;   // also increment for each swap
                swap(arr[j],arr[j+1]);
                sorted = false;
            }
        }
    }
}
