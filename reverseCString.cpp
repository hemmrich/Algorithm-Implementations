#include <iostream>

using namespace std;


void swap(char* a, char* b) {
   char tmp = *a;
   *a = *b;
   *b = tmp;
}



void reverse(char* string) {
   char* oldStart = string; //save starting point of old string
   int endIndex;
   for(endIndex = 0; ;endIndex++) {
      if(string[endIndex] == '\0')
         break;
   }

   char* oldEnd = &string[endIndex - 1];

   while(oldEnd > oldStart) {
      char tmp = *oldEnd;
      *oldEnd = *oldStart;
      *oldStart = tmp;

      oldEnd--; oldStart++;
   }
}




int main() {
   char string[] = "this is a test"; //char* is a string literal; use char array instead

   for(int i = 0; ; i++) {
      if(string[i] == '\0')
         break;
      cout << string[i];
   }
   cout << endl;

   reverse(string);

   for(int i = 0; ; i++) {
      if(string[i] == '\0')
         break;
      cout << string[i];
   }
   cout << endl;

}