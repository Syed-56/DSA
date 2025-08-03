#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums, int start, int mid, int end) {
    int i=start, j=mid+1;
    vector<int> temp;
    while(i <= mid && j<= end) {
        if(nums[i] <= nums[j]) {
            temp.push_back(nums[i]);
            i++;
        }
        else {
            temp.push_back(nums[j]);
            j++;
        }
    }

    while(i<=mid) {
        temp.push_back(nums[i]);
        i++;
    }
    while(j<=end) {
        temp.push_back(nums[j]);
        j++;
    }

    for(int idx=0; idx<temp.size(); idx++) {
        nums[idx+start] = temp[idx];
    }
}

void mergeSort(vector<int>& nums, int start, int end) {
    if(start >= end)  return;
    int mid = start + (end-start)/2;
    mergeSort(nums,start,mid);  //Sort Left Half
    mergeSort(nums,mid+1,end);  //Sort Right Half
    merge(nums,start,mid,end);  //merge sorted halves
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int n = arr.size()-1;
    mergeSort(arr,0,n);
    for(int val:arr)    cout << val << " ";
}