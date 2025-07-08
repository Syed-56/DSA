#include <iostream>
using namespace std;
int main() {
    int arr1[] = {1,2,3,4}; //array size initializes to 4 by itself
    int arr2[5] = {1,2,3,4};    //it means first four elements of array are initialized but 5th one is not
    int arr3[4] = {1,2,3,4};   //all indexes are initialized
    int arr4[5];    //array is declared but not initialized

    arr4[0] = 1;    //manually initializing array
    for(int i=1; i<5; i++)  cin >> arr4[i]; //user input

    //printing array
    for(int i=0; i<5; i++) {
        cout << arr4[i] << " ";
    }
    int arr1Size = sizeof(arr1)/sizeof(int);    //since array is int type, the sizeof(arr1) give whole array's bytes and dividing it by the bytes of int give the actual array size
    cout << endl << arr1Size;
}