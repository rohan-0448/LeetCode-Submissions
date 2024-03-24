class Solution {
public:
    
    // recusion with dp format
    int f(int x, int y, vector<vector<int>> &dp){
        if(x == 0 && y == 0) return 1;
        if(dp[x][y] != -1) return dp[x][y];
        
        int top = 0, left = 0;
        if(x > 0) top = f(x-1, y, dp);
        if(y > 0) left = f(x, y-1, dp);
        
        return dp[x][y] = top + left;
    }
    
    int uniquePaths(int m, int n) {
        // tabulation format
        vector<vector<int>> dp(m, vector<int> (n, 1));
        dp[0][0] = 1;
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                int left = 0, top = 0;
                if(i != 0) top = dp[i-1][j];                
                if(j != 0) left = dp[i][j-1];

                dp[i][j] = top + left;
            }
        }
        return dp[m-1][n-1];
        return f(m-1, n-1, dp);
    }
};