class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int presum = 0;
        unordered_map<int, int> mp {{0,-1}};
        for(int i=0; i<nums.size(); i++){
            presum += nums[i];
            presum %= k;
            if(mp.find(presum) != mp.end()) {
                if(i - mp[presum] >= 2) return true;
            }
            else mp[presum] = i;
        }
        return false;
    }
};