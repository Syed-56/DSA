#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> combinationSum(vector<int>& nums, int target) {

}

int main() {
    vector<int> nums = {2,3,5};
    vector<vector<int>> sumsPair = combinationSum(nums,8);
    for(const auto& row:sumsPair) {
        for(int val:row) {
            cout << val << " ";
        }
        cout << endl;
    }
}