#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    dq.push_back(10);
    dq.push_front(5);
    dq.push_back(20);  
    for(int val:dq)     cout << val << " ";
    cout << endl;

    dq.insert(dq.begin() + 1, 15);  // [5, 15, 10, 20]

    cout << "Front: " << dq.front() << endl; // 5
    cout << "Back: " << dq.back() << endl;   // 20
    cout << "Size: " << dq.size() << endl;   // 4

    dq.pop_front();  // Remove 5
    dq.pop_back();   // Remove 20

    for (int x : dq)
        cout << x << " "; // Output: 15 10
}
