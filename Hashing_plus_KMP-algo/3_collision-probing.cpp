#include <iostream>
using namespace std;

class HashTable {
    int* table; //actual table to dtore keys
    int size;   //size of table defined
    int count;  //no of elements
    int empty = -1;
    string probing;

    int hashFunction(int key) {
        return key % size;
    }

    public:
    HashTable(int s, string probeType) {
        size = s;
        table = new int[size];
        count = 0;
        for(int i=0; i<size; i++)   table[i] = empty;
        probing = probeType;
    }

    void insertKey(int key) {
        int index = hashFunction(key);
        for(int i=0; i<size; i++) {
            int newIndex;
            if(probing=="Linear") {
                newIndex = (index + i) % size;
            }
            else if(probing=="Quadratic") {
                newIndex = (index + i*i) % size;
            }   

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
        int index = hashFunction(key);
        for(int i=0; i<size; i++) {
            int newIndex;
            if(probing=="Linear") {
                newIndex = (index + i) % size;
            }
            else if(probing=="Quadratic") {
                newIndex = (index + i*i) % size;
            }   

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
        int index = hashFunction(key);
        for(int i=0; i<size; i++) {
            int newIndex;
            if(probing=="Linear") {
                newIndex = (index + i) % size;
            }
            else if(probing=="Quadratic") {
                newIndex = (index + i*i) % size;
            }   

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
    HashTable h1(7,"Linear");
    h1.insertKey(16);
    h1.insertKey(7);
    h1.insertKey(33);
    h1.insertKey(44);
    h1.print();
    cout << endl;
    HashTable h2(7,"Quadratic");
    h2.insertKey(16);
    h2.insertKey(7);
    h2.insertKey(33);
    h2.insertKey(44);
    h2.print();
}