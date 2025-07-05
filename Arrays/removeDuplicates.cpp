#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int count=n;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(nums[i] != -99 && nums[i]==nums[j]) {
                nums[j] = -99;
                count--;
            }
        }
    }
    int insertPos = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] != -99) {
            nums[insertPos++] = nums[i];
        }
    }
    while (insertPos < n) {
        nums[insertPos++] = -99;
    }

    for(int val:nums) {
        cout << val << " ";
    }
    return count;
}

int main() {
    vector<int> arr = {1,1,2};
    cout << "Unique = " << removeDuplicates(arr);
}