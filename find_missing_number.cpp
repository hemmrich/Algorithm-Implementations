// An array of size n has all but one of the numbers between 1 and n+1
// find the missing number


#include <iostream>

using namespace std;

// Calculate expected sum and subtract each element from it
// Runtime O(n)
void find_missing_num(int* arr, int size) {
    // sum of numbers 1 though n is n(n+1)/2
    int expected_sum = ((size + 1) * (size + 2)) / 2;

    for(int i = 0; i < size; i++) 
        expected_sum -= arr[i];

    cout << "missing number is " << expected_sum << endl;
}



int main() {
    int arr[] = { 2, 1, 6, 4, 3 }; //size = 5, missing 5 
    
    find_missing_num(arr, sizeof(arr)/sizeof(arr[0]));
}
