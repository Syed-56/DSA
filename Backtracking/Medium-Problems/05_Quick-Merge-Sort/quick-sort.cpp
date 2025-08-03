#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int>& nums, int start, int end) {

}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int n = arr.size()-1;
    quickSort(arr,0,n);
    for(int val:arr)    cout << val << " ";
}