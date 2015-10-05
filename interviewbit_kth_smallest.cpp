int Solution::kthsmallest(const vector<int> &A, int k) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    //try to find element that has k smaller elts in array
    //naive version - O(n^2)
    
    int high = INT_MAX, low = 0;
    
    for(int i = 0; i < A.size(); i++) {
        int num_smaller = 0;
        int num_smaller_or_eq = 0;
        
        //prune to improve runtime
        if(A[i] < low || A[i] > high)
            continue;
        
        for(int j = 0; j < A.size(); j++) {
            if(i == j) continue;
            
            if(A[j] < A[i])
                num_smaller++;
            if(A[j] <= A[i])
                num_smaller_or_eq++;
            
            //if >k elts are smaller, this isn't the kth smallest
            if(num_smaller > k)
                break;
        }
        
        //update bounds for better pruning
        //if >k elts are smaller or equal to elt, the kth smallest must be >= elt+1
        if(num_smaller_or_eq < k)
            low = A[i] + 1;
        else if(num_smaller >= k)
            high = A[i] - 1;
        
        //kth smallest elt has k - 1 elts to left of it
        //need to take repeats into account
        if(num_smaller <= k - 1 && k - 1 <= num_smaller_or_eq)
            return A[i];
    }
    return -1; //couldn't find kth smallest??
}


