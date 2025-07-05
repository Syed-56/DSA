#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> squareAndSort(vector<int>& nums) {
    for(int& val : nums) {
        val *= val;
    }
    sort(nums.begin(), nums.end());
    return nums;
}

int main() {
    vector<int> arr = {-4,-1,0,3,10};
    vector<int> nums = squareAndSort(arr);
    cout << "Squared and Sorted: ";
    for(int val : nums)  cout << val << " ";
}