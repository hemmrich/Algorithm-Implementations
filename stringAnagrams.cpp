#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void swap(char* a, char* b) {
   char tmp = *b;
   *b = *a;
   *a = tmp;
}

void printString(char* string) {
   for(int i = 0; string[i] != '\0'; i++)
      cout << string[i];
   cout << endl;
}

void genPerms(char* string, int start, int end) {
   if(start == end)
      printString(string);
   else {
      for(int i = start; i <= end; i++) {
         swap((string + start), (string + i));
         genPerms(string, start + 1, end);
         swap((string + start), (string + i)); //for backtracking
      }
   }
}

void printStack(stack<char> string) {
   while(!string.empty()) {
      cout << string.top();
      string.pop();
   }
   cout << endl;
}

//uses backtracking
void genPerms2(stack<char>& string, queue<char> unused) {
   if(unused.empty()) {
      printStack(string);
      return;
   }
   for(int i = 0; i < unused.size(); i++) {
      string.push(unused.front());
      unused.pop();
      genPerms2(string, unused);
      unused.push(string.top());
      string.pop();
   }
}

int main() {
   char string[] = "ABC";
   int length = 3;
   genPerms(string, 0, length - 1);
   cout << "-------------------------------------" << endl;

   stack<char> stackString;
   queue<char> unused;
   unused.push('A');
   unused.push('B');
   unused.push('C');
   genPerms2(stackString, unused);
}




void permute(char *a, int i, int n) 
{
   int j; 
   if (i == n)
     printf("%s\n", a);
   else
   {
        for (j = i; j <= n; j++)
       {
          swap((a+i), (a+j));
          permute(a, i+1, n);
          swap((a+i), (a+j)); //backtrack
       }
   }
} 