#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {

    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

// Returns:
// first  -> maximum money if current node is NOT robbed
// second -> maximum money if current node IS robbed
pair<int, int> solve(TreeNode* root) {

    if (root == nullptr) {
        return {0, 0};
    }

    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    // If current node is NOT robbed,
    // children may or may not be robbed.
    int notRobbed =
        max(left.first, left.second) +
        max(right.first, right.second);

    // If current node IS robbed,
    // children cannot be robbed.
    int robbed =
        root->val +
        left.first +
        right.first;

    return {notRobbed, robbed};
}

int rob(TreeNode* root) {

    pair<int, int> result = solve(root);

    return max(
        result.first,
        result.second
    );
}

int main() {

    /*
             3
            / \
           2   3
            \   \
             3   1

        Maximum = 7
    */

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);

    cout << "Maximum money: "
         << rob(root)
         << endl;

    return 0;
}
