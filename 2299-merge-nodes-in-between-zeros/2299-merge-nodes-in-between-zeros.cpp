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
    ListNode* mergeNodes(ListNode* head) {
        int sum = 0;
        ListNode* temp = new ListNode(0);
        ListNode* cpy = temp;
        while(head != NULL){
            while(head->val != 0){
                sum += head->val;
                head = head->next;
            }
            temp->next = new ListNode(sum);
            temp = temp->next;
            sum = 0;
            head = head->next;
        }
        return cpy->next->next;
    }
};