/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {

public:
    Node* root = new Node();
    unordered_map<Node*, Node*> nodeMap;

    Node* dfs(Node* node1, Node* node2){
        if(nodeMap.count(node1)) return nodeMap[node1];

        nodeMap[node1] = node2;
        node2->val = node1->val;
        for(int i = 0; i < node1->neighbors.size(); i++){
            //dfs
            if(!nodeMap.count(node1->neighbors[i])){
                Node* node = new Node();
                node2->neighbors.push_back(node);
            }
            else{
                node2->neighbors.push_back(nodeMap[node1->neighbors[i]]);
            }
            dfs(node1->neighbors[i], node2->neighbors[i]);
        }
        return node2;
    }

    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        return dfs(node, root);
    }
};
