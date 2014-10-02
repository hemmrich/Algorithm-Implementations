#include <iostream>
#include "bubbleSort.h"
#include "selectionSort.h"
#include "utility.h"

using namespace std;

int main() {
    int array[] = { 5, 3, 4, 1, 9, 2, 7, 6, 10, 8, 0 };
    //int array[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(array)/sizeof(*array);

    printArray(array, size);
    bubbleSort(array, size);
    
}
