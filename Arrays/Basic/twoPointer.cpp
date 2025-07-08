#include <iostream>
#include <vector>
using namespace std;

vector<int> pairSum(vector<int> nums, int target) {
    int n = nums.size();
    int start=0;
    int end=n;
    vector<int> pair;

    while (start < end) {
        int sum = nums[start] + nums[end];
        if(sum > target) {
            end--;
        }
        else if(sum < target) {
            start++;
        }
        else {
            pair.push_back(start);
            pair.push_back(end);
            break;
        }
    }

    return pair;
    
}

int main() {
    vector<int> arr = {1,2,3,4};
    int target = 3;
    vector<int> index = pairSum(arr,target);
    for(int val:index)  cout << val << " ";
}