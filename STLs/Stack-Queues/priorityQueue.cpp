#include <iostream>
#include <queue>
using namespace std;

int main() {
    //think of it as an already non-decreasing sorted array
    priority_queue<int> q;
    //REMEMBER THAT IT IS A TREE
    q.push(5);
    q.push(3);
    q.push(10);
    q.push(4);
    //here in top the priority element is stored which has largest value
    while(!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
}