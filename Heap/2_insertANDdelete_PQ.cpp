#include <iostream>
using namespace std;
int capacity = 100;

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

void insertMaxHeap(int arr[], int &n, int capacity, int val) {
    if(n>=capacity) {
        cout << "Heap Overflow\n";
        return;
    }
    //step1 insert element in array
    int i = n;
    arr[i] = val;
    n++;

    //step2 make parent
    int parent = (i-1)/2;
    //step3 while parent small: swap with current and update parent by going up (up-heapify)
    while(i!=0 && arr[parent] < arr[i]) {   //for inserting in minHeap: check arr[parent] >= arr[i]
        swap(arr[i], arr[parent]);
        i=parent;
        parent = (i-1)/2;
    }
}

void deleteMaxHeap(int arr[], int &n) {
    if(n<=0)    return;
    arr[0] = arr[n-1];  //step1 replace root with last element
    n--;    //step2 decrement heap size
    maxHeapify(arr,n,0);
}

int main() {
    int priorityQueue[] = {1,2,3,4,5,6,7};
    int n = sizeof(priorityQueue)/sizeof(priorityQueue[0]);
    buildMaxHeap(priorityQueue,n);
    insertMaxHeap(priorityQueue,n,capacity,8);
    for(int i=0; i<n; i++)  cout << priorityQueue[i] << " ";
    cout << endl;
    deleteMaxHeap(priorityQueue,n);
    deleteMaxHeap(priorityQueue,n);
    for(int i=0; i<n; i++)  cout << priorityQueue[i] << " ";
    return 0;
}