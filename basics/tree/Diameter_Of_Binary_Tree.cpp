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

// Calculate Height and Diameter
int findDiameter(Node* root, int &diameter) {

    if (root == nullptr) {
        return 0;
    }

    int leftHeight = findDiameter(root->left, diameter);
    int rightHeight = findDiameter(root->right, diameter);

    // Calculate diameter
    diameter = max(diameter, leftHeight + rightHeight);

    // Return height
    return 1 + max(leftHeight, rightHeight);
}

int main() {

    // Creating Binary Tree
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->left->left->left = new Node(6);

    int diameter = 0;

    findDiameter(root, diameter);

    cout << "Diameter of Binary Tree: "
         << diameter << endl;

    return 0;
}
