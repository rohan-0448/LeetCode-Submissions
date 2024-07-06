class Solution {
public:

    int check(vector<int>& nums, int index, vector<int>& dp){
        if(index==0) return nums[0];
        if(index<0) return 0;

        if(dp[index] != -1) return dp[index];

        int take = nums[index] + check(nums, index-2, dp);
        int not_take = check(nums, index-1, dp);

        return dp[index] = max(take, not_take);
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return check(nums, nums.size()-1, dp);
    }
};