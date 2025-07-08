#include <iostream>
using namespace std;

int sum(int arr[], int size) {
    int sum=0;
    for(int i=0; i<size; i++) {
        sum += arr[i];
    }
    return sum;
}

int product(int arr[], int size) {
    int product=1;
    for(int i=0; i<size; i++) {
        product *= arr[i];
    }
    return product;
}

int main() {
    int arr[6] = {1,2,3,4,5,6};
    cout << "Array Sum: " << sum(arr,6);
    cout << "\nArray Product: " << product(arr,6);
}