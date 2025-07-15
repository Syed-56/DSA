#include <iostream>
using namespace std;

int main() {
    //Initializing
    int matrix[3][2];
    int arr[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    //Printing
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    //Inputting
    for(int i=0; i<3; i++) {
        cout << "\nInput Row " << i+1 << ": ";
        for(int j=0; j<2; j++) {
            cin >> matrix[i][j];
        }
    }

    for(int i=0; i<3; i++) {
        for(int j=0; j<2; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}