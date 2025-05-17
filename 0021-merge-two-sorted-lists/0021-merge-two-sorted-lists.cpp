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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        ListNode* head = new ListNode(0);
        ListNode* temp = head;

        while(list1 && list2){
            if(list1->val < list2->val){
                temp->next = new ListNode(list1->val);
                temp = temp->next;
                list1 = list1->next;
            }else{
                temp->next = new ListNode(list2->val);
                temp = temp->next;
                list2 = list2->next;
            }
        }

        while(list1){
            temp->next = new ListNode(list1->val);
            temp = temp->next;
            list1 = list1->next;
        }

        while(list2){
            temp->next = new ListNode(list2->val);
            temp = temp->next;
            list2 = list2->next;
        }

        return head->next;







        
        
        // ListNode *head = new ListNode(0);
        // ListNode *a = head;
        // while(list1 && list2){
        //     if(list1 -> val < list2 -> val){
        //         a -> next = new ListNode(list1 -> val);
        //         a = a -> next;
        //         list1 = list1 -> next;
        //     }else{
        //         a -> next = new ListNode(list2 -> val);
        //         a = a -> next;
        //         list2 = list2 -> next;
        //     }
        // }

        // while(list1) {
        //     a -> next = new ListNode(list1 -> val);
        //     a = a-> next;
        //     list1 = list1 -> next;
        // }
        // while(list2) {
        //     a -> next = new ListNode(list2 -> val);
        //     a = a-> next;
        //     list2 = list2 -> next;
        // }

        // return head -> next;
        // ListNode* ans = new ListNode(0);
        // ListNode* cpy = ans;
        // int num = 0;
        // while(list1!=NULL && list2!=NULL){
        //     if(list1->val < list2->val){
        //         num = list1->val;
        //         list1 = list1->next;
        //     }else{
        //         num = list2->val;
        //         list2 = list2->next;
        //     }
        //     ans->next = new ListNode(num);
        //     ans = ans->next;
        // }
        // if(list1 != NULL){
        //     while(list1!=NULL){
        //         ans -> next = new ListNode(list1->val);
        //         ans = ans->next;
        //         list1 = list1->next;
        //     }
        // }
        // if(list2 != NULL){
        //     while(list2!=NULL){
        //         ans -> next = new ListNode(list2->val);
        //         ans = ans->next;
        //         list2 = list2->next;
        //     }
        // }

        // return cpy->next;
    }
};