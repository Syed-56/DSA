#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* random;
    Node(int x) : val(x), next(nullptr), random(nullptr) {}
};

// Function to copy the list with random pointers (logic not implemented yet)
Node* copyListWithRandomPointer(Node* head) {
    // TODO: Implement this function
    return nullptr;
}

// Function to print a list with next and random pointers
void printList(Node* head) {
    while (head) {
        cout << "Val: " << head->val;
        if (head->random)
            cout << ", Random: " << head->random->val;
        else
            cout << ", Random: NULL";
        cout << endl;
        head = head->next;
    }
    cout << "------\n";
}

int main() {
    // Create original list: 1 -> 2 -> 3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // Setup random pointers
    head->random = head->next->next;         // 1's random -> 3
    head->next->random = head;               // 2's random -> 1
    head->next->next->random = head->next;   // 3's random -> 2

    cout << "Original List:\n";
    printList(head);

    Node* copied = copyListWithRandomPointer(head);

    cout << "Copied List:\n";
    printList(copied);
}
