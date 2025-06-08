class Solution {
public:
    int count(int ind, int amount, vector<int> &coins, vector<vector<int>>& dp) {
        if(ind == 0) {
            if(amount % coins[0] == 0) return amount / coins[0];
            else return 1e9;
        }
        if(amount == 0) return 0;

        if(dp[ind][amount] != -1) return dp[ind][amount];

        int not_take = count(ind-1, amount, coins, dp);
        int take = 1e9; // initialise with big value cause we have to do min later
        if(amount >= coins[ind]) take = 1 + count(ind, amount-coins[ind], coins, dp);

        return dp[ind][amount] = min(take, not_take);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(coins.size(), vector<int> (amount+1, -1));
        int ans = count(n-1, amount, coins, dp);

        if(ans >= 1e9) return -1;
        else return ans;
    }
};