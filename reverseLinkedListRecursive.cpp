#include <iostream>

using namespace std;

struct Node {
   int val;
   Node* next;

   Node(int value, Node* nextNode = NULL) : val(value), next(nextNode) {}
};

void insertVal(Node* root, int val) {
   while(root->next)
      root = root->next;
   root->next = new Node(val);
}

void printList(Node* root) {
   while(root) {
      cout << root->val << " ";
      root = root->next;
   }
   cout << endl;
}

void reverseList(Node*& root) {
   //store next node
   Node* next = root->next;
   if(!next)
      return;

   //use recursion to go to end of list
   reverseList(next);

   //move 2nd to last element to behind last element
   root->next->next = root;
   //set new last element's next pointer to 0
   root->next = NULL;
   //move on to previous node
   root = next;

   printList(root);
}


int main() {
   Node* root = new Node(0);

   for(int i = 1; i < 9; i++)
      insertVal(root, i);

   printList(root);
   reverseList(root);
   printList(root);
}