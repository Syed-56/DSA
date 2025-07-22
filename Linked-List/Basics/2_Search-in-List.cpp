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
    }
    void print() {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << "|" << temp->next << " -> ";  //printing address just for understanding
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    Node* search(int val) {
        Node* temp = head;
        while(temp != NULL) {
            if(temp->data == val) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
};

int main() {
    List linkedList;
    linkedList.push_front(10);
    linkedList.push_front(20);

    Node* toSearch = linkedList.search(20);
    if(toSearch)  cout << toSearch-> data << "|" << toSearch->next;
    else    cout << "Node Not Found";
}