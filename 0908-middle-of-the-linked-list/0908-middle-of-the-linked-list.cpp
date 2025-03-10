class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        ListNode *slow = head, *fast = head;
        while(fast){
            fast = fast -> next;
            if(fast) fast = fast -> next;
            else break;
            slow = slow -> next;
        }
        return slow;
    }
};