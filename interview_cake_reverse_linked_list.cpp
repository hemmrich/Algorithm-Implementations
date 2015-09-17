// reverse a linked list in place

#include <iostream>
#include <list>

using namespace std;

class Node {
public:
  Node* next;
  int value;

  Node(int in_val) : value(in_val), next(nullptr) {}
};

Node* reverse_in_place(Node* head) {

  Node* tmp, *prev = nullptr;

  while(head) {
    tmp = head->next;
    head->next = prev;
    prev = head;
    head = tmp;
  }

  return prev;
}

int main() {
  
  Node first(0), second(1), third(2), fourth(3), fifth(4);
  first.next = &second;
  second.next = &third;
  third.next = &fourth;
  fourth.next = &fifth;
  
  Node* head = reverse_in_place(&first);

  for(Node* iterator = head; iterator; iterator = iterator->next)
    cout << iterator->value << " ";
  cout << endl;
}