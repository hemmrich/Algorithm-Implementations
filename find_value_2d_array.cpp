//find a value in a 2d array where both the rows and columns
//are increasing monotonically

#include <iostream>

using namespace std;

const int size = 5;


void find_element(int arr[][size], int element, int row, int col) {
    cout << "arr[" << row << "][" << col << "] = " << arr[row][col] << endl;
    
    int cur_val = arr[row][col];

    if(cur_val == element) {
        cout << "Found element!" << endl;
        exit(1);
    }

    //if cur_val < element, move right (values increase to right)
    else if(cur_val < element) {
        cout << "cur_val < element, moving right" << endl;
        return find_element(arr, element, row, col + 1);
    }
    
    //if cur_val > element, move up (values decrease upwards)
    else {
        cout << "cur_val > element, moving up" << endl;
        return find_element(arr, element, row - 1, col);
    }
}


int main() {
    
    int arr[][size] = {
                { 1, 4, 7, 11, 15 },
                { 2, 5, 8, 12, 19 },
                { 3, 6, 9, 16, 22 },
                { 10, 13, 14, 17, 24},
                { 18, 21, 23, 26, 30}
              };

    int element = 22;
    
    //start searching in bottom left of array
    find_element(arr, element, size - 1, 0); 
}
