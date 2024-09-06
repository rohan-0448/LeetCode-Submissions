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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st;
        for(auto i: nums) st.insert(i);

        ListNode *temp = new ListNode();
        temp->next = head;
        
        ListNode *curr = temp, *prev = temp;
        while(curr != NULL){
            ListNode *nextNode = curr->next;
            
            if(st.count(curr->val) != 0) prev->next = nextNode;
            else prev = curr;

            curr = nextNode;
        }

        return temp->next;
    }
};