#include <iostream>
#include <vector>
using namespace std;

int subArraySumEqualK(vector<int> nums, int k) {
    int result=0;
    int n = nums.size();

    for(int i=0; i<n; i++) {
        int sum = 0;
        for(int j=i; j<n; j++) {
            sum += nums[j];
            cout << sum << " ";
            if(sum==k)  result++;
        }
        cout << endl;
    }
    return result;
}

int main() {
    vector<int> nums = {1,2,3};
    int k = 3;
    int result = subArraySumEqualK(nums,k);
    cout << "Subarray Sum = " << result << endl;
}