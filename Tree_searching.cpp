#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    // Constructor
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
//class for binary search tree
class BST {
private:
    // Helper function to find the minimum value node
    Node* findMin(Node* root) {
        while (root && root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

public:
    // Recursive function to insert a value in the BST
    Node* insert(Node* root, int val) {
        if (root == nullptr) {
            return new Node(val);  // Create a new node if root is null
        }

        if (val < root->data) {
            root->left = insert(root->left, val);  // Insert in the left subtree
        } else if (val > root->data) {
            root->right = insert(root->right, val);  // Insert in the right subtree
        }

        return root;
    }
    // Recursive function to search for a value in the BST
    bool search(Node* root, int key) {
        if (root == nullptr) {
            return false;  // Key not found
        }

        if (root->data == key) {
            return true;  // Key found
        } else if (key < root->data) {
            return search(root->left, key);  // Search in the left subtree
        } else {
            return search(root->right, key);  // Search in the right subtree
        }
    }

    // Recursive function to delete a node from the BST
    Node* deleteNode(Node* root, int key) {
        if (root == nullptr) {
            return root;  // If root is null, nothing to delete
        }

        if (key < root->data) {
            root->left = deleteNode(root->left, key);  // Delete from the left subtree
        } else if (key > root->data) {
            root->right = deleteNode(root->right, key);  // Delete from the right subtree
        } else {
            // Node found; now handle three cases
            // Case 1: Node with only one child or no child
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Case 2: Node with two children, get the in-order successor (smallest in the right subtree)
            Node* temp = findMin(root->right);

            // Copy the in-order successor's value to this node
            root->data = temp->data;

            // Delete the in-order successor
            root->right = deleteNode(root->right, temp->data);
        }

        return root;
    }

    // In-order traversal to display the tree
    void inorderTraversal(Node* root) {
        if (root == nullptr) {
            return;
        }
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
    void preorderTraversal(Node* root){
        if(root==nullptr){
            return;
        }
        cout<<root->data<<" ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
};

int main() {
    BST tree;
    Node* root = nullptr;
    int choice, value;

    do {
        // Displaying the menu
        cout << "\nBinary Search Tree Operations Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Display In-order Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Insertion
                cout << "Enter value to insert: ";
                cin >> value;
                root = tree.insert(root, value);
                cout << "Value " << value << " inserted.\n";
                break;

            case 2:
                // Searching
                cout << "Enter value to search: ";
                cin >> value;
                if (tree.search(root, value)) {
                    cout << "Value " << value << " found in the tree.\n";
                } else {
                    cout << "Value " << value << " not found in the tree.\n";
                }
                break;

            case 3:
                // Deletion
                cout << "Enter value to delete: ";
                cin >> value;
                root = tree.deleteNode(root, value);
                cout << "Value " << value << " deleted if it existed.\n";
                break;

            case 4:
                // Display In-order Traversal
                cout << "In-order traversal of the tree: ";
                tree.inorderTraversal(root);
                cout<<endl;
                cout<<"Pre-Order Traversal of the tree: ";
                tree.preorderTraversal(root);
                cout << endl;
                break;

            case 5:
                // Exit
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
