#include <iostream>
using namespace std;

int findMax(int arr[], int size) {
    int largest = arr[0];

    for(int i=0; i<size; i++) {
        if (arr[i] > largest)  largest = arr[i];
    }
    return largest;
}

int findMin(int arr[], int size) {
    int smallest = arr[0];

    for(int i=0; i<size; i++) {
        if (arr[i] < smallest)  smallest = arr[i];
    }
    return smallest;
}

int swapMinMax(int arr[], int size) {
    int min = findMin(arr,size);
    int max = findMax(arr,size);
    int minIndex, maxIndex;

    for(int i=0; i<size; i++) {
        if(arr[i]==max)  maxIndex = i;
        if(arr[i]==min)  minIndex = i; 
    }

    swap(arr[maxIndex], arr[minIndex]);

    cout << "Array: ";
    for(int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[5] = {1,2,3,4,5};
    swapMinMax(arr,5);
}