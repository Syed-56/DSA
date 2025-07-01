#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int majorityElement(vector<int>& nums) {
    int n = nums.size();
    int freq=0, ans=nums[0];
    
    for(int i=0; i<n; i++) {
        if(freq==0)  ans=nums[i];

        if(ans==nums[i])  freq++;
        else   freq--;
    }
    return ans;
}

int main() {
    vector<int> nums = {1,3,3,3,2};
    cout << "Majority Element: " << majorityElement(nums);
}