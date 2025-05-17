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
    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(0);
        ListNode* temp = head;

        int carry = 0, sum = 0;
        while(list1 && list2){
            sum = list1->val + list2->val + carry;
            if(sum>9){
                carry = sum/10;
                sum = sum%10;
            }
            else carry = 0;
            temp->next = new ListNode(sum);
            temp = temp->next;
            list1 = list1->next;
            list2 = list2->next;
        }

        while(list1){
            sum = list1->val+carry;
            if(sum>9){
                carry = sum/10;
                sum = sum%10;
            }
            else carry = 0;
            temp->next = new ListNode(sum);
            temp = temp->next;
            list1 = list1->next;
        }

        while(list2){
            sum = list2->val+carry;
            if(sum>9){
                carry = sum/10;
                sum = sum%10;
            }else carry = 0;
            temp->next = new ListNode(sum);
            temp = temp->next;
            list2 = list2->next;
        }

        if(carry){
            temp->next = new ListNode(carry);
        }

        return head->next;










        // ListNode* temp = new ListNode(0);
        // ListNode* head = temp;
        // int carry = 0;
        // while(l1!=NULL && l2!=NULL){
        //     int curr = l1->val+l2->val;
        //     temp->next = new ListNode((curr + carry) % 10);
        //     if(curr+carry > 9) carry = 1;
        //     else carry = 0;
        //     temp = temp->next;
        //     l1 = l1->next;
        //     l2 = l2->next;
        // }
        // while(l1 != NULL){
        //     temp -> next = new ListNode((l1->val + carry)%10);
        //     if(l1->val+carry == 10) carry = 1;
        //     else carry = 0;
        //     l1 = l1->next;
        //     temp = temp->next;
        // }
        // while(l2 != NULL){
        //     temp -> next = new ListNode((l2->val + carry)%10);
        //     if(l2->val+carry == 10) carry = 1;
        //     else carry = 0;
        //     l2 = l2->next;
        //     temp = temp->next;
        // }
        // if(carry) temp->next = new ListNode(carry);
        // return head -> next;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        // ListNode* dum = new ListNode(0);
        // ListNode* cpy = dum;
        // int carry = 0;
        // int num1=0, num2=0;// , flag = 1;
        // while(l1!=NULL || l2!=NULL || carry!=0){
        // //     // if(flag==0){
        // //     //     dum->next = new ListNode;
        // //     //     dum = dum->next;
        // //     // }else{
        // //     //     flag = 0;
        // //     // }
            
        //     if(l1!=NULL) num1 = l1->val;
        //     else num1 = 0;
        //     if(l2!=NULL) num2=l2->val;
        //     else num2=0;

        // //     // dum->val = (num1+num2)/10+carry;
        // //     // carry = (num1+num2)%10;

        //     int sum = (num1+num2+carry);
            
        //     carry = (sum)/10;

        //     dum->next = new ListNode(sum%10);
        //     dum = dum->next;

        //     if (l1 != NULL) l1 = l1->next;
        //     if (l2 != NULL) l2 = l2->next;

        // }

        // return cpy->next;
    }
};