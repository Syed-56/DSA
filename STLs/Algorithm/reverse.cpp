#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s = "abc";
    reverse(s.begin(),s.end());
    cout << s << endl;

    int arr[3] = {1,3,2};
    reverse(arr, arr+3);
    for(int val:arr)    cout << val << " ";

    string sul = "Sultan";    //want to reverse but dont change position of S and n
    reverse(sul.begin()+1, sul.end()-1);
    cout << endl << sul;
}