class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto &i: nums) mp[i]++;


        int curr = k;
        while(true) {
            if(mp[curr] == 0) return curr;   
            curr += k;
        }

        return -1;
    }
};