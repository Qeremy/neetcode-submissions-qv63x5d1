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

        int currBranch = node->val;
        if(left > 0 && left > right) currBranch += left;
        else if(right > 0 && right > left) currBranch += right;

        return currBranch;
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};
