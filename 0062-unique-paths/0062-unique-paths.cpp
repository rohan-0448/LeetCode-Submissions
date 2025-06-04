class Solution {
public:
    // int count_paths(int x, int y, vector<vector<int>> &dp) {
    //     if(x == 0 && y == 0) return 1;
    //     if(dp[x][y] != -1) return dp[x][y]; 

    //     int top = 0, left = 0;
    //     if(x > 0) top = count_paths(x-1, y, dp);
    //     if(y > 0) left = count_paths(x, y-1, dp);

    //     return dp[x][y] = top + left;
    // }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        for(int i=0; i<m; i++) dp[i][0] = 1;
        for(int j=0; j<n; j++) dp[0][j] = 1;

        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];

        // return count_paths(m-1, n-1, dp);
    }
};