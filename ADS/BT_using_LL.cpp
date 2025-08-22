#include<iostream>
using namespace std;
struct node{
    int item;
    struct node*left;
    struct node*right;
    node(int value) : item(value), left(nullptr), right(nullptr) {}
};
void inordertraversal(struct node*root){
    if(root==nullptr){
        return ;
    }
    inordertraversal(root->left);
    cout<<root->item<< " ";
    inordertraversal(root->right);
}
 void preordertraversal(node* root) {
    if (root == nullptr) return;
    cout << root->item << " ";
    preordertraversal(root->left);
    preordertraversal(root->right);
 }
 void postordertraversal(node* root) {
    if (root == nullptr) return;
    postordertraversal(root->left);
    postordertraversal(root->right);
    cout << root->item << " ";
 }
 node* insertNode(node* root, int value) {
    if (root == nullptr) return new node(value);
    if (value < root->item) root->left = insertNode(root->left, value);
    else root->right = insertNode(root->right, value);
    return root;
 } 

int main(){
    node* root = nullptr;
    int n, value;
    cout << "Enter number of nodes in the binary tree: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        root = insertNode(root, value);
    }
    cout << "\nTraversal of the constructed binary tree\n";
    cout << "Inorder traversal:\n";
    inordertraversal(root);
    cout << "\nPreorder traversal:\n";
    preordertraversal(root);
    cout << "\nPostorder traversal:\n";
    postordertraversal(root);
    cout << endl;
    return 0;
}