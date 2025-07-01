#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> nums, int target) {
    vector<int> pair(2,0);
    for(int i=0; i<nums.size(); i++) {
        for(int j=i+1; j<nums.size(); j++) {
            if(nums[i]+nums[j]==target) {
                pair[0] = i;
                pair[1] = j;
                return pair;
            }
        }
    }
    return pair;
}

int main() {
    vector<int> nums = {2,7,11,5};
    int target = 13;
    vector<int> pair = twoSum(nums,target);
    cout << "Pair: ";
    for(int val : pair)  cout << val << " ";
}