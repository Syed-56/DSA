#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1,2,3,4,5};

    cout << "Subarrays:-\n";
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            for(int k=i; k<=j; k++) {
                cout << arr[k] << " ";
            }
            cout << "\t";
        } 
        cout << endl;
    }
}