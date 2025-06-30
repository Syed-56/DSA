#include <vector>
#include <iostream>
using namespace std;

int singleNumber(vector<int>& nums) {   //STL containers are by-default passed by value so we use & to pass address
    bool found;
    for(int i=0; i<nums.size(); i++) {
        found = false;
        for(int j=0; j<nums.size(); j++) {
            if(nums.at(i)==nums.at(j) && i!=j)    found= true;
        }
        if(!found)  return nums.at(i);
    }
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