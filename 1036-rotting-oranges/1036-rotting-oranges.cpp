class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> q;

        int time = 0, m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                }
            }
        }

        
        vector<int> c = {1, -1, 0 , 0, 0, 0, 1, -1};
        while(!q.empty()){
            pair<pair<int, int>, int> top = q.front();
            q.pop();
            int x = top.first.first, y = top.first.second, t = top.second;
            time = max(time, t);
            
            for(int i=0; i<4; i++){
                if(x+c[i]<m && x+c[i]>=0 && y+c[i+4]<n && y+c[i+4]>=0) {
                    if(grid[x+c[i]][y+c[i+4]] == 1){
                        grid[x+c[i]][y+c[i+4]] = 2;
                        q.push({{x+c[i], y+c[i+4]}, t+1});
                    }
                }  
            }
        }
        for(auto i: grid) for(auto j: i) if(j == 1) return -1;
        return time;
    }
};