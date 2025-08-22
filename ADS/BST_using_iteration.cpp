#include<iostream>
#include<stack>
using namespace std;
struct node {
    int data;
    node* left;
    node* right;
    node(int value) : data(value), left(nullptr), right(nullptr) {}
 };
 node* insertIter(node* root, int data) {
    if (!root) return new node(data);
    if (data < root->data) root->left = insertIter(root->left, data);
    else if (data > root->data) root->right = insertIter(root->right, data);
    return root;
 }
 void iterativeInorder(node* root) {
    stack<node*> s;
    node* current = root;
    while (current || !s.empty()) {
        while (current) {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        cout << current->data << " ";
        current = current->right;
    }
 }
 void iterativePreorder(node* root) {
    if (!root) return;
    stack<node*> s;
    s.push(root);
    while (!s.empty()) {
        node* current = s.top();
        s.pop();
        cout << current->data << " ";
        if (current->right) s.push(current->right);
        if (current->left) s.push(current->left);
    }
 }
 void iterativePostorder(node* root) {
    if (!root) return;
    stack<node*> s1, s2;
    s1.push(root);
    while (!s1.empty()) {
        node* current = s1.top();
        s1.pop();
        s2.push(current);
        if (current->left) s1.push(current->left);
        if (current->right) s1.push(current->right);
    }
    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
 }
 int main() {
    node* root = nullptr;
    int n, data;
    cout << "Enter the number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> data;
        root = insertIter(root, data);
    }
    cout << "Iterative In-order traversal: ";
    iterativeInorder(root);
    cout << "\nIterative Pre-order traversal: ";
    iterativePreorder(root);
    cout << "\nIterative Post-order traversal: ";
    iterativePostorder(root);
    cout << endl;
    return 0;
 }