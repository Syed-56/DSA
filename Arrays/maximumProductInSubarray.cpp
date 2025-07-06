#include <iostream>
#include <vector>
using namespace std;

int maximumProductInSubarray(vector<int>& nums) {
    int n = nums.size();
    int maxProduct = INT16_MIN;
    for(int i=0; i<n; i++) {
        int currentProduct = 1;
        for(int j=i; j<n; j++) {
            currentProduct *= nums[j];
            maxProduct = max(currentProduct, maxProduct);
        }
    }
    return maxProduct;
}

int main() {
    vector<int> arr = {2,3,-2,4};
    int maxProduct = maximumProductInSubarray(arr);
    cout << "Maximum Product = " << maxProduct;
}