#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> vec = {1,2,3,4};
    cout << "Max Element = " << *(max_element(vec.begin(),vec.end()));
    cout << "\nMin Element = " << *(min_element(vec.begin(),vec.end()));
    
}