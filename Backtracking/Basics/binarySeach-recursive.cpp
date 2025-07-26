#include <iostream>
using namespace std;

int binarySearch(int arr[], int target, int start, int end) {
    if(start > end)     return -1;
    int mid = start+end/2;
    if(arr[mid] > target)       return binarySearch(arr,target,start,mid-1);
    else if(arr[mid] < target)  return binarySearch(arr,target,mid+1,end);
    else    return mid;
}

int main() {
    int arr[5] = {1,2,3,4,5};
    int target=3;
    cout << "Target Found at Index: " << binarySearch(arr,target,0,5-1);
}