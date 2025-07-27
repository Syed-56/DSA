#include <iostream>
#include <vector>
using namespace std;

void backTrack(vector<int>& nums, vector<vector<int>>& ans, int i) {

}

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> permutations;
    backTrack(nums,permutations,0);
    for(const auto& row:permutations) {
        for(int val:row) {
            cout << val;
        }
        cout << endl;
    }
}