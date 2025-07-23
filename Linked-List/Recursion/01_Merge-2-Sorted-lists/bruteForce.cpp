#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Reverse a singly linked list
ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
    if(!head1)  return head2;
    if(!head2)  return head1;

    if(head1->val < head2->val) {
        head1->next = mergeTwoLists(head1->next, head2);
        return head1;
    }
    else {
        head2->next = mergeTwoLists(head1, head2->next);
        return head2;
    }
}

void printList(ListNode* head) {
    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
}

int main() {
    // Build list: 10 -> 20 -> 30 -> ...
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(5);
    ListNode* merged = mergeTwoLists(head1, head2);
    printList(merged);
}
