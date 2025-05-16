class Solution {
public:

    void bfs(int i, int j, vector<vector<char>> &grid){
        if(i>=grid.size() || i<0 || j>=grid[0].size() || j<0 || grid[i][j] == '0') return;

        grid[i][j] = '0';

        bfs(i+1, j, grid);
        bfs(i-1, j, grid);
        bfs(i, j+1, grid);
        bfs(i, j-1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0, m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1'){
                    bfs(i, j, grid);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};