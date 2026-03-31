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
    int goodNodeCount = 0;
    void dfs(TreeNode* node, int max){
        if(!node) return;
        if(node->val >= max){
            goodNodeCount++;
            max = node->val;
        }
        dfs(node->left, max);
        dfs(node->right, max);

    }
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return goodNodeCount;
    }
};
