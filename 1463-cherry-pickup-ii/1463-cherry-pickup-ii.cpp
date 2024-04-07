class Solution {
public:
    int f(int i, int j, int k, int row, int col, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
        if(j < 0 || k < 0 || j >= col || k >= col) return -1e8;
        
        if(i == row-1) {
            if(j == k) return grid[i][j];
            else return grid[i][j] + grid[i][k];
        }
        
        if(dp[i][j][k] != -1) return dp[i][j][k];
        
        // Explore All paths
        int max_value = INT_MIN;
        int value = 0;
        
        if(j == k) value = grid[i][j];
        else value = grid[i][j] + grid[i][k];
        
        for(int a=-1; a<2; a++){
            for(int b=-1; b<2; b++){
                max_value = max(max_value, f(i+1, j+a, k+b, row, col, grid, dp));
            }
        }
        return dp[i][j][k] = value + max_value;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<vector<vector<int>>> dp(r, vector<vector<int>> (c, vector<int> (c, -1)));
        return f(0, 0, c-1, r, c, grid, dp);
    }
};