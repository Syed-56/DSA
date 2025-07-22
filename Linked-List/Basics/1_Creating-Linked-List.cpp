#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class List {
    Node* head;
    Node* tail;

    public:
    List() {
        head = tail = NULL;
    }

    void push_back(int value) {
        Node* newNode = new Node(value);
        if(head == NULL) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }
};

int main() {

}