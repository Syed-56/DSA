#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to copy the list with random pointers (logic not implemented yet)
ListNode* addTwoNums(ListNode* head1, ListNode* head2) {
    if(head1->val==0 && head2->val==0)  return new ListNode(0);
    int num1=0, num2=0;
    ListNode* curr1 = head1;
    ListNode* curr2 = head2;

    while(curr1 || curr2) {
        if(curr1) {
            num1 *= 10;
            num1 += curr1->val;
            curr1 = curr1->next;
            cout << num1 << endl;
        }
        if(curr2) {
            num2 *= 10;
            num2 += curr2->val;
            curr2 = curr2->next;
            cout << num2 << endl;
        }
    }

    int sum = num1+num2;
    cout << sum << endl;

    ListNode* ans = NULL;
    ListNode* tail = ans;
    while(sum) {
        int digit = sum%10;
        ListNode* newNode = new ListNode(digit);

        if(!ans) {
            ans = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = tail->next;
        }
        sum /= 10;
    }
    return ans;
}

// Function to print a list with next and random pointers
void printList(ListNode* head) {
    while (head) {
        cout << ", " << head->val;
        head = head->next;
    }
    cout << "------\n";
}

int main() {
    // Create original list: 1 -> 2 -> 3
    ListNode* head = new ListNode(2);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);

    ListNode* head2 = new ListNode(5);
    head2->next = new ListNode(6);
    head2->next->next = new ListNode(4);

    ListNode* sum = addTwoNums(head, head2);

    printList(sum);
}
