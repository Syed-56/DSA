#include <iostream>
using namespace std;

int main(){
    int a=4, b=8;
    //in binary: 4 = 100 and 8 = 1000, since bits mismatch so we write 4 as 0100
    cout << (a & b) << endl;    //0&1=0, 1&0=0, 0&0=0, 0&0=0 
    cout << (a | b) << endl;    //0|1=1, 1|0=1, 0|0=0, 0|0=0
    cout <<  ~a << " " << ~b;   //bits reversed
}