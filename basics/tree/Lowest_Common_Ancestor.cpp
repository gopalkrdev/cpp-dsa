#include <iostream>
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

Node* findLCA(Node* root, int n1, int n2) {

    if (root == nullptr) {
        return nullptr;
    }

    if (root->data == n1 || root->data == n2) {
        return root;
    }

    Node* leftLCA = findLCA(root->left, n1, n2);
    Node* rightLCA = findLCA(root->right, n1, n2);

    if (leftLCA != nullptr && rightLCA != nullptr) {
        return root;
    }

    if (leftLCA != nullptr) {
        return leftLCA;
    }

    return rightLCA;
}

int main() {

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
