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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp = head;
        int len = 0;
        while(temp) {
            temp = temp->next;
            len++;
        }

        vector<ListNode*> ans(k);
        int part = len/k, rest = len%k;

        temp = head;
        ListNode* prev = temp;
        for(int i=0; i<k; i++) {
            ListNode* temp1 = temp;
            int size = part + (rest>0 ? 1: 0);
            rest--;
            
            while(size--) {
                prev=temp;
                if(temp) temp = temp->next;
            }
            if(prev != nullptr) prev->next = nullptr;

            ans[i] = temp1;
        }

        return ans;
    }
};