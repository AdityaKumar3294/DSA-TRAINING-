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

 void deletion (Node* &head, int key) {
    if (head == NULL) return;
    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node*temp = head;
    while (temp->next != NULL && temp->next->data != key)
    {
        temp=temp->next;
    }
    if (temp->next == NULL) return;
    Node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
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
    insertAttail(head,30);
    insertAttail(head,50);
    cout << "Linked List: ";
    display(head);
    deletion(head,30);
    cout << "Linked List after deletion: ";
    display(head); 
 }