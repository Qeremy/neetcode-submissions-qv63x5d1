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
    // bfs
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levelList;

        queue<TreeNode*> bfs;
        bfs.push(root);
        while(!bfs.empty()){
            // stor all value as vector
            int levelCount = bfs.size();
            vector<int> levelVal;

            if(!bfs.front()) return levelList;

            for(int i = 0; i < levelCount; i++){
                if(!bfs.front()){
                    levelList.push_back(levelVal);
                    return levelList;
                } 
                levelVal.push_back(bfs.front()->val);
                bfs.push(bfs.front()->left);
                bfs.push(bfs.front()->right);
                bfs.pop();
            }
            levelList.push_back(levelVal);

        }

        return levelList;
        
        
    }
};
