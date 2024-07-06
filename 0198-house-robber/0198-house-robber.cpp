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
        int n = nums.size();

        if(n == 2) return max(nums[0], nums[1]);
        if(n == 1) return nums[0]; 
        
        int prev = nums[0], prev2 = 0, curr = 0;

        for(int i=1; i<n; i++){
            int take = nums[i];
            if(i>1) take += prev2;
            int not_take = prev;

            curr = max(take, not_take);

            prev2 = prev;
            prev = curr;
        }

        return curr;

        // return check(nums, n-1, dp);
    }
};