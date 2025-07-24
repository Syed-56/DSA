#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;
    
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class List {
    Node* head;
    Node* tail;

    public:
    List() {
        head = tail = NULL;
    }

    void push_front(int value) {
        Node* newNode = new Node(value);
        if(head == NULL) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(int value) {
        Node* newNode = new Node(value);
        if(head==NULL) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void pop_front() {
        if(head==NULL)  return;
        Node* temp = head;
        head = head->next;
        if(!head)   tail = NULL;
        else        head->prev = NULL;

        delete temp;
    }

    void pop_back() {
        if(head==NULL)  return;
        Node* temp = tail;
        tail = tail->prev;
        if(!tail)   head = NULL;
        else        tail->next = NULL;
        delete temp;
    }

    void print() {
        Node* temp = head;
        cout << "Printing Forward: ";
        while (temp != NULL) {
            cout << "  [" << temp->data << " | " << temp->next << "]  ";
            temp = temp->next;
        }
        cout << "NULL" << endl;

        Node* newTemp = tail;
        cout << "Printing Backward: ";
        while (newTemp != NULL) {
            cout << "  [" << newTemp->data << " | " << newTemp->prev << "]  ";
            newTemp = newTemp->prev;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    List doublyLinkedList;
    doublyLinkedList.push_front(10);
    doublyLinkedList.push_front(20);
    doublyLinkedList.push_front(30);
    doublyLinkedList.push_back(5);

    doublyLinkedList.print();

    doublyLinkedList.pop_front();
    doublyLinkedList.pop_back();

    doublyLinkedList.print();

}