#include <iostream>
#include <chrono>
#include <fstream>


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
    //base case: when it is only one cell in the array, 
    //and solve the problem occours when start = 1 and end = 0.
    if(start >= end){
        return;
    }
    
    //Divide

        int mid = (start + end)/2;

        //recurrsive- has to be post order
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, mid, end);
    

}


int main(){
    ifstream file("data.txt", ios::in);
    while(!file.eof()){
        int size;
        file >> size;
        int arr[size];
        for(int i = 0; i < size;i++){
            file >> arr[i];
        }
        mergeSort(arr, 0, size-1);
        for(int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    file.close();
}
