#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int arr[5] = {2,3,6,1,5};
    sort(arr,arr+5);
    for(int val:arr)    cout << val << " ";
    cout << endl;

    vector<int> vec = {2,1,4,3,1,2};
    sort(vec.begin(),vec.end());
    for(int val:vec)    cout << val << " ";
    cout << endl;

    //reversing sort (descending order)
    sort(arr,arr+5,greater<int>());
    for(int val:arr)    cout << val << " ";
    cout << endl;

}