#include <iostream>
using namespace std;

int fact(int n) {
    if(n==0 || n==1)    return 1;
    else    return n * fact(n-1);
}

int main() {
    int n=6;
    int factorial = fact(n);
    cout << "Factorial of " << n << " = " << factorial;
}