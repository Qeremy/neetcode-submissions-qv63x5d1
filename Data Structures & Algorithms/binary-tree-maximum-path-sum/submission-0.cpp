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
    int maxSum = INT_MIN;
    int dfs(TreeNode* node){
        if(!node) return 0;

        int left = dfs(node->left);
        int right = dfs(node->right);

        int currMaxSum = node->val;
        if(left > 0){
            currMaxSum += left;
        }
        if(right > 0){
            currMaxSum += right;
        }
        maxSum = max(maxSum, currMaxSum);

        return node->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};
