class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode dummy(0, head);
        ListNode* left = &dummy;

        while(true){

            // find kth node
            ListNode* right = left;
            for(int i = 0; i < k; i++){
                right = right->next;
                if(!right){
                    return dummy.next;
                }
            }

            ListNode* groupStart = left->next;
            ListNode* groupNext = right->next;

            // reverse group
            ListNode* prev = groupNext;
            ListNode* curr = groupStart;

            while(curr != groupNext){
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // reconnect
            left->next = prev;

            // move left pointer
            left = groupStart;
        }

        return dummy.next;
    }
};