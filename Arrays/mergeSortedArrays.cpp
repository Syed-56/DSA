#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int size1 = nums1.size(), size2 = nums2.size();
    for(int i=m; i<size1; i++) {
        nums1.pop_back();
    }
    int index=0;
    for(int i=m; i<m+n; i++) {
        nums1.push_back(nums2[index]);
        index++;
    }
    sort(nums1.begin(), nums1.end());
}

int main() {
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m=3, n=3;
    merge(nums1,m,nums2,n);
    for(int val:nums1)  cout << val << " ";
}