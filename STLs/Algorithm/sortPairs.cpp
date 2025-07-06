#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<pair<int,int>> vec = {{1,2},{1,3},{7,1},{2,5}};
    sort(vec.begin(),vec.end());    //pairs are sorted on the basis of their first value
    for(auto val:vec)    cout << val.first << " " << val.second << "\n";
    cout << endl;
}