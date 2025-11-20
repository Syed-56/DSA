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
    int largest = i;
    int leftChild = 2*i + 1, rightChild = 2*i + 2;

    if(leftChild < n && arr[leftChild] >= arr[largest]) {
        largest = leftChild;
    }
    if(rightChild < n && arr[rightChild] >= arr[largest]) {
        largest = rightChild;
    }
    if(largest!=i) {
        swap(arr[largest],arr[i]);
        maxHeapify(arr,n,largest);
    }
} 

void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int leftChild = 2*i + 1, rightChild = 2*i + 2;

    if(leftChild < n && arr[leftChild] < arr[smallest]) {
        smallest = leftChild;
    }
    if(rightChild < n && arr[rightChild] < arr[smallest]) {
        smallest = rightChild;
    }
    if(smallest!=i) {
        swap(arr[smallest],arr[i]);
        minHeapify(arr,n,smallest);
    }
}

void buildMaxHeap(int arr[], int n) {
    int lastNonLeaf = (n/2)-1;
    for(int i=lastNonLeaf; i>=0; i--) {
        maxHeapify(arr,n,i);
    }
}

void buildMinHeap(int arr[], int n) {
    int lastNonLeaf = (n/2)-1;
    for(int i=lastNonLeaf; i>=0; i--) {
        minHeapify(arr,n,i);
    }
}

int main() {
    int arr[] = {10,19,14,42,31,26,27,35};
    int n = sizeof(arr)/sizeof(arr[0]);
    buildMaxHeap(arr,n);
    for(int i=0; i<n; i++)  cout << arr[i] << " ";
    cout << endl;
    int arr2[] = {42,35,44,49,33,36,27,35};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    buildMinHeap(arr2,n2);
    for(int i=0; i<n2; i++)  cout << arr2[i] << " ";
}