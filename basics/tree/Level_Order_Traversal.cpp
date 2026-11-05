#include <iostream>
#include <queue>
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

// Level Order Traversal
void levelOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    queue<Node*> q;

    // Insert root into queue
    q.push(root);

    while (!q.empty()) {

        // Get the front node
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        // Insert left child
        if (current->left != nullptr) {
            q.push(current->left);
        }

        // Insert right child
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
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

    cout << "Level Order Traversal: ";

    levelOrderTraversal(root);

    return 0;
}
