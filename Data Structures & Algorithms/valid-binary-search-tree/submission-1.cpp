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
    bool isValid = true;
    void dfs(TreeNode* node, int left, int right){
        if(!node) return;
        // right > node->val > left 
        if(node->val <= left || node->val >= right){
            isValid = false;
        }
        dfs(node->left, left, node->val);
        dfs(node->right, node->val, right);



    }

    bool isValidBST(TreeNode* root) {
        dfs(root, INT_MIN, INT_MAX);
        return isValid;
    }
};
