#include <iostream>
#include <queue>
#include <stack>
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

Node* insert(Node* root, int val) {
    if(!root)   return new Node(val);
    if(val < root->data)        root->left = insert(root->left, val);
    else if(val > root->data)   root->right = insert(root->right, val);
    return root;
}

Node* buildTree(int preorder[], int n) {
    Node* root = NULL;
    for(int i=0; i<n; i++) {
        root = insert(root, preorder[i]);
    }
    return root;
}

Node* min(Node* root) {
    if(!root)   return NULL;
    else if(!root->left) return root;
    else    return min(root->left);
}

Node* deleteNode(Node* root, int val) {
    if(!root)   return NULL;
    if(val < root->data)    root->left = deleteNode(root->left, val);
    else if(val > root->data)    root->right = deleteNode(root->right, val);

    else {
        if(!root->left && !root->right) {   //no child case
            delete root;
            return NULL;
        }
        else if(root->left && !root->right) {  //left chlid
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else if(!root->left && root->right) {  //right chlid
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else {  //both child exist
            Node* succ = min(root->right);
            root->data = succ->data;
            root->right = deleteNode(root->right, succ->data);
        }
    }
    return root;
}

void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }   else cout << "-1 ";
}

int main() {
    int preorder[] = {3,2,1,5,6,4};
    int n = sizeof(preorder)/sizeof(preorder[0]);
    Node* root = buildTree(preorder,n);
    cout << "Delete node " << deleteNode(root,3)->data << endl;
    preOrder(root);
}