#include <iostream>
using namespace std;
// Class definition for node
class Node {
public:
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize values
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
// Class definition for binary tree
class BinaryTree {
public:
    // Preorder traversal function
    void preorderTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }
        // Visit the root node
        cout << node->data << " ";
        // Traverse the left subtree
        preorderTraversal(node->left);
        // Traverse the right subtree
        preorderTraversal(node->right);
    }
    void inorderTraversal(Node* node){
        if(node==NULL){
            return;
        }
        inorderTraversal(node->left);
        cout<<node->data<<" ";
        inorderTraversal(node->right);

    }
    void postorderTraversal(Node*node){
        if(node==NULL){
            return;
        }
        postorderTraversal(node->left);
          postorderTraversal(node->right);
          cout<<node->data<<" ";
    }
};

int main() {
    // Creating the binary tree
    Node* root = new Node(36);
    root->left = new Node(26);
    root->right = new Node(46);
    root->left->left = new Node(21);
    root->left->right = new Node(31);
    root->right->left=new Node(11);
    root->right->right=new Node(24);
    root->left->left=new Node(41);
    root->left->right=new Node(56);
    root->left->left->left->left->left=new Node(51);
    root->left->left->left->left->right=new Node(66);
    // Creating a BinaryTree object
    BinaryTree tree;
    // Preorder traversal
    cout << "Preorder Traversal: ";
    tree.preorderTraversal(root);
    cout<<endl<<"Inorder Traversal: ";
    tree.inorderTraversal(root);
    cout<<endl<< "Postorder Traversal: ";
    tree.postorderTraversal(root);
    return 0;
}
