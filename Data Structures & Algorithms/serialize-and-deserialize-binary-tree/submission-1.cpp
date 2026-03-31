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

class Codec {
public:
    string serialized;
    int index = 0;
    void dfs(TreeNode* node){
        if(!node){
            serialized += "N,";
            return;
        }

        dfs(node->left);
        dfs(node->right);
        serialized += to_string(node->val) + ",";
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        serialized = "";
        dfs(root);
        return serialized;
    }

    TreeNode* build(vector<string>& nodes){
        string val = nodes[index--];

        if(val == "N") return nullptr;

        TreeNode* node = new TreeNode(stoi(val));

        // IMPORTANT: build right first
        node->right = build(nodes);
        node->left = build(nodes);

        return node;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string curr;

        // split by ','
        for(char c : data){
            if(c == ','){
                nodes.push_back(curr);
                curr = "";
            } else {
                curr += c;
            }
        }

        index = nodes.size() - 1;

        return build(nodes);
    }
};
