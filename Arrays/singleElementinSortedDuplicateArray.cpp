#include <iostream>
#include <vector>
using namespace std;

int singleElement(vector<int> nums) {
    //if(nums[i+1] != nums[i] || nums[i-1] != nums[i] && count==0)  return nums[i]
    //if(nums[i] != nums[i+1])  count=0
    //else  count++
    int count=0;
    int n = nums.size();
    for(int i=0; i<n-1; i++) {
        if(nums[i] != nums[i+1]) {
            if(count==0)    return nums[i];
            else    count=0;
        }
        else {
            count++;
        }
    }
    return nums[n-1];
}

int main() {
    vector<int> nums = {1,1,2,2,3,3,5};
    cout << "Single Element = " << singleElement(nums);
}