#include <iostream>
using namespace std;

class Node {
    public:
    Node* left;
    Node* right;
    int data;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void maxHeapify(int arr[], int n, int i) {
    int smallest = i;
    int leftChild = 2*i + 1, rightChild = 2*i + 2;

    if(leftChild < n && arr[leftChild] > arr[smallest]) {
        smallest = leftChild;
    }
    if(rightChild < n && arr[rightChild] > arr[smallest]) {
        smallest = rightChild;
    }
    if(smallest!=i) {
        swap(arr[smallest],arr[i]);
        maxHeapify(arr,n,smallest);
    }
}

void buildMaxHeap(int arr[], int n) {
    int lastNonLeaf = (n/2)-1;
    for(int i=lastNonLeaf; i>=0; i--) {
        maxHeapify(arr,n,i);
    }
}

void heapSort(int arr[], int n) {
    int lastNonLeaf = (n/2)-1;
    for(int i = lastNonLeaf; i>=0; i--) {
        maxHeapify(arr,n,i);
    }
    for(int i=n-1; i>=0; i--) {
        swap(arr[0],arr[i]);
        maxHeapify(arr,i,0);
    }
}

int main() {
    int arr[5] = {4,10,5,3,1};
    buildMaxHeap(arr,5); 
    heapSort(arr,5);
    for(int i=0; i<5; i++)  cout << arr[i] << " ";
}