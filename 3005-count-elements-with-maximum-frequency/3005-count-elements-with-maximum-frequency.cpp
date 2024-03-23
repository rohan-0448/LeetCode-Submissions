class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int c = 0, maxn = 0;
        for(auto i: nums) {
            mp[i]++;
            maxn = max(maxn, mp[i]);
        }
        for(auto i: mp) if(i.second == maxn) c++;
        return c*maxn;
    }
};