// reverse the words in a c-string, while preserving the locations of the spaces
// for example, "this is a test" would become "siht si a tset"

#include <iostream>
#include <string>

using namespace std;

void reverse(char* start, char* end) {
    while(start < end) {
        char tmp = *start;
        *start = *end;
        *end = tmp;

        start++;
        end--;
    }
}

void reverse_words(char* str) {
    char* follower = str;
    char* leader = str;

    //while in bounds of string
    while(*leader) {
        leader++;
        
        //word boundary, don't want to move the space
        if(*leader == ' ') {
            reverse(follower, leader - 1);
            follower = leader + 1;
        }
        //end of string, don't want to move the \0 character
        if(*leader == '\0')
            reverse(follower, leader - 1);
    }
}



int main() {
    string str = "this is a test";
    //string str = "";
    //string str = "test";

    cout << "original string: " << str << endl;

    //need to cast to non-const char*
    char* cstr = const_cast<char*>(str.c_str());    
    reverse_words(cstr);

    cout << "reversed words: " << cstr << endl;
}
