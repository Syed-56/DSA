#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    cout << "Size of Set = " << s.size();
    s.insert(2);    //this wont be addedd as set only stores unique elements
    cout << "\nSize of Set = " << s.size() << endl;

    for(int val:s)  cout << val << " ";
}