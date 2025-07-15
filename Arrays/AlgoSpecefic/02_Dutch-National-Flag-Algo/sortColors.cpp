#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> sortColor(vector<int> nums) {
    int low=0, mid=0, high=nums.size()-1;
    while (mid <= high) {
        if(nums[mid]==0) {
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid]==1) {
            mid++;
        }
        else if(nums[mid]==2) {
            swap(nums[mid], nums[high]);
            high--;
        }
    }

    return nums;
}

int main() {
    vector<int> colors = {2,0,2,1,1,0,1,2,0,0};
    vector<int> nums = sortColor(colors);
    for(int val:nums)   cout << val << " ";
}