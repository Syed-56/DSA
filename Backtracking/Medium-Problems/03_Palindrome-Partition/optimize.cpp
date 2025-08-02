#include <iostream>
#include <vector>
#include <string>
using namespace std;

void backTrack(string s, vector<vector<string>>& ans, vector<string>& combination, int i) {
    if(i==s.size())     return;
    
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> combination;
    backTrack(s,ans,combination,0);
    return ans;
}

int main() {
    string s = "aabc";
    vector<vector<string>> combinations = partition(s);
    for(const auto& row:combinations) {
        for(string val:row) {
            cout << val << " ";
        }
        cout << endl;
    }
}