#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target) {
    for(int i=0; i<size; i++) {
        if(arr[i]==target)  return i;
    }
    return -1;
}

int main() {
    int arr[5] = {1,0,7,4,8};
    int target = 7;
    int found = linearSearch(arr,5, target);

    if(found==-1)   cout << "Target Not Found";
    else    cout << "Target Found at Index: " << found;
    cout << endl;
    target = 10;
    found = linearSearch(arr,5, target);

    if(found==-1)   cout << "Target Not Found";
    else    cout << "Target Found at Index: " << found;
}