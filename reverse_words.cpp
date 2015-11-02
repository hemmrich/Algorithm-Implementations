#include <iostream>

using namespace std;

void reverse_word(char* begin, char* end) {
   while(begin < end) {
      char tmp = *begin;
      *begin++ = *end;
      *end-- = tmp;
   }
}

void reverse_words(char* str) {
   char* word_begin = str;
   char* tmp = str;

   while(tmp) {
      if(*tmp == '\0') {
         reverse_word(word_begin, tmp - 1);
         return;
      }

      if(*tmp == ' ') {
         reverse_word(word_begin, tmp - 1);
         word_begin = tmp + 1;
      }
      tmp++;
   }
}


int main() {
   char str[] = "this should be reversed";
   cout << "Original string: " << str << endl;
   reverse_words(str);   
   cout << "Reversed string: " << str << endl;
}
