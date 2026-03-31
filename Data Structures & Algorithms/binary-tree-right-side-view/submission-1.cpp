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
    vector<int> rightSideView(TreeNode* root) {
        // bfs
        if(!root) return {};
        queue<TreeNode*> bfs;
        bfs.push(root);

        vector<int> rightView;
        while(!bfs.empty()){
            rightView.push_back(bfs.back()->val);
            int n = bfs.size();
            for(int i = 0; i < n ; i++){
                if(bfs.front()->left) bfs.push(bfs.front()->left);
                if(bfs.front()->right) bfs.push(bfs.front()->right);
                bfs.pop();
            }
        }
        return rightView;
    }
};
