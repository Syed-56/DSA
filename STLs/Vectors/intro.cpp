//vectors library is required to use them since its an STL (a group of DS)
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> vec;    //this creates a vector of size 0
    //cout << vec[0];   this will give segmentation fault bcz we are trying to access something which doesn't exist

    vector<int> vec1 = {1,2,3};
    cout << vec1[0] << endl;

    vector<char> vec2(3,'a'); //this creates vector of size 3 with each element being 0
    cout << vec2[1] << endl;

        //we use for each loop with STL Data Structures where the iterator is not index but the actual value so we output it 
    for(int i: vec1) {
        cout << i << " ";
    }
    cout << endl;
    for(char val: vec2) {
        cout << val << " ";
    }

    return 0;
}