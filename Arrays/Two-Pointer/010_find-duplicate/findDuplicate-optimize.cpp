#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int> nums) {
    int slow = nums[0];
    int fast = nums[0];

    //do while loop bcz we also have to take account the iteration when they became equal
    do {
        slow = nums[slow];  //move 1x
        fast = nums[nums[fast]];    //move 2x
    }
    while(slow != fast);

    slow = nums[0];
    while(slow != fast) {
        slow = nums[slow];
        fast = nums[fast];  //both move at same speed
    }

    return fast;
}

int main() {
    vector<int> nums = {3,1,3,4,2};
    int duplicate = findDuplicate(nums);
    cout << "Duplicate: " << duplicate << endl;
}