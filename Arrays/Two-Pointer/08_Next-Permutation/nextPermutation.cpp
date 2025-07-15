#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int pivotIndex = -1;
    for(int i=n-1; i>=0; i--) {
        if(nums[i-1] < nums[i]) {
            pivotIndex = i-1;
            break;
        }
    }
    
     if(pivotIndex == -1) {
         reverse(nums.begin(), nums.end());
         return nums;
     }

    cout << "Pivot Element: " << nums[pivotIndex] << endl;

    int IndexofnextBig = -1;
    for(int val:nums)   cout << val << " ";
    cout << endl;
    for(int i=n-1; i>=0; i--) {
        if(nums[i] > nums[pivotIndex]) {
            IndexofnextBig = i;
            break;
        }
    }
    cout << "Next Big: " << nums[IndexofnextBig] << endl;
    swap(nums[IndexofnextBig],nums[pivotIndex]);
    reverse(nums.begin()+pivotIndex+1, nums.end());

    return nums;
}

int main() {
    vector<int> perm = {1,2,3,6,5,4};
    vector<int> nextPerm = nextPermutation(perm);
    for(int val:nextPerm)   cout << val << " ";
}