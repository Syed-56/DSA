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

//just like binary search
bool search(Node* root, int key) {
    if(!root)   return false;
    if(root->data>key)     return search(root->left, key);
    else if(root->data<key)     return search(root->right, key);
    else    return true;
}

//if leftmost root null means we are at leftmost i.e min otherwise traverse furtherleft
Node* min(Node* root) {
    if(!root)   return NULL;
    else if(!root->left) return root;
    else    return min(root->left);
}

Node* max(Node* root) {
    if(!root)   return NULL;
    else if(!root->right) return root;
    else    return max(root->right);
}

Node* predecessor(Node* root, Node* pred, int key) {
    if(!root)   return pred;

        if(key > root->data)   return predecessor(root->right, root, key);    //since pred is next min and root->data is less so update
    else if(key < root->data)  return predecessor(root->left, pred, key); //since pred is next min and root->data is big so unchanged
    else {  //node found
        if(root->left)   return max(root->left);    //since pred is max in left subtree
        return pred;
    }
}

Node* successor(Node* root, Node* succ, int key) {
    if(!root)   return succ;

        if(key > root->data)   return successor(root->right, succ, key);  //since succ is next max and root->data is less so unchanged
    else if(key < root->data)  return successor(root->left, root, key);  //since succ is next max and root->data is big so update
    else {  //node found
       if(root->right)  return min(root->right); //since succ is min in right subtree
       return succ;
    }
}

int height(Node* root) {
    if(!root)   return -1;
    else return 1+max(height(root->left), height(root->right));
}

int main() {
    int preorder[] = {3,2,1,5,6,4};
    int n = sizeof(preorder)/sizeof(preorder[0]);
    Node* root = buildTree(preorder,n);
    int key = 3;
    cout << "Node " << key << (search(root,key) ? " Found" : " Not Found") << endl;
    cout << "Min Node: " << min(root)->data << endl << "Max Node: " << max(root)->data << endl;
    cout << "Height = " << height(root) << endl;
    cout << "Predecessor of " << key << " = " << predecessor(root,NULL,key)->data
         << "\nSuccessor of " << key << " = " << successor(root,NULL,key)->data << endl;
}