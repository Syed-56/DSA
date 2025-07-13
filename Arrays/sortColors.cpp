#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> sortColor(vector<int> nums) {
    sort(nums.begin(), nums.end());
    return nums;
}

int main() {
    vector<int> colors = {2,0,2,1,1,0,1,2,0,0};
    vector<int> nums = sortColor(colors);
    for(int val:nums)   cout << val << " ";
}