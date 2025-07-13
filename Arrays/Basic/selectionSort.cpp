#include <vector>
#include <iostream>
using namespace std;

vector<int> selectionSort(vector<int> nums) {
    int n = nums.size();
    for(int i=0; i<n-1; i++) {
        int minIndex=i;
        for(int j=i+1; j<n; j++) {
            if(nums[j] < nums[minIndex])    minIndex=j;
        }
        swap(nums[i],nums[minIndex]);
    }
    return nums;
}

int main() {
    vector<int> nums = {3,4,1,4,6};
    nums = selectionSort(nums);
    for(int val:nums)   cout << val << " ";
}