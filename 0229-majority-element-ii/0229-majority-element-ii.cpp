class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        unordered_map<int, int> mp;
        vector<int> ans;
        for(auto i: nums) {
            mp[i]++;
            if(mp[i]>(nums.size()/3)) if(find(ans.begin(), ans.end(), i) == ans.end()) ans.push_back(i);
        }
        return ans;
        vector<int> v;
        for(auto i: ans) v.push_back(i);
        return v;
    }
};