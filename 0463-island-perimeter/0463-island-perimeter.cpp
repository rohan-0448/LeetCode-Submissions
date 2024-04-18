class Solution {
public:
    
    int check(int x, int y, vector<vector<int>> &grid){
        int res = 0;
        
        if(x == 0) res++;
        if(x == grid.size()-1) res++;
        if(y == 0) res++;
        if(y == grid[0].size()-1) res++;
        
        if(x>0 && grid[x-1][y] == 0) res++;
        if(y>0 && grid[x][y-1] == 0) res++;
        if(x<grid.size()-1 && grid[x+1][y] == 0) res++;
        if(y<grid[0].size()-1 && grid[x][y+1] == 0) res++;
        
        return res;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] != 1) continue;
                int temp = check(i, j, grid);
                ans += temp;
                // cout << i << "," << j << " - " << temp << endl;
            }
        }
        return ans;
    }
};