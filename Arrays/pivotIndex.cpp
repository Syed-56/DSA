#include <iostream>
#include <vector>
using namespace std;

int pivotIndex(vector<int> nums) {
    int n = nums.size();
    int sumLeft, sumRight;
    int pivotIndex = 0;
    bool found=false;
    while (pivotIndex < n) {
        sumLeft=0, sumRight=0;
        for(int j=0; j<pivotIndex; j++) {
            sumLeft += nums[j];
        }
        for(int j=n-1; j>pivotIndex; j--) {
            sumRight += nums[j];
        }
        cout << "\nPivot Index = " << pivotIndex << endl;
        cout << "Sum from Pivot Index Left = " << sumLeft << endl;
        cout << "Sum from Pivot Index Right = " << sumRight << endl;
        if(sumLeft==sumRight) {
            found=true;
            break;
        }
        else {
            pivotIndex++;
        }
    }
    if(found)   return pivotIndex;
    else    return -1;
}

int main() {
    vector<int> nums = {1,2,3,3,0};
    cout << "Pivot Index = " << pivotIndex(nums);
}