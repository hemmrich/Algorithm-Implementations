#include <iostream>
#include <fstream>

using namespace std;

string* lastNLines(int n, ifstream& input) {
   string tmp;
   string* lines = new string[n];

   for(int i = 0; getline(input, tmp); i++) 
      lines[i % n] = tmp;

   return lines;
}

void printLines(string* lines, int n) {
   for(int i = 0; i < n; i++) 
      cout << lines[i] << endl;
}

int main() {
   ifstream input;
   input.open("lastNLines.txt");

   int n = 5;
   
   string* lines = lastNLines(n, input);
   printLines(lines, n);
}