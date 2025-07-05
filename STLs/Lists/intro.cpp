#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {
    list<int> l;
    //push back adds element from back and push front adds from front
    l.push_back(1);
    l.push_back(2);
    l.push_front(3);
    l.push_front(5);
    for(int val:l)   cout << val << " ";
    cout << endl;
    
    //pop back remove element from end but pop from remove element from front
    l.pop_back();
    l.pop_front();
    for(int val:l)   cout << val << " ";

    //it is a doubly linked list so we cant access value by index
     // error:   cout << l[1];

}