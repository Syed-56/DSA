#include <iostream>
using namespace std;

void sort(int arr[]) {
    for(int i=0; i<5-1; i++) {
        for(int j=i; j<5-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j],arr[j+1]);
            }
        }
    }
    for(int i=0; i<5; i++)          cout << arr[i] << " ";
}

int main() {
    int arr[5] = {1,4,5,2,3};
    cout << "Sorted Array: ";
    sort(arr);
}