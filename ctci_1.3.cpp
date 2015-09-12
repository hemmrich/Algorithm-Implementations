// Given two strings, write a method to decide if one is a permutation of the other.

#include <iostream>
#include <unordered_map>

using namespace std;

// Store counts of each character in a hash table
// Runtime O(n)
void check_permutation(string str1, string str2) {

  if(str1.length() != str2.length()) {
    cout << "Not a permutation" << endl;
    return;
  }

  unordered_map<char, int> str1_counter;
  unordered_map<char, int> str2_counter;

  for(int i = 0; i < str1.length(); i++)
    str1_counter[str1[i]]++;

  for(int i = 0; i < str2.length(); i++)
    str2_counter[str2[i]]++;

  for(auto it = str1_counter.begin(); it != str1_counter.end(); it++) {
    // it->first = key, it->second = value
    if(it->second != str2_counter[it->first]) {
      cout << "Not a permutation" << endl;
      return;
    }
  }
  cout << "Permutation!" << endl;
}

int main() {
  string str1 = "thisisastring";
  string str2 = "thisstringisa";

  check_permutation(str1, str2);
}