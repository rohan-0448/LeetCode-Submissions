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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode *slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow -> next;
            fast = fast->next->next;
        }

        if (fast != nullptr) slow = slow->next;

        // cout << slow->val << endl;
        // slow = slow->next;
        // temp->next = NULL;
        // cout << slow->val << endl;
        ListNode *prev = NULL;
        while(slow){
            ListNode* curr = slow->next;
            slow->next = prev;
            prev = slow;
            slow = curr;
        }
        // cout << slow->val << " " << head->val << endl;
        while(prev && head){
            if(prev->val!=head->val) return false;
            prev = prev->next;
            head = head->next;
        }
        return true;
    }
};