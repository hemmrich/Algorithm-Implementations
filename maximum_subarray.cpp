// Find the maximum subsequence sum of an array of integers which contains both
// positive and negative numbers and return the starting and ending indices within 
// the array. 

//For example: 
//int array[] = {1, -2, -3, 4, 5, 7, -6} 
//The max subsquence sum is 4 + 5 + 7 = 16, start index = 3, end index = 5


#include <iostream>

using namespace std;


// O(n) solution - use Kadane's algorithm
// Loop through array, compute max (+ sum) subarray ending at that position
//  -Subarray is either empty (sum = 0) or
//  -Consists of 1+ elements than last max subarray ending at prev position
void max_subsequence_sum(int array[], int size) {

    int max_ending_here = 0, overall_max = 0;
    int start = 0, end = 0;


    for(int i = 0; i < size; i++) {
        // without start/end indices:
        //max_ending_here = max(0, max_ending_here + array[i]);
        //overall_max = max(overall_max, max_ending_here);
    
        // with start/end:
        if(max_ending_here + array[i] >= 0)
            max_ending_here += array[i];
        else {
            max_ending_here = 0;
            start = i + 1; //start sequences at next index
        }

        // >= because end needs to be updated if =
        if(max_ending_here >= overall_max) {
            overall_max = max_ending_here;
            end = i;
        }
    
    }

    cout << "max = " << overall_max << endl;
    cout << "start = " << start << endl;
    cout << "end = " << end << endl << endl;
}





int main() {

    int array[] = {1, -2, -3, 4, 5, 7, -6};
    int size = sizeof(array)/sizeof(array[0]);
    
    //should be max = 16, start = 3, end = 5
    max_subsequence_sum(array, size);


    int array2[] = {1, 2, 3, 4, 5, 6, 7, -50, -21, 14, -12, 33};
    size = sizeof(array2)/sizeof(array2[0]);

    //should be max = 35, start = 9, end = 11
    max_subsequence_sum(array2, size);


    int array3[] = {1, 2, 3, 4, 5, 6, 7, -50, -21, 14, -15, 33};
    size = sizeof(array3)/sizeof(array3[0]);

    //should be max = 33, start = 11, end = 11
    max_subsequence_sum(array3, size);

    int array4[] = {1, 2, 3, 4, 5, 6, 7, -50, -21, 12, -12, 33};
    size = sizeof(array4)/sizeof(array4[0]);

    //should be max = 33, start = 9, end = 11
    max_subsequence_sum(array4, size);

}
