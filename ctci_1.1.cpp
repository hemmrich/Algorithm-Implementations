// Implement an algorithm to determine if a string has all unique characters. 
// What if you cannot use additional data structures?

// use hash tables (char -> int counter), if counter > 1, return false
// search for(int i = index; i < str.length(); i++) for same character

#include <iostream>
#include <unordered_map>

using namespace std;

// Without additional data structures - check rest of string for duplicate, O(n^2) runtime
bool check_unique(string s) {
  // Base case - if 0 or 1 characters are present, they're unique
  if(s.length() < 2)
    return true;

  for(int i = 0; i < s.length() - 1; i++) {
    for(int j = i + 1; j < s.length(); j++) {
      if(s[i] == s[j])
        return false;
    }
  }
  return true;
}

// Best solution - use hash table, O(n) runtime
bool check_unique_2(string s) {
  unordered_map<char, int> counts;

  for(char c : s) 
    if(++counts[c] > 1)
      return false;
  return true;
}

int main() {
  // string s = "ashfklsjljfjaskljf13";
  // string s = "asdfghjkl09876";
  // string s = "aa";
  string s = "";

  cout << "string '" << s << "' is ";
  if (check_unique(s))
    cout << "unique!" << endl;
  else
    cout << "not unique" << endl;
  return 0;
}