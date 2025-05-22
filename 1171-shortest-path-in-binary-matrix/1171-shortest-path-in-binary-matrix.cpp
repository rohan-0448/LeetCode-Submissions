class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[0][0] == 1;
        queue<vector<int>> q;
        q.push({0, 0, 1});


        vector<int> dx = {+1, -1, 0, 0, +1, -1, +1, -1};
        vector<int> dy = {0, 0, +1, -1, +1, -1, -1, +1};
        while(!q.empty()){
            int x = q.front()[0], y = q.front()[1], dis = q.front()[2];
            q.pop();

            if(x == n-1 && y == m-1) return dis;

            for(int i=0; i<8; i++){
                int newx = x + dx[i], newy = y + dy[i];
                if(newx < n && newx >= 0 && newy < m && newy >=0 && vis[newx][newy] == 0 && grid[newx][newy] == 0){
                    q.push({newx, newy, dis+1});
                    vis[newx][newy] = 1;
                } 
            }
        }
        return -1;
    }
};