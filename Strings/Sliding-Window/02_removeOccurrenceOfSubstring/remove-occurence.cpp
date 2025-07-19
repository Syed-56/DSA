#include <iostream>
#include <string>
using namespace std;

string removeOccurrences(string s, string part) {
    int open=0, close=part.length();
    while (close <= s.length()) {
        if(s.substr(open, close-open) == part) {
            s.erase(open, close - open);
            open = 0;
            close = part.length();
        }
        else {
            open++;
            close++;
        }
    }
    return s;
}

int main() {
    string s = "daabcbaabcbc";
    string part = "abc";
    
    string result = removeOccurrences(s, part);
    cout << result << endl; 
    
    return 0;
}