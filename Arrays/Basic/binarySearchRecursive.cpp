#include <iostream>
#include <vector>
using namespace std;

int binarySearchRec(vector<int> nums, int target, int start, int end) {
    int mid = (start+end)/2;
    if(target > nums[mid])        return binarySearchRec(nums,target,mid+1,end);
    else if(target < nums[mid])   return binarySearchRec(nums,target,start,mid-1);
    else    return mid;
}

int main() {
    vector<int> arr = {2,4,5,7};
    int target = 7;
    cout << "Target at " << binarySearchRec(arr,target,0,arr.size()-1);
}