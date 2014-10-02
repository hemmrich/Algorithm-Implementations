#include <iostream>

using namespace std;

void swap(int* array, int j, int k) {
    int tmp = array[j];
    array[j] = array[k];
    array[k] = tmp;
}

void printArray(int* array, int size) {
    for(int i = 0; i < size; i++) 
        cout << array[i] << " ";
    cout << endl;
}
