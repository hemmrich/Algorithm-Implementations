#include <iostream>
#include <stack>
#include <queue>

using namespace std;

template<class T>
class MyQueue {
   stack<T> s1;
   stack<T> s2;
   int numElts;

   T pushPopHelper(bool pop) {
      //if pop == true, pop element. Otherwise, return elt
      if(s1.empty())
         return NULL;

      while(s1.size() > 1) {
         s2.push(s1.top());
         s1.pop();
      }
      T retVal = s1.top();

      if(pop)
         s1.pop();

      while(!s2.empty()) {
         s1.push(s2.top());
         s2.pop();
      }

      if(!pop)
         return retVal;
      return NULL;
   }

public:

   MyQueue() : numElts(0) {}

   void push(T val) {
      s1.push(val);
      numElts++;
   }

   void pop() {
      pushPopHelper(true);
      numElts--;
   }

   int front() {
      return pushPopHelper(false);
   }

   bool empty() {
      return !numElts;
   }

   int size() {
      return numElts;
   }

};



int main() {
   MyQueue<int> mq;
   queue<int> q;

   for(int i = 0; i < 10; i++) {
      for(int j = i + 1; j < 15; j++) {
         mq.push((int) ((i * i) / j + i % j));
         q.push((int) ((i * i) / j + i % j));
      }
   }

   while(!mq.empty() && !q.empty()) {
      if(mq.front() != q.front()) {
         cout << "NOT EQUAL!" << endl;
         return 1;
      }
      mq.pop(); q.pop();
   }
   cout << "Same queue behavior" << endl;

}




