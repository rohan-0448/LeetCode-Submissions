class Solution {
public:

    int check(vector<int>& nums, vector<int>& dp, int index){
        if(index < 0) return 0;
        if(index == 0) return nums[0];

        if(dp[index]!=-1) return dp[index];

        int take = nums[index] + check(nums, dp, index-2);
        int not_take = check(nums, dp, index-1);

        return dp[index] = max(take, not_take);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);

        return check(nums, dp, n-1);
    }
};