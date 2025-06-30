#include <iostream>
using namespace std;

int main() {
    //Left Shift, formula: a<<b = a * 2^b
    cout << (4<<1) << endl;  // 4 is 100 and we left-shift by 1 so it become 1000=8
    cout << (10 << 2) << endl;  //10 is 1010 and we left-shift by 2 so it become 101000=40

    //Right Shift, formula: a>>b = a/2^b
    cout << (4 >> 1) << endl;  // 4 is 100 and we right-shift by 1 so it become 0010=2 (last bit is discarded by going right-side)
    cout << (10 >> 2) << endl;  //10 is 1010 and we right-shift by 2 so it become 0010=2
}