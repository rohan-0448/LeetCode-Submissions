class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> ans(m, vector<int> (n, -1));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    ans[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            int x = q.front().first.first, y = q.front().first.second, t = q.front().second;
            q.pop();
            
            // if(t==-1) ans[x][y] = 0;
            // else ans[x][y] = t;

            if(ans[x][y] == -1) ans[x][y] = t;

            if(x-1 < m && x-1 >= 0 && y < n && y >= 0 && ans[x-1][y] == -1) q.push({{x-1, y}, t+1}); 
            if(x+1 < m && x+1 >= 0 && y < n && y >= 0 && ans[x+1][y] == -1) q.push({{x+1, y}, t+1});
            if(x < m && x >= 0 && y+1 < n && y+1 >= 0 && ans[x][y+1] == -1) q.push({{x, y+1}, t+1});
            if(x < m && x >= 0 && y-1 < n && y-1 >= 0 && ans[x][y-1] == -1) q.push({{x, y-1}, t+1});
        }

        return ans;
    }
};