#include <vector>
#include <iostream>
using namespace std;

int singleNumber(vector<int>& nums) {   //STL containers are by-default passed by value so we use & to pass address
    int ans = 0;
    for(int val: nums) {
        ans ^= val;     //here number is being xored by himself so duplicates xoring themselves will result in 0 and the remaining number xoring with 0 will return itselt
    }
    return ans;
}

int main() {
    int size;
    cout << "Enter Vector Size: ";
    cin >> size;
    vector<int> vec(size);
    cout << "Input Vector Elements: ";
    for(int i=0; i<size; i++)   cin >> vec.at(i);
    cout << "Unique Element: " << singleNumber(vec);
    return 0;
}