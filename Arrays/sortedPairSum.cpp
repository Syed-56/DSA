#include <iostream>
#include <vector>
using namespace std;

vector<int> sumOfPairs(vector<int> nums, int target) {
    vector<int> pair(2,0);
    int start=0, end=nums.size()-1;

    while(start < end) {
        int sum = nums[start] = nums[end];
        if(sum > target)    end--;
        else if(sum < target)   start++;
        else {
            pair[0] = start;
            pair[1] = end;
            return pair;
        }
    }
    return pair;
}

int main() {
    vector<int> nums = {2,7,11,13};
    int target = 11;
    vector<int> pairSum = sumOfPairs(nums,target);
    cout << "Pair Sum: ";

    for(int val : pairSum)  cout << val << " ";
}