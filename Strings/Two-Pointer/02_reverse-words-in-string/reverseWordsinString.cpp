#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reverseWord(string s) {
    int n = s.length();
    int letter = 0;
    string ans = "";
    reverse(s.begin(), s.end());

    while(letter < n) {
        if(s[letter] == ' ') {
            letter++;
            continue;
        }
        string word = "";
        while(s[letter] != ' ' && letter < n) {
            word += s[letter];
            letter++;
        }
        reverse(word.begin(), word.end());
        if(word.length()>0) ans += word + " ";
    }
    while(ans[ans.length() - 1] == ' ') {
        ans.pop_back();
    }
    return ans;
}

int main() {
    string s = "  Sky is the blue  ";
    string result = reverseWord(s);
    cout << "|" << result << "|"; 
}