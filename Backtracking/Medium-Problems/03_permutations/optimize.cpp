#include <iostream>
#include <vector>
using namespace std;

void backTrack(vector<int>& nums, vector<vector<int>>& ans, int i, int n) {
    if(i==n) {
        ans.push_back(nums);
        return;
    }
    for(int j=i; j<n; j++) {
        swap(nums[j], nums[i]); //swap for permutation.
        backTrack(nums,ans,i+1,n);  //exmplore more permutations.
        swap(nums[j], nums[i]); //reset the array to as it was.
    }
}

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> permutations;
    backTrack(nums,permutations,0,nums.size());
    for(const auto& row:permutations) {
        for(int val:row) {
            cout << val;
        }
        cout << endl;
    }
}