#include "utility.h"

//Slightly optimized bubble sort - stop once no more improvements can be made
void bubbleSort(int* array, int size) {
    bool unordered = true;
    while(unordered) {
        unordered = false;
        for(int j = 0; j < size - 1; j++) {
            if(array[j] > array[j + 1]) {
                swap(array, j, j + 1);
                unordered = true;
                printArray(array, size);
            }
        }
    }
}
