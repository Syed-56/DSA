#include <iostream>
#include <map>
using namespace std;

int main() {
    multimap<string, int> m;

    m.emplace("tv",100);
    m.emplace("tv",800);
    m.emplace("tv",500);

    for(auto val:m)   cout << endl << val.first << " " << val.second;
    cout << endl;
    m.erase(m.find("tv"));  //remove 1 instance of tv
    for(auto val:m)   cout << endl << val.first << " " << val.second;
    cout << endl;

    m.erase("tv");
    cout << "\nSize of map = " << m.size();
} 
