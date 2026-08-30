class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int l=0, r=0, n=nums.size(), mx = INT_MIN;
        while(r<n) {
            if(mp[nums[r]] <= k) {
                mp[nums[r]]++;
            }            
            while(mp[nums[r]] > k) {
                mp[nums[l]]--;
                l++;
            }
            mx = max(mx, r-l+1);
            r++;
        }
        return mx;
    }
};