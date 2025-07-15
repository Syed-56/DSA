#include <iostream>
#include <vector>
using namespace std;

int peakIndex(vector<int> arr) {
    int n = arr.size();
    int start=1, end=n-2;
    while(start <= end) {
        int mid = start + (end-start)/2;

        if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]) {
            return mid;
        }
        else if(arr[mid+1] > arr[mid]) {
            start=mid+1;
        }
        else if(arr[mid+1] < arr[mid]) {
            end=mid;
        }
    }
}

int main() {
    vector<int> arr = {0,2,1,0};
    cout << "Peak Index = " << peakIndex(arr);
}