#include <iostream>
#include <algorithm>
using namespace std;

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

Node* invertTree(Node* root) {

    if (root == nullptr) {
        return nullptr;
    }

    swap(root->left, root->right);

    invertTree(root->left);

    // Recursively invert right subtree
    invertTree(root->right);

    return root;
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

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Original Tree Inorder: ";
    inorder(root);

    // Invert the Binary Tree
    invertTree(root);

    cout << "\nMirror Tree Inorder: ";
    inorder(root);

    return 0;
}
