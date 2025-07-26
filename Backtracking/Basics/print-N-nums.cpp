#include <iostream>
using namespace std;

void printTill(int n) {
    if(!n)  return;
    printTill(n-1);
    cout << n << " ";
}

int main() {
    int n = 6;
    printTill(6);
}