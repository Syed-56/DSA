#include <iostream>
#include <vector>
using namespace std;

vector<char> reverseString(vector<char>& s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }

    return s;
}

int main() {
    vector<char> charArray = {'H', 'e', 'l', 'l', 'o'};
    vector<char> reversedArray = reverseString(charArray);
    cout << "Reversed string: ";
    for (char c : reversedArray) {
        cout << c;
    }
    cout << endl;

    return 0;
}