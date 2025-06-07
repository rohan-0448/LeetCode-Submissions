class Solution {
public:
    int recur(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp) {
        if(j1 < 0 || j1 >= grid[0].size() || j2 < 0 || j2 >= grid[0].size()) return -1e8;
        if(i == grid.size()-1) {
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int mx = -1e8;
        for(int x=-1; x<2; x++) {
            for(int y=-1; y<2; y++) {
                int val = 0;
                if(j1 == j2) val = grid[i][j1];
                else val = grid[i][j1] + grid[i][j2];

                val += recur(i+1, j1+x, j2+y, grid, dp);
                mx = max(mx, val);
            }
        }
        return dp[i][j1][j2] = mx;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<vector<vector<int>>> dp(r, vector<vector<int>> (c, vector<int> (c, 0)));
        for(int i=0; i<c; i++) {
            for(int j=0; j<c; j++) {
                if(i == j) dp[r-1][i][j] = grid[r-1][i];
                else dp[r-1][i][j] = grid[r-1][i] + grid[r-1][j];
            }
        }

        for(int i=r-2; i>=0; i--) {
            for(int j1=0; j1<c; j1++) {
                for(int j2=0; j2<c; j2++) {
                    int mx = -1e8;
                    for(int x=-1; x<2; x++) {
                        for(int y=-1; y<2; y++) {
                            int dj1 = j1+x, dj2 = j2+y, val = 0;
                            if(j1 == j2) val = grid[i][j1];
                            else val = grid[i][j1] + grid[i][j2];

                            if(dj1 >= 0 && dj1 < c && dj2 >= 0 && dj2 < c) val += dp[i+1][dj1][dj2];
                            else val = -1e8;

                            mx = max(mx, val);
                        }
                    }
                    dp[i][j1][j2] = mx;
                }
            } 
        }
        return dp[0][0][c-1];

        // return recur(0, 0, c-1, grid, dp);
    }
};