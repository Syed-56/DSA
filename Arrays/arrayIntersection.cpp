#include <iostream>
using namespace std;

void findIntersection(int arr1[], int size1, int arr2[], int size2) {
    int sizeToLoop;
    if(size1 > size2)   sizeToLoop = size2;
    else    sizeToLoop = size1;

    for(int i=0; i<size1; i++) {
        for(int j=i; j<size2; j++) {
            if(arr1[i]==arr2[j]) {
                cout << arr1[i] << " ";
            }
        }
    }
}

int main() {
    int arr1[5] = {1,3,5,4,1};
    int arr2[6] = {1,4,2,1,5,6};
    findIntersection(arr1,5,arr2,6);
    return 0;
}