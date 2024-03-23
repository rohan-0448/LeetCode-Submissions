class Solution {
public:
    
    int check(vector<int> &nums, vector<int> &dp, int index){
        if(index == 0) return nums[0];
        if(index <= 0) return 0;
        
        if(dp[index] != -1) return dp[index];
        
        int include = nums[index] + check(nums, dp, index-2);
        int not_include = check(nums, dp, index-1);
            
        return dp[index] = max(include, not_include);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==0) return 0;
        vector<int> dp(n, -1), dp2(n, -1);
        vector<int> a = vector<int>(nums.begin(), nums.end()-1);
        vector<int> b = vector<int>(nums.begin()+1, nums.end());
        return max(check(a, dp, n-2), check(b, dp2, n-2));
    }
};