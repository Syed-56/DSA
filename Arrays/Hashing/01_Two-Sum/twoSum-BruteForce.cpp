#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> twoSum(vector<int> nums, int target) {
    int n = nums.size();
    vector<int> pair(2,0);
    vector<int> tempNums = nums;
    sort(tempNums.begin(),tempNums.end());
    int start=0, end=n-1;
    int num1, num2;
    while(start < end) {
        int sum = tempNums[start] + tempNums[end];
        if(sum < target) {
            start++;
        }
        else if(sum > target) {
            end--;
        }
        else {
            num1 = tempNums[start];
            num2 = tempNums[end];
        }
    }
    for(int i=0; i<n; i++) {
        if(nums[i]==num1)   pair[0]=i;
        if(nums[i]==num2)   pair[1]=i;
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