#include <iostream>
#include <vector>

using namespace std;


void find_target_range(const vector<int>& A, vector<int>& sol, int start, int end, int target) {
    int begin = start;
    while(begin - 1 >= 0 && A[start] == A[begin - 1])
        begin--;
            
    sol.push_back(begin);
        
    int finish = end;
    while(finish + 1 < A.size() && A[start] == A[finish + 1])
        finish++;
            
    sol.push_back(finish);
}

void binary_search(const vector<int>& A, vector<int>& sol, int start, int end, int target) {
    
    if(start > end) {
        sol.push_back(-1);
        sol.push_back(-1);
        return;
    }
    
    //runtime improvement - if A[start] -> A[end] contains only target,
    //use start and end as starting boundaries for range search
    if(A[start] == target && A[end] == target) {
        find_target_range(A, sol, start, end, target);
        return;
    }
    
    int midpoint = (start + end) / 2;

    // found target - need to find start & end
    if(target == A[midpoint]) {
        find_target_range(A, sol, midpoint, midpoint, target);
        return;
    }
        
    if(target < A[midpoint]) {
        binary_search(A, sol, start, midpoint - 1, target);
    }
    if(target > A[midpoint]) {
        binary_search(A, sol, midpoint + 1, end, target);
    }
}

vector<int> searchRange(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> sol;
    
    binary_search(A, sol, 0, A.size() - 1, B);
    
    return sol;
}

int main() {

    vector<int> v {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    
    int B = 10;

    vector<int> sol = searchRange(v, B);
    for(int i = 0; i < sol.size(); i++)
        cout << sol[i] << " ";
    cout << endl;

    if(sol[0] == 118 && sol[1] == 133)
        cout << "CORRECT" << endl;
    else
        cout << "Not right :(" << endl;
}



