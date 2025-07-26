#include <iostream>
using namespace std;

void printTill(int n) {
    cout << n << " ";
    if(!n)  return;
    n--;
    printTill(n);
}

int main() {
    int n = 6;
    printTill(6);
}