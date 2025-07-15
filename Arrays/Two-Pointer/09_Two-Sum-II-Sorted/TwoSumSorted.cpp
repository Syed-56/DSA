#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSumII(vector<int> nums, int target) {
    int start=0, end = nums.size()-1;

    while(start < end) {
        int sum = nums[start] + nums[end];
        if(sum > target)    end--;
        else if(sum < target)   start++;
        else    return {start+1, end+1};    //bcz Q says 1-based indexing
    }
    return nums;
}

int main() {
    vector<int> nums = {2,3,7,11};
    int target = 10;
    nums = twoSumII(nums,target);
    for(int val:nums)   cout << val << " ";
}