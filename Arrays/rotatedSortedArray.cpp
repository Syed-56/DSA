#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> nums, int target) {
    int start=0, end=nums.size()-1;
    while(start <= end) {
        int mid = start + (end-start)/2;
        if(target==nums[mid])   return mid;
        //check if left half is sorted
        if(nums[start] <= nums[mid]) {
            if(nums[start] <= target && target < nums[mid]) {    //Inside left sorted array: check if target is in left half or right half
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        //otherwise right half must be sorted
        else {
            if(nums[end] >= target && target > nums[mid]) {   //Inside right sorted array: check if target is in left half or right half
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {4,5,6,7,0,1,2};
    int target=0;
    cout << "Index = " << search(arr,target);
}