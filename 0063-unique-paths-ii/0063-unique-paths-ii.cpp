class Solution {
public:
    int count_paths(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(r == 0 && c == 0) return 1;
        if(dp[r][c] != -1) return dp[r][c];

        int top = 0, left = 0;

        if(r > 0 && grid[r-1][c] == 0) top = count_paths(r-1, c, grid, dp);
        if(c > 0 && grid[r][c-1] == 0) left = count_paths(r, c-1, grid, dp);

        return dp[r][c] = top + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r = obstacleGrid.size(), c = obstacleGrid[0].size();
        if(obstacleGrid[r-1][c-1] == 1) return 0;
        vector<vector<int>> dp(r, vector<int> (c, -1));
        return count_paths(r-1, c-1, obstacleGrid, dp);
    }
};