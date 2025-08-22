#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
 };
 Node* insertRec(Node* root, int data) {
    if (!root) return new Node(data);
    if (data < root->data) root->left = insertRec(root->left, data);
    else if (data > root->data) root->right = insertRec(root->right, data);
    return root;
 }
 void inorderTraversal(Node* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
 }
 void preorderTraversal(Node* root) {
    if (root) {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
 }
 void postorderTraversal(Node* root) {
    if (root) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
 }
 int main() {
    Node* root = nullptr;
    int n, data;
    cout << "Enter the number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> data;
        root = insertRec(root, data);
    }
    cout << "Recursive In-order traversal: ";
    inorderTraversal(root);
    cout << "\nRecursive Pre-order traversal: ";
    preorderTraversal(root);
    cout << "\nRecursive Post-order traversal: ";
    postorderTraversal(root);
    cout << endl;
    return 0;
}