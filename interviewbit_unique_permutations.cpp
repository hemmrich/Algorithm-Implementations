void permutation_helper(vector<int>&, set<vector<int>>&, vector<int>&, 
                        unordered_map<int, bool>&);


vector<vector<int> > Solution::permute(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    // remember if a particular value in A has been used or not
    unordered_map<int, bool> used; 
    
    set<vector<int>> sol_set; 
    vector<int> current;
    
    permutation_helper(A, sol_set, current, used);
    
    vector<vector<int>> sol(sol_set.begin(), sol_set.end()); 
    
    return sol;
}


void permutation_helper(vector<int>& v, set<vector<int>>& sol, vector<int>& current, 
                        unordered_map<int, bool>& used) { 
    
    //generated one permutation
    if(current.size() == v.size()) {
        sol.insert(current);
        return;
    }
    
    for(int i = 0; i < v.size(); i++) {
        
        //if value hasn't been used yet
        if(!used[i]) {
        
            current.push_back(v[i]);
            used[i] = true;
            
            permutation_helper(v, sol, current, used);
            
            current.pop_back();
            used[i] = false;
        }
    }    
}

