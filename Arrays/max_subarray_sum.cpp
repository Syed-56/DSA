#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int maxSum=INT16_MIN, sum;
    for(int i=0; i<nums.size(); i++) {
        sum=0;
        for(int j=i; j<nums.size(); j++) {
            sum += nums[j];
        }
        if(sum > maxSum)    maxSum=sum; 
    }
    return maxSum;
}

int main() {
    vector<int> nums = {1,2,3,4,5};
    cout << "Max Sum: " << maxSubArray(nums);
}