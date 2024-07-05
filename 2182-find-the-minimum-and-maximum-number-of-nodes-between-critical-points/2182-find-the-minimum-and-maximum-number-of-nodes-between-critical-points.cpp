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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int prev = 0, ind = 2, minn = INT_MAX;
        vector<int> ans;
        
        while(head->next->next != NULL){
            if((head->next->val > head->val && head->next->val > head->next->next->val) || (head->next->val < head->val && head->next->val < head->next->next->val)) {
                ans.push_back(ind);
                if(prev!=0) minn = min(ind-prev, minn);
                prev = ind;
            }
            ind++;
            head = head->next;
        }
        if(ans.size()<2) return {-1, -1};
        for(auto i: ans) cout << i << " ";
        if(minn == INT_MAX) return {ans[ans.size()-1]-ans[0], ans[ans.size()-1]-ans[0]};
        return {minn, ans[ans.size()-1]-ans[0]};
    }
};