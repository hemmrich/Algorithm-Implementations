#include "utility.h"

void quickSort(int* array, int left, int right, int size, bool verbose) {
    //Step 1: Find pivot of array (naively use middle of array)
	int pivotIndex = (left + right) / 2;	
    int pivotVal = array[pivotIndex];

    //Step 2: Partition array
    int i = left;
    int j = right;
    while(!(i > j)) {
        while(array[i] < pivotVal)
            i++;
        while(array[j] > pivotVal)
            j--;
        if(i <= j) { //swap elements so that smaller is on left of pivot, larger on right
            swap(array, i, j);
            printArray(array, size, verbose);
            i++; //advance i and j to next location
            j--;
        }
    }

    //Step 3: Recursively sort subarrays
    if(left < j)
        quickSort(array, left, j, size, verbose);
    if(right > i)
        quickSort(array, i, right, size, verbose);
}
