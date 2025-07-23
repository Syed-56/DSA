#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Reverse a singly linked list
ListNode* removeCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    bool cycleFound=false;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) {
            cycleFound=true;
            break;
        }
    }
    if(!cycleFound) return NULL;

    slow = head;
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;

}

void printList(ListNode* head) {
    if(!head)   cout << "Null";
    else cout << head->val;
}

int main() {
    // Build list: 10 -> 20 -> 30 -> ...
    ListNode* head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = head->next;
    ListNode* cycle = removeCycle(head);
    printList(cycle);
}
