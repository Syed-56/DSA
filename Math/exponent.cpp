#include <iostream>
#include <vector>
using namespace std;

double power(double x, int n) {
    double ans=1, exp = abs(n);
    for(int i=0; i<n; i++) {
        ans *= x;
    }
    if(n < 0)   ans = 1/ans;
    
    
    return ans;
}

int main() {
    double base = 4;
    int exponent = -2;
    cout << base << " ^ " << exponent << " = " << power(base,exponent);
}