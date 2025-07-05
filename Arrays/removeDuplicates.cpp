#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int count=1, pointer=0;     //bcz nums[0] will always be unique
    for(int i=1; i<n; i++) {
        if(nums[i] != nums[pointer]) {
            nums[count] = nums[i];
            count++;
            pointer=i;
        }
    }
    for(int i=count; i<n; i++) {
        nums[i] = INT16_MIN;
    }

    for(int val:nums) {
        cout << val << " ";
    }
    return count;
}

int main() {
    vector<int> arr = {1,1,2,3,3,3,4,4,5};
    cout << "Unique = " << removeDuplicates(arr);
}