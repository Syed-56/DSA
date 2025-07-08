#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> nums, int target) {
    int start=0, end = nums.size()-1;
    while(start <= end) {
        int mid = (start+end)/2;
        //if start = end = INT_MAX then overflow occur in a test case so to escape that you can use mid = start + (end-start)/2
        if(target > nums[mid]) {
            start = mid+1;
        }
        else if(target < nums[mid]) {
            end = mid-1;
        }
        else {
            return mid;
        }
    }
    return -1;
}

int main() {
    vector<int>  arr = {1,2,3,4,5};
    vector<int>  nums = {2,4,5,6,8,8};
    int target=5;
    cout << "Target in Array 1 = " << binarySearch(arr,target);
    cout << "\nTarget in Array 2 = " << binarySearch(nums,target);

}