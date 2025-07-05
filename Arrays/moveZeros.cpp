#include <iostream>
#include <vector>
using namespace std;

vector<int> moveZeros(vector<int>& nums) {
    int n = nums.size();
    vector<int> arr(n,0);
    int pointer=0;
    for(int i=0; i<n; i++) {
        if(nums[i]!=0) {
            arr[pointer] = nums[i];
            pointer++;
        }
    }
    nums = arr;
    return nums;
}

int main() {
    vector<int> nums = {0,1,0,2,3};
    nums = moveZeros(nums);
    for(int val:nums)   cout << val << " ";
}