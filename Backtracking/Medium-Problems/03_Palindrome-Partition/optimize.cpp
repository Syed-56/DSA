#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindrome(string s) {
    int start=0, end = s.size()-1;
    while(start < end) {
        if(s[start] != s[end])  return false;
        start++;
        end--;
    }
    return true;
}

void backTrack(string s, vector<vector<string>>& ans, vector<string>& combination, int call) {
    if(call==s.size()) {
        ans.push_back(combination);
        return;
    }

    for(int i=call; i<s.size(); i++) {
        if(isPalindrome(s.substr(call,i-call+1))) {
            combination.push_back(s.substr(call,i-call+1));
            backTrack(s,ans,combination,i+1);   //now find palindrome from string after current letter
            combination.pop_back(); //backtrack
        }
    }
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