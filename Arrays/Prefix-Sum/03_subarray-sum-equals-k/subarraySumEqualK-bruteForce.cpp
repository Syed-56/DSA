#include <iostream>
#include <vector>
using namespace std;

vector<int> subArraySumEqualK(vector<int> nums, int target) {

}

int main() {
    vector<int> nums = {1,2,3};
    int k = 3;
    vector<int> result = subArraySumEqualK(nums,k);
    cout << "Subarray = ";
    for(int val:nums)   cout << val << " ";
}