#include <iostream>
using namespace std;

// Node definition
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) {
        val = _val;
        prev = nullptr;
        next = nullptr;
        child = nullptr;
    }
};

// Doubly linked list class
class MultilevelDoublyLinkedList {
public:
    Node* head;

    MultilevelDoublyLinkedList() {
        head = nullptr;
    }

    Node* flatten(Node* head) {
        
    }

    // Print the list
    void printList(Node* head) {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function
int main() {
    MultilevelDoublyLinkedList list;

    // Level 1: 1 - 2 - 3 - 4 - 5
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);

    n1->next = n2; n2->prev = n1;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;
    n4->next = n5; n5->prev = n4;

    // Level 2: 7 - 8 - 9 (child of 3)
    Node* c1 = new Node(7);
    Node* c2 = new Node(8);
    Node* c3 = new Node(9);

    c1->next = c2; c2->prev = c1;
    c2->next = c3; c3->prev = c2;

    n3->child = c1;

    // Level 3: 11 - 12 (child of 8)
    Node* cc1 = new Node(11);
    Node* cc2 = new Node(12);
    cc1->next = cc2; cc2->prev = cc1;
    c2->child = cc1;

    list.head = n1;

    // Call flatten (not implemented)
    Node* flatHead = list.flatten(list.head);

    // For now just printing original (nested) structure
    list.printList(flatHead); // Will be empty/null unless flatten is implemented

    return 0;
}
