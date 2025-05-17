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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int c = 0;
        
        while(temp){
            temp = temp->next;
            c++;
        }
        if(c==n) return head->next;
        c -= n;

        temp = head;
        ListNode* prev = NULL;
        while(c>0){
            c--;
            if(!temp) break;
            prev = temp;
            temp = temp->next;
            cout << prev->val;
        }
        // cout << (temp==NULL);
        prev->next = temp->next;

        return head;
        
        
        
        
        
        // if(head->next == NULL && n == 1) return NULL;
        // ListNode *curr = head, *prev = head;

        // while(curr && n--) curr = curr -> next;
        // if(!curr) return head->next;

        // while(curr -> next){
        //     curr = curr -> next;
        //     // if(!curr) break;
        //     prev = prev -> next;
        // }

        // if(prev->next) prev -> next = prev -> next -> next;
        // return head;

        // ListNode* curr = head, *prev = NULL;
        
        // int count = 0;
        // ListNode* temp = head;
        // while(temp){
        //     temp = temp->next;
        //     count++;
        // }
        // n = count - n; 
        // while(n--) {
        //     prev = curr;
        //     curr = curr->next;
        // }
        // prev -> next = curr -> next;

        // return head;
    }
};