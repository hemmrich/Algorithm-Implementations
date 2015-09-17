// Find the largest subarray with 0 sum

#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>

using namespace std;

// function to convert int to bitstring
string convert_to_binary(int num, int length) {
    string bitstring(length, '0');

    for(int i = length - 1; i >= 0; --i) {
        if(num % 2) bitstring[i] = '1';
        else        bitstring[i] = '0';
        num /= 2;
    }

    return bitstring;
}


// naive: consider all 2^n possible subarrays
// runtime O(2^n)
void largest_subarray(vector<int>& v, int sum) {
    int num_subarrays = pow(2, v.size());
    int longest_length = v.size();
    int longest_subarray = 0;
    
    for(int i = 0; i < num_subarrays; i++) {
        string bitstring = convert_to_binary(i, longest_length);

        int subarray_sum = 0, cur_subarray = 0;
        for(int j = 0; j < bitstring.length(); j++) {
            if(bitstring[j] == '1') {
                subarray_sum += v[j];
                cur_subarray++;
            }
        }

        if(subarray_sum == sum && cur_subarray > longest_subarray)
            longest_subarray = cur_subarray;
    }

    cout << "Longest subarray is of length: " << longest_subarray << endl;
}

// if array must be contiguous:
// naive: consider all possible subarrays starting at index i
// runtime O(n^2)
void largest_subarray_2(vector<int>& v, int sum) {
    int longest_subarray = 0;
    
    for(int i = 0; i < v.size(); i++) {
        int subarray_sum = 0;

        for(int j = i; j < v.size(); j++) {
            subarray_sum += v[j];

            if(subarray_sum == sum && j - i + 1 > longest_subarray)
                longest_subarray = j - i + 1;
        }
    }

    cout << "Longest contiguous subarray is of length: " << longest_subarray << endl;
}

// if array must be contiguous:
// better: use hashing to store sums
// if we encounter a sum that's stored in the map, the sum of the
// subset between the sum's location and the current location is 0
// runtime O(n)
void largest_subarray_3(vector<int>& v, int sum) {
    unordered_map<int, int> sums;
    int cur_sum = 0, longest_subarray = 0;

    for(int i = 0; i < v.size(); i++) {
        cur_sum += v[i];

        if(longest_subarray == 0 && v[i] == 0)
            longest_subarray = 1;
        
        if(cur_sum == 0)
            longest_subarray = i + 1;

        if(sums.count(cur_sum) != 0 && 
                i - sums.at(cur_sum) > longest_subarray)
            longest_subarray = i - sums.at(cur_sum);
        else
            sums[cur_sum] = i;
    }

    cout << "Longest contiguous subarray is of length: " << longest_subarray << endl;
}


int main() {
    //vector<int> v { 1, 2, 3 }; //length = 0, contiguous = 0
    //vector<int> v { 1, 2, -1, -3 }; // {1, 2, -3}, length = 3, contig = 0
    //vector<int> v { 15, -2, 2, -8, 1, 7, 10, 23 }; //length = contig = 5
    //vector<int> v { -5, 1, 2, 3, 5 -3 }; //length = 4, contig = 0
    vector<int> v { 1, 2, 3, 4, -4, -3, -2, -1, 0, 1, -1 }; //length = contig = 11

    int sum = 0;
    
    cout << "Determining longest subarrays that add up to " << sum << endl;

    largest_subarray(v, sum);
    largest_subarray_2(v, sum);
    largest_subarray_3(v, sum);

    return 0;     
}

