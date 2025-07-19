#include<iostream>
#include<string>
#include <vector>
#include <unordered_set>
using namespace std;

int longestSubstringWithourRepeatingCharacters(string s) {
    int maxLen=0;
    string substringToPrint = "";
    int left=0, right=0;
    int currentLength;
    while(right < s.length()) {
        if (s[left] != s[right]) {
            substringToPrint += s[right];
            currentLength++;
        }
        else {
            left = right;
            currentLength=0;
            maxLen = max(maxLen, int(substringToPrint.length()));
        }
        right++;
    }
    cout << substringToPrint << "\t";
    return maxLen;
}

int main() {
    string s = "abcabcbcbb";
    cout << "Length = " << longestSubstringWithourRepeatingCharacters(s);
}