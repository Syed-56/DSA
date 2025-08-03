#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& nums, int start, int end) {
    int pivot = nums[end];
    int i = start-1;
    for(int j=start; j<end; j++) {
        if(nums[j] < pivot) {
            i++;
            swap(nums[i],nums[j]);
        }
    }
    swap(nums[i+1],nums[end]);
    return i+1;
}

void quickSort(vector<int>& nums, int start, int end) {
    if(start < end) {
        int pivot = partition(nums,start,end);
        quickSort(nums,start,pivot-1);
        quickSort(nums,pivot+1,end);
    }
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int n = arr.size()-1;
    quickSort(arr,0,n);
    for(int val:arr)    cout << val << " ";
}