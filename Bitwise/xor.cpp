#include <iostream>
using namespace std;
int main() {
    int a=3,b=7;    //0011 and 0111
    int xor_operation = (a ^ b);  // 0^0=0, 0^1=1, 1^1=0, 1^1=0 
    cout << xor_operation;
} 
