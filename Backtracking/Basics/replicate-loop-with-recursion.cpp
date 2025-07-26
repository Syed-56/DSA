#include <iostream>
using namespace std;

void patternPrint(int i, int j) {
    if (i == 5) return;           // base case: 5 rows printed
    if (j <= i) {                 // print current row
        cout << " * ";
        patternPrint(i, j + 1);   // print next column
    } else {
        cout << endl;
        patternPrint(i + 1, 0);   // move to next row
    }
}

int main() {
    cout << "\nPattern Printing using loop\n";
    for(int i=0; i<5; i++) {
        for(int j=0; j<=i; j++) {
            cout << " * ";
        }
        cout << endl;
    }

    cout << "\nPattern Printing using Recursion\n";
    patternPrint(0,0);
}