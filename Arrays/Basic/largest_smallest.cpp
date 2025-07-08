#include <iostream>
using namespace std;

int main() {
    int arr[] = {1,2,3,4,5};
    int smallest = arr[0];

    for(int i=0; i<(sizeof(arr)/sizeof(int)); i++) {
        if (arr[i] < smallest)  smallest = arr[i];
    }
    cout << "Smallest: " << smallest << endl;

    int array[] = {1,2,3,4,5};
    int largest = array[0];

    for(int i=0; i<(sizeof(array)/sizeof(int)); i++) {
        if (array[i] > largest)  largest = array[i];
    }
    cout << "Largest: " << largest << endl;
}