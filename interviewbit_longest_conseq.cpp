/*
   Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Example: 
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list> //for testing

using namespace std;


//int Solution::longestConsecutive(const vector<int> &A) {
int longestConsecutive(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(A.size() < 2) return A.size();

    unordered_map<int, bool> num_present;

    for(int i = 0; i < A.size(); i++)
        num_present[A[i]] = true;

    int max_length = 1;

    list<int> current, longest;

    for(auto it = num_present.begin(); it != num_present.end(); it++) {
        int prev = it->first - 1;
        int next = it->first + 1;
        int cur_length = 1;
        current.push_back(it->first);

        while(num_present.count(prev)) {
            cur_length++;
            current.push_front(prev);
            num_present.erase(prev);
            prev--;
        }

        while(num_present.count(next)) {
            cur_length++;
            current.push_back(next);
            num_present.erase(next);
            next++;
        }

        if(cur_length > max_length) {
            max_length = cur_length;
            longest = current;
        }
        current.clear();
    }    

    for(auto it = longest.begin(); it != longest.end(); it++)
        cout << *it << " ";
    cout << endl;

    return max_length;


    /*
    TECHNICALLY INCORRECT COMPLEXITY: O(N) where N = largest_elt - smallest_elt
    //find largest and smallest elements
    //can store all values in hashmap in same loop

    int smallest_value = INT_MAX, largest_value = -INT_MAX;

    for(int i = 0; i < A.size(); i++) {
        if(A[i] < smallest_value)
        smallest_value = A[i];
        if(A[i] > largest_value)
        largest_value = A[i];
        num_present[A[i]] = true;
    }

    //iterate through from smallest -> largest and find longest seq
    int longest_seq = 1, current_seq = 0;

    for(int i = smallest_value; i <= largest_value; i++) {
        if(num_present[i] && num_present[i - 1])
            current_seq++;
        else {
            if(current_seq > longest_seq)
                longest_seq = current_seq;
            current_seq = 1;
        }
    }
    return current_seq > longest_seq ? current_seq : longest_seq;
    */
}


int main() {

    vector<int> v {8, 105, -1, 65, 95, 41, 36, 54, 50, 78, 102, 61, 83, 119, 48, 12, 20, 47, 85, 14, 53, 31, 5, 23, 107, 96, 40, 18, 100};

    int longest = longestConsecutive(v);

    cout << "longest = " << longest << endl;
}




