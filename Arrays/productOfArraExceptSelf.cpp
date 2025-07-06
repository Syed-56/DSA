#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int> nums) {
    int n = nums.size();
    vector<int> ans(n,1);

    int prefix=1;
    for(int i=1; i<n; i++) {
        prefix *= nums[i-1];
        ans[i] = prefix;
    }
    int suffix=1;
    for(int i=n-2; i>=0; i--) {
        suffix *= nums[i+1];
        ans[i] *= suffix;
    }

    return ans;
}

int main() {
    vector<int> arr = {1,2,3,4};
    vector<int> nums = productExceptSelf(arr);
    for(int val:nums)   cout << val << " ";
}