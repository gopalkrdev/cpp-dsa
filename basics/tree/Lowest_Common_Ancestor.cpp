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

// Find Lowest Common Ancestor
Node* findLCA(Node* root, int n1, int n2) {

    // Base condition
    if (root == nullptr) {
        return nullptr;
    }

    // If current node matches either value
    if (root->data == n1 || root->data == n2) {
        return root;
    }

    // Search in left and right subtrees
    Node* leftLCA = findLCA(root->left, n1, n2);
    Node* rightLCA = findLCA(root->right, n1, n2);

    // Both nodes found in different subtrees
    if (leftLCA != nullptr && rightLCA != nullptr) {
        return root;
    }

    // Return the non-null result
    if (leftLCA != nullptr) {
        return leftLCA;
    }

    return rightLCA;
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

    int n1 = 4;
    int n2 = 5;

    Node* lca = findLCA(root, n1, n2);

    if (lca != nullptr) {
        cout << "Lowest Common Ancestor of "
             << n1 << " and " << n2
             << " is: " << lca->data << endl;
    }
    else {
        cout << "LCA not found!" << endl;
    }

    return 0;
}
