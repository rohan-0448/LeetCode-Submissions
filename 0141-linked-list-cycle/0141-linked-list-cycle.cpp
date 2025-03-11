/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        while(slow!=NULL && fast!=NULL){
            slow = slow->next;
            fast = fast->next;
            if(fast) fast = fast->next;
            else return false;

            if(slow == fast) return true;
        }
        return false;
    }
    // bool hasCycle(ListNode *head) {
    //     unordered_map<ListNode*, int> mp;
    //     while(head){
    //         mp[head]++;
    //         if(mp[head] == 2) return true;
    //         head = head -> next;
    //     }
    //     return false;
    // }
};