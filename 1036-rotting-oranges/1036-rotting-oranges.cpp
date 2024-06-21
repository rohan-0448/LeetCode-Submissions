class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(row, vector<int>(col, 0));

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                } 
            }
        }

        int time = 0;
        vector<int> dcol = {-1, 0, 1, 0};
        vector<int> drow = {0, -1, 0, 1};

        while(q.empty() == false){
            int x = q.front().first.first, y = q.front().first.second;
            time = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = x+drow[i], ncol = y+dcol[i];
                if(nrow < row && nrow >=0 && ncol < col && ncol >=0 && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1){
                    q.push({{nrow, ncol}, time+1});
                    vis[nrow][ncol] = 2;
                }
            }
        }

        for(int i=0; i<row; i++) for(int j=0; j<col; j++) if(vis[i][j] != 2 && grid[i][j] == 1) return -1;
    
        return time;
    }
};