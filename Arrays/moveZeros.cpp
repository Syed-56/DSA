#include <iostream>
#include <vector>
using namespace std;

void moveZeros(vector<int>& nums) {
    int n = nums.size();
    int insertPos=0;
    for(int val:nums) {
        if(val != 0) {
            nums[insertPos++] = val;
        }
    }
    for(int i=insertPos; i<n; i++)  nums[i]=0;
}

int main() {
    vector<int> nums = {0,1,0,2,3};
    moveZeros(nums);
    for(int val:nums)   cout << val << " ";
}