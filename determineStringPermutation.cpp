#include <iostream>
#include <unordered_map>

using namespace std;

void swap(string& str, int i, int j) {
    char tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
}

void quicksort(string& input, int lower, int upper) {
   if(upper - lower < 2) //if 0 or 1 elt, already sorted
      return;

   //Step 1 - choose pivot (use middle of string)
   int pivot = (upper - lower)/ 2;

   //Step 2 - partition string into two sections
   int i = lower, j = upper;
   while(i < j) {
      while(input[i] < input[pivot])
         i++;
      while(input[j] > input[pivot])
         j--;
      if(i < j) {
         swap(input, i, j);
         i++; j--;
      }
   }

   //Step 3 - recursively sort two halves
   quicksort(input, lower, i);
   quicksort(input, upper, j);
}


//quicksort - uses O(nlogn) to sort array and O(n) to compare sorted ==> O(nlogn)
bool isPermutationSort(string s1, string s2) {
   if(s1.size() != s2.size()) //can't have same letters if different size
      return false;

   quicksort(s1, 0, s1.size() - 1);
   quicksort(s2, 0, s2.size() - 1);

   for(int i = 0; i < s2.size(); i++)
      if(s1[i] != s2[i])
         return false;

   return true;
}

//hashtable - uses 2*O(n) to linearly traverse strings ==> O(n)
bool isPermutationHash(string s1, string s2) {
   if(s1.size() != s2.size()) //can't have same letters if different length
      return false;

   unordered_map<char, int> map; //map char to number of occurrences
   for(int i = 0; i < s1.size(); i++) 
      map[s1[i]] += 1; //default val is 0

   for(int i = 0; i < s2.size(); i++) {
      map[s2[i]] -= 1;
      if(map[s2[i]] < 0) //first string had fewer of this character -> not permutation
         return false;
   }

   return true;
}





int main() {
   //string s1 = "this is definitely not a permutation";
   //string s2 = "of this string, which is completely different";

   //string s1 = "however, this is going to be a string that will be tested with a permutation.";
   //string s2 = ".permutation a with tested be will that string a be to going is this ,however";

   string s1 = "213";
   string s2 = "321";

   if(isPermutationSort(s1, s2))
      cout << "IS PERMUTATION (SORT)!" << endl;
   else
      cout << "Not a permutation (sort)" << endl;

   if(isPermutationHash(s1, s2))
      cout << "IS PERMUTATION (HASH)!" << endl;
   else
      cout << "Not a permutation (hash)" << endl;
}