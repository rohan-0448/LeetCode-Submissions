class Solution {
public:
    
    int f(vector<vector<int>> &dp, vector<vector<int>> &grid, int x, int y){
        if(x == 0 && y == 0) return grid[0][0];
        if(dp[x][y] != -1) return dp[x][y];
        
        int top = INT_MAX, left = INT_MAX;
        if(x > 0) top = grid[x][y] + f(dp, grid, x-1, y);
        if(y > 0) left = grid[x][y] + f(dp, grid, x, y-1);
    
        return dp[x][y] = min(top, left);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return f(dp, grid, m-1, n-1);
    }
};