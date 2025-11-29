#include <iostream>
using namespace std;

class HashTable {
    int* table; //actual table to dtore keys
    int size;   //size of table defined
    int count;  //no of elements
    int empty = -1;

    int hashFunction1(int key) {
        return key % size;
    }
    int hashFunction2(int key) {
        return 5 - (key % 5);
    }
    float getLoadFactor() {
        return (float)count/size;
    }

    void reHash() {
        int oldSize = size;
        int* oldTable = table;
        cout << "\nRehashing...\n";
        size = size*2 + 3;  //since size 7 so 7x2=14 and next prime is 14+3=17
        table = new int[size];
        count = 0;
        for(int i=0; i<size; i++)   table[i]=empty;
        //re-insert old keys
        for(int i=0; i<oldSize; i++) {
            if(oldTable[i]!=empty)  insertKey(oldTable[i]);
        }
    }

    public:
    HashTable(int s) {
        size = s;
        table = new int[size];
        count = 0;
        for(int i=0; i<size; i++)   table[i] = empty;
    }

    void insertKey(int key) {
        if(getLoadFactor()>0.7)   reHash();
        int index = hashFunction1(key);
        for(int i=0; i<size; i++) {
            int newIndex = (index + i*(hashFunction2(key))) % size;

            if(table[newIndex]==-1) {
                table[newIndex] = key;
                count++;
                cout << key << " inserted at " << newIndex << endl;
                return;
            }
        }
        cout << "Hash Table Full\n" << endl;
    }
    
    void deleteKey(int key) {
        int index = hashFunction1(key);
        for(int i=0; i<size; i++) {
            int newIndex = (index + i*(hashFunction2(key))) % size;

            if(table[newIndex]) {
                table[newIndex] = empty;
                count--;
                cout << key << " deleted at " << newIndex << endl;
                return;
            }
            else {
                cout << "Already Empty\n";
                return;
            }
        }
        cout << "Key Not Found\n" << endl;
    }

    void search(int key) {
        int index = hashFunction1(key);
        for(int i=0; i<size; i++) {
            int newIndex = (index + i*(hashFunction2(key))) % size;
            
            if(table[newIndex]==key) {
                cout << key << " found at " << newIndex << endl;
                return;
            }
            if(table[newIndex]==-1) {
                cout << key << " not found" << endl;
                return;
            }
        }
        cout << "Hash Table Full\n" << endl;
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
    HashTable doubleHash(7);
    doubleHash.insertKey(16);
    doubleHash.insertKey(7);
    doubleHash.insertKey(33);
    doubleHash.insertKey(44);
    doubleHash.insertKey(13);
    doubleHash.insertKey(56);
    doubleHash.insertKey(25);
    doubleHash.insertKey(99);
    doubleHash.print();
}