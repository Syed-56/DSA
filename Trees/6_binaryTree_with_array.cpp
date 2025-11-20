#include <iostream>
#include <queue>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    public:
    Node(int val) {
        data=val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) {
    Node* newNode = new Node(val);
    if (!root) return newNode;

    // Use queue to do level-order traversal
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        if (!curr->left) {
            curr->left = newNode;
            return root;
        } else {
            q.push(curr->left);
        }
        if (!curr->right) {
            curr->right = newNode;
            return root;
        } else {
            q.push(curr->right);
        }
    }

    return root; // should never reach here
}


void BFS(Node* root, int arr[], int n) {
    if(!root)   return; //empty tree
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();
        arr[n++] = curr->data;
        if(curr->left)   q.push(curr->left);
        if(curr->right)  q.push(curr->right);
    }
}

void parent(int arr[], int n, int i) {
    if(i<1 || i>n) return;
    if(i!=1)    cout << "\nParent = " << arr[i/2] << endl;
}

void childs(int arr[], int n, int i) {
    if(i<1 || i>n) return;
    if((2*i) < n)  cout << "Left Chlid = " << arr[2*i];
    if((2*i)+1 < n) cout << "\tRight Child = " << arr[(2*i)+1] << endl;
}

int main() {
    Node* tree = NULL;
    tree = insert(tree,3);
    tree = insert(tree,9);
    tree = insert(tree,5);
    tree = insert(tree,14);
    tree = insert(tree,10);
    tree = insert(tree,6);
    tree = insert(tree,8);
    int treeInArray[8];
    BFS(tree,treeInArray,1);
    for(int i=1; i<8; i++)  cout << treeInArray[i] << " ";
    parent(treeInArray,8,2);
    childs(treeInArray,8,3);
}