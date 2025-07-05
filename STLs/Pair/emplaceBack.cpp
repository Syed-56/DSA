#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<pair<int,int>> vp = {{1,2}, {2,3}};
    vp.push_back({4,5});    //pushing a pair
    vp.emplace_back(6,9);   //using emplace_back we dont need to make a pair
    for(auto val:vp)    cout << val.first << "," << val.second << endl;
}