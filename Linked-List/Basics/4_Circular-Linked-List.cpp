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

    void push_front(int value) {
        Node* newNode = new Node(value);
        if(head == NULL) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
        tail->next = head;
    }

    void push_back(int value) {
        Node* newNode = new Node(value);
        if(head==NULL) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        tail->next = head;
    }

    void pop_front() {
        if(head==NULL)  return;
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        head = head->next;
        tail->next = head;
        temp->next = NULL;

        delete temp;
    }

    void pop_back() {
        if(head==NULL)  return;
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        while(temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = head;
    }

    void insert(int val, int pos) {
        if(pos<0)   return;
        if(pos==0) {
            push_front(val);
            return;
        }
        
        Node* temp = head;
        for(int i=0; i<pos-1; i++) {
            if(temp == NULL) {
                cout << "Invalid Position";
                return;
            }
            temp = temp->next;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void print() {
        Node* temp = head;
        do {
            cout << temp->data << "|" << temp->next << " -> ";  //printing address just for understanding
            temp = temp->next;
        } while(temp->next != head);
        cout << endl;
    }
};

int main() {
    List linkedList;
    linkedList.push_front(10);
    linkedList.push_front(20);
    linkedList.push_front(30);
    linkedList.push_back(5);
    linkedList.push_back(0);

    linkedList.print();

    linkedList.pop_front();
    linkedList.pop_back();

    linkedList.print();

    linkedList.insert(15,1);
    linkedList.print();
}