#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Reverse a singly linked list
ListNode* mergeTwoLists(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void printList(ListNode* head) {
    cout << head->val;
}

int main() {
    // Build list: 10 -> 20 -> 30 -> ...
    ListNode* head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head = mergeTwoLists(head);
    printList(head);
}
