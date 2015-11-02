/*  Given a nested list of integers, return the sum of all
 *  integers in the list weighted by their depth.
 *
 *  Example: Given {{1,1},2,{1,1}}, return 10
 *  (four 1s at depth 2 + one 2 at depth 1)
 */


#include <iostream>
#include <vector>

using namespace std;

int char_to_int(char c) {
    return c - '0';
}

int list_sum(string input) {
    
    int depth = 0, sum = 0, cur_val = 0;

    for(int i = 0; i < input.length(); i++) {
        //if at end of int (either , or })
        if(input[i] == ',' || input[i] == '}') {
            //add to total
            sum += cur_val * depth;
            cur_val = 0;
        }
    
        //update depth if at brace
        if(input[i] == '{') 
            depth++;
        else if(input[i] == '}')
            depth--;
        else if(input[i] == ',')
            continue;
       
        //if we're looking at an int
        else {
            int tmp = char_to_int(input[i]);
            cur_val *= 10; //shift number
            cur_val += tmp;
        }
    }

    return sum;
}


int main() {
   
    //assume input is well formed
    vector<pair<string, int>> inputs;

    inputs.push_back({"{{1,1},2,{1,1}}", 10});
    inputs.push_back({"{{1,1},2,{1,1}}", 10});
    inputs.push_back({"{1,2,3,4,5}", 15});
    inputs.push_back({"{{{{{1}}}}}", 5});
    inputs.push_back({"{}", 0}); 
    inputs.push_back({"{1,{2,{3,{4,{5}}}}}", 55});
   

    for(int i = 0; i < inputs.size(); i++) {
        int sum = list_sum(inputs[i].first);
        
        if(sum == inputs[i].second)
            cout << "CORRECT: sum of " << inputs[i].first << " is " << sum << endl;
        else
            cout << "WRONG: sum of " << inputs[i].first << " should be " << inputs[i].second << " (function returned " << sum << ")" << endl;
        
        

    }

    
    
}

