class Solution {
public:

    int recur(string &s, string &t, int i, int j, vector<vector<int>> &dp) {
        if(j == t.length()) return 1;
        if(i == s.length()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int not_take = recur(s, t, i+1, j, dp);
        int take = 0;

        if(s[i] == t[j]) take = recur(s, t, i+1, j+1, dp);

        return dp[i][j] = not_take + take;
    }

    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length(), vector<int> (t.length(), -1));
        return recur(s, t, 0, 0, dp);
    }
};