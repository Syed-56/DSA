#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "Syed Sultan";
    cout << str << "\n" << str.length() << endl;
    string str2 = "Ahmed";
    str += " " + str2; // Concatenating strings
    cout << str << "\n";

    string inputString;
    cout << "Enter a string: ";
    getline(cin, inputString); // Using getline to read a full line including spaces
    cout << "You entered: " << inputString << "\n";
}