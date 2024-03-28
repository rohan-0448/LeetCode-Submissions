class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        // if(nums.size()==1)
        int left = 0, right = 0, max_l = 0, n = nums.size();
        map<int, int> mp;
        while(right < n){
            if(mp[nums[right]] == k) max_l = max(max_l, right-left);
            while(left < n && mp[nums[right]] == k) mp[nums[left++]]--;
            if(mp[nums[right]] <= k) mp[nums[right++]]++;
        }
        return max(max_l, right-left);
    }
};