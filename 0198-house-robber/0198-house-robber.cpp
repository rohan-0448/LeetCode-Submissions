class Solution {
public:

    static int check(vector<int> &dp, vector<int> &nums, int index){
        if(index==0) return nums[0];
        if(index<0) return 0;
        if(dp[index]!=-1) return dp[index];

        int take = INT_MIN, not_take = INT_MIN;
        take = nums[index] + check(dp, nums, index-2);
        not_take = check(dp, nums, index-1);

        return dp[index] = max(take, not_take);
    }

    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        vector<int> dp(nums.size(),-1);
        int x = max(check(dp, nums, nums.size()-1), check(dp, nums, nums.size()-2));
        return dp[nums.size()-1];
    }
};