// Implement a method to perform basic string compression using the counts of repeated characters. 
// For example, the string aabcccccaaa would become a2b1c5a3. 
// If the "compressed" string would not become smaller than the original string, your method should return the original string.

#include <iostream>

using namespace std;

string basic_compression(string str) {

  // this compression doesn't work for strings of length 0, 1, or 2
  if(str.length() < 3)
    return str;


  string new_str;

  char cur_char = str[0];
  int cur_counter = 1;

  for(int i = 1; i < str.length(); i++) {
    if(str[i] == cur_char) {
      cur_counter++;
      continue;
    }

    // new character - write last character to new string and reset counter
    new_str += cur_char;
    new_str += to_string(cur_counter);

    cur_char = str[i];
    cur_counter = 1;
  }

  // need to write last character to new string
  new_str += cur_char;
  new_str += to_string(cur_counter);

  return (str.length() <= new_str.length()) ? str : new_str;
}


int main() {

  string str = "aabcccccaaa";
  // string str = "abcdefg";
  // string str = "";

  cout << "Original string: " << str << endl;
  str = basic_compression(str);
  cout << "String is now: " << str << endl;

  return 0;
}