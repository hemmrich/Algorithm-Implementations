// Implement a function void reverse(char* str) which reverses a 
// null-terminated string

#include <iostream>

using namespace std;


// Better solution - do an in-place switching of characters from front and back
// Runtime O(n), Space requirement O(1)
void reverse(char* str) {
  // length doesn't include null at end
  int length = strlen(str);
  int midpoint = length / 2; // works for odds, we don't need to swap middle

  for(int i = 0; i < midpoint; i++) {
    char tmp = str[i];
    str[i] = str[length - 1 - i];
    str[length - 1 - i] = tmp;
  }
}


// Naive/bad solution - create new C string and copy reverse of original into it
// Runtime O(n), Space requirement O(n)
// This doesn't work - pointer isn't updated to point to reversed string!
// void reverse(char* str) {

//   // length doesn't include the null character at the end
//   int length = strlen(str);
//   char reversed[length + 1];

//   for(int i = 0; i < length; i++) {
//     reversed[i] = str[length - 1 - i];
//   }
//   reversed[length] = '\0';
//   str = reversed;
// }


int main() {
  // char str[] = "thisisastring\0";
  // char str[] = "";
  // char str[] = "a";
  char str[] = "this is of even length";

  cout << "Original: " << str << endl;
  reverse(str);
  cout << "Reversed: " << str << endl;
  return 0;
}