class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int &v:nums){
            if(pq.size()==k){
                if(v>pq.top()){
                    pq.pop();
                    pq.push(v);
                }
            }
            else{
                pq.push(v);
            }
        }
        return pq.top();
    }
};