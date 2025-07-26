#include <iostream>
using namespace std;

int sumTill(int n) {
    if(!n)  return n;
    return n + sumTill(n-1);
}

int main() {
    int n =5;
    int sum = sumTill(5);
    cout << "Sum of numbers till " << n << " = " << sum;
}