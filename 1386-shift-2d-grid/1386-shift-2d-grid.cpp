class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int tot = m*n;
        k %= tot;

        vector<vector<int>> ans(m, vector<int> (n,0));

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int od = i*n+j;
                int nw = (od+k) % tot;

                ans[nw/n][nw%n] = grid[i][j];
            }
        }
        return ans;
    }
};