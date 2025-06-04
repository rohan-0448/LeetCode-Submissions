class Solution {
public:
    // int count_paths(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    //     if(r == 0 && c == 0) return 1;
    //     if(dp[r][c] != -1) return dp[r][c];

    //     int top = 0, left = 0;

    //     if(r > 0 && grid[r-1][c] == 0) top = count_paths(r-1, c, grid, dp);
    //     if(c > 0 && grid[r][c-1] == 0) left = count_paths(r, c-1, grid, dp);

    //     return dp[r][c] = top + left;
    // }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r = obstacleGrid.size(), c = obstacleGrid[0].size();
        if(obstacleGrid[r-1][c-1] == 1 || obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>> dp(r, vector<int> (c, 0));

        for(int i=0; i<r; i++) {
            dp[i][0] = (obstacleGrid[i][0] == 0? 1: 0);
            if(dp[i][0] == 0) break;
        }
        for(int j=0; j<c; j++) {
            dp[0][j] = (obstacleGrid[0][j] == 0? 1: 0);
            if(dp[0][j] == 0) break;
        }

        for(int i=1; i<r; i++) {
            for(int j=1; j<c; j++) {
                if(obstacleGrid[i][j] != 1) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[r-1][c-1];

        // return count_paths(r-1, c-1, obstacleGrid, dp);
    }
};