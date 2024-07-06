class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        // for(auto i: dp) cout << i << " ";
        // cout << endl;
        for(int coin : coins) {
            for(int i = coin; i <= amount; ++i) dp[i] = min(dp[i], dp[i - coin] + 1);
            // for(auto i: dp) cout << i << " ";
            // cout << endl;
        } 
        return dp[amount] > amount ? -1 : dp[amount];
    }


// void check(vector<int>& coins, int tar, int ind, int curr, long long& minn, int c) {
//         if (curr > tar) return;
//         if (ind == coins.size()) {
//             if (curr == tar) minn = min(minn, (long long)c);
//             return;
//         }
//         if (curr == tar) {
//             minn = min(minn, (long long)c);
//             return;
//         }

//         check(coins, tar, ind + 1, curr, minn, c);
//         if(coins[ind] != INT_MAX && curr + coins[ind] <= tar) check(coins, tar, ind, curr + coins[ind], minn, c + 1);
//     }

//     int coinChange(vector<int>& coins, int amount) {
//         long long minn = LLONG_MAX;
//         check(coins, amount, 0, 0, minn, 0);

//         if (minn == LLONG_MAX) return -1;
//         return (int)minn;
//     }

    // void check(vector<int>& coins, int tar, int ind, int curr, int& minn, int c){
    //     cout << curr << " " << ind << " " << c << endl;
    //     if(curr > tar) return;
    //     if(ind == coins.size()) {
    //         if(curr == tar) minn = min(minn, c);
    //         return;
    //     }
    //     if(curr == tar) {
    //         minn = min(minn, c);
    //         return;
    //     }

    //     check(coins, tar, ind+1, curr, minn, c);
    //     if(curr+coins[ind] <= tar) check(coins, tar, ind, curr+coins[ind], minn, c+1);
    // }

    // int coinChange(vector<int>& coins, int amount) {
    //     int minn = INT_MAX;
    //     check(coins, amount, 0, 0, minn, 0);

    //     if(minn == INT_MAX) return -1;
    //     return minn;
    // }
};