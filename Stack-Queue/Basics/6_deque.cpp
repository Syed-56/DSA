#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int val) {
        data=val;
        next = NULL;
    }
};

class Deque {
    Node *head;
    Node *tail;

    public:
    Deque() {head=tail=NULL;}
    bool isEmpty() {return head==NULL;}
    
    void pushFront(int val) {
        Node *newNode = new Node(val);
        if(isEmpty()) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }
    void pushBack(int val) {
        Node *newNode = new Node(val);
        if(isEmpty()) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void popFront() {
        if(isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    void popBack() {
        if(isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        if(head==tail) {
            popFront();
            return;
        }
        Node *temp = head;
        while(temp->next != tail)   temp = temp->next;
        delete tail;
        tail = temp;
        tail->next = NULL;
    }
    int front() {
        if(!isEmpty())  return head->data;
        else {
            cout << "Queue Empty\n";
            return -1;
        }
    }
    int rear() {
        if(!isEmpty())  return tail->data;
        else {
            cout << "Queue Empty\n";
            return -1;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Deque dq;
    dq.pushBack(10);
    dq.pushBack(20);
    dq.pushFront(5);
    dq.display(); // 5 10 20
    dq.popBack();
    dq.display(); // 5 10
    dq.popFront();
    dq.display(); // 10
}