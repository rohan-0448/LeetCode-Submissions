class Solution {
public:
    int f(int index, int target, vector<int> &coins, vector<vector<int>> &dp) {
        if(index < 0 || target < 0) return 0;
        if(target == 0) return 1;

        if(dp[index][target] != -1) return dp[index][target];

        int not_take = f(index-1, target, coins, dp);
        int take = 0;
        if(coins[index] <= target) take = f(index, target-coins[index], coins, dp);

        return dp[index][target] = take + not_take;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        return f(n-1, amount, coins, dp);
    }
};