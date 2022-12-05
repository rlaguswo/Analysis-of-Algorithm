#include <iostream>
#include <cstdlib>
#include <chrono>
#include <vector>

using namespace std;

void merge(int arr[], int start, int mid, int end){
    int leftSize = mid - start + 1; // ex) 0 1(mid) 2 3 -> mid = (int)3/2 = 1, size [0, 1]= 2 = 1(mid)-0(start)+1
    int rightSize = end - mid; // ex)0 1(mid) 2 3(end) -> size [2, 3] = 2 = 3(end) - 1(mid)

    // make left and right subarrays
    int leftArr[leftSize];
    int rightArr[rightSize];

    //fill the subarrays
    for(int i = 0; i < leftSize; i++){
        leftArr[i] = arr[start + i];
    }
    for(int j = 0; j < rightSize; j++){
        rightArr[j] = arr[j + mid+1];
    }

    // Now sorting the elements of subarrays
    int leftIndex = 0, rightIndex = 0, mergeIndex = start;

    while(leftIndex != leftSize && rightIndex != rightSize){
        if(leftArr[leftIndex] <= rightArr[rightIndex]){
            arr[mergeIndex] = leftArr[leftIndex];
            leftIndex++;
        }
        else{
            arr[mergeIndex] = rightArr[rightIndex];
            rightIndex++;
        }
        mergeIndex++;
    }

    // If left array has elements after the preivous step (when the size of array is odd)
    for(int i = leftIndex; i < leftSize;i++){
        arr[mergeIndex] = leftArr[i];
        mergeIndex++;
    }
    
    // If right array has elements after the preivous step (when the size of array is odd)
    for(int j = rightIndex; j < rightSize;j++){
        arr[mergeIndex] = rightArr[j];
        mergeIndex++;
    }

}

void mergeSort(int arr[], int start, int end){
    //base case: when it is only one cell in the array
    if(start >= end){
        return;
    }
    
    //Divide

        int mid = (start + end)/2;

        //recurrsive divide the array into half
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        // merge and sort the divided array 
        merge(arr, start, mid, end);
    

}


int main(){
     
    int size = 10000, index = 0;
    
    cout << "N" << '\t' << "Average Time(seconds)" << endl;
    while(index != 10){
        int arr[size];
        double avg = 0;
        for(int n = 0; n < 10; n++){ // run merge sort for 10 times.
            srand(time(NULL));
            for(int i = 0; i < size; i++){
                arr[i] = rand()%(size+1); // randomly generate the numbers between 0 and size(i.e. 50000, 100000, 150000, etc.); average case
                //arr[i] = size - i; // worst case - in descending order; Still have same time complexity as average case
                //arr[i] = i; // best case - in ascending order; Still have same time complexity as average case
            }
            
            //start measuring execution time of sorting function. 
            auto start = chrono::high_resolution_clock::now();
            mergeSort(arr, 0, size-1);
            auto end = chrono::high_resolution_clock::now();

            //The execution time of the sorting function
            chrono::duration<double> period = end - start;
            avg += period.count(); // collects the each running time. 
        } 
        cout << size  <<'\t' << avg/10 << endl;
        index++;
        size += 10000; // increment size by 10000
    }

}
