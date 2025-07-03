#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int> nums) {
    int n = nums.size();
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if (nums[i] == nums[j] && i != j)   return true;
        }
    }
    return false;
}

int main() {
    vector<int> nums = {1,2,1,4,2};
    cout << "Existence of Duplicate: " << findDuplicate(nums);
}