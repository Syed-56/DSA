#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int k) {

}

int main() {
    vector<int> nums = {0,1,2,2,3,4,2};
    int k=3;
    cout << "Instances of " << k << " removed = " << removeElement(nums,k);
}