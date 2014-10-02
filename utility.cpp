#include <iostream>

using namespace std;

void swap(int* array, int j, int k) {
    int tmp = array[j];
    array[j] = array[k];
    array[k] = tmp;
}

void printArray(int* array, int size, bool verbose) {
    if(!verbose)
        return;
    for(int i = 0; i < size; i++) 
        cout << array[i] << " ";
    cout << endl;
}


void printFinalArray(int* array, int size) {
    cout << "FINAL ORDER:" << endl;
    printArray(array, size, true);
    cout << endl;
}

void copyArray(int* array, int* arrayCopy, int size) {
    for(int i = 0; i < size; i++)
        arrayCopy[i] = array[i];
}
