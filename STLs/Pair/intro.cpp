#include <iostream>
#include <vector>
using namespace std;

int main() {
    //initializing method
    pair<int, int> p1 = {1,2};  
    pair<string, int> p2("Sultan", 18);
    pair<float, bool> p3 = make_pair(6.9,true); //very usefil
    
    cout << p1.second << " " << p2.first;
    p3.second = false;  //update value

}