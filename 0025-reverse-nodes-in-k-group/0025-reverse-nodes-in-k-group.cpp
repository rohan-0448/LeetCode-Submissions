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
        int len = 0;
        ListNode *curr = head;
        while(curr){
            curr = curr->next;
            len++;
        }

        curr = head;
        ListNode* prev = NULL, *nxt = NULL;
        ListNode* prev_start = NULL, *new_head = NULL, *start = NULL;
        for(int i=0; i<len/k; i++){
            int k_temp = k;
            start = curr;
            prev = NULL;
            while(k_temp--){
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }
            if(i == 0) new_head = prev;

            if(prev_start) prev_start->next = prev;
            prev_start = start;
        }
        if(prev_start) prev_start->next = curr;
        return new_head;
    }
};