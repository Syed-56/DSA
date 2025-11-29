#include <iostream>
using namespace std;
//THIS DEMONSTRATES BASIC OPERATIONS IN HASH TABLE WITHOUT COMPLEX COLLISION AND PROBATION

class HashTable {
    int* table; //actual table to dtore keys
    int size;   //size of table defined
    int count;  //no of elements
    int empty = -1;

    int hashFunction(int key) {
        return key % size;
    }

    public:
    HashTable(int s) {
        size = s;
        table = new int[size];
        count = 0;
        for(int i=0; i<size; i++)   table[i] = empty;
    }

    void insertKey(int key) {
        int index = hashFunction(key);
        table[index] = key;
        count++;
        cout << key << " inserted at " << index << endl;
    }
    
    void deleteKey(int key) {
        int index = hashFunction(key);
        table[index] = empty;
        count--;
        cout << key << " deleted at " << index << endl;
    }

    void search(int key) {
        int index = hashFunction(key);
        if(table[index]==key) cout << key << " found at " << index << endl;
        else    cout << "Key not found\n";
    }

    void print() {
        cout << "Hash Table:-\n ";
        for(int i=0; i<size; i++)   cout << "[" << table[i] << "]" << endl;
        cout << endl;
    }

    ~HashTable() {
        delete[] table;
    }
};

int main() {
    HashTable h(7);
    h.insertKey(16);
    h.insertKey(7);
    h.insertKey(33);
    h.insertKey(43);
    h.deleteKey(43);
    h.print();
    h.search(29);
}