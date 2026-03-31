/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:

    // merge two sorted linked list
    ListNode* merge2Lists(ListNode* l1, ListNode* l2){
        ListNode dummy;
        ListNode* curr = &dummy;
        while(l1 && l2){
            int v1 = l1 ? l1->val : INT_MAX;
            int v2 = l2 ? l2->val : INT_MAX;
            if(v1 <= v2){
                curr->next = l1;
                l1 = l1->next;
                
            }
            else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        curr->next = l1 ? l1 : l2;

        return dummy.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return nullptr;
        }
        else if(lists.size() == 1){
            return lists[0];
        }

        ListNode* result = lists[0];
        for(int i = 1; i < lists.size(); i++){
            result = merge2Lists(result, lists[i]);
        }
        return result;
    }
};
