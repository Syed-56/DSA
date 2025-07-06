#include <iostream>
#include <vector>
using namespace std;

int maximumProductInSubarray(vector<int>& nums) {
    int n = nums.size();
    int maxProduct = INT16_MIN;
    int currentProduct=1;
    for(int i=0; i<n; i++) {
        if(nums[i] < currentProduct*nums[i])    currentProduct=1;
        else    currentProduct *= nums[i];
        maxProduct = max(maxProduct,currentProduct);
    }
    return maxProduct;
}

int main() {
    vector<int> arr = {2,3,-2,4};
    int maxProduct = maximumProductInSubarray(arr);
    cout << "Maximum Product = " << maxProduct;
}