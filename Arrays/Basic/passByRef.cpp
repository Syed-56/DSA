#include <iostream>
using namespace std;

void changeArr(int arr[], int size) {
    for(int i=0; i<size; i++)   arr[i] *= 2;
    cout << "In Function:";
    for(int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[5] = {1,2,3,4,5};
    changeArr(arr,5);
    cout << "In main:";
    for(int i=0; i<5; i++) {
        cout << arr[i] << " ";  //the reason that both outputs are same despite not passing the address is that non primitive data types are always passed by reference.
    } 
    cout << endl;
}