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
    bool isSub = false;

    int heightOfSub(TreeNode* node){
        if(!node) return 0;
        return 1 + max(heightOfSub(node->left), heightOfSub(node->right));
    }

    bool nodeMatch(TreeNode* node, TreeNode* sub){
        if(!node || !sub){
            if(!node && !sub) return true;
            return false;
        }

        bool left = nodeMatch(node->left, sub->left);
        bool right = nodeMatch(node->right, sub->right);
        bool curr = (node->val == sub->val);

        return (left && right && curr);
    }

    // dfs but tests when height is equal to height of Sub
    int dfs(TreeNode* node, TreeNode* sub, int h){
        if(!node) return 0;

        int currH = 1 + max(dfs(node->left, sub, h), dfs(node->right, sub, h));
        if(currH == h){
            // perform a match search
            if(nodeMatch(node, sub)){
                isSub = true;
            }
        }

        return currH;
    }


    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // base case
        if(!root){
            if(!subRoot) return true;
            return false;
        }

        // compare root on the same level as subRoot
        int subHeight = heightOfSub(subRoot);
        dfs(root, subRoot, subHeight);
        return isSub;
    }
};
