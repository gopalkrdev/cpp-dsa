#include <iostream>
using namespace std;

// Node structure
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

// Calculate total number of nodes
int countNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    return 1 + countNodes(root->left)
             + countNodes(root->right);
}

// Calculate height of Binary Tree
int height(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}

// Count leaf nodes
int countLeafNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    // Leaf node has no children
    if (root->left == nullptr &&
        root->right == nullptr) {
        return 1;
    }

    return countLeafNodes(root->left)
         + countLeafNodes(root->right);
}

// Inorder Traversal
void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    // Creating Binary Tree
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->right = new Node(6);

    cout << "Inorder Traversal: ";
    inorder(root);

    cout << "\nTotal Nodes: "
         << countNodes(root);

    cout << "\nHeight of Tree: "
         << height(root);

    cout << "\nLeaf Nodes: "
         << countLeafNodes(root);

    return 0;
}
