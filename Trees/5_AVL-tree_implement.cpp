#include <iostream>
using namespace std;

class Node {
    public:
    Node* left;
    Node* right;
    char data;
    int height;

    Node(char val) {
        data = val;
        left = right = NULL;
        height=0;
    }
};

int height(Node* root) {
    if(!root)   return -1;
    else return 1+max(height(root->left), height(root->right));
}

//to get BF of a node
int getBalance(Node* root) {
    if(!root)   return 0;
    return height(root->left) - height(root->right);
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* z = y->left;
    y->left = x;
    x->right = z;

    x->height = height(x);
    y->height = height(y);
    return y;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* z = x->right;
    x->right=y;
    y->left=z;

    x->height = height(x);
    y->height = height(y);
    return x;
}

Node* balanceAVL(Node* root, int val) {
    root->height = height(root);
    int balance = getBalance(root);
    //now we have nodes and balance factor for each node, rotate them to correctly insert
    if(balance>1 && val < root->left->data)     return rightRotate(root);   //LL case
    if(balance<-1 && val > root->right->data)   return leftRotate(root);    //RR case
    if(balance<-1 && val < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }   //RL case
    if(balance>1 && val > root->left->data) {   //LR case
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    return root;
}

Node* insert(Node* root, char val) {
    if(!root)   return new Node(val);
    if(val < root->data)        root->left = insert(root->left, val);
    else if(val > root->data)   root->right = insert(root->right, val);
    else return root;

    return balanceAVL(root,val);
}

void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }   else cout << "-1 ";
}

Node* buildTree(char preorder[], int n) {
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
    
    return balanceAVL(root,val);
}

int main() {
    char preorder[] = {'H','I','J','B','A','E','C','F','D','G','K','L'};
    int n = sizeof(preorder)/sizeof(preorder[0]);
    Node* root = buildTree(preorder,n);
    preOrder(root);
}