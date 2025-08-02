#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

set<vector<int>> s;
void backTrack(vector<int> nums, int i, vector<int>& combination, vector<vector<int>>& ans, int target) {
    if(i==nums.size()) {
        return;
    }
    if(target==0) {
       if(s.find(combination) == s.end()) {
            s.insert(combination);
            ans.push_back(combination);
        }
        return;
    }
    if(target<0) {
        return;
    }
    combination.push_back(nums[i]);
    backTrack(nums,i+1,combination,ans,target-nums[i]); //include element once
    combination.pop_back(); //exclude element while backtracking
    int next=i+1;
    while(i>0 && nums[i-1]==nums[i]) {
        next++;
    }
    backTrack(nums,next,combination,ans,target); //since we dont include a number so we dont decrease our target
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<int> combination;
    vector<vector<int>> ans;
    sort(candidates.begin(), candidates.end());
    backTrack(candidates,0,combination,ans,target);
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<int> nums = {2,3,5};
    vector<vector<int>> sumsPair = combinationSum2(nums,8);
    for(const auto& row:sumsPair) {
        for(int val:row) {
            cout << val << " ";
        }
        cout << endl;
    }
}