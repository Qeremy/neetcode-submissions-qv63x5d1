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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // group start 
        // group next

        ListNode dummy(0, head);
        ListNode* left = &dummy;
        while(true){
            ListNode* right = left;

            
            // moving right forward by k step
            for(int i = 0; i < k; i++){
                right = right->next;
                if(!right) return dummy.next;
            }

            ListNode* groupStart = left->next;
            ListNode* groupNext = right->next;

            ListNode* prev = groupNext;
            ListNode* curr = groupStart;

            while(curr != groupNext){
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            left->next = prev;
            left = groupStart;
        }
    }
};
