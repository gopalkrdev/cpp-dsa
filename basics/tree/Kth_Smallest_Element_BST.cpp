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

Node* insert(Node* root, int value) {

    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

void kthSmallest(Node* root, int k, int& count, int& result) {

    if (root == nullptr || count >= k) {
        return;
    }

    kthSmallest(root->left, k, count, result);

    count++;

    if (count == k) {
        result = root->data;
        return;
    }

    // Visit Right Subtree
    kthSmallest(root->right, k, count, result);
}

int main() {

    Node* root = nullptr;

    // Creating BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    int k = 3;
    int count = 0;
    int result = -1;

    kthSmallest(root, k, count, result);

    if (count >= k) {
        cout << k << "rd Smallest Element: " << result;
    }
    else {
        cout << "Invalid value of K";
    }

    return 0;
}
