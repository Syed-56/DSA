#include <iostream>
#include <vector>
using namespace std;

vector<int> squareAndSort(vector<int>& nums) {

}

int main() {
    vector<int> arr = {-4,-1,0,3,10};
    vector<int> nums = squareAndSort(arr);
    cout << "Squared and Sorted: ";
    for(int val : nums)  cout << val << " ";
}