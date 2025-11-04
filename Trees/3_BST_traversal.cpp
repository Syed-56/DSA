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

void BFS(Node* root) {
    if(!root)   return; //empty tree
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();
        cout << curr->data << "  ";
        if(curr->left)   q.push(curr->left);
        if(curr->right)  q.push(curr->right);
    }
}

void preOrder_DFS(Node* root) {
    if(!root)   return; //empty tree
    stack<Node*> s;
    s.push(root);
    while(!s.empty()) {
        Node* curr = s.top();
        s.pop();
        cout << curr->data << "  ";
        if(curr->right)  s.push(curr->right);
        if(curr->left)   s.push(curr->left);
    }
}

void inOrder_DFS(Node* root) {
    stack<Node*> s;
    Node* curr = root;

    while(curr || !s.empty()) {
        while(curr) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << "  ";
        curr = curr->right;
    }
}

void postOrder_DFS(Node* root) {
    stack<Node*> s;
    Node* curr = root;
    Node* lastVisit = NULL;

    while(!s.empty() || curr) {
        if(curr) {
            s.push(curr);
            curr= curr->left;
        } else {
            Node* peek = s.top();
            if(peek->right && lastVisit != peek->right) {
                curr = peek->right;
            } else {
                cout << peek->data << "  ";
                lastVisit = peek;
                s.pop();
            }
        }
    }
}

int main() {
    int preorder[] = {3,2,1,5,6,4};
    int n = sizeof(preorder)/sizeof(preorder[0]);
    Node* root = buildTree(preorder,n);
    cout << "\nBFS traversal:-\n";
    BFS(root);
    cout << "\nDFS preorder traversal:-\n";
    preOrder_DFS(root);
    cout << "\nDFS Inorder traversal:-\n";
    inOrder_DFS(root);
    cout << "\nDFS Postorder traversal:-\n";
    postOrder_DFS(root);
}