#include <iostream>

using namespace std;

void replaceSpaces(string& str) {
   string newStr;
   for(int i = 0, j = 0; i < str.size(); i++) {
      if(str[i] == ' ')
         newStr.append("%20");
      else
         newStr += str[i];
         //newStr.append( (string)str[i] );
   }
   str = newStr;
}

int main() {
   string str = "Mr John Smith";
   cout << str << endl;
   replaceSpaces(str);
   cout << str << endl;
}