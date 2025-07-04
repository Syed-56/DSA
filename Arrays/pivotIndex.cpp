#include <iostream>
#include <vector>
using namespace std;

int pivotIndex(vector<int> nums) {
    int n = nums.size();
    int totalSum=0;
    int pivotIndex;
    bool found=false;
    for(int i=0; i<n; i++) {
        totalSum += nums[i];
    }
    int rightSum=totalSum, leftSum=0;
    for(int i=0; i<n; i++) {
        rightSum -= nums[i];
        cout << "\nRigth Sum = " << rightSum;
        if(rightSum==leftSum) {
            pivotIndex=i;
            found=true;
            break;
        }
        leftSum += nums[i];
        cout << "\nLeft Sum = " << leftSum;
    }
    if(found)   return pivotIndex;
    else    return -1;
}

int main() {
    vector<int> nums = {2, 3, -1, 8};
    cout << "Pivot Index = " << pivotIndex(nums);
}