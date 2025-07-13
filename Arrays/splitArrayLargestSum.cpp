#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> nums, int n, int k, int maxPages) {
    int student=1, pages=0;
    for(int i=0; i<n; i++) {
        if(pages + nums[i] <= maxPages) pages += nums[i];
        else {
            student++;
            pages = nums[i]; //keeping track of pages of new student
        }
    }
    if (student > k)    return false;
    else    return true;
}

int maxSumMinimized(vector<int> nums, int k) {
    int n = nums.size();
    int sum=0;
    for(int i=0; i<n; i++)  sum += nums[i];     //ans lies bw this range as these are the pages.
    //but we will have invalid answers like 0 (no pages for everyone) and 10(all pages for 1) Also 5 (no contagious sum is 5

    int start=0, end=sum, mid;
    while(start <= end) {
        mid = start + (end-start)/2;
        if(isValid(nums,n,k,mid)) {
            end=mid-1;  //to find for a smaller valid answer
        }
        else {
            start=mid+1;    //means you need more than mentioned students for 'mid' amount of pages so it means pages cant be reduced more
        }
    }
    return mid;
}

int main() {
    vector<int> nums = {1,2,3,4,5};
    int k=2;
    cout << "Maximum Sum Minimized = " << maxSumMinimized(nums,k);
}