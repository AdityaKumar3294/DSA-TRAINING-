#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

 void insertAthead(Node* &head, int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
 }

 void insertAttail(Node* &head, int val) {
    Node*newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;
    while (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
 }

 void display(Node* head) {
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    
 }
 int main() {
    Node* head = NULL;
    insertAthead(head,20);
    insertAttail(head,10);
    cout << "Linked List: ";
    display(head); 
 }