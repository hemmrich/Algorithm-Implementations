/*
Given a string containing just the characters '(', ')', '{', '}', 
'[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" 
are all valid but "(]" and "([)]" are not.
*/

#include <iostream>
#include <cassert>
#include <stack>

using namespace std;

bool opening_bracket(char c) {
    return (c == '(' || c == '{' || c == '[');
}

char matching_bracket(char c) {
    if(c == ')') return '(';
    if(c == '}') return '{';
    if(c == ']') return '[';
}

bool is_valid(string s) {

    //uneven string can't be valid
    if(s.length() % 2)
        return false;

    stack<char> brackets;

    for(int i = 0; i < s.length(); i++) {
        if(opening_bracket(s[i]))
            brackets.push(s[i]);
        else {
            if(brackets.empty())
                return false;

            char top = brackets.top();
            brackets.pop();

            if(matching_bracket(s[i]) != top)
                return false;
        }
    }
    //brackets left over
    if(brackets.size())
        return false;
    return true;
}

int main() {
    assert(is_valid("()") == true);
    assert(is_valid("()[]{}") == true);
    assert(is_valid("(]") == false);
    assert(is_valid("([)]") == false);
    assert(is_valid("{{{{}}") == false);
    assert(is_valid("") == true);

    cout << "Success!" << endl;
}
