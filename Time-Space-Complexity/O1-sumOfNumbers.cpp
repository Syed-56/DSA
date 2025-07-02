#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter Number: ";
    cin >> n;
    int sum = n * (n+1)/2;
    cout << "Sum from 1 to " << n << " = " << sum;
}