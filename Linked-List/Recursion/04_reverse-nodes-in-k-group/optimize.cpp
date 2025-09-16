#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Reverse a singly linked list
ListNode* reverseList(ListNode* head, int k) {
    ListNode* curr = head;
    for(int i=0; i<k; i++) {
        if(!curr)   return head;    //base case
        curr = curr->next;
    }

    ListNode* prevNode = reverseList(curr,k);
    ListNode* tempHead = head;
    for(int i=0; i<k; i++) {
        ListNode* currNext = tempHead->next;
        tempHead->next = prevNode;
        prevNode = tempHead;
        tempHead = currNext;
    }
    return prevNode;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    // Build list: 10 -> 20 -> 30 -> ...
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    head = reverseList(head, 2);

    printList(head);
}
