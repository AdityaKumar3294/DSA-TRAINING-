#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;

        // If left child is missing
        if(root->left == nullptr)
            return 1 + minDepth(root->right);

        // If right child is missing
        if(root->right == nullptr)
            return 1 + minDepth(root->left);

        // If both children exist
        return 1 + min(
            minDepth(root->left),
            minDepth(root->right)
        );
    }
};