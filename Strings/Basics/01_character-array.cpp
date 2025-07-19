#include <iostream>
using namespace std;

int main() {
    // Declare a character array
    char name[20];

    // Prompt user for input
    cout << "Enter your name: ";
    cin.getline(name, 20);

    // Output the entered name
    cout << "Hello, " << name << "!" << endl;

    //initialization: (\0 used to terminate character array)
    char str[] = {'h','e','l','l','o','\0'};
    char str1[] = "\nhello"; // equivalent to the above initialization
    cout << str << str1;
    
    return 0;
}