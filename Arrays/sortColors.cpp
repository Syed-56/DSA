#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> sortColor(vector<int> nums) {
    int zeroCount=0, oneCount=0, twoCount=0;
    for(int val:nums) {
        if(val==0)  zeroCount++;
        else if(val==1)  oneCount++;
        else if(val==2)  twoCount++;
    }

    for(int i=0; i<zeroCount; i++)  nums[i] = 0;
    for(int i=zeroCount; i<zeroCount+oneCount; i++)   nums[i] = 1;
    for(int i=zeroCount+oneCount; i<nums.size(); i++)    nums[i] = 2;

    return nums;
}

int main() {
    vector<int> colors = {2,0,2,1,1,0,1,2,0,0};
    vector<int> nums = sortColor(colors);
    for(int val:nums)   cout << val << " ";
}