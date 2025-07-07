#include <iostream>
#include <vector>
using namespace std;

vector<int> shuffleArray(vector<int> nums, int n) {
    int left=0, right=n;
    vector<int> ans;
    while(ans.size() != nums.size()) {
        ans.push_back(nums[left]);
        ans.push_back(nums[right]);
        left++;
        right++;
    }
    return ans;
}

int main() {
    vector<int> arr = {1,3,5,2,4,6};
    vector<int> nums = shuffleArray(arr,3);
    for(int val:nums)   cout << val << " ";
}