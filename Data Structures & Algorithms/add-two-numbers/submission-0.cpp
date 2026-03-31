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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* curr = &dummy;
        bool plusOne = false;
        while(l1 || l2){
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;
            int sum = (plusOne) ? v1 + v2 + 1 : v1 + v2;
            plusOne = false;

            if(sum >= 10){
                sum -= 10;
                plusOne = true;
            }

            curr->next = new ListNode(sum);

            curr = curr->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(plusOne){
            curr->next = new ListNode(1);
        }
        return dummy.next;

    }
};
