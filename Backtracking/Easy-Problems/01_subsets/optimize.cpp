#include <iostream>
#include <vector>
using namespace std;

void getSubsets(vector<int>& nums, vector<int> subset, vector<vector<int>> &ans, int i) {
    if(i==nums.size()) {
        ans.push_back(subset);
        return;
    }
    subset.push_back(nums[i]);
    getSubsets(nums,subset,ans,i+1);
    cout << "Current Subset: ";
    for(int val:subset) cout << val;
    cout << endl;
    subset.pop_back();
    getSubsets(nums,subset,ans,i+1);
}

vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> allSubsets;
    vector<int> subset;
    getSubsets(nums,subset,allSubsets,0);
    return allSubsets;
}

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> sub = subsets(nums);
    for(const auto& row:sub) {
        for(int val:row) {
            cout << val;
        }
        cout << "  ";
    }
}