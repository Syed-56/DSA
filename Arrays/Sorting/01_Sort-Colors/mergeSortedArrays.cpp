#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int idx = m+n-1, i=m-1, j=n-1;
    while(i>=0 && j>=0) {
        if(nums1[i] < nums2[j]) {
            nums1[idx] = nums2[j];
            idx--;
            j--;
        }
        else {
            nums1[idx] = nums1[i];
            idx--;
            i--;
        }
    }
    while (j >= 0) {
        nums1[idx--] = nums2[j--];
    }
}

int main() {
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m=3, n=3;
    merge(nums1,m,nums2,n);
    for(int val:nums1)  cout << val << " ";
}