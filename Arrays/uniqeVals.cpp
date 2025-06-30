#include <iostream>
using namespace std;

void printUnique(int arr[], int size) {
    int found;
    for(int i=0; i<size; i++) {
        found=0;
        for(int j=0; j<size; j++) {
            if(arr[i]==arr[j] && i!=j)  found=1;
        }
        if(!found)  cout << arr[i] << " ";
    }
}

int main() {
    int arr[10] = {1,2,5,2,9,0,5,4,5,6};
    printUnique(arr,10);
}