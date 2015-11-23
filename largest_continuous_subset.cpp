#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


vector<int> largest_subset(const vector<int>& input) {
    if(input.empty()) 
        return {};

    int max_subset_start = 0, max_subset_end = 0;
    int max_subset_val = -INT_MAX;
    
    int cur_subset_start = 0;
    int cur_subset_val = input[0];

    for(int i = 1; i < input.size(); i++) {
        //take the max of current elt and current elt + cur sum
        if(cur_subset_val + input[i] >= input[i]) {
            cur_subset_val += input[i];
        }
        
        //if cur_elt > cur_sum + cur_elt, start over
        else {
            cur_subset_val = input[i];
            cur_subset_start = i;
        }

        //update max if needed
        if(cur_subset_val > max_subset_val) {
            max_subset_val = cur_subset_val;
            max_subset_start = cur_subset_start;
            max_subset_end = i;
        }
    }
    
    vector<int> ret;
    for(int i = max_subset_start; i <= max_subset_end; i++)
        ret.push_back(input[i]);
    return ret;
}


int main() {
    
    vector<int> ret_vec, sol_vec;
    
    ret_vec = largest_subset({0,1,2,3,4,5});
    sol_vec = {0,1,2,3,4,5};
    assert(ret_vec == sol_vec);

    ret_vec = largest_subset({0,-1,2,3,4,-5});
    sol_vec = {2,3,4};
    assert(ret_vec == sol_vec);

    ret_vec = largest_subset({});
    sol_vec = {};
    assert(ret_vec == sol_vec);

    ret_vec = largest_subset({-3, -2, -1, -4, -5});
    sol_vec = {-1};
    assert(ret_vec == sol_vec);

    ret_vec = largest_subset({5, 4, 2, -1, 11, 1, -5});
    sol_vec = {5, 4, 2, -1, 11, 1};
    assert(ret_vec == sol_vec);

    ret_vec = largest_subset({1, 2, 3, 4, -25, 9, -1, 3, -1});
    sol_vec = {9, -1, 3};
    assert(ret_vec == sol_vec);

    cout << "Tests succeeded!" << endl;   

}




