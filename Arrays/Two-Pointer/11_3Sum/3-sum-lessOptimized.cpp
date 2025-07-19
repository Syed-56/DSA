#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums, int target) {
    set<vector<int>> result;   //we use set so we dont get any duplicates
    int n = nums.size();

    for(int i=0; i<n; i++) {
        set<int> seen; 
        int a = nums[i];
        for(int j=i+1; j<n; j++) {
            int b = nums[j];
            int c = 0 - (a + b);    //wrote 0 for the sake of understanding.
            vector<int> triplet;
            if(seen.find(c) != seen.end()) {
                triplet = {a,b,c};
                sort(triplet.begin(), triplet.end()); 
                result.insert(triplet);
            }
            seen.insert(b);
        }
    }
    vector<vector<int>> finalResult(result.begin(), result.end());
    return finalResult;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    int target = 0;
    vector<vector<int>> result = threeSum(nums, target);
    for (const auto& triplet : result) {
        cout << "[";
        for (size_t i = 0; i < triplet.size(); ++i) {
            cout << triplet[i];
            if (i < triplet.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }   

}