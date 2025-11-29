#include <iostream>
using namespace std;

void buildLPS(string pattern, int LPS[]) {
    int n = pattern.length();
    int i=1, len=0;
    LPS[0]=0;

    while(i<n) {
        if(pattern[i]==pattern[len]) {
            len++;
            LPS[i]=len;
            i++;
        }
        else {
            if(len!=0)    len = LPS[len-1];
            else {
                LPS[i]=0;
                i++;
            }            
        }
    }
}

void KMPsearch(string text, string pattern) {
    int textLen = text.length();
    int patternLen = pattern.length();
    int i=0, j=0;
    int LPS[patternLen];
    buildLPS(pattern,LPS);

    while(i<textLen) {
        if(text[i]==pattern[j]) {
            i++, j++;
            if(j==patternLen) {
                cout << "Pattern Found at Index " << i-j << endl;
                j = LPS[j-1];
            }
        }
        else {
            if(j!=0) j=LPS[j-1];
            else    i++;
        }
    }
}

int main() {
    string text = "ababcababababcabab";
    string pattern = "ababcabab";

    KMPsearch(text, pattern);
}