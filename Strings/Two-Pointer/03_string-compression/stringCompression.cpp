#include <iostream>
#include <string>
#include <vector>
using namespace std;

int compress(vector<char>& chars) {
    int n = chars.size();
    vector<char> ans;
    for(int i=0; i<n; i++) {
        int count=1;
        if(count==1)    ans.push_back(chars[i]);
        while(i<n-1 && chars[i]==chars[i+1]) {
            count++;
            i++;
        }
        if (count > 1) {
            string countStr = to_string(count);
            for (char c : countStr) {
                ans.push_back(c);
            }
        }
    }
    
    chars = ans; // Update the original vector with compressed characters
    return ans.size();
}

int main() {
    vector<char> s = {'a', 'a', 'b', 'b','c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c'};
    int compressed = compress(s);
    cout << "\nCompressed length: " << compressed << endl;
    return 0;
}