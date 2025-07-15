#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int> nums, int target) {
    int n = nums.size();
    unordered_map<int,int> pair;
    vector<int> ans;

    for(int i=0; i<n; i++) {
        int first = nums[i];
        int second = target - nums[i];
        if(pair.find(second) != pair.end()) {   //this checks if second variable value exist in hashmap
            ans.push_back(pair[second]);    //this gives the value at key second(we have a value of array stored in map as key whose value is index)
            ans.push_back(i);
            return ans;
        }
        pair.emplace(nums[i],i);
    }
    return ans;
}

int main() {
    vector<int> nums = {2,7,11,5};
    int target = 13;
    vector<int> pair = twoSum(nums,target);
    cout << "Pair: ";
    for(int val : pair)  cout << val << " ";
}