#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> squareAndSort(vector<int>& nums) {
    int n = nums.size();
    int start = 0, end = n-1;
    vector<int> arrayToReturn(n,0);
    for(int i=0; start < end; i++) {
        if(abs(nums[start]) < abs(nums[end])) {
            arrayToReturn[n-1-i] = nums[end]*nums[end];
            end--;
        }
        else {
            arrayToReturn[n-1-i] = nums[start]*nums[start];
            start++;
        }

    }
    return arrayToReturn;
}

int main() {
    vector<int> arr = {-4,-1,0,3,5,10};
    vector<int> nums = squareAndSort(arr);
    cout << "Squared and Sorted: ";
    for(int val : nums)  cout << val << " ";
}