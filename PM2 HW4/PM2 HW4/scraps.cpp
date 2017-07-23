
/////////////////////////////////////// SCRAPS ///////////////////////////////////////////////
void merge2(int arr[], int first, int mid, int last){
    int size = last-first+1;
    
    int temp[size];
    
    int first2 = mid+1;             // beginning of second subbarry
    
    for (int i = 0; i<size; i++){
        temp[i] = arr[first + i];
    }
    
    // while both subarrays are not empty, copy the
    // smaller item into the array
    int index = first;             // first index in array to add to
    while ((first <= mid) && (first2 <= last)){
        if (temp[first] <= temp[first2]){
            arr[index++] = temp[first++];      // increment iterator after taking element
        }
        else{
            arr[index++] = temp[first2++];      // increment iterator after taking element
        }
    }
    
    // above while loop could have ended if one of the two subarrays is finished but the other is not
    // therefore, we must finish off both subarrays
    
    while (first <= mid){
        arr[index++] = temp[first++];
    }
    
    while (first2 <= last){
        arr[index++] = temp[first2++];
    }
    
}


// if i set size as a really large constant, it works. if i move cout statements, it changes output, why?????
void merge3(int arr[], int first, int mid, int last){
    int size = (last-first) + 1;        // get the size for the temp array
    cout << "size is: " << size << endl;
    int temp[size];                 // create the temporary array
    
    int first1 = first;             // beginning of first subarray
    int last1 = mid;                // end of first subarray
    int first2 = mid+1;             // beginning of second subarray
    int last2 = last;               // end of second subarray
    
    cout << "first1 = " << first1 << " last1 = " << last1 << " first2 = " << first2 << " last2 = " << last2 << endl;
    // while both subarrays are not empty, copy the
    // smaller item into the temporary array
    int index = first1;             // next available location in temp
    while ((first1 <= last1) && (first2 <= last2)){
        cout << "arr[first1] = " << arr[first1] << " arr[first2] = " << arr[first2] << endl;
        if (arr[first1] <= arr[first2]){
            temp[index] = arr[first1];
            first1++;
        }
        else{
            temp[index] = arr[first2];
            first2++;
        }
        index++;
    }
    
    // above while loop could have ended if one of the two subarrays is finished but the other is not
    // therefore, we must finish off both subarrays
    
    while (first1 <= last1){
        cout << "arr[first1] = " << arr[first1] << endl;
        cout << "first1 = " << first1 << endl;
        cout << "index = " << index << endl;
        temp[index] = arr[first1];
        cout << "temp[index] = " << temp[index] << endl;
        first1++;
        index++;
    }
    
    while (first2 <= last2){
        cout << "arr[first2] = " << arr[first2] << endl;
        cout << "first2 = " << first2 << endl;
        temp[index] = arr[first2];
        first2++;
        index++;
    }
    for(int i = first; i<=last; i++){
        cout << i << ". " << temp[i] << endl;
        arr[i] = temp[i];
    }
    
    //     copy temp back into the original array
    for (int i = first; i <= last; i++){
        //        cout << "i = " << i << endl;
        //        cout << "temp[i] = " << temp[i] << endl;
        //        //arr[i] = temp[i];
        //        cout << "temp[i] = " << temp[i] << endl;
        //        cout << "arr[i] = " << arr[i] << endl;
    }
    
}

// tested it again with vector still some issue
void merge4(int arr[], int first, int mid, int last){
    
    vector<int> temp;                 // create the temporary array
    
    int first1 = first;             // beginning of first subarray
    int last1 = mid;                // end of first subarray
    int first2 = mid+1;             // beginning of second subarray
    int last2 = last;               // end of second subarray
    
    cout << "first1 = " << first1 << " last1 = " << last1 << " first2 = " << first2 << " last2 = " << last2 << endl;
    // while both subarrays are not empty, copy the
    // smaller item into the temporary array
    int index = first1;             // next available location in temp
    while ((first1 <= last1) && (first2 <= last2)){
        cout << "arr[first1] = " << arr[first1] << " arr[first2] = " << arr[first2] << endl;
        if (arr[first1] <= arr[first2]){
            temp.push_back(arr[first1++]);
        }
        else{
            temp.push_back(arr[first2++]);
        }
        index++;
    }
    
    // above while loop could have ended if one of the two subarrays is finished but the other is not
    // therefore, we must finish off both subarrays
    
    while (first1 <= last1){
        temp.push_back(arr[first1++]);
        index++;
    }
    
    while (first2 <= last2){
        temp.push_back(arr[first2++]);
        index++;
    }
    
    //     copy temp back into the original array
    for (int i = 0; i <= last; i++){
        arr[first+i] = temp[i];
        
    }
    
}
