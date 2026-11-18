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

bool isIdentical(Node* root1, Node* root2) {

    if (root1 == nullptr && root2 == nullptr) {
        return true;
    }

    if (root1 == nullptr || root2 == nullptr) {
        return false;
    }

    // Check current nodes and subtrees
    return (root1->data == root2->data) &&
           isIdentical(root1->left, root2->left) &&
           isIdentical(root1->right, root2->right);
}

int main() {

    // Creating First Binary Tree
    Node* root1 = new Node(1);

    root1->left = new Node(2);
    root1->right = new Node(3);

    root1->left->left = new Node(4);
    root1->left->right = new Node(5);

    // Creating Second Binary Tree
    Node* root2 = new Node(1);

    root2->left = new Node(2);
    root2->right = new Node(3);

    root2->left->left = new Node(4);
    root2->left->right = new Node(5);

    // Check whether trees are identical
    if (isIdentical(root1, root2)) {
        cout << "Both Binary Trees are Identical";
    }
    else {
        cout << "Binary Trees are Not Identical";
    }

    return 0;
}
