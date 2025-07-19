#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int> nums, int target) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for(int i=0; i<n; i++) {
        if(i>0 && nums[i] == nums[i-1]) continue; // Skip duplicates for the first number
        for(int j=i+1; j<n; j++) {
            if(j>i+1 && nums[j]==nums[j-1]) continue; // Skip duplicates for the second number
            int left = j+1, right = n-1 ;
            while(left < right) {
                if(nums[left] == nums[left-1] && left > j+1) {
                    left++; // Skip duplicates for the third number
                    continue;
                }
                long long sum = 1LL * nums[i] + nums[j] + nums[left] + nums[right];
                if(sum < target) {
                    left++;
                }
                else if(sum > target) {
                    right--;
                }
                else {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    left++;
                    right--;
                }
            }
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    vector<vector<int>> result = fourSum(nums, target);
    for (const auto& vec : result) {
        cout << "[";
        for (int i = 0; i < vec.size(); ++i) {
            cout << vec[i];
            if (i < vec.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
}