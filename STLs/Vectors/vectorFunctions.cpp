#include <vector>
#include <iostream>
using namespace std;

int main() {
    //array are static, they are stored in stack. vectors are dynamic, they are stored in heap
    vector<char> vec1 = {'a','b','c','d'};
    cout << "Size of Vec1: " << vec1.size();

    vec1.push_back('e');
    cout << "\nSize of Vec1 after Push Back: " << vec1.size();
    cout << "\nCapacity of Vec1 after Push Back: " << vec1.capacity();  //basically the size() is 5 bcz 5 elements are here but when we call push_back to insert element, the vector size is doubled for accomodation thats why 8 is output
    vec1.push_back('f');
    cout << "\nCapacity of Vec1 after Push Back: " << vec1.capacity();  //but it's not always doubled, its only doubled when whole capacity is occupied.s

    vec1.pop_back();
    cout << "\nSize of Vec1 after Pop Back: " << vec1.size();

    cout << "\nFirst Element of Vec1: " << vec1.front();    //same as vec1[0]
    cout << "\nLast Element of Vec1: " << vec1.back();      //same as vec1[vec1.size-1]
    cout << "\nElement at 2nd index: " << vec1.at(2);
}