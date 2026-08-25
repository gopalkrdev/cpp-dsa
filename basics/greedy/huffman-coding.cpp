#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {

    char ch;
    int freq;

    Node* left;
    Node* right;

    Node(char character, int frequency) {

        ch = character;
        freq = frequency;

        left = nullptr;
        right = nullptr;
    }
};

struct Compare {

    bool operator()(Node* a, Node* b) {

        return a->freq > b->freq;
    }
};

void generateCodes(
    Node* root,
    string code
) {
    if (root == nullptr) {
        return;
    }

    // Leaf node
    if (root->left == nullptr &&
        root->right == nullptr) {

        cout << root->ch
             << " : "
             << code
             << endl;

        return;
    }

    // Left = 0
    generateCodes(
        root->left,
        code + "0"
    );

    // Right = 1
    generateCodes(
        root->right,
        code + "1"
    );
}

int main() {

    vector<char> characters = {
        'A', 'B', 'C',
        'D', 'E', 'F'
    };

    vector<int> frequencies = {
        5, 9, 12,
        13, 16, 45
    };

    priority_queue<
        Node*,
        vector<Node*>,
        Compare
    > minHeap;

    // Create leaf nodes
    for (int i = 0;
         i < characters.size();
         i++) {

        minHeap.push(
            new Node(
                characters[i],
                frequencies[i]
            )
        );
    }

    // Build Huffman Tree
    while (minHeap.size() > 1) {

        Node* left = minHeap.top();
        minHeap.pop();

        Node* right = minHeap.top();
        minHeap.pop();

        Node* parent =
            new Node(
                '#',
                left->freq + right->freq
            );

        parent->left = left;
        parent->right = right;

        minHeap.push(parent);
    }

    Node* root = minHeap.top();

    cout << "Huffman Codes:\n";

    generateCodes(root, "");

    return 0;
}
