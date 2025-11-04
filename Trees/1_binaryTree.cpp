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

static int idx = -1;    //empty tree
Node* buildTree(int preorder[]) {
    idx++;
    if(preorder[idx]==-1)   return NULL;    //end of branch
    Node* root = new Node(preorder[idx]);   //create node of tree
    root->left = buildTree(preorder);   //create left branches
    root->right = buildTree(preorder);  //create right branches
    return root;
}

int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int height(Node* root) {
    if (!root) return 0;   // empty tree has height 0
    int leftH = height(root->left);
    int rightH = height(root->right);
    return 1 + max(leftH, rightH);  // count current level
}

void printDegrees(Node* root) {
    if (!root) return;

    int d = 0;
    if (root->left)  d++;
    if (root->right) d++;

    cout << "Node " << root->data << " has degree " << d << endl;

    printDegrees(root->left);
    printDegrees(root->right);
}

void nodeType(Node* root) {
    if(!root)   return;
    if(!root->left && !root->right)  cout << root->data << " is Leaf\n";
    if((!root->left && root->right) || (root->left && !root->right))  cout << root->data << " is Unary\n";
    if(root->left && root->right)  cout << root->data << " is Full\n";
}

int main() {
    int preorder[] = {10, 20, 40, -1, -1, 50, -1, -1, 30, -1, -1};
    int n = sizeof(preorder) / sizeof(preorder[0]);

    Node* tree = buildTree(preorder);
    idx=-1;
    cout << "Total Nodes = " << countNodes(tree) << endl;
    cout << "Height: " << height(tree) << endl;
    nodeType(tree->left->right);
    printDegrees(tree);
}