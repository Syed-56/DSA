#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    //nested pairs
    pair<int, pair<string,int>> nested = {1,{"Sultan",18}};
    cout << nested.second.first << endl;

    //sorting pairs using vector
    vector<pair<int,int>> pairWithVector = {{2,3},{1,5},{1,2}};
    sort(pairWithVector.begin(), pairWithVector.end());
    for(auto val:pairWithVector)     cout << val.first << "," << val.second << "   ";
}