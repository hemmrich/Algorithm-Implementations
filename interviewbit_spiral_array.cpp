#include <iostream>
#include <vector>

using namespace std;


void print_vec(vector<vector<int>>& v) {
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v.size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


void spiral_fill(vector<vector<int>>& v, int val, int xy_start, int xy_end) {

    cout << "spiral_fill with " << val << ", " << xy_start << ", " << xy_end << endl;

    if(!val) return;

    //fill top and bottom rows
    for(int i = xy_start; i <= xy_end; i++) {
        v[xy_start][i] = val;
        v[xy_end][i] = val;
    }

    //fill left and right columns
    for(int i = xy_start; i <= xy_end; i++) {
        v[i][xy_start] = val;
        v[i][xy_end] = val;
    }

    print_vec(v);

    spiral_fill(v, val - 1, xy_start + 1, xy_end - 1);
}



vector<vector<int>> prettyPrint(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int size = 2 * A - 1;

    vector<vector<int>> v(size, vector<int>(size, A));

    spiral_fill(v, A, 0, size - 1);

    return v;
}


int main() {
    
    vector<vector<int>> sol = prettyPrint(4);

}
