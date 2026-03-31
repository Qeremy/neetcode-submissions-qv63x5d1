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
    int preIndex = 1;

    void dfs(TreeNode* node, vector<int>& preorder, 
    unordered_map<int, int> inList, int l, int r){
        if(!node) return;

        int currIn = inList[node->val];
        if(l < currIn){
            node->left = new TreeNode(preorder[preIndex]);
            preIndex++;
            dfs(node->left, preorder, inList, l, currIn - 1);
        }
        
        if(r > currIn){
            node->right = new TreeNode(preorder[preIndex]);
            preIndex++;
            dfs(node->right, preorder, inList, currIn + 1, r);
        }
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // wants O(1) lookup
        unordered_map<int, int> inList;
        int n = inorder.size();
        for(int i = 0; i < n; i++){
            inList[inorder[i]] = i;
        }

        // dfs
        TreeNode* root = new TreeNode(preorder[0]);
        dfs(root, preorder, inList, 0, n - 1);

        return root;
    }
};
