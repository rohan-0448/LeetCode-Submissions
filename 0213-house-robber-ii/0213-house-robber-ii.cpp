class Solution {
public:
    int recur(int ind, vector<int> &nums, vector<int> &dp) {
        if(ind == -1) return 0;
        if(ind == 0) return nums[0];

        if(dp[ind] != -1) return dp[ind];

        int take = nums[ind] + recur(ind-2, nums, dp); // take curr and move back 2 spaces;
        // not take - move back one space;
        int not_take = recur(ind-1, nums, dp);

        return dp[ind] = max(take, not_take);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        vector<int> temp1, temp2;
        for(int i=0; i<n; i++) {
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }

        vector<int> dp1(n-1, -1), dp2(n-1, -1);
        return  max(recur(n-2, temp1, dp1), recur(n-2, temp2, dp2));
    }
};