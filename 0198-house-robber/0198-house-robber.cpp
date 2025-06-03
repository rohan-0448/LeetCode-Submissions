class Solution {
public:
    int recur(int ind, vector<int> &nums, vector<int> &dp) {
        if(ind == -1) return 0;
        if(ind == 0) return nums[0];

        if(dp[ind] != -1) return dp[ind];

        int take = nums[ind] + recur(ind-2, nums, dp);
        int not_take = recur(ind-1, nums, dp);

        return dp[ind] = max(take, not_take);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        vector<int> dp(n, -1);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i=2; i<n; i++) {
            int take = dp[i-2] + nums[i];
            int not_take = dp[i-1];

            dp[i] = max(take, not_take);
        }

        return dp[n-1];

        // return recur(n-1, nums, dp); // take curr and move n-2, or not take curr and move n-1
    }
};