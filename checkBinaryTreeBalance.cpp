#include <iostream>
#include <cmath>

using namespace std;

struct Node {
   int val;
   Node* left;
   Node* right;

   Node(int val = 0, Node* left = NULL, Node* right = NULL) {
      this->val = val;
      this->left = left;
      this->right = right;
   }
};







int getHeight(Node* node) {
   if(!node)
      return 0; //base case
   return max(getHeight(node->left), getHeight(node->right)) + 1;
}


bool isBalanced(Node* root) {
   if(!root)
      return false;

   if(abs(getHeight(root->left) - getHeight(root->right)) >= 2)
      return false;
   else
      return isBalanced(root->left) && isBalanced(root->right);
}


int main() {

   Node* root = new Node(5);
   Node* l1 = new Node(3);
   Node* l2 = new Node (1);
   root->left = l1;
   root->right = l2;

   l1->left = new Node(7, new Node(3), new Node(9));
   l1->right = new Node(3, new Node(1));

   l2->left = new Node()


}