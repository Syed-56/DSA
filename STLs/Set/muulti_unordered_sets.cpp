#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int main() {
    multiset<int> s = {1,2,3};
    s.insert(1);    //in multiset, multiple values can be putted
    s.insert(3);
    for(int val:s)  cout << val << " ";
    cout << endl;

    unordered_set<int> s1 = {1,2,3,4,5,6};  //here data is unsorted
    for(int val:s1)     cout << val << " ";
    cout << endl;

    unordered_multiset<int> s2 = {1,1,3,4,2,3,2};   //multiple and unsorted data
    for(int val:s2)     cout << val << " ";

}