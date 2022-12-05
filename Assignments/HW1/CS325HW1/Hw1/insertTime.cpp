#include <iostream>
#include <fstream>
#include <cstdlib>
#include <chrono>

using namespace std;

void insertionSort(int arr[], int size){
    int i, j, key; // set index and key variables
     for(i = 1; i < size; i++){ // start from the 2nd index to n-1 index
        key = arr[i]; // set the key as a starting index
        for(j = i-1; j >= 0 && key < arr[j]; j--){ // compare and swap the value
            arr[j+1] = arr[j];
        }
        arr[j+1] = key; // now go to the next index
    }
}

int main(){
    
    int size = 10000;
    int index = 0;
    
    cout << "N" << '\t' << "Average Time(seconds)" << endl;
    while(index != 10){
        
        int arr[size];
        double avg = 0;
        for(int n = 0; n < 10;n++){ // run insertion sort for 10 times. 
            srand(time(NULL));
            for(int i = 0; i < size; i++){
               arr[i] = rand()%(size+1); // generate random numbers between 0 and size(i.e.10000, 20000, etc.); average case
                //arr[i] = size - i; // worst case - in descending order; O(n^2)
                //arr[i] = i; // best case - in ascending order; O(n)
            }   

            //start measuring execution time of sorting function.
            auto start = chrono::high_resolution_clock::now();
            insertionSort(arr, size);
            auto end = chrono::high_resolution_clock::now();

            //The execution time of sorting funciton
            chrono::duration<double> period = end - start; 
            avg += period.count(); // collects each running time. 
        }
        cout << size  <<'\t' <<avg/10<< endl;
        index++;
        size += 10000; //increment size by 10000
    }

}
