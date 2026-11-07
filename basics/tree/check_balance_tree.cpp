#include <iostream>
#include <algorithm>
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

// Calculate Height and Check Balance
int checkHeight(Node* root) {

    if (root == nullptr) {
        return 0;
    }

    int leftHeight = checkHeight(root->left);

    // If left subtree is unbalanced
    if (leftHeight == -1) {
        return -1;
    }

    int rightHeight = checkHeight(root->right);

    // If right subtree is unbalanced
    if (rightHeight == -1) {
        return -1;
    }

    // Check height difference
    if (abs(leftHeight - rightHeight) > 1) {
        return -1;
    }

    return 1 + max(leftHeight, rightHeight);
}

// Check Balanced Binary Tree
bool isBalanced(Node* root) {
    return checkHeight(root) != -1;
}

int main() {

    // Creating Binary Tree
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Binary Tree: ";

    if (isBalanced(root)) {
        cout << "Balanced Tree";
    }
    else {
        cout << "Not a Balanced Tree";
    }

    return 0;
}
