// Write a method to replace all spaces in a string with'%20'. 
// You may assume that the string has sufficient space at the end of the string to hold the additional characters, and that you are given the "true" length of the string.
//(Note: if implementing in Java, please use a character array so that you can perform this opera- tion in place.)
//

#include <iostream>
using namespace std;


void replace_spaces(string& input) {
    string encoded = "";

    for(int i = 0; i < input.length(); i++) {
        if(input[i] == ' ')
            encoded += "%20";
        else
            encoded += input[i];
    }

    input = encoded;
}



int main() {
    string test = " this is a string      ";

    cout << "original: " << test << endl;
    replace_spaces(test);
    cout << "replaced: " << test << endl;
}
