#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
 void insertAthead(Node* head, int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
 }
 int main() {
    Node* head = NULL;
    insertAthead(head,20);
 }