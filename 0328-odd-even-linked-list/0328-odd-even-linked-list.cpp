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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *temp = NULL;
        if(head && head->next && head->next->next) temp = head->next->next;
        else return head;
        ListNode *odd = head, *even = head->next;
        ListNode* cpy = even;
        int flg=1;
        while(temp){
            if(flg) {
                odd->next = temp;
                flg = 0;
                odd = odd -> next;
            }
            else {
                even->next = temp;
                flg = 1;
                even = even -> next;
            }
            temp = temp -> next;
        }
        odd -> next = cpy;
        even->next = NULL;
        return head;
        // vector<ListNode*> v;
        // ListNode* temp;
        // while(temp){
        //     v.push_back(temp);
        //     temp = temp->next;
        // }
        // temp = head;
        // for(int i=2; i<v.size(); i+2){
        //     temp -> next = v[i];
        //     temp = temp -> next;
        // }
        // for(int i=1; i<v.size(); i+2){
        //     temp -> next = v[i];
        //     temp = temp -> next;
        // }
        // return head;
    }
};