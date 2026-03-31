/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // edge case
        if(!root) return nullptr;

        // swap left and right
        TreeNode* left = root->left;
        root->left = root->right;
        root->right = left;

        // recursion on left and right
        invertTree(root->left);
        invertTree(root->right);
        return root;

    }
};
