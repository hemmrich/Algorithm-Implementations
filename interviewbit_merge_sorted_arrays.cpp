#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> result(A.size() + B.size());
    
    int longest = (A.size() > B.size()) ? A.size() : B.size();

    //at each i, choose the smallest of the smallest elts in the arrays 
    //that haven't been merged yet
    int index_A = 0, index_B = 0;
    for(int i = 0; i < A.size() + B.size(); i++) {
        //A is done, fill rest of B into result
        while(index_A >= A.size() && index_B < B.size()) {
            cout << "A empty, merging B[" << index_B << "]" << endl;
            result[i++] = B[index_B++];
        }
        
        //B is done, fill rest of A into result
        while(index_B >= B.size() && index_A < A.size()) {
            cout << "B empty, merging A[" << index_A << "]" << endl;
            result[i++] = A[index_A++];
        }

        if(index_A >= A.size() && index_B >= B.size()) {
            A = result;
            return;
        }

        //else, take smallest of A[index_A] and B[index_B]
        if(A[index_A] < B[index_B]) {
            cout << "A < B, merging " << A[index_A] << endl;
            result[i] = A[index_A++];
        }
        else {
            cout << "A >= B, merging " << B[index_B] << endl;
            result[i] = B[index_B++];
        }
    }
    
    A = result;
}

int main() {
    //vector<int> v1 {0, 2, 4};
    //vector<int> v2 {1, 3, 5};

    vector<int> v1 {-4, 3};
    vector<int> v2 {-2, -2};


    merge(v1, v2);

    for(int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";
    cout << endl;
}
