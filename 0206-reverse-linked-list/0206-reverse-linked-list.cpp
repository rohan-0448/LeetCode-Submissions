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
    ListNode* reverseList(ListNode* head) {
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        if(!head) return head;
        ListNode* prev = NULL, *next2 = head->next;
        while(next2 != NULL){
            head -> next = prev;
            prev = head;
            head = next2;
            next2 = next2 -> next;
        }
        head -> next = prev;
        return head;
    }
};