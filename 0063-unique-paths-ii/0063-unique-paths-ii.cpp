class Solution {
public:
    // Recursion with DP
    int f(vector<vector<int>> matrix, vector<vector<int>> &dp, int x, int y) {
        if(matrix[x][y] == 1) return 0;
        if(x == 0 && y == 0) return 1;
        if(dp[x][y] != -1) return dp[x][y];
        
        int top = 0, left = 0;
        if(x > 0) top = f(matrix, dp, x-1, y);        
        if(y > 0) left = f(matrix, dp, x, y-1);
        
        return dp[x][y] = top + left;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return f(obstacleGrid, dp, m-1, n-1);
    }
};