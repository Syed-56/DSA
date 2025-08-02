#include <iostream>
#include <vector>
using namespace std;

void backTrack(string s, vector<vector<string>>& ans, int i) {

}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    backTrack(s,ans,0);
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