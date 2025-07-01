#include <iostream>
#include <vector>
using namespace std;

void maxSubArray(vector<int>& nums) {
    int maxSum=0;
    for(int i=0; i<nums.size(); i++) {
        for(int j=i; j<nums.size(); j++) {
            int sum=0;
            for(int k=i; k<=j; k++) {
                sum += nums[k];
            }
            cout << sum << " ";
            if(sum > maxSum)    maxSum=sum;
        }
        cout << endl;
    }
    cout << "Max Sum: " << maxSum;
}

int main() {
    vector<int> nums = {1,2,3,4,5};
    maxSubArray(nums);
}