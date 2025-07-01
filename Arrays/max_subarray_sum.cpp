#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int maxSum=INT16_MIN, sum=0;
    for(int i=0; i<nums.size(); i++) {
        if(nums[i] > sum+nums[i]) sum = nums[i];
        else    sum += nums[i];
        if(sum > maxSum)    maxSum = sum;
    }
    return maxSum;
}

int main() {
    vector<int> nums = {1,2,3,4,5};
    cout << "Max Sum: " << maxSubArray(nums);
}