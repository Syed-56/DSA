#include <iostream>
#include <vector>
using namespace std;

vector<int> insertionSort(vector<int> nums) {
    for(int i=0; i<nums.size(); i++) {
        int curr=nums[i];
        int prev=i-1;
        while (prev >=0 && nums[prev] > curr) {
            nums[prev+1] = nums[prev];
            prev--;
        }
        nums[prev+1] = curr;
    }
    return nums;
}

int main() {
    vector<int> nums = {3,2,1,5,7};
    nums = insertionSort(nums);
    for(int val:nums)   cout << val << " ";
}