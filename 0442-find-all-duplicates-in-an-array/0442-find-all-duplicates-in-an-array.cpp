class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(auto i: nums) {
            mp[i]++;
            if(mp[i] == 2) ans.push_back(i);
        }
        return ans;
    }
};