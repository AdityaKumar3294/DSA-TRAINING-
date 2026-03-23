#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Insert at Tail
void insertAtTail(Node* &head, int val) {
    Node* newNode = new Node();
    newNode->data = val;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

// Insert at Head
void insertAtHead(Node* &head, int val) {
    Node* newNode = new Node();
    newNode->data = val;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}

// Display list
void display(Node* head) {
    if (head == NULL) return;

    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(back to head)" << endl;
}

// Delete node
void deleteNode(Node* &head, int key) {
    if (head == NULL) return;

    // If only one node
    if (head->data == key && head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    // If head is to be deleted
    if (head->data == key) {
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }

    // Other nodes
    do {
        prev = temp;
        temp = temp->next;
    } while (temp != head && temp->data != key);

    if (temp->data == key) {
        prev->next = temp->next;
        delete temp;
    }
}

// Main function
int main() {
    Node* head = NULL;

    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtHead(head, 5);

    cout << "Circular Linked List: ";
    display(head);

    deleteNode(head, 20);
    cout << "After deleting 20: ";
    display(head);

    return 0;
}