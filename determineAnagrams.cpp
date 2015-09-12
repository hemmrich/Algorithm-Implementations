//use hashmap - sort each word and use it as a hash key
//if there is a collision, then the word is an anagram of the original




#include <iostream>
#include <cstdlib>
using namespace std;

const int NUM_ASCII_CHARS = 256;

void swap(string& s, int i, int j) {
    char tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
}
void quicksort(string& s, int left, int right) {
 
    int pivotIndex = (left + right) / 2;
    char pivotChar = s[pivotIndex];
    
    int i = left;
    int j = right;
    while(!(i > j)) {
        while((int)s[i] < (int)pivotChar)
            i++;
        while((int)s[j] > (int)pivotChar) 
            j--;
        if(i <= j) {
            swap(s, i, j);
            i++;
            j--;
        }
    }
    if(left < j)
        quicksort(s, left, j);
    if(right > i)
        quicksort(s, i, right);
}

//uses quicksort to sort strings and then compare, runtime O(n^2) (average runtime O(nlogn))
bool areAnagramsSorting(string& s1, string& s2) {
    //sort both strings using quicksort
    quicksort(s1, 0, s1.length() - 1);
    quicksort(s2, 0, s2.length() - 1);
    
    if(s1 == s2)
        return true;
    else
        return false;
}

//uses arrays to store counts, runtime O(n)
bool areAnagramsArrays(string& s1, string& s2) {
    //use arrays to keep track of character counts (256 different ASCII characters)
    int string1[NUM_ASCII_CHARS] = {0};
    int string2[NUM_ASCII_CHARS] = {0};
    
    //if strings not the same length, they're not anagrams (checked in main)
    for(int i = 0; i < s1.length(); i++) {
        string1[(int)s1[i]]++;
        string2[(int)s2[i]]++;
    }
    
    for(int i = 0; i < NUM_ASCII_CHARS; i++)
        if(string1[i] != string2[i])
            return false;
    return true;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    string s1 = "", s2 = "";
    getline(cin, s1);
    getline(cin, s2);
    
    if(s1.length() != s2.length()) {
        cout << "Not anagrams!" << endl;
        return 0;
    }
    
    /*if(areAnagramsSorting)
        cout << "Anagrams!" << endl;
    else
        cout << "Not anagrams!" << endl;*/
    
    if(areAnagramsArrays)
        cout << "Anagrams!" << endl;
    else
        cout << "Not anagrams!" << endl;
    
    
    return 0;
}