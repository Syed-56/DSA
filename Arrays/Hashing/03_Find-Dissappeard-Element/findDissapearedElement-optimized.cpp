#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> findDissappeared(vector<int>& nums) {
    int n = nums.size();
    unordered_set<int> numSet;

    for(int i=n-1; i>=0; i--) {
        numSet.insert(nums[i]);
        nums.pop_back();
    }

    for(int i=1; i<=n; i++) {
        if(numSet.find(i) == numSet.end()) {
            nums.push_back(i);
        }
    }
    return nums;
}

int main() {
    vector<int> arr = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> result = findDissappeared(arr);
    cout << "The disappeared elements are: ";
    for (int num : result) {
        cout << num << " ";
    }
}