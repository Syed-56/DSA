#include <iostream>
#include <vector>
using namespace std;

class Stack {
    vector<int> v;
    int capacity;

    public:
    Stack(int val=0) {
        capacity = val;
    }

    bool isEmpty() {
        return (v.size()==0);
    }

    void push(int val) {
        if(capacity==v.size()) {
            cout << "Stack Overflow\n";
            return;
        }
        v.push_back(val);
    }
    void pop() {
        if(isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        v.pop_back();
    }
    int top() {
        return v[v.size()-1];
    }
};

int main() {
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);

    while(!s.isEmpty()) {
        cout << s.top() << " ";
        s.pop();
    }
}