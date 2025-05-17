class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> visited(m, vector<int> (n, 0)); 
        
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++){
            if(board[i][0] == 'O') q.push({i, 0});
            if(board[i][n-1] == 'O') q.push({i, n-1});
        }
        for(int j=0; j<n; j++){
            if(board[0][j] == 'O') q.push({0, j});
            if(board[m-1][j] == 'O') q.push({m-1, j});
        }
        // cout << q.size() << endl;
        vector<int> ex = {0 , 0, -1, +1, +1, -1, 0, 0};
        while(!q.empty()){
            int x = q.front().first, y = q.front().second;
            q.pop();

            visited[x][y] = 1;

            for(int i=0; i<4; i++){
                if(x+ex[i]<m && x+ex[i]>=0 && y+ex[i+4]<n && y+ex[i+4]>=0 && board[x+ex[i]][y+ex[i+4]]=='O' && visited[x+ex[i]][y+ex[i+4]]==0) q.push({x+ex[i], y+ex[i+4]}); 
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                // cout << visited[i][j] << " ";
                if(visited[i][j] == 0){
                    // cout << i << "-" << j << endl;
                    board[i][j] = 'X';
                }
            }
            // cout << endl;
        } 
    }
};