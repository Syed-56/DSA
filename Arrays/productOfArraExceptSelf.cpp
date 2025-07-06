#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int> nums) {
    int n = nums.size();
    vector<int> arrayToReturn;
    int product;
    for(int i=0; i<n; i++) {
        product=1;
        for(int j=0; j<n; j++) {
            if(i == j)  continue;
            product *= nums[j];
        }
        arrayToReturn.push_back(product);
    }
    return arrayToReturn;
}

int main() {
    vector<int> arr = {1,2,3,4};
    vector<int> nums = productExceptSelf(arr);
    for(int val:nums)   cout << val << " ";
}