#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Reverse a singly linked list
ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
    ListNode head(0); //head of new list
    ListNode* current = &head;   //current node traverses the both list and creates the merged list
    while(head1 != NULL && head2 != NULL) {
        if(head1->val < head2->val) {
            current->next = head1;
            head1 = head1->next;
        }
        else {
            current->next = head2;
            head2 = head2->next;
        }
        current = current->next;
    }

    if(head1 != NULL)   current->next = head1;
    else if(head2 != NULL)  current->next = head2;

    return head.next;   //the head was just a dummy static node, from its next node the list starts
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
