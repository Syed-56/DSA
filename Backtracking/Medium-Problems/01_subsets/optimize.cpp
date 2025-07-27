#include <iostream>
#include <vector>
using namespace std;

void getSubsets(vector<int>& nums, vector<int> subset, vector<vector<int>> &ans, int i) {
    // Print the current index and subset
    cout << "Called getSubsets(i = " << i << ", subset = [";
    for (int val : subset) cout << val << " ";
    cout << "])" << endl;

    // Base case: if we've reached the end of the array
    if (i == nums.size()) {
        cout << "-> Reached end. Saving subset: [";
        for (int val : subset) cout << val << " ";
        cout << "]" << endl;
        ans.push_back(subset);
        return;
    }

    // Include nums[i] in subset
    cout << "Including nums[" << i << "] = " << nums[i] << endl;
    subset.push_back(nums[i]);
    getSubsets(nums, subset, ans, i + 1);

    // Backtrack: remove nums[i] and try without it
    cout << "Excluding nums[" << i << "] = " << nums[i] << " after backtracking" << endl;
    subset.pop_back();
    getSubsets(nums, subset, ans, i + 1);
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