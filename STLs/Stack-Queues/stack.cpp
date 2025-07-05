#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);

    stack<int> s2;
    cout << "\nSize of new stack: " << s2.size();
    //swapping stack
    s2.swap(s);
    cout << "\nSize of new stack: " << s2.size() << "\tSize of Old Stack: " << s.size() << endl;

    while(!s2.empty()) {
        cout << s2.top() << " ";
        s2.pop();
    }
    //Stack = LIFO so here 3 was added lastly so when first pop is called the 3 is removed
}