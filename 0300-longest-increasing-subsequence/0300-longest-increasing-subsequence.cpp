class Solution {
public:
    
    int f(vector<int> &nums, vector<vector<int>> &dp, int index, int last_index){
        if(index == nums.size()){
            return 0;
        }
        if(dp[index][last_index+1] != -1) return dp[index][last_index+1];
        
        int len = f(nums, dp, index+1, last_index);
        if(last_index == -1 || nums[last_index] < nums[index]){
            len = max(len, 1 + f(nums, dp, index+1, index));
        }
        return dp[index][last_index+1] = len;
    }
        
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1, -1));
        return f(nums, dp, 0, -1);
    }
};