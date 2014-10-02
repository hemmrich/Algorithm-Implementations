#include <iostream>
#include "utility.h"

using namespace std;

void selectionSort(int* array, int size, bool verbose) {
    int minVal = numeric_limits<int>::max();
    int minIndex = 0;

    for(int i = 0; i < size; i++) {
        minVal = numeric_limits<int>::max();
        minIndex = 0;
        
        for(int j = i; j < size; j++) {
            if(array[j] < minVal) {
                minVal = array[j];
                minIndex = j;
            }
        }
        swap(array, i, minIndex);
        printArray(array, size, verbose);
    }
    printFinalArray(array, size);
}
