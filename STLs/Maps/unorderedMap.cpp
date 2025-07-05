#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string,int> m;
    m.emplace("tv",100);
    m.emplace("fridge",100);
    m.emplace("earpod",20);
    for(auto val:m)     cout << val.first << " " << val.second << endl; //no ascending/descending order
}