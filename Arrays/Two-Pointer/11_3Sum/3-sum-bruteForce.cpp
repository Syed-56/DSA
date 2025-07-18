#include <iostream>
#include <vector>
using namespace std;

vector<int> threeSum(vector<int> nums) {

}

int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<int> pairs = threeSum(nums);
    cout << "PAir Indices: ";
    for(int val:pairs)  cout << val << " ";
}