#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Reverse a singly linked list
ListNode* middleNode(ListNode* head) {
    ListNode* temp = head;
    int size=0;
    while(temp != NULL) {
        temp = temp->next;
        size++;
    }

    temp = head;
    int count=0;
    while(count < (size/2)) {
        temp = temp->next;
        count++;
    }
    return temp;
}

void printList(ListNode* head) {
    cout << head->val;
}

int main() {
    // Build list: 10 -> 20 -> 30 -> ...
    ListNode* head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);

    head = middleNode(head);

    printList(head);
}  
