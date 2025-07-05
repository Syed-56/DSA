#include <iostream>
#include <vector>
using namespace std;

vector<int> removeElement(vector<int>& nums, int k) {
    int insertPos=0;
    for(int val:nums) {
        if(val != k) {
            nums[insertPos++] = val;
        }
    }
    for(int i=insertPos; i<nums.size(); i++)    nums[i] = k;
    for(int val:nums)   cout << val << " ";
    return nums;
}

int main() {
    vector<int> nums = {0,1,2,2,3,4,2};
    int k=3;
    cout << "After Removing " << k << " = ";
    for(int val:nums)   cout << val << " ";
}