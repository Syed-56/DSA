#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comparitor(pair<int,int> p1, pair<int,int> p2) {
    if(p1.second < p2.second)   return true;
    else if(p1.second == p1.first) {
        if(p1.first < p2.first)     return true;
        else    return false;
    }
    else    return false;
}

int main() {
    vector<pair<int,int>> vec = {{1,2},{1,3},{7,1},{2,1}};
    sort(vec.begin(), vec.end(), comparitor);
    for(auto val:vec)    cout << val.first << "," << val.second << "\n";
    cout << endl;
}