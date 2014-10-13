#include <iostream>
#include <queue>

using namespace std;

struct Node {
   Node* left;
   Node* right;
   int val;

   Node(int inVal, Node* l = NULL, Node* r = NULL) : val(inVal), left(l), right(r) {}
};


void levelOrder(Node* root) {
   queue<Node*> q;
   if(!root)
      return; //empty tree
   q.push(root);
   while(!q.empty()) {
      Node* n = q.front();
      q.pop();
      if(!n)
         continue; //empty tree
      cout << n->val << " ";
      q.push(n->left);
      q.push(n->right);
   }
   cout << endl;
}



int main() {
   Node* root = new Node(0);
   root->left = new Node(1, new Node(2));
   root->right = new Node(3);
   root->right->left = new Node(4);

   levelOrder(root);
}