class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int, int> mp;
        int max_val = -1;
        // sort(nums.begin(), nums.end());
        set<int> num;
        for(auto i: nums) num.insert(i);
        for(auto i: num){
            mp[abs(i)]++;
            if(mp[abs(i)] >= 2) max_val = max(max_val, abs(i));
        }
        return max_val;
    }
};