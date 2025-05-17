class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; i++){
            if(grid[i][0] == 1) {
                grid[i][0] = 0;
                q.push({i, 0});
            }
            if(grid[i][n-1] == 1) {
                grid[i][n-1] = 0;
                q.push({i, n-1});
            }
        }

        for(int j=0; j<n; j++){
            if(grid[0][j] == 1) {
                grid[0][j] = 0;
                q.push({0, j});
            }
            if(grid[m-1][j] == 1) {
                grid[m-1][j] = 0;
                q.push({m-1, j});
            }
        }

        vector<int> dir = {0, 0, -1, +1, +1, -1, 0, 0};
        while(!q.empty()){
            int x = q.front().first, y = q.front().second;
            q.pop();

            // grid[x][y] = 0;

            for(int i=0; i<4; i++){
                int nx = x+dir[i], ny = y+dir[i+4];
                if(nx<m && nx>=0 && ny<n && ny>=0 && grid[nx][ny] == 1) {
                    q.push({nx, ny});
                    grid[nx][ny] = 0;
                }
            }
        }

        int sum = 0;
        for(auto i: grid) sum+=accumulate(i.begin(), i.end(), 0);
        return sum;
    }
};