#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> m;
    //here string is datatype of key and int is datatype of value. The value can be reassigned but a key can't
    m["tv"] = 100;
    m["laptop"] = 50;
    m["headphone"] = 10;
    for(auto val:m)     cout << val.first << " " << val.second << endl;
    //the output is in ascending order wrt key 
    m["tv"] = 10;
    cout << endl << m["tv"];    //prints value at key
    
    m.insert({"Tablet",10});    //inserts key
    cout << endl << m["Tablet"];   
    m.emplace("Camera",25); //no braces needed
    cout << endl << m["Camera"];
    cout << endl << m.count("laptop");  //prints number of laptop keys
    m.erase("laptop");

    //now use find function to check if laptop exist or not
    if(m.find("laptop") != m.end()) {
        cout << "\nLaptop Found";
    } else  cout << "\nLaptop Not Found";
    cout << endl;
    for(auto val:m)     cout << val.first << " " << val.second << endl;
}