#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int x;
    cout << "Input Number: ";
    cin >> x;
    //this is bcz when a number is power of 2 its all bits are 0 except first and that number's previous number has all bits 1 except first so doing and operation on them returns 0.
    if ((x>0) && (x & (x-1))==0)  cout << "Number is Power of 2";
    else    cout << "Number isn't power of 2";
}