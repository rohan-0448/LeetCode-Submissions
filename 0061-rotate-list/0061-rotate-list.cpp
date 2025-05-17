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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        int len = 0;
        ListNode* temp = head;
        while(temp -> next){
            temp = temp -> next;
            len++;
        }
        temp -> next = head;
        
        len -= (k%(len+1));
        while(len--) head = head -> next;

        temp = head -> next;
        head -> next = NULL;

        return temp;
    }
};