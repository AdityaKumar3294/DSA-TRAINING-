#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }

    ListNode(int x, ListNode *next) {
        val = x;
        this->next = next;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *res = new ListNode(0, head);
        ListNode *temp = res;

        for (int i = 0; i < n; i++) {
            head = head->next;
        }

        while (head != NULL) {
            head = head->next;
            temp = temp->next;
        }

        temp->next = temp->next->next;

        ListNode *result = res->next;
        delete res;

        return result;
    }
};

// Function to print linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    // Creating linked list: 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;

    Solution obj;
    head = obj.removeNthFromEnd(head, n);

    cout << "Updated Linked List: ";
    printList(head);

    return 0;
}