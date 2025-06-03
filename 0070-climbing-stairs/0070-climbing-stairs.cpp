class Solution {
public:
    int ways(int c, vector<int> &dp) {
        if(c == 1 || c == 0) return 1;

        if(dp[c] != -1) return dp[c];

        return dp[c] = ways(c-1, dp) + ways(c-2, dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return ways(n, dp);
    }
};