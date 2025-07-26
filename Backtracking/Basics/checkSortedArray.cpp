#include <iostream>
using namespace std;

//TC and SC = O(n)
bool isSorted(int arr[], int index) {
    if(index==0)    return true;
    if(arr[index] > arr[index-1])   return isSorted(arr,index-1);
    else    return false;
}

int main() {
    int arr[5] = {1,2,3,4,0};
    cout << "Is Array Sorted?" << isSorted(arr,4);
}