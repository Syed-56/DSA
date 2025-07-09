#include <iostream>
#include <vector>
using namespace std;

int peakIndex(vector<int> arr) {
    int n = arr.size();
    int peakIndex=0, peakElement = arr[0];
    for(int i=0; i<n; i++) {
        if(arr[i] > peakElement) {
            peakElement = arr[i];
            peakIndex=i;
        }
    }
    return peakIndex;
}

int main() {
    vector<int> arr = {0,2,1,0};
    cout << "Peak Index = " << peakIndex(arr);
}