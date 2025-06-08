class Solution {
public:
    int find_subsets(int index, int target, vector<int> &nums, vector<vector<int>> &dp) {
        if(index == 0) {
            if(nums[0] == target && nums[0] == 0) return 2;
            else if(nums[0] == target || target == 0) return 1;
            return 0;
        }

        if(dp[index][target] != -1) return dp[index][target];

        int not_take = find_subsets(index-1, target, nums, dp);
        int take = 0;
        if(nums[index] <= target) take = find_subsets(index-1, target-nums[index], nums, dp);

        return dp[index][target] = take+not_take;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        // basically find 2 set whose difference is target. s1 - s2 = target, s1 + s2 = sum, 
        int sum = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
        vector<vector<int>> dp(n, vector<int> ((target+sum)/2+1, -1));
    
        if((target + sum) % 2 != 0 || abs(target) > sum) return 0;
        return find_subsets(n-1, (target+sum) / 2, nums, dp);
    }
};