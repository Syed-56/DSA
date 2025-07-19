#include <iostream>
#include <string>
using namespace std;

bool isValidPalindrome(string s) {
    int left = 0;
    int right = s.size() - 1;
    
    while (left < right) {
        while (left < right && !isalnum(s[left])) left++;
        while (left < right && !isalnum(s[right])) right--;
        if (tolower(s[left]) != tolower(s[right])) return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    string s = "Race car";
    if (isValidPalindrome(s)) {
        cout << "\"" << s << "\" is a valid palindrome." << endl;
    } else {
        cout << "\"" << s << "\" is not a valid palindrome." << endl;
    }
}