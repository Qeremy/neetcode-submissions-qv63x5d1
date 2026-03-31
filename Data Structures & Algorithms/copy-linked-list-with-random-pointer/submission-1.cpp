/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* copy = head;
        unordered_map<Node*, Node*> mapNode;
        while(copy){
            mapNode[copy] = new Node(copy->val);
            copy = copy->next;
        }

        for(auto &it : mapNode){
            it.second->next = it.first->next ? mapNode[it.first->next] : nullptr;
            it.second->random = it.first->random ? mapNode[it.first->random] : nullptr;
        }

        return mapNode[head];


    }
};



