#include <iostream>
#include <vector>

using namespace std;

vector<string> letters = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void keypad_problem(string digits, int index, string str, vector<string>& result) {
    if(index >= digits.length()) {
        result.push_back(str);
        return;
    }

    string current_combo = letters[index];
    for(int i = 0; i < current_combo.size(); i++) {
        str += current_combo[i];
        keypad_problem(digits, index + 1, str, result);
        str.pop_back();

    }

}


int main() {
    string digits = "234";
    
    vector<string> result;
    
    string str;

    keypad_problem(digits, 0, str, result); 

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
}
