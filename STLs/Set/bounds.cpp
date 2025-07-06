#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s = {1,2,3,4,5,6};
    cout << *(s.lower_bound(4)) << endl;    //an iterator is returned so we have to dereference it
    //lower bound checks if passed value exist in set then it's printed otherwise the bigger value wrt that present will be printed
    s.erase(4);
    cout << *(s.lower_bound(4)) << endl;
    //if no value greater than 4 exist, no value (0) is returned

    cout << *(s.upper_bound(5)) << endl;    //upper bound means to return a value greater than passed one
}