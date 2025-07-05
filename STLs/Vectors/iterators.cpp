#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec = {1,2,3,4,5};
    vector<int>::iterator it;   //this creates it iterator of datatype vector
    for(it = vec.begin(); it != vec.end(); it++) {  //forward loop
        cout << *(it) << " ";
    }
    cout << endl;
    //it is a pointer to a index so we dereference to print value at that index
    for(auto it=vec.rbegin(); it != vec.rend(); it++) {     //backward loop uses rbegin and rend
        cout << *(it) << " ";
    }
    //to escape form always writing vector<int>::iterator it, you can simply use auto in for loop
}