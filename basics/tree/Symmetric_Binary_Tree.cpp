#include <iostream>
using namespace std;

// Node Structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Check whether two subtrees are Mirror Images
bool isMirror(Node* leftNode, Node* rightNode) {

    // Both nodes are NULL
    if (leftNode == nullptr && rightNode == nullptr) {
        return true;
    }

    // One node is NULL
    if (leftNode == nullptr || rightNode == nullptr) {
        return false;
    }

    // Compare values and opposite subtrees
    return (leftNode->data == rightNode->data) &&
           isMirror(leftNode->left, rightNode->right) &&
           isMirror(leftNode->right, rightNode->left);
}

// Check Symmetric Binary Tree
bool isSymmetric(Node* root) {

    if (root == nullptr) {
        return true;
    }

    return isMirror(root->left, root->right);
}

int main() {

    // Creating Symmetric Binary Tree
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(2);

    root->left->left = new Node(3);
    root->left->right = new Node(4);

    root->right->left = new Node(4);
    root->right->right = new Node(3);

    // Check Symmetry
    if (isSymmetric(root)) {
        cout << "Binary Tree is Symmetric";
    }
    else {
        cout << "Binary Tree is Not Symmetric";
    }

    return 0;
}
