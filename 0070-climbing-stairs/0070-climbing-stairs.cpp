class Solution {
public:
    int ways(int c, vector<int> &dp) {
        if(c == 1 || c == 0) return 1;

        if(dp[c] != -1) return dp[c];

        return dp[c] = ways(c-1, dp) + ways(c-2, dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        dp[0] = 1;
        dp[1] = 1;

        for(int i=2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
        return ways(n, dp);
    }
};