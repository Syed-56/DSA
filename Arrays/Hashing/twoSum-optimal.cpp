#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> nums, int target) {
    
}

int main() {
    vector<int> nums = {2,7,11,5};
    int target = 13;
    vector<int> pair = twoSum(nums,target);
    cout << "Pair: ";
    for(int val : pair)  cout << val << " ";
}