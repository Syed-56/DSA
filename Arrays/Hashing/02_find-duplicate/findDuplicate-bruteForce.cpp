#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    unordered_set<int> seen;
    for (int i=0; i<n; i++) {
        if(seen.find(nums[i]) != seen.end()) {
            return nums[i]; 
        }
        seen.insert(nums[i]);
    }
    
    return -1; // If no duplicate is found
}

int main() {
    vector<int> nums = {1, 3, 4, 2, 2};
    int duplicate = findDuplicate(nums);
    cout << "Duplicate: " << duplicate << endl;
}