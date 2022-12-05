#include <iostream>
#include <chrono>
#include <fstream>


using namespace std;

void insertionSort(int arr[], int size){
    int i, j, key;
     for(i = 1; i < size; i++){
        key = arr[i];
        for(j = i-1; j >= 0 && key < arr[j]; j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = key;
    }
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
        insertionSort(arr, size);
        for(int i = 0; i < size;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    file.close();
     
}
