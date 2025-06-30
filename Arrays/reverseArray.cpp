#include <iostream>
using namespace std;

int main() {
    int size=8;
    int arr[size] ={5,7,3,2,6,9,1,10};
    //one variable to point at start and other to point at end, they will be incremented,decremented upon each iteration
    int start = 0;
    int end = size-1;

    cout << "Before Reversing: ";
    for(int i=0; i<size; i++)           cout << arr[i] << " ";

    //the array will be reversed when we reach half of it, for even its start=end and for odd its start > end, thats why we use this condition
    while(start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }

    cout << "\nAfter Reversing: ";
    for(int i=0; i<size; i++)           cout << arr[i] << " ";
}