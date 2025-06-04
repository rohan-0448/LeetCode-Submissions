class Solution {
public:
    int min_cost(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(r == 0 && c == 0) return grid[0][0];
        if(dp[r][c] != -1) return dp[r][c];
            
        int left = INT_MAX, up = INT_MAX;
        if(r > 0) up = min_cost(r-1, c, grid, dp);
        if(c > 0) left = min_cost(r, c-1, grid, dp);

        return dp[r][c] = grid[r][c] + min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<vector<int>> dp(r, vector<int> (c, -1));

        return min_cost(r-1, c-1, grid, dp);
    }
};