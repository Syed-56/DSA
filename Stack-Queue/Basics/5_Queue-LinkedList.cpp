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

class Queue {
    Node* head;
    Node* tail;

    public:
    Queue() {head=tail=NULL;}

    bool isEmpty() {
        return head==NULL;
    }
    void enqueue(int val) {   //pushfront of LL
        Node* newNode = new Node(val);
        if(isEmpty())   head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void dequeue() {
        if(isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    int front() {
        if(!isEmpty())  return head->data;
        else {
            cout << "Queue Underflow\n";
            return -1;
        }
    }
};

int main() {
    Queue q;
    q.dequeue();
    q.enqueue(10);
    q.enqueue(20);
    while(!q.isEmpty()) {
        cout << q.front() << " ";
        q.dequeue();
    }

}