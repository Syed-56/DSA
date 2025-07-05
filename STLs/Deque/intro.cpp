#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    deque<int> d = {1,2,3,4,5};
    for(int val:d)  cout << val << " ";
    //it is a dynamic array like vector so can be accessed by index
    cout << d[1] << endl;
    //it also used push_back push_front pop_back pop_front methods
    
}