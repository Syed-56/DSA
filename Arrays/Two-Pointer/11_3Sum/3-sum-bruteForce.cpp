#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector <int>> threeSum(vector<int> nums) {
    int n = nums.size();
    vector<vector <int>> pairs;
    set<vector <int>> set;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            for(int k=j+1; k<n; k++) {
                if(i==j && j==k && i==k) continue;
                if(nums[i]+nums[j]+nums[k] == 0) {
                    vector<int> triplets = {nums[i],nums[j],nums[k]};
                    sort(triplets.begin(), triplets.end());

                    if(set.find(triplets) == set.end()) {
                        set.insert(triplets);
                        pairs.push_back(triplets);
                    }
                }
            }
        }
    }
    return pairs;
}

int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector <int>> pairs = threeSum(nums);
    cout << "PAir Indices: ";
    for(const auto& row:pairs) {
        for(int val:row) {
            cout << val << " ";
        }
        cout << endl;
    }
}