class Solution {
public:

    void bfs(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &visited){
        if(i>=grid.size() || i<0 || j>=grid[0].size() || j<0 || visited[i][j] == 1 || grid[i][j] == '0') return;

        visited[i][j] = 1;

        bfs(i+1, j, grid, visited);
        bfs(i-1, j, grid, visited);
        bfs(i, j+1, grid, visited);
        bfs(i, j-1, grid, visited);
    }

    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0, m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int> (n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1' && visited[i][j] == 0){
                    bfs(i, j, grid, visited);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};