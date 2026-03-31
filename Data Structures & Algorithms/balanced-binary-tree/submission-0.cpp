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
    bool balanced = true;

    int dfs(TreeNode* node){
        if(!node) return 0;
        int left = 1 + dfs(node->left);
        int right = 1 + dfs(node->right);
        if(abs(left - right) > 1){
            balanced = false;
        }
        return max(left, right);

    }
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return balanced;


        



        
    }
};
